#include "../../inc/assembler/assembler.hpp"
extern FILE* yyin;
int yyparse();
#include <fstream>
#include <cstring> 
#include <unistd.h>

Assembler Assembler::assembler;

std::ostream& operator<<(std::ostream& os, Assembler& assm){
	os << assm.simbol_table;
	for(auto &sec: assm.sekcije) os << sec;
	for(auto &sec: assm.sekcije) os << sec.get_relokacije();
	return os;
}

void Assembler::finish_assembly(){
	Assembler::assembler.calculate_equ();
	for(auto &sec: Assembler::assembler.sekcije){
		sec.do_back_patch();
		sec.Tliterali.Trelokacija.add_sekcija_offset(sec.offset);
		sec.fix_relokacije();
	}
	for(auto &s: Assembler::assembler.simbol_table.tabela){
		if(s.type == TabelaSimbola::SCTN){
			s.value = get_section_size(s.name);
		}
	}
	Assembler::assembler.simbol_table.sortiraj();
}

void Assembler::error(std::string msg){
	std::cerr << msg << std::endl;
	exit(1);
}

int main(int argc, char *argv[]){
	std::string inputFile;
	std::string outputFile = "UND";

    	int opt;
    	while ((opt = getopt(argc, argv, "o:")) != -1) {
        	switch (opt) {
        	case 'o':
            		outputFile = optarg;
            		break;
        	case '?':
            		std::cerr << "Nepoznata opcija ili nedostaje argument." << std::endl;
            		return 1;
        	}
    	}

    	if (optind < argc) {
        	inputFile = argv[optind];
    	} else {
        	std::cerr << "Greška: nije zadat ulazni fajl." << std::endl;
        	return 1;
    	}

	if(outputFile == "UND"){
		outputFile = inputFile;
		outputFile.back() = 'o';
	}

	FILE* f = fopen(inputFile.c_str(), "r");
	yyin = f;
	yyparse();
	fclose(f);
	Assembler::assembler.finish_assembly();

	std::ofstream out(outputFile);

	if(!out.is_open()){
		std::cerr << "Greska pri otvaranju fajla" << std::endl;
		return 1;
	}
	
	out << Assembler::assembler;
	
	//std::cout << Assembler::assembler;

	return 0;
}
