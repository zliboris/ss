/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_ASSEMBLER_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_ASSEMBLER_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    HALT = 258,                    /* HALT  */
    INT = 259,                     /* INT  */
    IRET = 260,                    /* IRET  */
    CALL = 261,                    /* CALL  */
    RET = 262,                     /* RET  */
    JMP = 263,                     /* JMP  */
    BEQ = 264,                     /* BEQ  */
    BNE = 265,                     /* BNE  */
    BGT = 266,                     /* BGT  */
    PUSH = 267,                    /* PUSH  */
    POP = 268,                     /* POP  */
    XCHG = 269,                    /* XCHG  */
    ADD = 270,                     /* ADD  */
    SUB = 271,                     /* SUB  */
    MUL = 272,                     /* MUL  */
    DIV = 273,                     /* DIV  */
    NOT = 274,                     /* NOT  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    XOR = 277,                     /* XOR  */
    SHL = 278,                     /* SHL  */
    SHR = 279,                     /* SHR  */
    LD = 280,                      /* LD  */
    ST = 281,                      /* ST  */
    CSRRD = 282,                   /* CSRRD  */
    CSRWR = 283,                   /* CSRWR  */
    REC = 284,                     /* REC  */
    STRING = 285,                  /* STRING  */
    GLOBAL = 286,                  /* GLOBAL  */
    EXTERN = 287,                  /* EXTERN  */
    SECTION = 288,                 /* SECTION  */
    WORD = 289,                    /* WORD  */
    SKIP = 290,                    /* SKIP  */
    ASCII = 291,                   /* ASCII  */
    EQU = 292,                     /* EQU  */
    END = 293,                     /* END  */
    REG = 294,                     /* REG  */
    BROJ = 295,                    /* BROJ  */
    SREG = 296,                    /* SREG  */
    LEVA_ZAGRADA = 297,            /* LEVA_ZAGRADA  */
    DESNA_ZAGRADA = 298,           /* DESNA_ZAGRADA  */
    DOLAR = 299,                   /* DOLAR  */
    DVOTACKA = 300,                /* DVOTACKA  */
    PLUS = 301,                    /* PLUS  */
    MINUS = 302,                   /* MINUS  */
    ZAREZ = 303                    /* ZAREZ  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "misc/parser.y"

std::string* str;
uint32_t num;
sreg type;
reg_lit* rl_addr;
reg_sim* rs_addr;
std::vector<std::string*> *list_simbol;
std::vector<sim_or_lit> *list_simbol_or_literal;
std::vector<sim_or_lit_izraz> *izraz_list;

#line 123 "src/assembler/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_ASSEMBLER_PARSER_TAB_HPP_INCLUDED  */
