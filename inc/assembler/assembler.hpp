#ifndef _assembler_hpp_
#define _assembler_hpp_

#include <iostream>
#include <cstdint>
#include <vector>

enum sreg {STATUS = 0, HANDLER = 1, CAUSE = 2};
enum sim_tip {NOTYP = 0, SCTN = 1};
enum rela_tip {};

struct reg_lit {
	uint32_t reg;
	uint32_t literal;
};

struct reg_sim {
	uint32_t reg;
	char* simbol;
};

struct simbol {
	uint32_t value;
	int size;
	sim_tip type;
	bool global;
	int Ndx;
	std::string name;
	simbol(uint32_t v, int s, sim_tip t, bool g, int N, std::string n) : value(v), size(s), type(t), global(g), Ndx(N), name(n) {}
};

struct lit_ref {
	int offset;
	int lit_offset;
	lit_ref(int o, int lo) : offset(o), lit_offset(lo) {}
};

struct literal_tab {
	bool simbol;
	std::string ime;
	uint32_t value;
	int offset;
	literal_tab(bool s, std::string i, uint32_t v, int o) : simbol(s), ime(i), value(v), offset(o) {}
};

struct sekcija {
	std::string ime;
	std::vector<uint8_t> content;
	std::vector<literal_tab> literali;
	std::vector<lit_ref> referenciranje_literala;
	int cur_offset = 0;
	int cur_lit_offset = 0;
};

struct relokacija {
	uint32_t offset;
	rela_tip type;
	uint32_t simbol;
	int addend;
};

struct relokaciona_tabela {
	std::string ime;
	std::vector<relokacija> content;
};

struct elf {
	std::vector<simbol> tabela_simbola;
	std::vector<sekcija> lista_sekcija;
	std::vector<relokaciona_tabela> lista_rela_tabela;
};

static elf *fajl;

#endif
