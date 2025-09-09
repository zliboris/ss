#ifndef _assembler_hpp_
#define _assembler_hpp_

#include "../../inc/assembler/sekcija.hpp"
#include "../../inc/assembler/tabelasimbola.hpp"

class Assembler {
	public:

	TabelaSimbola simbol_table;

	std::vector<Sekcija> sekcije;


	static Assembler assembler;

	void new_section(std::string name){
		simbol_table.add_section(name);
		sekcije.emplace_back(name);
	}

	Sekcija& get_curr_section(){return sekcije.back();}

	void finish_assembly();

	void error(std::string msg);

};

#endif
