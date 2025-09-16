#ifndef _tabela_simbola_hpp_
#define _tabela_simbola_hpp_ 

#include <iostream>
#include <cstdint>
#include <vector>

#define UND ""

class TabelaSimbola {
	public:

	enum sim_tip {NOTYP = 1, SCTN = 0};

	void add_simbol(uint32_t val, sim_tip tip, bool glob, std::string sekcija, std::string simbol){tabela.emplace_back(val,tip,glob,sekcija,simbol);}

	struct simbol {
		uint32_t value;
		sim_tip type;
		bool global;
		std::string section;
		std::string name;
		simbol(uint32_t v, sim_tip t, bool g, std::string N, std::string n) : value(v), type(t), global(g), section(N), name(n) {}
		bool operator<(simbol s) { return type < s.type;}
	};

	std::vector<simbol> tabela;

};

std::istream& operator>>(std::istream& is, TabelaSimbola& ts);

std::ostream& operator<<(std::ostream& os, TabelaSimbola& ts);

#endif
