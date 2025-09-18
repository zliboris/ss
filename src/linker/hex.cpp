#include "../../inc/linker/hex.hpp"
#include "../../inc/linker/hex_print.hpp"

#include <iostream>

int Hex::section_index(std::string name){
	for(uint i = 0; i < hex_sec.size(); i++)
	{
		if(hex_sec[i].name == name) return i;
	}
	return -1;
}

uint32_t Hex::get_start_addr(std::string section_name){
	int i = section_index(section_name);
	if(i == -1) return 0;
	return hex_sec[i].start_addr;
}

void Hex::add_place_flags(std::string name, uint32_t start_addr, uint32_t size){
	hex_sec.emplace_back(name, start_addr, size);
}
Hex& Hex::operator+=(Sekcija &sec){
	int i = section_index(sec.name);

	if(i == -1){
		uint32_t addr = get_new_sec_addr();
		//std::cout << "novi addr za sekciju " << sec.name << " je " << to_hex_8(addr) << std::endl;
		//std::cout << "poslednja sekcija " << hex_sec.back().name << " je velicine " << to_hex_8(hex_sec.back().size) << " a start_addr mu je " << to_hex_8(hex_sec.back().start_addr) << std::endl;
		hex_sec.emplace_back(sec.name, addr, sec.content.size());
		i = section_index(sec.name);
	}
	
	hex_sec[i].bytes = sec.content;

	return *this;
}

std::ostream& operator<<(std::ostream &os, Hex &hex){
	uint32_t addr = 0;
	bool beginingin = true;
	int i = 7;
	os << std::setfill('0');
	for(auto &bytes: hex.hex_sec){
		if (bytes.start_addr < addr){
			std::cerr << "Greska: preklapanje sekcija " << bytes.name << std::endl;
			//std::cout << "addr je " << to_hex_8(addr) << ", a start_addr " << to_hex_8(bytes.start_addr) << std::endl;
			exit(1);
		}
		else if(bytes.start_addr != addr){ 
			//std::cout << "addr je " << to_hex_8(addr) << ", a start_addr " << to_hex_8(bytes.start_addr) << std::endl;
			addr = bytes.start_addr;
			i = 7;
		}
		for(auto &byte: bytes.bytes){
			if(i % 8 == 7){ 
				if(beginingin == true) beginingin = false;
				else os << std::endl;
				os << std::setw(8) << to_hex_8(addr) << ": ";
			}
			os << std::setw(2) << to_hex_2(byte) << " ";

			i++;
			addr++;
		}
	}

	return os;
}
