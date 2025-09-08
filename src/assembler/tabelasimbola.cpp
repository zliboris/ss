#include "../../inc/assembler/tabelasimbola.hpp"

TabelaSimbola TabelaSimbola::simbol_table = TabelaSimbola();

TabelaSimbola::TabelaSimbola(){
	tabela.emplace_back(0, 0, NOTYP, false, 0, "");
}

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
		if(tabela[i].Ndx == 0 || tabela[i].type != SIM){
			*defined = false;
			return 0;
		}
		else{
			*defined = true;
			return tabela[i].value;
		}
	}
	tabela.emplace_back(0, 0, NOTYP, false, 0, name);
	*defined = false;
	return 0;
}
