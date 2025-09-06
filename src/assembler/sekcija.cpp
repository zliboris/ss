#include "../../inc/assembler/sekcija.hpp"
#include <algorithm>

int TabelaLiterala::index_sim(std::string simbol){
	for(literal_t l: tabela){
		if(l.simbol && l.ime == simbol){ 
			auto it = std::find(tabela.begin(),tabela.end(),l);
			return std::distance(tabela.begin(), it);
		}
	}
	return -1;
}

int TabelaLiterala::index_lit(uint32_t literal){
	for(literal_t l: tabela){
		if(!l.simbol && l.value == literal){ 
			auto it = std::find(tabela.begin(),tabela.end(),l);
			return std::distance(tabela.begin(), it);
		}
	}
	return -1;
}

int TabelaLiterala::insert_sim(std::string simbol){
	tabela.emplace_back(true, simbol, 0);
	return index_sim(simbol);
}

int TabelaLiterala::insert_lit(uint32_t literal){
	tabela.emplace_back(false, "", literal);
	return index_lit(literal);
}

int TabelaLiterala::get_sim_offset(std::string simbol){
	int index = index_sim(simbol);	
	if(index != -1) return index * 4;
	return insert_sim(simbol) * 4;
}

int TabelaLiterala::get_lit_offset(uint32_t literal){
	int index = index_lit(literal);	
	if(index != -1) return index * 4;
	return insert_lit(literal) * 4;
}
