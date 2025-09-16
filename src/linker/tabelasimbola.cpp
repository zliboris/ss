#include "../../inc/assembler/tabelasimbola.hpp"
#include "../../inc/assembler/assembler.hpp"
#include "../../inc/assembler/hex_print.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>


// funkcija koja parsira hex string ("1A") u broj
uint8_t from_hex_8(const std::string& s) {
    return static_cast<uint8_t>(std::stoi(s, nullptr, 16));
}

std::istream& operator>>(std::istream& is, TabelaSimbola& ts) {
    ts.tabela.clear();

    std::string line;

    // preskoči header linije
    std::getline(is, line); // "#.symtab"
    std::getline(is, line); // "Num ..."

    while (std::getline(is, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);

        int index;
        char colon;
        std::string value_hex, type_str, bind_str, section_str, name_str;

        iss >> index >> colon >> value_hex >> type_str >> bind_str >> section_str >> name_str;

        if (!iss) continue; // preskoči ako parsiranje nije uspelo

	TabelaSimbola::simbol s(0,TabelaSimbola::NOTYP,false,"","");
        s.value = from_hex_8(value_hex);

        if (type_str == "NOTYP") s.type = TabelaSimbola::NOTYP;
        else if (type_str == "SCTN") s.type = TabelaSimbola::SCTN;

        s.global = (bind_str == "GLOB");
        s.section = (section_str == "UND" ? "" : section_str);
        s.name = name_str;

        ts.tabela.push_back(s);
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, TabelaSimbola& ts){
	os << "#.symtab\n";
	os << "Num\tValue\t\tType\tBind\tSection\tName\n";
	int i=0;
	for(auto &sim: ts.tabela){
		os << i++ << ':' << '\t' << to_hex_8(sim.value) << '\t';
		switch(sim.type){
			case TabelaSimbola::NOTYP : 
				os << "NOTYP";
				break;
			case TabelaSimbola::SCTN : 
				os << "SCTN";
				break;
		}
		os << '\t' << ((sim.global) ? "GLOB" : "LOC") << '\t' << ((sim.section == UND) ? "UND" : sim.section) << '\t' << sim.name << std::endl;
	}
	return os;
}


