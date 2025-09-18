%{
#include "../inc/assembler/instructions.hpp"
#include "../inc/assembler/toggleoutput.hpp"
#include <iostream>
int yylex(void); 
void yyerror(const char *s);
%}

%union{
std::string* str;
uint32_t num;
sreg type;
reg_lit* rl_addr;
reg_sim* rs_addr;
std::vector<std::string*> *list_simbol;
std::vector<sim_or_lit> *list_simbol_or_literal;
std::vector<sim_or_lit_izraz> *izraz_list;
}
   	   	   

%token HALT INT IRET CALL RET JMP BEQ BNE BGT PUSH POP XCHG ADD SUB MUL DIV NOT AND OR XOR SHL SHR LD ST CSRRD CSRWR
%token <str> REC STRING
%token GLOBAL EXTERN SECTION WORD SKIP ASCII EQU END
%token <num> REG BROJ
%token <type> SREG
%token LEVA_ZAGRADA DESNA_ZAGRADA DOLAR DVOTACKA PLUS MINUS ZAREZ

%type <num> literal_vr literal_addr reg_addr reg_vr
%type <str> simbol_vr simbol_addr
%type <str> labela
%type <rl_addr> reg_lit_addr
%type <rs_addr> reg_sim_addr
%type <list_simbol> lista_simbola
%type <list_simbol_or_literal> lista_simbola_ili_literala
%type <izraz_list> izraz


%start program

%%

program	: 	program instrukcija
	| 	program direktiva
	| 	program labela
	| 	instrukcija
	|	direktiva
	|	labela

literal_vr : 	DOLAR BROJ 	{$$ = $2;}
literal_addr : 	BROJ 		{$$ = $1;}

simbol_vr : 	DOLAR REC 	{$$ = $2;}
simbol_addr : 	REC 		{$$ = $1;}

reg_addr : 	LEVA_ZAGRADA REG DESNA_ZAGRADA 				{$$ = $2;}
reg_lit_addr : 	LEVA_ZAGRADA REG PLUS literal_addr DESNA_ZAGRADA 	{reg_lit* temp = new reg_lit; temp->reg = $2; temp->literal = $4; $$ = temp;}
reg_sim_addr : 	LEVA_ZAGRADA REG PLUS simbol_addr DESNA_ZAGRADA 	{reg_sim* temp = new reg_sim; temp->reg = $2; temp->simbol = $4; $$ = temp;}
reg_vr : 	REG 							{$$ = $1;}

labela : 	REC DVOTACKA 	{resolve_label($1);ToggleOstream::stream() << *$1 << ":" << std::endl;}

