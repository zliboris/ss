#ifndef _assembler_hpp_
#define _assembler_hpp_

#include "../../inc/assembler/sekcija.hpp"
#include "../../inc/assembler/tabelasimbola.hpp"

enum sreg {STATUS = 0, HANDLER = 1, CAUSE = 2};

struct reg_lit {
	uint32_t reg;
	uint32_t literal;
};

struct reg_sim {
	uint32_t reg;
	std::string* simbol;
};

struct sim_or_lit{
	bool is_simbol;
	std::string* simbol;
	uint32_t literal;
	sim_or_lit(std::string* s): is_simbol(true), simbol(s){}
	sim_or_lit(uint32_t l): is_simbol(false), literal(l){}
};

struct sim_or_lit_izraz{
	bool is_simbol;
	bool plus;
	std::string* simbol;
	uint32_t literal;
	sim_or_lit_izraz(std::string* s, bool p): is_simbol(true), simbol(s), plus(p){}
	sim_or_lit_izraz(uint32_t l, bool p): is_simbol(false), literal(l), plus(p){}
};

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

	std::vector<std::pair<std::string,std::vector<sim_or_lit_izraz>*>> equ_izrazi;

	void add_equ(std::string* labela, std::vector<sim_or_lit_izraz> *izraz);

	void calculate_equ();

};

#endif
