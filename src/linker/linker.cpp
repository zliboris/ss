#include "../../inc/linker/linker.hpp"
#include "../../inc/linker/elf.hpp"

#include <fstream>


int main(int argc, char *argv[]){
	std::vector<Elf> input_files;

	for(int i = 1; i < argc; i++){
		if(argv[i][0] == '-'){
			//opcije
		}
		else{
			std::ifstream input(argv[i]);
			input_files.emplace_back();
			input >> input_files.back();
		}
	}


	for(auto file: input_files){
		std::cout << file;
	}


	return 0;
}
