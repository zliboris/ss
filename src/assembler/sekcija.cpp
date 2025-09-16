#include "../../inc/assembler/sekcija.hpp"
#include "../../inc/assembler/assembler.hpp"
#include "../../inc/assembler/hex_print.hpp"
#include <algorithm>


void Sekcija::add_instruction(instrucion_code ic, uint8_t mode, gpr a, gpr b, gpr c, uint32_t displacment){
	content.emplace_back(ic,mode,a,b,c,displacment, offset);
	offset += 4;
}

void Sekcija::add_instruction_literal(instrucion_code ic, uint32_t literal, uint8_t mode, gpr a, gpr b, gpr c){
	content.emplace_back(ic,mode,a,b,c,Tliterali.get_lit_index(literal), offset);
	offset += 4;
}

void Sekcija::add_instruction_simbol(instrucion_code ic ,std::string simbol, uint8_t mode, gpr a, gpr b, gpr c){
	content.emplace_back(ic,mode,a,b,c,Tliterali.get_sim_index(simbol), offset);
	offset += 4;
}

void Sekcija::add_word_literal(uint32_t word){
	content.emplace_back(word, offset);
	offset += 4;
}


void Sekcija::add_word_simbol(std::string simbol){
	content.emplace_back(0, offset);
	Trelokacija.add_rel(offset, simbol, 0);
	offset += 4;
}

void Sekcija::back_patch_displacment_at_last(std::string simbol){
	back_patches.emplace_back(content.back(),simbol);
}

void Sekcija::do_back_patch(){
	for(auto bp : back_patches){
		bool defined = false;
		uint32_t sim_val = Assembler::assembler.simbol_table.simbol_value(bp.second, &defined);
		if(!defined) Assembler::assembler.error("Simbol nije definisan");
		if(sim_val > 0xFFF) Assembler::assembler.error("Vrednost simbola veca od 12 bita");
		bp.first.disp = sim_val;
	}
}

void Sekcija::skip(uint32_t size){
	while(size > 4){
		content.emplace_back(0,4, offset);
		offset += 4;
		size -= 4;
	}
	if(size == 0) return;
	content.emplace_back(0,size, offset);
	offset += size;
}

void Sekcija::ascii(std::string string){
	for(char c: string){
		content.emplace_back(c,1, offset);
		offset += 1;
	}
	content.emplace_back('\0',1, offset);
	offset += 1;
}

std::vector<uint8_t> Sekcija::get_binary(){
	std::vector<uint8_t> rtn;

	for(auto &b: content){
		if(b.is_instruction){
			if(b.literal_index != -1){
				b.disp = offset - (b.t_offset + 4) + b.literal_index * 4;
			}
			rtn.push_back((uint8_t) (b.disp & 0xffu));
			rtn.push_back((uint8_t) (((b.RegC & 0xf) << 4) | ((b.disp & 0xf00) >> 1 * 8)));
			rtn.push_back((uint8_t) ((b.RegA & 0xf) << 4 | (b.RegB & 0xf)));
			rtn.push_back((uint8_t) (((b.instruction & 0xf) << 4) | (b.mode & 0xf)));
		}
		else{
			uint32_t mask = 0xFF;
			for(int i = b.size - 1; i >= 0; i--){
				rtn.push_back((uint8_t) ((mask << i * 8) & b.value) >> i * 8);
			}
		}
	}
	for(auto &lit: Tliterali.tabela){
		rtn.push_back((uint8_t) ((lit.value & 0x000000ffu) >> (0 * 8)));
		rtn.push_back((uint8_t) ((lit.value & 0x0000ff00u) >> (1 * 8)));
		rtn.push_back((uint8_t) ((lit.value & 0x00ff0000u) >> (2 * 8)));
		rtn.push_back((uint8_t) ((lit.value & 0xff000000u) >> (3 * 8)));
	}
	
	return rtn;
}

TabelaRelokacija& Sekcija::get_relokacije(){
	return Trelokacija;
}

void Sekcija::fix_relokacije(){
	while(Tliterali.Trelokacija.tabela.size() > 0)
	{
		TabelaRelokacija::relokacija rel = Tliterali.Trelokacija.tabela.back();
		Tliterali.Trelokacija.tabela.pop_back();
		Trelokacija.tabela.emplace_back(rel.offset, rel.simbol, rel.addend);
	}
	std::sort(Trelokacija.tabela.begin(),Trelokacija.tabela.end());
}

std::ostream& operator<<(std::ostream& os, Sekcija& s){
	os << "#." << s.name << std::endl;
	int i = 0;
	for(auto &b: s.get_binary()){
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
