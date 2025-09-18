#include "../../inc/linker/elf.hpp"
#include "../../inc/linker/tabelasimbola.hpp"
#include "../../inc/linker/hex_print.hpp"

std::istream& operator>>(std::istream& is, Elf& of) {
    std::string line;

    while (std::getline(is, line)) {
        if (line.rfind("#.symtab", 0) == 0) {
            std::getline(is, line);
            while (std::getline(is, line) && !line.empty() && line[0] != '#') {
                std::istringstream iss(line);
                std::string numStr, valueHex, typeStr, bindStr, sectStr, nameStr;
                iss >> numStr >> valueHex >> typeStr >> bindStr >> sectStr >> nameStr;

                uint32_t value = std::stoul(valueHex, nullptr, 16);
                TabelaSimbola::sim_tip tip = (typeStr == "SCTN" ? TabelaSimbola::SCTN : TabelaSimbola::NOTYP);
		if (typeStr == "SCTN") tip = TabelaSimbola::SCTN;
		else if(typeStr == "NOTYP") tip = TabelaSimbola::NOTYP;
		else if(typeStr == "SIM") tip = TabelaSimbola::SIM;
                bool glob = (bindStr == "GLOB");
		int Ndx = std::stoi(sectStr);

                of.symtab.load_simbol(value, tip, glob, Ndx, nameStr);
            }
	    of.symtab.update_table();
		if (!line.empty() && line[0] == '#') {
    	    	    is.seekg(-static_cast<int>(line.size()) - 1, std::ios_base::cur);
		}
        }
        else if (line.rfind("#.", 0) == 0 && line.find("rela") == std::string::npos) {
            Sekcija sec;
            sec.name = line.substr(2);
            while (std::getline(is, line) && !line.empty() && line[0] != '#') {
                std::istringstream iss(line);
                std::string byteStr;
                while (iss >> byteStr) {
                    uint8_t val = static_cast<uint8_t>(std::stoul(byteStr, nullptr, 16));
                    sec.add_byte(val);
                }
            }
            of.sections.push_back(std::move(sec));
            if (!is) break;
            is.seekg(-static_cast<int>(line.size()) - 1, std::ios_base::cur);
        }
        else if (line.rfind("#.rela.", 0) == 0) {
            TabelaRelokacija tr;
            tr.section_name = line.substr(7);
            std::getline(is, line);
            while (std::getline(is, line) && !line.empty() && line[0] != '#') {
                std::istringstream iss(line);
                std::string offsetHex, sym;
                int addend;
                iss >> offsetHex >> addend >> sym;
                uint32_t offset = std::stoul(offsetHex, nullptr, 16);
                tr.add_rel(offset, sym, addend);
            }
            of.relos.push_back(std::move(tr));
            if (!is) break;
            is.seekg(-static_cast<int>(line.size()) - 1, std::ios_base::cur);
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, Elf& of) {

	os << of.symtab;

	for (auto& sec : of.sections) {
    	    os << sec;
	}

	for (auto& tr : of.relos) {
    	    os << tr;
	}

	return os;
}

Elf& Elf::operator+=(Elf& asm_file){
	int idx;
	TabelaSimbola temp = asm_file.symtab;
	for(auto sim: asm_file.symtab.tabela){
		if(sim.type == TabelaSimbola::SCTN){
			if( (idx = symtab.simbol_index(sim.name)) != -1 && symtab.tabela[idx].type == TabelaSimbola::SCTN){
				for(auto &simbol : temp.tabela){
					if(simbol.section == sim.name && simbol.type == TabelaSimbola::NOTYP)simbol.value += symtab.tabela[idx].value;
				}
				for(auto sec: asm_file.sections){
					if(sec.name == sim.name){
						for(auto &sec_linked: sections){
							if(sec_linked.name == sim.name){
								sec_linked += sec;
								break;
							}
						}
						break;
					}
				}
				for(auto rel: asm_file.relos){
					if(rel.section_name == sim.name){
						for(auto &rela: rel.tabela){
							rela.offset += symtab.tabela[idx].value;
						}
						for(auto &rel_linked : relos){
							if(rel_linked.section_name == sim.name){
								rel_linked += rel;
								break;
							}
						}
						break;
					}
				}
			}
			else if (symtab.simbol_index(sim.name) != -1){
				std::cerr << "Greska: redefinicija simbola :" << sim.name << std::endl;
				exit(1);
			}
			else {
				Sekcija new_sec;
				new_sec.name = sim.name;
				for(auto sec: asm_file.sections){
					if(sec.name == sim.name){
						new_sec += sec;
						break;
					}
				}
				sections.push_back(new_sec);

				TabelaRelokacija new_relos;
				new_relos.section_name = sim.name;
				for(auto rel: asm_file.relos){
					if(rel.section_name == sim.name){
						new_relos += rel;
					}
				}
				relos.push_back(new_relos);
			}
			symtab.add_section(sim.value, sim.name);
		}
	}
	for(auto &sim: temp.tabela){
		if(sim.type != TabelaSimbola::SCTN && sim.name != UND){
			symtab.add_simbol(sim.value, sim.type, sim.global, sim.Ndx, sim.section, sim.name);
		}
	}

	return *this;
}
