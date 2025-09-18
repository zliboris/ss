#include "../../inc/linker/elf.hpp"
#include "../../inc/linker/hex.hpp"
#include "../../inc/linker/hex_print.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <getopt.h>
#include <cstdlib>
#include <algorithm>

struct PlaceOption {
	std::string section;
	std::string address;
};

int main(int argc, char* argv[]) {
	std::string outputFile = "linked.out";
	bool hexMode = false;
	bool relocatableMode = false;
	std::vector<PlaceOption> places;
	std::vector<std::string> inputFiles;

	const option long_options[] = {
		{"place", required_argument, nullptr, 'p'},
		{"hex", no_argument, nullptr, 'h'},
    		{"relocatable", no_argument, nullptr, 'r'},
    		{"o", required_argument, nullptr, 'o'},
   		{0, 0, 0, 0}
	};

	int opt;
	int option_index = 0;
	while ((opt = getopt_long(argc, argv, "o:", long_options, &option_index)) != -1) {
		switch (opt) {
			case 'o':
    	    			outputFile = optarg;
    	    			break;
			case 'p': {
    	    			std::string param(optarg);
    	    			auto pos = param.find('@');
    	    			if (pos == std::string::npos) {
        				std::cerr << "Greška: -place zahteva format sekcija@adresa\n";
        				return 1;
    	    	    		}
    	    	    		places.push_back({param.substr(0, pos), param.substr(pos + 1)});
    	    	    		break;
			}
			case 'h':
    	    			if (relocatableMode) {
        				std::cerr << "Greška: ne može i -hex i -relocatable.\n";
        				return 1;
    	    	    		}
    	    	    		hexMode = true;
    	    	    		break;
			case 'r':
    	    	    		if (hexMode) {
        				std::cerr << "Greška: ne može i -hex i -relocatable.\n";
        				return 1;
    	    	    		}
    	    	    		relocatableMode = true;
    	    	    		break;
			case '?':
    	    	    		std::cerr << "Nepoznata opcija.\n";
    	    	    		return 1;
		}
}

	while (optind < argc) {
    	    	inputFiles.push_back(argv[optind++]);
	}

	if (!(hexMode ^ relocatableMode)) {
    	    	std::cerr << "Greška: mora biti navedena tačno jedna od opcija -hex ili -relocatable.\n";
    	    	return 1;
	}
	if (inputFiles.empty()) {
    	    	std::cerr << "Greška: nije naveden nijedan ulazni fajl.\n";
    	    	return 1;
	}

	std::cout << "Izlazna datoteka: " << outputFile << "\n";
	std::cout << "Mod rada: " << (hexMode ? "HEX" : "RELOCATABLE") << "\n";

	for (auto& pl : places) {
    	    	std::cout << "Sekcija " << pl.section << " na adresi " << pl.address << "\n";
	}

    	    	std::cout << "Ulazne datoteke:\n";
    	    	for (auto& f : inputFiles) {
    			std::cout << "  " << f << "\n";
    	    	}

    	std::vector<Elf> input_elfs;

	for(auto f: inputFiles){
		std::ifstream input(f);
		input_elfs.emplace_back();
		input >> input_elfs.back();
	}

	Elf linked_files;

    	for(auto elf: input_elfs){
		linked_files += elf;
	}
	linked_files.symtab.sortiraj();

	std::ofstream out(outputFile);

	if(!out.is_open()){
		std::cerr << "Greska pri otvaranju fajla" << std::endl;
		return 1;
	}

	if(hexMode){

		Hex linked_hex;

		for(auto &pl: places){
			int i = linked_files.symtab.simbol_index(pl.section);
			if(i == -1){
				std::cerr << "Greska: Nepostojeca sekcija u opciji place " << pl.section << std::endl;
				exit(1);
			}
			linked_hex.add_place_flags(pl.section, parseHex(pl.address.substr(2)), linked_files.symtab.tabela[i].value);
		}
		std::sort(linked_hex.hex_sec.begin(),linked_hex.hex_sec.end());

		for(auto &sec: linked_files.sections){
			linked_hex += sec;
		}

		for(auto &sim: linked_files.symtab.tabela){
			if(sim.type == TabelaSimbola::NOTYP && sim.name != UND){
				int index = linked_hex.section_index(sim.section);
				if(index == -1){
					std::cerr << "Greska: neki simbol greska " << sim.name << std::endl;
					exit(1);
				}
				sim.value += linked_hex.get_start_addr(sim.section);
			}
		}

		for(auto &rel: linked_files.relos){
			int i = linked_hex.section_index(rel.section_name);
			if(i == -1){
				std::cerr << "Greska: tabela relokacija za nepostojecu sekciju " << rel.section_name << std::endl;
				exit(1);
			}
			for(auto &relokacija : rel.tabela){
				int index = linked_files.symtab.simbol_index(relokacija.simbol);
				if(index == -1){
					std::cerr << "Greska: neki simbol greska " << relokacija.simbol << std::endl;
					exit(1);
				}
				uint32_t value = linked_files.symtab.tabela[index].value + relokacija.addend;
				linked_hex.hex_sec[i].bytes[relokacija.offset]     = ((value & 0x000000ffu) >> (0 * 8));	
				linked_hex.hex_sec[i].bytes[relokacija.offset + 1] = ((value & 0x0000ff00u) >> (1 * 8));	
				linked_hex.hex_sec[i].bytes[relokacija.offset + 2] = ((value & 0x00ff0000u) >> (2 * 8));	
				linked_hex.hex_sec[i].bytes[relokacija.offset + 3] = ((value & 0xff000000u) >> (3 * 8));	
			}
		}

		out << linked_hex;
	}
	else{
		out << linked_files;
	}
	

    	for(auto elf: input_elfs){
    		std::cout << elf;
    	}

	std::cout << linked_files;

	return 0;
}
