%{
#include "../inc/assembler/assembler.hpp"
#include "parser.tab.hpp"
int fileno(FILE *stream);
%}

%%

[ \t\n]+		;
#.*			;

halt			{ return HALT;};
int			{ return INT;};
iret			{ return IRET;};
call			{ return CALL;};
ret			{ return RET;};
jmp			{ return JMP;};
beq			{ return BEQ;};
bne			{ return BNE;};
bgt			{ return BGT;};
push			{ return PUSH;};
pop			{ return POP;};
xchg			{ return XCHG;};
add			{ return ADD;};
sub			{ return SUB;};
mul			{ return MUL;};
div			{ return DIV;};
not			{ return NOT;};
and			{ return AND;};
or			{ return OR;};
xor			{ return XOR;};
shl			{ return SHL;};
shr			{ return SHR;};
ld			{ return LD;};
st			{ return ST;};
csrrd			{ return CSRRD;};
csrwr			{ return CSRWR;};

[.]global		{ return GLOBAL;};
[.]extern		{ return EXTERN;};
[.]section		{ return SECTION;};
[.]word			{ return WORD;};
[.]skip			{ return SKIP;};
[.]ascii		{ return ASCII;};
[.]equ			{ return EQU;};
[.]end			{ return END;};


%r([0-9]+)		{ yylval.num = atoi(yytext+2); return REG;};
%sp 			{ yylval.num = 14; return REG;};
%pc			{ yylval.num = 15; return REG;};

%status			{ yylval.type = STATUS; return SREG;};
%handler		{ yylval.type = HANDLER; return SREG;};
%cause			{ yylval.type = CAUSE; return SREG;};

\"[^"\n]*\" 		{ yytext[yyleng - 1] = '\0';
			yylval.str = new std::string(yytext + 1);
    			return STRING;};

([a-zA-Z_][a-zA-Z0-9_]*)		{ yylval.str = new std::string(yytext); return REC;};

0x[0-9]+		{ yylval.num = strtoul(yytext, NULL, 0); return BROJ;};

[-]{0,1}[0-9]+			{ yylval.num = atoi(yytext); return BROJ;};

","			{ return ZAREZ;};
"+"			{ return PLUS;};
"-"			{ return MINUS;};
":"			{ return DVOTACKA;};
"$"			{ return DOLAR;};
"["			{ return LEVA_ZAGRADA;};
"]"			{ return DESNA_ZAGRADA;};


%%

int yywrap(void) {
    return 1;
}

