#include "../../inc/assembler/tabelasimbola.hpp"
#include "../../inc/assembler/assembler.hpp"
#include "../../inc/assembler/hex_print.hpp"

#include <algorithm>

TabelaSimbola::TabelaSimbola(){}

int TabelaSimbola::simbol_index(std::string name){
	for(uint i = 0; i < tabela.size(); i++)
	{
		if(tabela[i].name == name) return i;
	}
	return -1;
}

uint32_t TabelaSimbola::simbol_value(std::string name, bool* defined){
	int i = simbol_index(name);
	if(i != -1){
		if(tabela[i].section == UND){
			*defined = false;
			return 0;
		}
		else{
			*defined = true;
			return tabela[i].value;
		}
	}
	*defined = false;
	return 0;
}

void TabelaSimbola::global_simbol(std::string name){
	int i = simbol_index(name);
	if(i == -1){
		tabela.emplace_back(0, NOTYP, true, UND, name);
	}
	else{
		tabela[i].global = true;
	}
}

void TabelaSimbola::extern_simbol(std::string name){
	int i = simbol_index(name);
	if(i == -1){
		tabela.emplace_back(0, NOTYP, true, UND, name);
	}
	else{
		tabela[i].global = true;
	}
}

void TabelaSimbola::add_section(std::string name){
	tabela.emplace_back(0, SCTN, false, name, name);
}

void TabelaSimbola::add_label(std::string name){
	int i = simbol_index(name);
	if(i == -1){
		tabela.emplace_back(Assembler::assembler.get_curr_section().offset, NOTYP, false, Assembler::assembler.get_curr_section().name, name);
	}
	else {
		tabela[i].value = Assembler::assembler.get_curr_section().offset;
		tabela[i].section = Assembler::assembler.get_curr_section().name;
	}
}

void TabelaSimbola::add_simbol(std::string name){
	int i = simbol_index(name);
	if(i == -1){
		tabela.emplace_back(0, NOTYP, false, UND, name);
	}
}

void TabelaSimbola::add_simbol_value(std::string name, uint32_t value){
	int i = simbol_index(name);
	if(i == -1){
		tabela.emplace_back(value, NOTYP, false, EQU_SIM, name);
	}
	else{
		tabela[i].value = value;
		tabela[i].section = EQU_SIM;
	}
}

void TabelaSimbola::sortiraj(){
	std::sort(tabela.begin(), tabela.end());
	tabela.insert(tabela.begin(), {0,NOTYP,false,UND,UND,});
}

std::ostream& operator<<(std::ostream& os, TabelaSimbola& ts){
	os << "#.symtab\n";
	os << "Num\tValue\t\tType\tBind\tSection\tName\n";
	int i=0;
	for(auto &sim: ts.tabela){
		os << i++ << ':' << '\t' << to_hex_8(sim.value) << '\t';
		switch(sim.type){
			case TabelaSimbola::NOTYP : 
				os << "NOTYP";
				break;
			case TabelaSimbola::SCTN : 
				os << "SCTN";
				break;
		}
		os << '\t' << ((sim.global) ? "GLOB" : "LOC") << '\t' << ((sim.section == UND) ? "UND" : sim.section) << '\t' << sim.name << std::endl;
	}
	return os;
}


