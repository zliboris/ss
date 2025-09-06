#ifndef _sim_lit_hpp_
#define _sim_lit_hpp_

#include "assembler.hpp"

int get_sim_offset(char* simbol);

int get_lit_offset(uint32_t literal);

void insert_lit_ref(int lit_offset);

int simbol_index(std::string name);

#endif
