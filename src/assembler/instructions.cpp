#include "../../inc/assembler/instructions.hpp"

void Assembler::add_equ(std::string *simbol, std::vector<sim_or_lit_izraz> *izraz){
	equ_izrazi.push_back({*simbol, izraz});
	Assembler::assembler.simbol_table.add_simbol(*simbol, Assembler::assembler.get_curr_section().name);
}

void Assembler::calculate_equ(){
	int n = equ_izrazi.size();
	for(int i = 0; i < n && equ_izrazi.size() > 0; i++)
	{
		for(auto it = equ_izrazi.begin(); it != equ_izrazi.end(); )
		{
			uint32_t value = 0;
			bool failed = false;
			for(auto elem : *it->second)
			{
				if(elem.is_simbol){
					bool defined = false;
					uint32_t sim_value = simbol_table.simbol_value(*elem.simbol, &defined);
					if(!simbol_table.da_li_postoji(*elem.simbol)){
						failed = true; 
						break;
					}
					if(elem.plus) value += sim_value;
					else value -= sim_value;

				}
				else {
					if(elem.plus) value += elem.literal;
					else value -= elem.literal;
				}

			}
			if(!failed){
				simbol_table.add_simbol_value(it->first,value);
				simbol_table.promeni_u_sim(it->first);
				simbol_table.sad_postoji(it->first);
				equ_izrazi.erase(it);
			}
			else it++;
		}
	}
	if(equ_izrazi.size() > 0) Assembler::assembler.error("Simbole u equ direktivama nije moguce definisati");

}

void resolve_global(std::vector<std::string*> *simbols){
	for(auto s : *simbols)
	{
		Assembler::assembler.simbol_table.global_simbol(*s);
	}
}
void resolve_extern(std::vector<std::string*> *simbols){
	for(auto s : *simbols)
	{
		Assembler::assembler.simbol_table.extern_simbol(*s);
	}
}
void resolve_section(std::string* name){
	Assembler::assembler.new_section(*name);
}
void resolve_word(std::vector<sim_or_lit> *sim_and_lit_list){
	for(auto sl : *sim_and_lit_list){
		if(sl.is_simbol){
			Assembler::assembler.get_curr_section().add_word_simbol(*sl.simbol);
		}
		else {
			Assembler::assembler.get_curr_section().add_word_literal(sl.literal);
		}
	}
}
void resolve_skip(uint32_t size){
	Assembler::assembler.get_curr_section().skip(size);
}
void resolve_ascii(std::string *string){
	Assembler::assembler.get_curr_section().ascii(*string);
}
void resolve_equ(std::string* simbol, std::vector<sim_or_lit_izraz> *izraz){
	Assembler::assembler.add_equ(simbol, izraz);
}

void resolve_label(std::string* labela){
	Assembler::assembler.simbol_table.add_label(*labela);
	Assembler::assembler.simbol_table.sad_postoji(*labela);
}

void inst_halt(){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::HALT);
}

void inst_int(){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::INT);
}
void inst_iret(){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOAD, 0b0110, (Sekcija::gpr) STATUS, Sekcija::SP, Sekcija::R0, 0x4);
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOAD, 0b0011, Sekcija::PC, Sekcija::SP, Sekcija::R0, 0x8);
}

void inst_call_sym(std::string* labela){
	Assembler::assembler.get_curr_section().add_instruction_simbol(Sekcija::CALL, *labela, 0b0001, Sekcija::PC);
}
void inst_call_lit(uint32_t addr){
	Assembler::assembler.get_curr_section().add_instruction_literal(Sekcija::CALL, addr, 0b0001, Sekcija::PC);
}
void inst_ret(){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOAD, 0b0011, Sekcija::PC, Sekcija::SP, Sekcija::R0, 0x4);
}

void inst_jmp_sym(std::string* labela){
	Assembler::assembler.get_curr_section().add_instruction_simbol(Sekcija::JMP, *labela, 0b1000, Sekcija::PC);
}
void inst_jmp_lit(uint32_t addr){
	Assembler::assembler.get_curr_section().add_instruction_literal(Sekcija::JMP, addr, 0b1000, Sekcija::PC);
}

