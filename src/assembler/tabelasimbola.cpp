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

void TabelaSimbola::add_simbol(std::string name, std::string sekcija){
	int i = simbol_index(name);
	if(i == -1){
		tabela.emplace_back(0, NOTYP, false, sekcija, name);
	}
	else{
		tabela[i].section = sekcija;
	}
}

void TabelaSimbola::add_simbol_value(std::string name, uint32_t value){
	int i = simbol_index(name);
	if(i == -1){
		tabela.emplace_back(value, SIM, false, Assembler::assembler.get_curr_section().name, name);
	}
	else{
		tabela[i].value = value;
	}
}

void TabelaSimbola::promeni_u_sim(std::string name){
	int i = simbol_index(name);
	if(i == -1)return;
	tabela[i].type = SIM;
}

void TabelaSimbola::sortiraj(){
	std::sort(tabela.begin(), tabela.end());
	tabela.insert(tabela.begin(), {0,NOTYP,false,UND,UND,});
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


