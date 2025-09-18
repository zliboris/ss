#include "../../inc/emulator/emulator.hpp"

extern void write_term_out(uint32_t value);
extern uint32_t read_term_in();

extern void write_tim_cfg(uint32_t value);
extern uint32_t read_tim_cfg();

void Emulator::write_mem_32(uint32_t addr, uint32_t value){
	if(addr == term_out_addr){
		write_term_out(value);
		return;
	}
	if(addr == tim_cfg_addr){
		write_tim_cfg(value);
		return;
	}
	memory[addr + 0] = ((value & 0x000000ffu) >> (0 * 8));	
	memory[addr + 1] = ((value & 0x0000ff00u) >> (1 * 8));	
	memory[addr + 2] = ((value & 0x00ff0000u) >> (2 * 8));	
	memory[addr + 3] = ((value & 0xff000000u) >> (3 * 8));	
}

uint32_t Emulator::read_mem_32(uint32_t addr){
	if(addr == term_in_addr){
		return read_term_in();
	}
	if(addr == tim_cfg_addr){
		return read_tim_cfg();
	}
	uint32_t value = 0;
	value += ((uint32_t)(memory[addr + 0]) << (0 * 8));	
	value += ((uint32_t)(memory[addr + 1]) << (1 * 8));	
	value += ((uint32_t)(memory[addr + 2]) << (2 * 8));	
	value += ((uint32_t)(memory[addr + 3]) << (3 * 8));	
	return value;
}

void Emulator::write_reg(int reg, uint32_t value){
	if(reg == 0)return;
	gpr[reg] = value;
}

uint32_t Emulator::read_reg(int reg){
	if(reg == 0)return 0;
	return gpr[reg];
}

void Emulator::write_sys_reg(int reg, uint32_t value){
	system_reg[reg] = value;
}

uint32_t Emulator::read_sys_reg(int reg){
	return system_reg[reg];
}