void inst_beq_sym(uint32_t reg1, uint32_t reg2, std::string* labela){
	Assembler::assembler.get_curr_section().add_instruction_simbol(Sekcija::JMP, *labela, 0b1001, Sekcija::PC, (Sekcija::gpr) reg1, (Sekcija::gpr) reg2);
}
void inst_beq_lit(uint32_t reg1, uint32_t reg2, uint32_t addr){
	Assembler::assembler.get_curr_section().add_instruction_literal(Sekcija::JMP, addr, 0b1001, Sekcija::PC, (Sekcija::gpr) reg1, (Sekcija::gpr) reg2);
}

void inst_bne_sym(uint32_t reg1, uint32_t reg2, std::string* labela){
	Assembler::assembler.get_curr_section().add_instruction_simbol(Sekcija::JMP, *labela, 0b1010, Sekcija::PC, (Sekcija::gpr) reg1, (Sekcija::gpr) reg2);
}
void inst_bne_lit(uint32_t reg1, uint32_t reg2, uint32_t addr){
	Assembler::assembler.get_curr_section().add_instruction_literal(Sekcija::JMP, addr, 0b1010, Sekcija::PC, (Sekcija::gpr) reg1, (Sekcija::gpr) reg2);
}

void inst_bgt_sym(uint32_t reg1, uint32_t reg2, std::string* labela){
	Assembler::assembler.get_curr_section().add_instruction_simbol(Sekcija::JMP, *labela, 0b1011, Sekcija::PC, (Sekcija::gpr) reg1, (Sekcija::gpr) reg2);
}
void inst_bgt_lit(uint32_t reg1, uint32_t reg2, uint32_t addr){
	Assembler::assembler.get_curr_section().add_instruction_literal(Sekcija::JMP, addr, 0b1011, Sekcija::PC, (Sekcija::gpr) reg1, (Sekcija::gpr) reg2);
}

void inst_push(uint32_t reg){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::STOR, 0b0001, Sekcija::SP, Sekcija::R0, (Sekcija::gpr) reg, 0xffc);
}
void inst_pop(uint32_t reg){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOAD, 0b0011, (Sekcija::gpr) reg, Sekcija::SP, Sekcija::R0, 0x4);
}

void inst_xchg(uint32_t regS, uint32_t regD){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::XCHG, 0b0000, Sekcija::R0, (Sekcija::gpr) regS, (Sekcija::gpr) regD);
}
void inst_add(uint32_t regS, uint32_t regD){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::ARTH, 0b0000, (Sekcija::gpr) regD, (Sekcija::gpr) regD, (Sekcija::gpr) regS);
}
void inst_sub(uint32_t regS, uint32_t regD){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::ARTH, 0b0001, (Sekcija::gpr) regD, (Sekcija::gpr) regD, (Sekcija::gpr) regS);
}
void inst_mul(uint32_t regS, uint32_t regD){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::ARTH, 0b0010, (Sekcija::gpr) regD, (Sekcija::gpr) regD, (Sekcija::gpr) regS);
}
void inst_div(uint32_t regS, uint32_t regD){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::ARTH, 0b0011, (Sekcija::gpr) regD, (Sekcija::gpr) regD, (Sekcija::gpr) regS);
}
void inst_not(uint32_t reg){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOGI, 0b0000, (Sekcija::gpr) reg, (Sekcija::gpr) reg, Sekcija::R0);
}
void inst_and(uint32_t regS, uint32_t regD){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOGI, 0b0001, (Sekcija::gpr) regD, (Sekcija::gpr) regD, (Sekcija::gpr) regS);
}
void inst_or(uint32_t regS, uint32_t regD){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOGI, 0b0010, (Sekcija::gpr) regD, (Sekcija::gpr) regD, (Sekcija::gpr) regS);
}
void inst_xor(uint32_t regS, uint32_t regD){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOGI, 0b0011, (Sekcija::gpr) regD, (Sekcija::gpr) regD, (Sekcija::gpr) regS);
}
void inst_shl(uint32_t regS, uint32_t regD){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::SHIF, 0b0000, (Sekcija::gpr) regD, (Sekcija::gpr) regD, (Sekcija::gpr) regS);
}
void inst_shr(uint32_t regS, uint32_t regD){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::SHIF, 0b0001, (Sekcija::gpr) regD, (Sekcija::gpr) regD, (Sekcija::gpr) regS);
}

