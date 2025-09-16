#include "../../inc/linker/elf.hpp"

std::istream& operator>>(std::istream& is, Elf& of) {
    std::string line;

    while (std::getline(is, line)) {
        if (line.rfind("#.symtab", 0) == 0) {
            // preskoči header
            std::getline(is, line);
            while (std::getline(is, line) && !line.empty() && line[0] != '#') {
                std::istringstream iss(line);
                std::string numStr, valueHex, typeStr, bindStr, sectStr, nameStr;
                iss >> numStr >> valueHex >> typeStr >> bindStr >> sectStr >> nameStr;

                uint32_t value = std::stoul(valueHex, nullptr, 16);
                TabelaSimbola::sim_tip tip = (typeStr == "SCTN" ? TabelaSimbola::SCTN : TabelaSimbola::NOTYP);
                bool glob = (bindStr == "GLOB");

                of.symtab.add_simbol(value, tip, glob, sectStr, nameStr);
            }
		if (!line.empty() && line[0] == '#') {
    	    	    is.seekg(-static_cast<int>(line.size()) - 1, std::ios_base::cur);
		}
        }
        else if (line.rfind("#.", 0) == 0 && line.find("rela") == std::string::npos) {
            // obična sekcija
            Sekcija sec;
            sec.name = line.substr(2);
            while (std::getline(is, line) && !line.empty() && line[0] != '#') {
                std::istringstream iss(line);
                std::string byteStr;
                while (iss >> byteStr) {
                    uint8_t val = static_cast<uint8_t>(std::stoul(byteStr, nullptr, 16));
                    sec.add_byte(val);
                }
            }
            of.sections.push_back(std::move(sec));
            if (!is) break;
            is.seekg(-static_cast<int>(line.size()) - 1, std::ios_base::cur);
        }
        else if (line.rfind("#.rela", 0) == 0) {
            // relokacije
            TabelaRelokacija tr;
            tr.section_name = line.substr(6); // posle "#.rela"
            std::getline(is, line); // preskoči header
            while (std::getline(is, line) && !line.empty() && line[0] != '#') {
                std::istringstream iss(line);
                std::string offsetHex, sym;
                int addend;
                iss >> offsetHex >> addend >> sym;
                uint32_t offset = std::stoul(offsetHex, nullptr, 16);
                tr.add_rel(offset, sym, addend);
            }
            of.relos.push_back(std::move(tr));
            if (!is) break;
            is.seekg(-static_cast<int>(line.size()) - 1, std::ios_base::cur);
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Elf& of) {
    // Symtab
    os << "#.symtab\n";
    os << "Num\tValue\t\tType\tBind\tSection\t\tName\n";
    int idx = 0;
    for (const auto& sym : of.symtab.tabela) {
        os << idx++ << ":\t"
           << std::setw(8) << std::setfill('0') << std::hex << sym.value << std::dec << "\t"
           << (sym.type == TabelaSimbola::SCTN ? "SCTN" : "NOTYP") << "\t"
           << (sym.global ? "GLOB" : "LOC") << "\t"
           << sym.section << "\t"
           << sym.name << "\n";
    }

    // Sekcije
    for (const auto& sec : of.sections) {
        os << "#." << sec.name << "\n";
        for (size_t i = 0; i < sec.content.size(); i++) {
            os << std::setw(2) << std::setfill('0') << std::hex
               << (int)sec.content[i] << " ";
            if ((i + 1) % 4 == 0) os << "\t";
            if ((i + 1) % 8 == 0) os << "\n";
        }
        if (sec.content.size() % 8 != 0) os << "\n";
    }

    // Relokacije
    for (const auto& tr : of.relos) {
        os << "#.rela." << tr.section_name << "\n";
        os << "Offset\t\tAddend\tSymbol\n";
        for (const auto& r : tr.tabela) {
            os << std::setw(8) << std::setfill('0') << std::hex << r.offset << std::dec << "\t"
               << r.addend << "\t"
               << r.simbol << "\n";
        }
    }
    return os;
}
