#include "../../inc/assembler/tabelarelokacija.hpp"
#include "../../inc/assembler/hex_print.hpp"

void TabelaRelokacija::add_rel(uint32_t of, std::string sim, int ae){
	tabela.emplace_back(of, sim, ae);
}

void TabelaRelokacija::add_sekcija_offset(uint32_t offset_sekcije){
	for(auto &rel : tabela) { 
		rel.offset += offset_sekcije;
	}
}

std::ostream& operator<<(std::ostream& os, TabelaRelokacija& tr){
	os << "#.rela." << tr.section_name << std::endl;
	os << std::setfill(' ') << std::left;
	os << std::setw(12) << "Offset" << std::setw(10) << std::left << "Addend" << std::setw(10) << "Symbol" << std::endl;
	for(auto &r: tr.tabela){
		os << std::setw(12) << to_hex_8(r.offset);
		os << std::setw(10) << r.addend << std::setw(10) << r.simbol << std::endl;
	}
	return os;
}
