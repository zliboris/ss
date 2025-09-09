#include "../../inc/assembler/tabelaliterala.hpp"
#include "../../inc/assembler/tabelasimbola.hpp"
#include <algorithm>

int TabelaLiterala::index_sim(std::string simbol){
	for(literal_t &l: tabela){
		if(l.simbol && l.ime == simbol){ 
			auto it = std::find(tabela.begin(),tabela.end(),l);
			return std::distance(tabela.begin(), it);
		}
	}
	return -1;
}

int TabelaLiterala::index_lit(uint32_t literal){
	for(literal_t &l: tabela){
		if(!l.simbol && l.value == literal){ 
			auto it = std::find(tabela.begin(),tabela.end(),l);
			return std::distance(tabela.begin(), it);
		}
	}
	return -1;
}

int TabelaLiterala::insert_sim(std::string simbol){
	tabela.emplace_back(true, simbol, 0);
	Trelokacija.add_rel((tabela.size() - 1) * 4, simbol, 0);
	return index_sim(simbol);
}

int TabelaLiterala::insert_lit(uint32_t literal){
	tabela.emplace_back(false, "", literal);
	return index_lit(literal);
}

int TabelaLiterala::get_sim_index(std::string simbol){
	int index = index_sim(simbol);	
	if(index != -1) return index;
	return insert_sim(simbol);
}

int TabelaLiterala::get_lit_index(uint32_t literal){
	int index = index_lit(literal);	
	if(index != -1) return index;
	return insert_lit(literal);
}
