#ifndef _sekcija_hpp_
#define _sekcija_hpp_

#include "tabelaliterala.hpp"

class Sekcija {
	public:

	enum instrucion_code {HALT = 0b0000, INT = 0b0001, CALL = 0b0010, JMP = 0b0011, XCHG = 0b0100, ARTH = 0b0101, LOGI = 0b0110, SHIF = 0b0111, STOR = 0b1000, LOAD = 0b1001};
	enum gpr {R0 = 0, R1 = 1, R2 = 2, R3 = 3, R4 = 4, R5 = 5, R6 = 6, R7 = 7, R8 = 8, R9 = 9, R10 = 10, R11 = 11, R12 = 12, R13 = 13, R14 = 14, R15 = 15, SP = 14, PC = 15};

	TabelaLiterala Tliterali;

	struct machine_code {
		bool is_instruction;
		uint32_t value;
		instrucion_code instruction;
		uint8_t mode;
		gpr RegA, RegB, RegC;
		uint32_t disp;
		int literal_index;

		machine_code(uint32_t value): 
			is_instruction(false), value(value), literal_index(-1){};
		machine_code(instrucion_code ic, uint8_t m, gpr a, gpr b, gpr c, uint32_t d) :
			is_instruction(true), instruction(ic), mode(m), RegA(a), RegB(b), RegC(c), disp(d), literal_index(-1) {};
		machine_code(instrucion_code ic, uint8_t m, gpr a, gpr b, gpr c, int lit_index) :
			is_instruction(true), instruction(ic), mode(m), RegA(a), RegB(b), RegC(c), literal_index(lit_index), disp(0) {};
	};

	void add_instruction(instrucion_code ic, uint8_t mode = 0, gpr a = R0, gpr b = R0, gpr c = R0, uint32_t displacment = 0);

	void add_instruction_literal(instrucion_code ic, uint32_t literal, uint8_t mode = 0, gpr a = R0, gpr b = R0, gpr c = R0);

	void add_instruction_simbol(instrucion_code ic ,std::string simbol, uint8_t mode = 0, gpr a = R0, gpr b = R0, gpr c = R0);

	void add_word(uint32_t);

	std::vector<machine_code> content;
	
	std::string name;

};
#endif
