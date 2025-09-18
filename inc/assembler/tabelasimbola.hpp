#ifndef _tabela_simbola_hpp_
#define _tabela_simbola_hpp_ 

#include <iostream>
#include <cstdint>
#include <vector>

#define UND ""

class Assembler;

class TabelaSimbola {
	public:

	enum sim_tip {NOTYP = 1, SCTN = 0, SIM = 2};

	int simbol_index(std::string name);

	uint32_t simbol_value(std::string name, bool* defined);

	bool simbol_exists(std::string name);

	void global_simbol(std::string name);

	void extern_simbol(std::string name);

	void add_section(std::string name);

	void add_label(std::string name);

	void add_simbol(std::string name, std::string sekcija);

	void promeni_u_sim(std::string name);

	void add_simbol_value(std::string name, uint32_t value);

	void sortiraj();

	void sad_postoji(std::string name){int i; if((i = simbol_index(name)) != -1) tabela[i].exists = true;}

	bool da_li_postoji(std::string name){
		int i; 
		if((i = simbol_index(name)) == -1) return false;
		return tabela[i].exists;
	}

	bool da_li_je_lokalan(std::string name){
		int i; 
		if((i = simbol_index(name)) == -1) return false;
		return !tabela[i].global;
	}

	struct simbol {
		uint32_t value;
		sim_tip type;
		bool global;
		std::string section;
		std::string name;
		bool exists;
		simbol(uint32_t v, sim_tip t, bool g, std::string N, std::string n) : value(v), type(t), global(g), section(N), name(n), exists(false) {}
		bool operator<(simbol s) { return type < s.type;}
	};

	std::vector<simbol> tabela;

	TabelaSimbola();
};

std::ostream& operator<<(std::ostream& os, TabelaSimbola& ts);

#endif