instrukcija :	HALT			{inst_halt(); ToggleOstream::stream() << "Halt" << std::endl;}
	    |	INT			{inst_int(); ToggleOstream::stream() << "Int" << std::endl;}
	    |	IRET			{inst_iret();ToggleOstream::stream() << "Iret" << std::endl;}
	    |	CALL	simbol_addr	{inst_call_sym($2);ToggleOstream::stream() << "Call " << *$2 << std::endl;}
	    |	CALL	literal_addr	{inst_call_lit($2);ToggleOstream::stream() << "Call " << $2 << std::endl;}
	    |	RET			{inst_ret();ToggleOstream::stream() << "Ret" << std::endl;}
	    |	JMP	simbol_addr	{inst_jmp_sym($2);ToggleOstream::stream() << "Jmp " << *$2 << std::endl;}
	    |	JMP	literal_addr	{inst_jmp_lit($2);ToggleOstream::stream() << "Jmp " << $2 << std::endl;}
	    |	BEQ	reg_vr	ZAREZ	reg_vr	ZAREZ	simbol_addr	{inst_beq_sym($2,$4,$6);ToggleOstream::stream() << "Beq " << $2 << " " << $4 << " " << *$6 << std::endl;}
	    |	BEQ	reg_vr	ZAREZ	reg_vr	ZAREZ	literal_addr	{inst_beq_lit($2,$4,$6);ToggleOstream::stream() << "Beq " << $2 << " " << $4 << " " << $6 << std::endl;}
	    |	BNE	reg_vr	ZAREZ	reg_vr	ZAREZ	simbol_addr	{inst_bne_sym($2,$4,$6);ToggleOstream::stream() << "Bne " << $2 << " " << $4 << " " << *$6 << std::endl;}
	    |	BNE	reg_vr	ZAREZ	reg_vr	ZAREZ	literal_addr	{inst_bne_lit($2,$4,$6);ToggleOstream::stream() << "Bne " << $2 << " " << $4 << " " << $6 << std::endl;}
	    |	BGT	reg_vr	ZAREZ	reg_vr	ZAREZ	simbol_addr	{inst_bgt_sym($2,$4,$6);ToggleOstream::stream() << "Bgt " << $2 << " " << $4 << " " << *$6 << std::endl;}
	    |	BGT	reg_vr	ZAREZ	reg_vr	ZAREZ	literal_addr	{inst_bgt_lit($2,$4,$6);ToggleOstream::stream() << "Bgt " << $2 << " " << $4 << " " << $6 << std::endl;}
	    |	PUSH	reg_vr					{inst_push($2);ToggleOstream::stream() << "Push " << $2 << std::endl;}
	    |	POP	reg_vr					{inst_pop($2);ToggleOstream::stream() << "Pop " << $2 << std::endl;}
	    |	XCHG	reg_vr	ZAREZ	reg_vr			{inst_xchg($2,$4);ToggleOstream::stream() << "Xchg " << $2 << " " << $4 << std::endl;}
	    |	ADD	reg_vr	ZAREZ	reg_vr  		{inst_add($2,$4);ToggleOstream::stream() << "Add " << $2 << " " << $4 << std::endl;}
	    |	SUB	reg_vr	ZAREZ	reg_vr  		{inst_sub($2,$4);ToggleOstream::stream() << "Sub " << $2 << " " << $4 << std::endl;}
	    |	MUL	reg_vr	ZAREZ	reg_vr  		{inst_mul($2,$4);ToggleOstream::stream() << "Mul " << $2 << " " << $4 << std::endl;}
	    |	DIV	reg_vr	ZAREZ	reg_vr  		{inst_div($2,$4);ToggleOstream::stream() << "Div " << $2 << " " << $4 << std::endl;}
	    |	NOT	reg_vr          			{inst_not($2);ToggleOstream::stream() << "Not " << $2 << std::endl;}
	    |	AND	reg_vr	ZAREZ	reg_vr  		{inst_and($2,$4);ToggleOstream::stream() << "And " << $2 << " " << $4 << std::endl;}
	    |	OR	reg_vr	ZAREZ	reg_vr  		{inst_or($2,$4);ToggleOstream::stream() << "Or " << $2 << " " << $4 << std::endl;}
	    |	XOR	reg_vr	ZAREZ	reg_vr  		{inst_xor($2,$4);ToggleOstream::stream() << "Xor " << $2 << " " << $4 << std::endl;}
	    |	SHL	reg_vr	ZAREZ	reg_vr  		{inst_shl($2,$4);ToggleOstream::stream() << "Shl " << $2 << " " << $4 << std::endl;}
	    |	SHR	reg_vr	ZAREZ	reg_vr  		{inst_shr($2,$4);ToggleOstream::stream() << "Shr " << $2 << " " << $4 << std::endl;}
	    |	LD	literal_vr	ZAREZ	reg_vr		{inst_ld_lit_vr($4,$2);ToggleOstream::stream() << "Ld " << $2 << " " << $4 << std::endl;}
	    |	LD	simbol_vr	ZAREZ	reg_vr		{inst_ld_sim_vr($4,$2);ToggleOstream::stream() << "Ld " << *$2 << " " << $4 << std::endl;}
	    |	LD	literal_addr	ZAREZ	reg_vr		{inst_ld_lit_addr($4,$2);ToggleOstream::stream() << "Ld " << $2 << " " << $4 << std::endl;}
	    |	LD	simbol_addr	ZAREZ	reg_vr		{inst_ld_sim_addr($4,$2);ToggleOstream::stream() << "Ld " << *$2 << " " << $4 << std::endl;}
	    |	LD	reg_vr	ZAREZ		reg_vr		{inst_ld_reg_vr($4,$2);ToggleOstream::stream() << "Ld " << $2 << " " << $4 << std::endl;}
	    |	LD	reg_addr	ZAREZ	reg_vr		{inst_ld_reg_addr($4,$2);ToggleOstream::stream() << "Ld " << $2 << " " << $4 << std::endl;}
	    |	LD	reg_lit_addr	ZAREZ	reg_vr		{inst_ld_reg_lit_addr($4,$2);ToggleOstream::stream() << "Ld " << $2 << " " << $4 << std::endl;}
	    |	LD	reg_sim_addr	ZAREZ	reg_vr		{inst_ld_reg_sim_addr($4,$2);ToggleOstream::stream() << "Ld " << $2 << " " << $4 << std::endl;}
	    |	ST	reg_vr	ZAREZ	literal_addr    	{inst_st_lit_addr($2,$4);ToggleOstream::stream() << "St " << $2 << " " << $4 << std::endl;}
	    |	ST	reg_vr	ZAREZ	simbol_addr     	{inst_st_sim_addr($2,$4);ToggleOstream::stream() << "St " << $2 << " " << *$4 << std::endl;}
	    |	ST	reg_vr	ZAREZ	reg_addr        	{inst_st_reg_addr($2,$4);ToggleOstream::stream() << "St " << $2 << " " << $4 << std::endl;}
	    |	ST	reg_vr	ZAREZ	reg_lit_addr    	{inst_st_reg_lit_addr($2,$4);ToggleOstream::stream() << "St " << $2 << " " << $4 << std::endl;}
	    |	ST	reg_vr	ZAREZ	reg_sim_addr    	{inst_st_reg_sim_addr($2,$4);ToggleOstream::stream() << "St " << $2 << " " << $4 << std::endl;}
	    |	CSRRD	SREG	ZAREZ	reg_vr			{inst_csrrd($4,$2);ToggleOstream::stream() << "CSRRD " << $2 << " " << $4 << std::endl;}
	    |	CSRWR	reg_vr	ZAREZ	SREG			{inst_csrwr($2,$4);ToggleOstream::stream() << "CSRWR " << $2 << " " << $4 << std::endl;}

