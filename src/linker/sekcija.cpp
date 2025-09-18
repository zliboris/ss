#include "../../inc/linker/sekcija.hpp"
#include "../../inc/linker/hex_print.hpp"

Sekcija& Sekcija::operator+=(Sekcija& sec){

	for(auto &byte: sec.content){
		add_byte(byte);
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, Sekcija& s){
	os << "#." << s.name << std::endl;
	int i = 0;
	for(auto &b: s.content) {
		os << to_hex_2(b);
		if(i == 3){
			os << '\t';
			i++;
		}
		else if(i == 7){
			os << std::endl;
			i = 0;
		}
		else{
			os << ' ';
			i++;
		}
	}
	if(i != 0)
		os << std::endl;
	return os;
}

