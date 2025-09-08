#include "../../inc/assembler/sekcija.hpp"

void Sekcija::add_instruction(instrucion_code ic, uint8_t mode, gpr a, gpr b, gpr c, uint32_t displacment){
	content.emplace_back(ic,mode,a,b,c,displacment);
}

void Sekcija::add_instruction_literal(instrucion_code ic, uint32_t literal, uint8_t mode, gpr a, gpr b, gpr c){
	content.emplace_back(ic,mode,a,b,c,Tliterali.get_lit_index(literal));
}

void Sekcija::add_instruction_simbol(instrucion_code ic ,std::string simbol, uint8_t mode, gpr a, gpr b, gpr c){
	content.emplace_back(ic,mode,a,b,c,Tliterali.get_sim_index(simbol));
}

void Sekcija::add_word(uint32_t word){
	content.emplace_back(word);
}
