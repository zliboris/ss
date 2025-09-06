%{
#include "../inc/assembler/instructions.hpp"
int yylex(void); 
void yyerror(const char *s);
%}

%union{
std::string* str;
uint32_t num;
sreg type;
reg_lit* rl_addr;
reg_sim* rs_addr;
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

%%

literal_vr : 	DOLAR BROJ 	{$$ = $2;}
literal_addr : 	BROJ 		{$$ = $1;}

simbol_vr : 	DOLAR REC 	{$$ = $2;}
simbol_addr : 	REC 		{$$ = $1;}

reg_addr : 	LEVA_ZAGRADA REG DESNA_ZAGRADA 				{$$ = $2;}
reg_lit_addr : 	LEVA_ZAGRADA REG PLUS literal_addr DESNA_ZAGRADA 	{reg_lit* temp = new reg_lit; temp.reg = $2; temp.literal = $4; $$ = temp;}
reg_sim_addr : 	LEVA_ZAGRADA REG PLUS simbol_addr DESNA_ZAGRADA 	{reg_sim* temp = new reg_sim; temp.reg = $2; temp.simbol = $4; $$ = temp;}
reg_vr : 	REG 							{$$ = $1;}

labela : 	REC DVOTACKA 	{$$ = $1;}

instrukcija :	HALT			{inst_halt();}
	    |	INT			{inst_int();}
	    |	IRET			{inst_iret();}
	    |	CALL	simbol_addr	{inst_call_sym($2);}
	    |	CALL	literal_addr	{inst_call_lim($2);}
	    |	RET			{inst_ret();}
	    |	JMP	simbol_addr	{inst_jmp_sym($2);}
	    |	JMP	literal_addr	{inst_jmp_lit($2);}
	    |	BEQ	reg_vr	reg_vr	simbol_addr	{inst_beq_sym($2,$3,$4);}
	    |	BEQ	reg_vr	reg_vr	literal_addr	{inst_beq_lit($2,$3,$4);}
	    |	BNE	reg_vr	reg_vr	simbol_addr	{inst_bne_sym($2,$3,$4);}
	    |	BNE	reg_vr	reg_vr	literal_addr	{inst_bne_lit($2,$3,$4);}
	    |	BGT	reg_vr	reg_vr	simbol_addr	{inst_bgt_sym($2,$3,$4);}
	    |	BGT	reg_vr	reg_vr	literal_addr	{inst_bgt_lit($2,$3,$4);}
	    |	PUSH	reg_vr				{inst_puch($2);}
	    |	POP	reg_vr				{inst_pop($2);}
	    |	XCHG	reg_vr	reg_vr			{inst_xchg($2,$3);}
	    |	ADD	reg_vr	reg_vr  		{inst_add($2,$3);}
	    |	SUB	reg_vr	reg_vr  		{inst_sub($2,$3);}
	    |	MUL	reg_vr	reg_vr  		{inst_mul($2,$3);}
	    |	DIV	reg_vr	reg_vr  		{inst_div($2,$3);}
	    |	NOT	reg_vr          		{inst_not($2);}
	    |	AND	reg_vr	reg_vr  		{inst_and($2,$3);}
	    |	OR	reg_vr	reg_vr  		{inst_or($2,$3);}
	    |	XOR	reg_vr	reg_vr  		{inst_xor($2,$3);}
	    |	SHL	reg_vr	reg_vr  		{inst_shl($2,$3);}
	    |	SHR	reg_vr	reg_vr  		{inst_shr($2,$3);}
	    |	LD	literal_vr	reg_vr		{inst_ld_lit_vr($3,$2);}
	    |	LD	simbol_vr	reg_vr		{inst_ld_sim_vr($3,$2);}
	    |	LD	literal_addr	reg_vr		{inst_ld_lit_addr($3,$2);}
	    |	LD	simbol_addr	reg_vr		{inst_ld_sim_addr($3,$2);}
	    |	LD	reg_vr		reg_vr		{inst_ld_reg_vr($3,$2);}
	    |	LD	reg_addr	reg_vr		{inst_ld_reg_addr($3,$2);}
	    |	LD	reg_lit_addr	reg_vr		{inst_ld_reg_lit_addr($3,$2);}
	    |	LD	reg_sim_addr	reg_vr		{inst_ld_reg_sim_addr($3,$2);}
	    |	ST	reg_vr		literal_vr	{inst_st_lit_vr($2,$3);}
	    |	ST	reg_vr		simbol_vr       {inst_st_sim_vr($2,$3);}
	    |	ST	reg_vr		literal_addr    {inst_st_lit_addr($2,$3);}
	    |	ST	reg_vr		simbol_addr     {inst_st_sim_addr($2,$3);}
	    |	ST	reg_vr		reg_vr          {inst_st_reg_vr($2,$3);}
	    |	ST	reg_vr		reg_addr        {inst_st_reg_addr($2,$3);}
	    |	ST	reg_vr		reg_lit_addr    {inst_st_reg_lit_addr($2,$3);}
	    |	ST	reg_vr		reg_sim_addr    {inst_st_reg_sim_addr($2,$3);}
	    |	CSRRD	SREG	reg_vr			{inst_csrrd($3,$2);}
	    |	CSRWR	reg_vr	SREG			{inst_csrwr($2,$3);}

izraz :		izraz PLUS BROJ
      |		izraz PLUS REC
      |		izraz MINUS BROJ
      |		izraz MINUS REC
      |		BROJ
      |		REC

lista_simbola :	lista_simbola ZAREZ REC
	      |	REC

lista_simbola_ili_literala :	lista_simbola_ili_literala ZAREZ REC
			   |	lista_simbola_ili_literala ZAREZ BROJ
			   |	BROJ
			   |	REC

direktiva :	GLOBAL	lista_simbola
	  |	EXTERN	lista_simbola
	  |	SECTION	REC
	  |	WORD	lista_simbola_ili_literala
	  |	SKIP	BROJ
	  |	ASCII	STRING
	  |	EQU	REC ZAREZ izraz
	  |	END

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parser error: %s\n", s);
    return;
}

