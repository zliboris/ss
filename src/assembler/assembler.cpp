#include "../../inc/assembler/assembler.hpp"
extern FILE* yyin;
int yyparse();
#include <fstream>
#include <cstring> 

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

	char* file;
	if(strcmp(argv[1],"-o") == 0) file = argv[3];
	else file = argv [1];
	FILE* f = fopen(file,"r");
	yyin = f;
	yyparse();
	fclose(f);
	Assembler::assembler.finish_assembly();

	std::string outf;
	if(strcmp(argv[1],"-o") == 0)outf = argv[2];
	else {
		outf = argv[1];
		outf.back() = 'o';
	}
	std::ofstream out(outf);
	
	out << Assembler::assembler;
	
	std::cout << Assembler::assembler;

	return 0;
}
