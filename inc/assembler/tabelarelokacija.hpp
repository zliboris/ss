#ifndef _tabela_relokacija_hpp_
#define _tabela_relokacija_hpp_

#include <iostream>
#include <cstdint>
#include <vector>

class TabelaRelokacija{
	public:
	//mora da se prodje kroz sve ove relokacije i inkrementuje se za velicinu sekcije(bez tabele literala)
	struct relokacija {
		uint32_t offset;
		std::string simbol;
		int addend;
		relokacija(uint32_t o, std::string sim, int a) : offset(o), simbol(sim), addend(a) {};
		bool operator<(relokacija r){return offset < r.offset;}
	};

	void add_sekcija_offset(uint32_t offset_sekcije);

	void add_rel(uint32_t of, std::string sim, int ae);

	std::string section_name;

	std::vector<relokacija> tabela;
};

std::ostream& operator<<(std::ostream& os, TabelaRelokacija& tr);

#endif
