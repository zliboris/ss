#ifndef _tabelaliterala_hpp_
#define _tabelaliterala_hpp_

#include <iostream>
#include <cstdint>
#include <vector>

#include "tabelarelokacija.hpp"

class TabelaLiterala {
	public:

	int index_sim(std::string simbol);

	int index_lit(uint32_t literal);

	int insert_sim(std::string simbol);

	int insert_lit(uint32_t literal);

	int get_sim_index(std::string simbol);

	int get_lit_index(uint32_t literal);

	struct literal_t {
		bool simbol;
		std::string ime;
		uint32_t value;
		literal_t(bool s, std::string i, uint32_t v) : simbol(s), ime(i), value(v) {}
	};

	TabelaRelokacija Trelokacija;

	std::vector<literal_t> tabela;
};

#endif
