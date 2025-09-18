#ifndef _input_file_
#define _input_file_

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <cstdint>
#include <string>

#include "sekcija.hpp"
#include "tabelasimbola.hpp"
#include "tabelarelokacija.hpp"

class Elf {
	public:
		TabelaSimbola symtab;
		std::vector<Sekcija> sections;
		std::vector<TabelaRelokacija> relos;

		Elf& operator+=(Elf& asm_file);
};

std::istream& operator>>(std::istream& is, Elf& of);

std::ostream& operator<<(std::ostream& os, Elf& of);


#endif
