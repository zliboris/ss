%{
#include "../inc/assembler/assembler.hpp"
int yylex(void); 
void yyerror(const char *s);
%}

%union{
char* str;
uint num;
sreg type;
reg_lit* rl_addr;
reg_sim* rs_addr;
}


%token HALT INT IRET CALL RET JMP BEQ BNE BGT PUSH POP XCHG ADD SUB MUL DIV NOT AND OR XOR SHL SHR LD ST CSRRD CSRWR
%token <str> REC STRING
%token GLOBAL EXTERN SECTION WORD SKIP ASCII EQU END
%token <num> REG BROJ
%token <type> SREG
%token LEVA_ZAGRADA DESNA_ZAGRADA NAVODNIK DOLAR DVOTACKA PLUS MINUS

%type <num> literal_vr literal_addr reg_addr reg_vr
%type <str> simbol_vr simbol_addr
%type <str> labela
%type <rl_addr> reg_lit_addr
%type <rs_addr> reg_sim_addr

%%

literal_vr : 	DOLAR BROJ 	{$$ = $2;};
literal_addr : 	BROJ 		{$$ = $1;};

simbol_vr : 	DOLAR REC 	{$$ = $2;};
labela : 	REC DVOTACKA 	{$$ = $1;};
simbol_addr : 	REC 		{$$ = $1;};

reg_addr : 	LEVA_ZAGRADA REG DESNA_ZAGRADA 				{$$ = $2;};
reg_lit_addr : 	LEVA_ZAGRADA REG PLUS literal_addr DESNA_ZAGRADA 	{reg_lit* temp = new reg_lit; temp.reg = $2; temp.literal = $4; $$ = temp;};
reg_sim_addr : 	LEVA_ZAGRADA REG PLUS simbol_addr DESNA_ZAGRADA 	{reg_sim* temp = new reg_sim; temp.reg = $2; temp.simbol = $4; $$ = temp;};
reg_vr : 	REG 							{$$ = $1;};



%%

void yyerror(const char *s) {
    fprintf(stderr, "Parser error: %s\n", s);
    return;
}