izraz :		izraz PLUS BROJ		{$1->emplace_back($3,true); $$ = $1;}
      |		izraz PLUS REC		{$1->emplace_back($3,true); $$ = $1;}
      |		izraz MINUS BROJ	{$1->emplace_back($3,false); $$ = $1;}
      |		izraz MINUS REC		{$1->emplace_back($3,false); $$ = $1;}
      |		BROJ			{$$ = new std::vector<sim_or_lit_izraz>(); $$->emplace_back($1,true);}	
      |		REC			{$$ = new std::vector<sim_or_lit_izraz>(); $$->emplace_back($1,true);}

lista_simbola :	lista_simbola ZAREZ REC		{$1->push_back($3); $$ = $1;}
	      |	REC				{$$ = new std::vector<std::string*>(); $$->push_back($1);}

lista_simbola_ili_literala :	lista_simbola_ili_literala ZAREZ REC			{$1->emplace_back($3); $$ = $1;}
			   |	lista_simbola_ili_literala ZAREZ BROJ                   {$1->emplace_back($3); $$ = $1;}
			   |	BROJ	{$$ = new std::vector<sim_or_lit>(); $$->emplace_back($1);}
			   |	REC	{$$ = new std::vector<sim_or_lit>(); $$->emplace_back($1);}

direktiva :	GLOBAL	lista_simbola			{resolve_global($2);	ToggleOstream::stream() << "Global" << std::endl;}
	  |	EXTERN	lista_simbola			{resolve_extern($2);	ToggleOstream::stream() << "Extern" << std::endl;}
	  |	SECTION	REC				{resolve_section($2);	ToggleOstream::stream() << "Section" << std::endl;}
	  |	WORD	lista_simbola_ili_literala	{resolve_word($2);	ToggleOstream::stream() << "Word" << std::endl;}
	  |	SKIP	BROJ				{resolve_skip((uint32_t)$2);	ToggleOstream::stream() << "Skip" << std::endl;}
	  |	ASCII	STRING				{resolve_ascii($2);	ToggleOstream::stream() << "Ascii" << std::endl;}
	  |	EQU	REC ZAREZ izraz			{resolve_equ($2,$4);	ToggleOstream::stream() << "Equ" << std::endl;}
	  |	END					{ return 0;}

%%

void yyerror(const char *s) {
    std::cerr << "Parser error:" << s << std::endl;
    return;
}

