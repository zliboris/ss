#include <iostream>
enum sreg {STATUS = 0, HANDLER = 1, CAUSE = 2};

struct reg_lit {
	uint reg;
	uint literal;
};

struct reg_sim {
	uint reg;
	char* simbol;
};
