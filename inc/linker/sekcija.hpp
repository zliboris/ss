#ifndef _section_
#define _section_

#include <iostream>
#include <cstdint>
#include <vector>

class Sekcija{
	public:

	std::string name;

	std::vector<uint8_t> content;

	void add_byte(uint8_t byte){content.push_back(byte);}

};

std::ostream& operator<<(std::ostream& os, Sekcija& s);

#endif
