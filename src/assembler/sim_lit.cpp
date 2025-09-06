#include "../../inc/assembler/sim_lit.hpp"

int get_sim_offset(char* simbol){
	for(uint i = 0; i < fajl->lista_sekcija.back().literali.size(); i++)
	{
		if(fajl->lista_sekcija.back().literali[i].simbol && fajl->lista_sekcija.back().literali[i].ime.compare(simbol) == 0) return fajl->lista_sekcija.back().literali[i].offset;
	}
	fajl->lista_sekcija.back().literali.emplace_back(true, std::string(simbol), 0, fajl->lista_sekcija.back().cur_lit_offset);
	fajl->lista_sekcija.back().cur_lit_offset += 4;
	return fajl->lista_sekcija.back().literali.back().offset;
}

int get_lit_offset(uint32_t literal){
	for(uint i = 0; i < fajl->lista_sekcija.back().literali.size(); i++)
	{
		if(!fajl->lista_sekcija.back().literali[i].simbol && fajl->lista_sekcija.back().literali[i].value == literal) return fajl->lista_sekcija.back().literali[i].offset;
	}
	fajl->lista_sekcija.back().literali.emplace_back(false, std::string(""), literal, fajl->lista_sekcija.back().cur_lit_offset);
	fajl->lista_sekcija.back().cur_lit_offset += 4;
	return fajl->lista_sekcija.back().literali.back().offset;
}

void insert_lit_ref(int lit_offset){
	fajl->lista_sekcija.back().referenciranje_literala.emplace_back(fajl->lista_sekcija.back().cur_offset,lit_offset);
}

int simbol_index(std::string name){
	for(uint i = 0; i < fajl->tabela_simbola.size(); i++)
	{
		if(fajl->tabela_simbola[i].name == name) return i;
	}
	return -1;
}

uint32_t get_sim_value(std::string name,bool *defined){
	int i = simbol_index(name);
	if(i != -1){
		if(fajl->tabela_simbola[i].Ndx == 0){
			*defined = false;
			return 0;
		}
		else{
			*defined = true;
			return fajl->tabela_simbola[i].value;
		}
	}
	fajl->tabela_simbola.emplace_back(0,0,NOTYP,false,0,name);
	*defined = false;
	return 0;
}
