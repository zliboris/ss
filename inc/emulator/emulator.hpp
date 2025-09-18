#ifndef _emulator_hpp_
#define _emulator_hpp_

#define DEBUG false
#define term_out_addr 0xFFFFFF00
#define term_in_addr 0xFFFFFF04
#define tim_cfg_addr 0xFFFFFF10


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdint>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <thread>
#include <atomic>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

class Emulator{
	public:

		enum instrucion_code {HALT = 0b0000, INT = 0b0001, CALL = 0b0010, JMP = 0b0011, XCHG = 0b0100, ARTH = 0b0101, LOGI = 0b0110, SHIF = 0b0111, STOR = 0b1000, LOAD = 0b1001};
		enum system_reg_name {STATUS = 0, HANDLER = 1, CAUSE = 2};
		enum register_numbers {R0 = 0, R1 = 1, R2 = 2, R3 = 3, R4 = 4, R5 = 5, R6 = 6, R7 = 7, R8 = 8, R9 = 9, R10 = 10, R11 = 11, R12 = 12, R13 = 13, R14 = 14, R15 = 15, SP = 14, PC = 15};

		std::map<uint32_t, uint8_t> memory;

		std::vector<uint32_t> gpr;

		std::vector<uint32_t> system_reg;

		void write_mem_32(uint32_t addr, uint32_t value);

		uint32_t read_mem_32(uint32_t addr);

		void write_reg(int reg, uint32_t value);

		uint32_t read_reg(int reg);

		void write_sys_reg(int reg, uint32_t value);

		uint32_t read_sys_reg(int reg);

		void increment_reg(int reg, int value){gpr[reg] += value;};

		void illegal_instruction(){
				push(read_sys_reg(Emulator::STATUS));
				push(read_reg(Emulator::PC));
				write_sys_reg(Emulator::CAUSE, 1);
				write_sys_reg(Emulator::STATUS, read_sys_reg(Emulator::STATUS) & (~0x1));
				write_reg(Emulator::PC, read_sys_reg(Emulator::HANDLER));
		}

		void push(uint32_t value){
			gpr[SP] -= 4;
			write_mem_32(gpr[SP], value);
		}

		uint32_t pop(){
			uint32_t ret = read_mem_32(gpr[SP]);			
			gpr[SP] += 4;
			return ret;
		}

		Emulator(){
			for(int i = 0; i < 16; i++) {gpr.emplace_back(); gpr.back() = 0;}
			for(int i = 0; i < 3; i++) {system_reg.emplace_back(); system_reg.back() = 0;}
			system_reg[STATUS] = 0b111;
			gpr[PC] = 0x40000000;
		}

};


#endif
