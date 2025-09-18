#include "../../inc/emulator/emulator.hpp"

extern void terminal_thread();
extern void timer_thread();

extern std::atomic<bool> terminal_interrupt_pending;
extern std::atomic<bool> timer_interrupt_pending;
extern std::atomic<bool> running;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Koriscenje: " << argv[0] << " <ime_fajla>\n";
        return 1;
    }

    std::string fileName = argv[1];
    std::ifstream input(fileName);
    if (!input.is_open()) {
        std::cerr << "Greska: ne mogu da otvorim fajl " << fileName << "\n";
        return 1;
    }

    Emulator emu;

    std::map<uint32_t, uint8_t> &memory = emu.memory;

    std::string line;
    while (std::getline(input, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::string addrStr;
        if (!(iss >> addrStr)) continue;

        if (addrStr.back() == ':') {
            addrStr.pop_back();
        }

        uint32_t baseAddr = 0;
        try {
            baseAddr = static_cast<uint32_t>(std::stoul(addrStr, nullptr, 16));
        } catch (...) {
            std::cerr << "Nevalidna adresa u liniji: " << line << "\n";
            continue;
        }

        std::string byteStr;
        uint32_t offset = 0;
        while (iss >> byteStr) {
            try {
                uint8_t value = static_cast<uint8_t>(std::stoul(byteStr, nullptr, 16));
                memory[baseAddr + offset] = value;
                offset++;
            } catch (...) {
                std::cerr << "Nevalidan bajt '" << byteStr << "' u liniji: " << line << "\n";
            }
        }
    }

    input.close();

    //int count = 0;
    //for (auto& [addr, val] : memory) {
    //    std::cout << std::hex << std::setw(8) << std::setfill('0') << addr
    //              << ": " << std::setw(2) << std::setfill('0') << (int)val << "\n";
    //}
	
    std::thread term(terminal_thread);
    std::thread t(timer_thread);

    uint32_t IR = 0;
	uint regA = 0, regB = 0, regC = 0;
	uint inst, mode, unsgn_disp;
	int32_t disp;
	uint32_t temp;

	int br_inst = 1;

	bool emulation = true;
	while(emulation){

		//IF

		IR = emu.read_mem_32(emu.read_reg(Emulator::PC));
		emu.increment_reg(Emulator::PC, 4);

		//ID

		inst = ((IR & 0xF0000000u) >> (7 * 4));
		mode = ((IR & 0x0F000000u) >> (6 * 4));
		regA = ((IR & 0x00F00000u) >> (5 * 4));
		regB = ((IR & 0x000F0000u) >> (4 * 4));
		regC = ((IR & 0x0000F000u) >> (3 * 4));
		unsgn_disp = (IR & 0x00000FFFu) >> (0 * 4);
		disp = (int32_t)(IR << 20) >> 20;

		if(DEBUG)std::cout << "Instrukcija broj " << std::dec << br_inst++ << " na adresi " << std::hex << emu.read_reg(Emulator::PC) - 4 << " je " << IR << std::endl;

		//EXEC

		switch(inst){
			case Emulator::HALT:

				if(mode != 0 || regA != 0 || regB != 0 || regC != 0 || disp != 0){
					//Fault: ilegalna instrukcija
					emu.illegal_instruction();
				}
				emulation = false;

				break;
			case Emulator::INT:

				if(mode != 0 || regA != 0 || regB != 0 || regC != 0 || disp != 0){
					//Fault: ilegalna instrukcija
					emu.illegal_instruction();
				}
				emu.push(emu.read_sys_reg(Emulator::STATUS));
				emu.push(emu.read_reg(Emulator::PC));
				emu.write_sys_reg(Emulator::CAUSE, 4);
				emu.write_sys_reg(Emulator::STATUS, emu.read_sys_reg(Emulator::STATUS) & (~0x1));
				emu.write_reg(Emulator::PC, emu.read_sys_reg(Emulator::HANDLER));


				break;
			case Emulator::CALL:

				if( regA > 15 || regB > 15 || regC != 0){
					//Fault: ilegalno adresiranje
					emu.illegal_instruction();
				}
				switch(mode){
					case 0b0000:

						emu.push(emu.read_reg(Emulator::PC));
						emu.write_reg(Emulator::PC, emu.read_reg(regA) + emu.read_reg(regB) + disp);

						break;
					case 0b0001:

						emu.push(emu.read_reg(Emulator::PC));
						emu.write_reg(Emulator::PC, emu.read_mem_32(emu.read_reg(regA) + emu.read_reg(regB) + disp));

						break;
					default:
						//Fault: ilegalna instrukcija
						emu.illegal_instruction();
						break;
				}

				break;
			case Emulator::JMP:

				if( regA > 15 || regB > 15 || regC > 15){
					//Fault: ilegalno adresiranje
					emu.illegal_instruction();
				}

				switch(mode){
					case 0b0000:

						emu.write_reg(Emulator::PC, emu.read_reg(regA) + disp);

						break;
					case 0b0001:

						if(emu.read_reg(regB) == emu.read_reg(regC)){
							emu.write_reg(Emulator::PC, emu.read_reg(regA) + disp);
						}

						break;
					case 0b0010:

						if(emu.read_reg(regB) != emu.read_reg(regC)){
							emu.write_reg(Emulator::PC, emu.read_reg(regA) + disp);
						}

						break;
					case 0b0011:

						if(((int) emu.read_reg(regB)) > ((int) emu.read_reg(regC))){
							emu.write_reg(Emulator::PC, emu.read_reg(regA) + disp);
						}

						break;
					case 0b1000:

						emu.write_reg(Emulator::PC, emu.read_mem_32(emu.read_reg(regA) + disp));

						break;
					case 0b1001:

						if(emu.read_reg(regB) == emu.read_reg(regC)){
							emu.write_reg(Emulator::PC, emu.read_mem_32(emu.read_reg(regA) + disp));
						}

						break;
					case 0b1010:

						if(emu.read_reg(regB) != emu.read_reg(regC)){
							emu.write_reg(Emulator::PC, emu.read_mem_32(emu.read_reg(regA) + disp));
						}

						break;
					case 0b1011:

						if(((int) emu.read_reg(regB)) > ((int) emu.read_reg(regC))){
							emu.write_reg(Emulator::PC, emu.read_mem_32(emu.read_reg(regA) + disp));
						}

						break;
					default:
						//Fault: ilegalna instrukcija
						emu.illegal_instruction();
						break;
				}

				break;
			case Emulator::XCHG:

				if(mode != 0 || regA != 0 || disp != 0){
					//Fault: ilegalna instrukcija
					emu.illegal_instruction();
				}
				if(regB > 15 || regC > 15){
					//Fault: ilegalno adresiranje
					emu.illegal_instruction();
				}

				temp = emu.read_reg(regB);
				emu.write_reg(regB, emu.read_reg(regC));
				emu.write_reg(regC, temp);

				break;
			case Emulator::ARTH:

				if( regA > 15 || regB > 15 || regC > 15){
					//Fault: ilegalno adresiranje
					emu.illegal_instruction();
				}

				if(disp != 0){
					//Fault: ilegalna instrukcija
					emu.illegal_instruction();
				}

				switch(mode){
					case 0b0000:

						emu.write_reg(regA, emu.read_reg(regB) + emu.read_reg(regC));

						break;
					case 0b0001:

						emu.write_reg(regA, emu.read_reg(regB) - emu.read_reg(regC));

						break;
					case 0b0010:

						emu.write_reg(regA, emu.read_reg(regB) * emu.read_reg(regC));

						break;
					case 0b0011:

						emu.write_reg(regA, emu.read_reg(regB) / emu.read_reg(regC));

						break;
					default:
						//Fault: ilegalna instrukcija
						emu.illegal_instruction();
						break;
				}

				break;
			case Emulator::LOGI:

				if( regA > 15 || regB > 15 || regC > 15){
					//Fault: ilegalno adresiranje
					emu.illegal_instruction();
				}

				if(disp != 0){
					//Fault: ilegalna instrukcija
					emu.illegal_instruction();
				}

				switch(mode){
					case 0b0000:

						emu.write_reg(regA, ~emu.read_reg(regB));

						break;
					case 0b0001:

						emu.write_reg(regA, emu.read_reg(regB) & emu.read_reg(regC));

						break;
					case 0b0010:

						emu.write_reg(regA, emu.read_reg(regB) | emu.read_reg(regC));

						break;
					case 0b0011:

						emu.write_reg(regA, emu.read_reg(regB) ^ emu.read_reg(regC));

						break;
					default:
						//Fault: ilegalna instrukcija
						emu.illegal_instruction();
						break;
				}


				break;
			case Emulator::SHIF:

				if( regA > 15 || regB > 15 || regC > 15){
					//Fault: ilegalno adresiranje
					emu.illegal_instruction();
				}

				if(disp != 0){
					//Fault: ilegalna instrukcija
					emu.illegal_instruction();
				}

				switch(mode){
					case 0b0000:

						emu.write_reg(regA, emu.read_reg(regB) << emu.read_reg(regC));

						break;
					case 0b0001:

						emu.write_reg(regA, emu.read_reg(regB) >> emu.read_reg(regC));

						break;
					default:
						//Fault: ilegalna instrukcija
						emu.illegal_instruction();
						break;
				}

				break;
			case Emulator::STOR:

				if( regA > 15 || regB > 15 || regC > 15){
					//Fault: ilegalno adresiranje
					emu.illegal_instruction();
				}

				switch(mode){
					case 0b0000:
						emu.write_mem_32(emu.read_reg(regA) + emu.read_reg(regB) + disp, emu.read_reg(regC));
						break;
					case 0b0010:
						emu.write_mem_32(emu.read_mem_32(emu.read_reg(regA) + emu.read_reg(regB) + disp), emu.read_reg(regC));
						break;
					case 0b0001:
						emu.increment_reg(regA,disp);
						emu.write_mem_32(emu.read_reg(regA), emu.read_reg(regC));
						break;
					default:
						//Fault: ilegalna instrukcija
						emu.illegal_instruction();
						break;
				}

				break;
			case Emulator::LOAD:

				if( regA > 15 || regB > 15 || regC > 15){
					//Fault: ilegalno adresiranje
					emu.illegal_instruction();
				}

				switch(mode){
					case 0b0000:

						emu.write_reg(regA, emu.read_sys_reg(regB));

						break;
					case 0b0001:

						emu.write_reg(regA, emu.read_reg(regB) + disp);

						break;
					case 0b0010:

						emu.write_reg(regA, emu.read_mem_32(emu.read_reg(regB) + emu.read_reg(regC) + disp));

						break;
					case 0b0011:

						emu.write_reg(regA, emu.read_mem_32(emu.read_reg(regB)));
						emu.increment_reg(regB, disp);

						break;
					case 0b0100:

						emu.write_sys_reg(regA, emu.read_reg(regB));

						break;
					case 0b0101:

						emu.write_sys_reg(regA, emu.read_sys_reg(regB) | unsgn_disp);

						break;
					case 0b0110:

						emu.write_sys_reg(regA, emu.read_mem_32(emu.read_reg(regB) + emu.read_reg(regC) + disp));

						break;
					case 0b0111:

						emu.write_sys_reg(regA, emu.read_mem_32(emu.read_reg(regB)));
						emu.increment_reg(regB, disp);

						break;
					default:
						//Fault: ilegalna instrukcija
						emu.illegal_instruction();
						break;
				}

				break;
			default:
				//Fault: ilegalna instrukcija
				emu.illegal_instruction();
				break;
		}

		//INT
		if(terminal_interrupt_pending){
				emu.push(emu.read_sys_reg(Emulator::STATUS));
				emu.push(emu.read_reg(Emulator::PC));
				emu.write_sys_reg(Emulator::CAUSE, 3);
				emu.write_sys_reg(Emulator::STATUS, emu.read_sys_reg(Emulator::STATUS) & (~0x1));
				emu.write_reg(Emulator::PC, emu.read_sys_reg(Emulator::HANDLER));
				terminal_interrupt_pending = false;
		}
		else if(timer_interrupt_pending){
				emu.push(emu.read_sys_reg(Emulator::STATUS));
				emu.push(emu.read_reg(Emulator::PC));
				emu.write_sys_reg(Emulator::CAUSE, 2);
				emu.write_sys_reg(Emulator::STATUS, emu.read_sys_reg(Emulator::STATUS) & (~0x1));
				emu.write_reg(Emulator::PC, emu.read_sys_reg(Emulator::HANDLER));
				timer_interrupt_pending = false;
		}
		

		if(DEBUG){
    		for (int i = 0; i < 16; i++) {
				std::cout << "r" << std::dec << i << "=" 
             	 	 << "0x" << std::setw(8) << std::setfill('0') << std::hex << std::uppercase << emu.read_reg(i) 
             	 	 << " ";

        		if ((i + 1) % 4 == 0) std::cout << std::endl;
    		}
			uint32_t addr = emu.read_reg(Emulator::SP);
			for (int i = 0; i < 20; i++){
				std::cout << std::dec << i << ": " << std::hex << emu.read_mem_32(addr) << std::endl << std::dec;
				addr += 4;
			}
			getchar();

		}


	}
    running = false;
    term.join();
    t.join();
	std::cout << std::endl << "-----------------------------------------------------------------" << std::endl;
	std::cout << "Emulated processor executed halt instruction\n";
    std::cout << "Emulated processor state:\n";

    for (int i = 0; i < 16; i++) {
		std::cout << "r" << std::dec << i << "=" 
             << "0x" << std::setw(8) << std::setfill('0') << std::hex << std::uppercase << emu.read_reg(i) 
             << " ";

        if ((i + 1) % 4 == 0) std::cout << std::endl;
    }


    return 0;
}
