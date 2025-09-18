#include "../../inc/linker/tabelasimbola.hpp"
#include "../../inc/linker/hex_print.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>



int TabelaSimbola::simbol_index(std::string name){
	for(uint i = 0; i < tabela.size(); i++)
	{
		if(tabela[i].name == name) return i;
	}
	return -1;
}

void TabelaSimbola::load_simbol(uint32_t val, TabelaSimbola::sim_tip tip, bool glob, int Ndx, std::string simbol){
	tabela.emplace_back(val,tip,glob,Ndx,UND,simbol);
}

void TabelaSimbola::update_table(){
	for(auto &sim: tabela){
		sim.section = tabela[sim.Ndx].name;
	}
}

void TabelaSimbola::add_simbol(uint32_t val, TabelaSimbola::sim_tip tip, bool glob, int Ndx, std::string section, std::string simbol){
	int i;
	i = simbol_index(simbol);
	if(i != -1 && Ndx != 0 && tip != TabelaSimbola::SCTN){
		std::cerr << "Greska: redefinicija simbola " << simbol << std::endl;
		exit(1);
	}
	else if(Ndx != 0 && tip != TabelaSimbola::SCTN) tabela.emplace_back(val,tip,glob,0,section,simbol);
}

void TabelaSimbola::add_section(uint32_t size, std::string name){
	int i = simbol_index(name);
	if(i != -1){
		tabela[i].value += size;
	}
	else tabela.emplace_back(size, TabelaSimbola::SCTN, false, 0, name, name);
}

void TabelaSimbola::sortiraj(){
	std::sort(tabela.begin(), tabela.end());
	tabela.insert(tabela.begin(), {0,NOTYP,false,0,UND,UND});
}


std::ostream& operator<<(std::ostream& os, TabelaSimbola& ts){
	os << std::left << "#.symtab" << std::endl;
	os << std::setfill(' ');
	os << std::setw(8) << "Num" << std::setw(13) << "Value" << std::setw(10) << "Type" << std::setw(10) << "Bind" << std::setw(10) << "Ndx" << std::setw(20) << "Name" << std::endl;
	int i=0;
	for(auto &sim: ts.tabela){
		os << std::setw(8) << std::to_string(i++) + ":" << std::setw(13) << to_hex_8(sim.value) << std::setw(10);
		switch(sim.type){
			case TabelaSimbola::NOTYP : 
				os << "NOTYP";
				break;
			case TabelaSimbola::SCTN : 
				os << "SCTN";
				break;
			case TabelaSimbola::SIM : 
				os << "SIM";
				break;
		}
		os << std::setw(10) << ((sim.global) ? "GLOB" : "LOC") << std::setw(10) << ((ts.simbol_index(sim.section) == -1) ? 0 : ts.simbol_index(sim.section)) << std::setw(20) << sim.name << std::endl;
	}
	return os;
}


