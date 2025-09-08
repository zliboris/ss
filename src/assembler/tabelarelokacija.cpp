#include "../../inc/assembler//tabelarelokacija.hpp"


void TabelaRelokacija::add_rel(uint32_t of, uint32_t sim, int ae){
	tabela.emplace_back(of, sim, ae);
}
