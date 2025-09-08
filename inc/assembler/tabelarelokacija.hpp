#ifndef _tabela_relokacija_hpp_
#define _tabela_relokacija_hpp_

#include <iostream>
#include <cstdint>
#include <vector>

class TabelaRelokacija{
	public:
	
	struct relokacija {
		uint32_t offset;
		uint32_t simbol;
		int addend;
		relokacija(uint32_t o, uint32_t sim, int a) : offset(o), simbol(sim), addend(a) {};
	};

	void add_rel(uint32_t of, uint32_t sim, int ae);

	std::vector<relokacija> tabela;
};

#endif
