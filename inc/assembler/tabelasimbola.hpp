#ifndef _tabela_simbola_hpp_
#define _tabela_simbola_hpp_ 

#include <iostream>
#include <cstdint>
#include <vector>

class TabelaSimbola {
	public:

	int simbol_index(std::string name);

	uint32_t simbol_value(std::string name, bool* defined);

	struct simbol {
		enum sim_tip {NOTYP = 0, SCTN = 1};
		uint32_t value;
		int size;
		sim_tip type;
		bool global;
		int Ndx;
		std::string name;
		simbol(uint32_t v, int s, sim_tip t, bool g, int N, std::string n) : value(v), size(s), type(t), global(g), Ndx(N), name(n) {}
	};

	std::vector<simbol> tabela;

	TabelaSimbola();
};


#endif
