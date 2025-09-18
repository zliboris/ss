#ifndef _tabela_simbola_hpp_
#define _tabela_simbola_hpp_ 

#include <iostream>
#include <cstdint>
#include <vector>

#define UND ""

class TabelaSimbola {
	public:

	enum sim_tip {NOTYP = 1, SCTN = 0, SIM = 2};

	void add_simbol(uint32_t val, sim_tip tip, bool glob, int Ndx, std::string section, std::string simbol);

	void load_simbol(uint32_t val, TabelaSimbola::sim_tip tip, bool glob, int Ndx, std::string simbol);

	void add_section(uint32_t size, std::string name);

	void update_table();

	void sortiraj();

	int simbol_index(std::string name);

	struct simbol {
		uint32_t value;
		sim_tip type;
		bool global;
		int Ndx;
		std::string section;
		std::string name;
		simbol(uint32_t v, sim_tip t, bool g, int Ndx, std::string N, std::string n) : value(v), type(t), global(g), Ndx(Ndx), section(N), name(n) {}
		bool operator<(simbol s) { return type < s.type;}
	};

	std::vector<simbol> tabela;


};

std::ostream& operator<<(std::ostream& os, TabelaSimbola& ts);

#endif
