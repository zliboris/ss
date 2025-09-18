#ifndef _hex_hpp_
#define _hex_hpp_ 

#include "sekcija.hpp"

#include <vector>
#include <cstdint>
#include <iostream>

class Hex{
	public:

	struct byte_sec{
		std::string name;
		uint32_t start_addr;
		uint32_t size;
		std::vector<uint8_t> bytes;
		byte_sec(std::string n, uint32_t sa, uint32_t s) : name(n), start_addr(sa), size(s) {};
		bool operator<(byte_sec &bs){return start_addr < bs.start_addr;};
	};

	std::vector<byte_sec> hex_sec;

	void add_place_flags(std::string name, uint32_t start_addr, uint32_t size);

	uint32_t get_start_addr(std::string section_name);

	uint32_t get_new_sec_addr(){return hex_sec.empty() ? 0 : hex_sec.back().start_addr + hex_sec.back().size;};

	int section_index(std::string name);

	Hex& operator+=(Sekcija &sec);

};

std::ostream& operator<<(std::ostream &os, Hex &hex);

#endif