void inst_ld_lit_vr(uint32_t reg, uint32_t lit_vr){
	Assembler::assembler.get_curr_section().add_instruction_literal(Sekcija::LOAD, lit_vr, 0b0010, (Sekcija::gpr) reg, Sekcija::PC, Sekcija::R0);
}
void inst_ld_sim_vr(uint32_t reg, std::string* sim_vr){
	Assembler::assembler.get_curr_section().add_instruction_simbol(Sekcija::LOAD, *sim_vr, 0b0010, (Sekcija::gpr) reg, Sekcija::PC, Sekcija::R0);

}
void inst_ld_lit_addr(uint32_t reg, uint32_t lit_addr){
	Assembler::assembler.get_curr_section().add_instruction_literal(Sekcija::LOAD, lit_addr, 0b0010, (Sekcija::gpr) reg, Sekcija::PC, Sekcija::R0);
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOAD, 0b0010, (Sekcija::gpr) reg, (Sekcija::gpr) reg, Sekcija::R0);
}
void inst_ld_sim_addr(uint32_t reg, std::string* sim_addr){
	Assembler::assembler.get_curr_section().add_instruction_simbol(Sekcija::LOAD, *sim_addr, 0b0010, (Sekcija::gpr) reg, Sekcija::PC, Sekcija::R0);
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOAD, 0b0010, (Sekcija::gpr) reg, (Sekcija::gpr) reg, Sekcija::R0);
}
void inst_ld_reg_vr(uint32_t reg, uint32_t reg_vr){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOAD, 0b0001, (Sekcija::gpr) reg, (Sekcija::gpr) reg_vr, Sekcija::R0);
}
void inst_ld_reg_addr(uint32_t reg, uint32_t reg_addr){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOAD, 0b0010, (Sekcija::gpr) reg, (Sekcija::gpr) reg_addr, Sekcija::R0);
}
void inst_ld_reg_lit_addr(uint32_t reg, reg_lit* reg_lit_addr){
	if( reg_lit_addr->literal > 0xFFF) Assembler::assembler.error("Literal veci od 12 bita");
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOAD, 0b0010, (Sekcija::gpr) reg, (Sekcija::gpr) reg_lit_addr->reg, Sekcija::R0, reg_lit_addr->literal);
}
void inst_ld_reg_sim_addr(uint32_t reg, reg_sim* reg_sim_addr){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOAD, 0b0010, (Sekcija::gpr) reg, (Sekcija::gpr) reg_sim_addr->reg, Sekcija::R0);
	Assembler::assembler.get_curr_section().back_patch_displacment_at_last(*reg_sim_addr->simbol);
}

void inst_st_lit_addr(uint32_t reg, uint32_t lit_addr){
	Assembler::assembler.get_curr_section().add_instruction_literal(Sekcija::STOR, lit_addr, 0b0010, Sekcija::PC, Sekcija::R0, (Sekcija::gpr) reg);
}
void inst_st_sim_addr(uint32_t reg, std::string* sim_vr){
	Assembler::assembler.get_curr_section().add_instruction_simbol(Sekcija::STOR, *sim_vr, 0b0010, Sekcija::PC, Sekcija::R0, (Sekcija::gpr) reg);
}
void inst_st_reg_addr(uint32_t reg, uint32_t reg_addr){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::STOR, 0b0000, (Sekcija::gpr) reg_addr, Sekcija::R0, (Sekcija::gpr) reg);
}
void inst_st_reg_lit_addr(uint32_t reg, reg_lit* reg_lit_addr){
	if( reg_lit_addr->literal > 0xFFF) Assembler::assembler.error("Literal veci od 12 bita");
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::STOR, 0b0000, (Sekcija::gpr) reg_lit_addr->reg, Sekcija::R0, (Sekcija::gpr) reg, reg_lit_addr->literal);
}
void inst_st_reg_sim_addr(uint32_t reg, reg_sim* reg_sim_addr){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::STOR, 0b0000, (Sekcija::gpr) reg_sim_addr->reg, Sekcija::R0, (Sekcija::gpr) reg);
	Assembler::assembler.get_curr_section().back_patch_displacment_at_last(*reg_sim_addr->simbol);
}

void inst_csrrd(uint32_t reg, sreg sreg){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOAD, 0b0000, (Sekcija::gpr) reg, (Sekcija::gpr) sreg);
}
void inst_csrwr(uint32_t reg, sreg sreg){
	Assembler::assembler.get_curr_section().add_instruction(Sekcija::LOAD, 0b0100, (Sekcija::gpr) sreg, (Sekcija::gpr) reg);
}

