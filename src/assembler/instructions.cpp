#include "../../inc/assembler/instructions.hpp"

void insert_inst(uint32_t inst){
	fajl->lista_sekcija.back().content.push_back((uint8_t)inst >> 24);
	fajl->lista_sekcija.back().content.push_back((uint8_t)inst >> 16);
	fajl->lista_sekcija.back().content.push_back((uint8_t)inst >> 8);
	fajl->lista_sekcija.back().content.push_back((uint8_t)inst);
	fajl->lista_sekcija.back().cur_offset += 4;
}

void inst_halt(){
	insert_inst(0x00000000);
}

void inst_int(){
	insert_inst(0x10000000);
}
void inst_iret()
{
	//pop pc, pop status
}

void inst_call_sym(char* labela){
	insert_lit_ref(get_sim_offset(labela));
	insert_inst(0x21F0000);
}
void inst_call_lit(uint32_t addr);
void inst_ret();

void inst_jmp_sym(char* labela);
void inst_jmp_lit(uint32_t addr);

void inst_beq_sym(uint32_t reg1, uint32_t reg2, char* labela);
void inst_beq_lit(uint32_t reg1, uint32_t reg2, char* addr);

void inst_bne_sym(uint32_t reg1, uint32_t reg2, char* labela);
void inst_bne_lit(uint32_t reg1, uint32_t reg2, char* addr);

void inst_bgt_sym(uint32_t reg1, uint32_t reg2, char* labela);
void inst_bgt_lit(uint32_t reg1, uint32_t reg2, char* addr);

void inst_push(uint32_t reg);
void inst_pop(uint32_t reg);

void inst_xchg(uint32_t regS, uint32_t regD);
void inst_add(uint32_t regS, uint32_t regD);
void inst_sub(uint32_t regS, uint32_t regD);
void inst_mul(uint32_t regS, uint32_t regD);
void inst_div(uint32_t regS, uint32_t regD);
void inst_not(uint32_t reg);
void inst_and(uint32_t regS, uint32_t regD);
void inst_or(uint32_t regS, uint32_t regD);
void inst_xor(uint32_t regS, uint32_t regD);
void inst_shl(uint32_t regS, uint32_t regD);
void inst_shr(uint32_t regS, uint32_t regD);

void inst_ld_lit_vr(uint32_t reg, uint32_t lit_vr);
void inst_ld_sim_vr(uint32_t reg, char* sim_vr);
void inst_ld_lit_addr(uint32_t reg, uint32_t lit_addr);
void inst_ld_sim_addr(uint32_t reg, char* sim_vr);
void inst_ld_reg_vr(uint32_t reg, uint32_t reg_vr);
void inst_ld_reg_addr(uint32_t reg, uint32_t reg_addr);
void inst_ld_reg_lit_addr(uint32_t reg, reg_lit* reg_lit_addr);
void inst_ld_reg_sim_addr(uint32_t reg, reg_sim* reg_sim_addr);

void inst_st_lit_vr(uint32_t reg, uint32_t lit_vr);
void inst_st_sim_vr(uint32_t reg, char* sim_vr);
void inst_st_lit_addr(uint32_t reg, uint32_t lit_addr);
void inst_st_sim_addr(uint32_t reg, char* sim_vr);
void inst_st_reg_vr(uint32_t reg, uint32_t reg_vr);
void inst_st_reg_addr(uint32_t reg, uint32_t reg_addr);
void inst_st_reg_lit_addr(uint32_t reg, reg_lit* reg_lit_addr);
void inst_st_reg_sim_addr(uint32_t reg, reg_sim* reg_sim_addr);

void inst_csrrd(uint32_t reg, sreg sreg);
void inst_csrwr(uint32_t reg, sreg sreg);
