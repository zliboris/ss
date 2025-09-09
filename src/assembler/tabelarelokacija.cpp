#include "../../inc/assembler//tabelarelokacija.hpp"
#include <iomanip>

std::string to_hex(uint32_t value) {
    std::ostringstream oss;
    oss << std::setw(8)        // širina = 2 cifre
        << std::setfill('0')   // popuni nulama
        << std::hex
        << std::nouppercase    // koristi mala slova a–f
        << static_cast<int>(value); // cast jer bi se uint8_t ispisao kao char
    return oss.str();
}

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
	os << "Offset\t\tSymbol\tAddend\n";
	for(auto &r: tr.tabela){
		os << to_hex(r.offset);
		os << '\t' << r.simbol << '\t' << r.addend << std::endl;
	}
	return os;
}
