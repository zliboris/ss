#ifndef _tabela_simbola_hpp_
#define _tabela_simbola_hpp_ 

#include <iostream>
#include <cstdint>
#include <vector>

#define UND ""

class TabelaSimbola {
	public:

	enum sim_tip {NOTYP = 1, SCTN = 0};

	int simbol_index(std::string name);

	uint32_t simbol_value(std::string name, bool* defined);

	void global_simbol(std::string name);

	void extern_simbol(std::string name);

	void add_section(std::string name);

	void add_label(std::string name);

	void sortiraj();

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

	TabelaSimbola();
};

std::ostream& operator<<(std::ostream& os, TabelaSimbola& ts);

#endif
