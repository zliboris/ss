/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "misc/parser.y"

#include "../inc/assembler/instructions.hpp"
#include "../inc/assembler/toggleoutput.hpp"
#include <iostream>
int yylex(void); 
void yyerror(const char *s);

#line 79 "src/assembler/parser.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_HALT = 3,                       /* HALT  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_IRET = 5,                       /* IRET  */
  YYSYMBOL_CALL = 6,                       /* CALL  */
  YYSYMBOL_RET = 7,                        /* RET  */
  YYSYMBOL_JMP = 8,                        /* JMP  */
  YYSYMBOL_BEQ = 9,                        /* BEQ  */
  YYSYMBOL_BNE = 10,                       /* BNE  */
  YYSYMBOL_BGT = 11,                       /* BGT  */
  YYSYMBOL_PUSH = 12,                      /* PUSH  */
  YYSYMBOL_POP = 13,                       /* POP  */
  YYSYMBOL_XCHG = 14,                      /* XCHG  */
  YYSYMBOL_ADD = 15,                       /* ADD  */
  YYSYMBOL_SUB = 16,                       /* SUB  */
  YYSYMBOL_MUL = 17,                       /* MUL  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_NOT = 19,                       /* NOT  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_XOR = 22,                       /* XOR  */
  YYSYMBOL_SHL = 23,                       /* SHL  */
  YYSYMBOL_SHR = 24,                       /* SHR  */
  YYSYMBOL_LD = 25,                        /* LD  */
  YYSYMBOL_ST = 26,                        /* ST  */
  YYSYMBOL_CSRRD = 27,                     /* CSRRD  */
  YYSYMBOL_CSRWR = 28,                     /* CSRWR  */
  YYSYMBOL_REC = 29,                       /* REC  */
  YYSYMBOL_STRING = 30,                    /* STRING  */
  YYSYMBOL_GLOBAL = 31,                    /* GLOBAL  */
  YYSYMBOL_EXTERN = 32,                    /* EXTERN  */
  YYSYMBOL_SECTION = 33,                   /* SECTION  */
  YYSYMBOL_WORD = 34,                      /* WORD  */
  YYSYMBOL_SKIP = 35,                      /* SKIP  */
  YYSYMBOL_ASCII = 36,                     /* ASCII  */
  YYSYMBOL_EQU = 37,                       /* EQU  */
  YYSYMBOL_END = 38,                       /* END  */
  YYSYMBOL_REG = 39,                       /* REG  */
  YYSYMBOL_BROJ = 40,                      /* BROJ  */
  YYSYMBOL_SREG = 41,                      /* SREG  */
  YYSYMBOL_LEVA_ZAGRADA = 42,              /* LEVA_ZAGRADA  */
  YYSYMBOL_DESNA_ZAGRADA = 43,             /* DESNA_ZAGRADA  */
  YYSYMBOL_DOLAR = 44,                     /* DOLAR  */
  YYSYMBOL_DVOTACKA = 45,                  /* DVOTACKA  */
  YYSYMBOL_PLUS = 46,                      /* PLUS  */
  YYSYMBOL_MINUS = 47,                     /* MINUS  */
  YYSYMBOL_ZAREZ = 48,                     /* ZAREZ  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_literal_vr = 51,                /* literal_vr  */
  YYSYMBOL_literal_addr = 52,              /* literal_addr  */
  YYSYMBOL_simbol_vr = 53,                 /* simbol_vr  */
  YYSYMBOL_simbol_addr = 54,               /* simbol_addr  */
  YYSYMBOL_reg_addr = 55,                  /* reg_addr  */
  YYSYMBOL_reg_lit_addr = 56,              /* reg_lit_addr  */
  YYSYMBOL_reg_sim_addr = 57,              /* reg_sim_addr  */
  YYSYMBOL_reg_vr = 58,                    /* reg_vr  */
  YYSYMBOL_labela = 59,                    /* labela  */
  YYSYMBOL_instrukcija = 60,               /* instrukcija  */
  YYSYMBOL_izraz = 61,                     /* izraz  */
  YYSYMBOL_lista_simbola = 62,             /* lista_simbola  */
  YYSYMBOL_lista_simbola_ili_literala = 63, /* lista_simbola_ili_literala  */
  YYSYMBOL_direktiva = 64                  /* direktiva  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  87
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    42,    42,    43,    44,    45,    46,    47,    49,    50,
      52,    53,    55,    56,    57,    58,    60,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   105,
     106,   107,   108,   109,   110,   112,   113,   115,   116,   117,
     118,   120,   121,   122,   123,   124,   125,   126,   127
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "HALT", "INT", "IRET",
  "CALL", "RET", "JMP", "BEQ", "BNE", "BGT", "PUSH", "POP", "XCHG", "ADD",
  "SUB", "MUL", "DIV", "NOT", "AND", "OR", "XOR", "SHL", "SHR", "LD", "ST",
  "CSRRD", "CSRWR", "REC", "STRING", "GLOBAL", "EXTERN", "SECTION", "WORD",
  "SKIP", "ASCII", "EQU", "END", "REG", "BROJ", "SREG", "LEVA_ZAGRADA",
  "DESNA_ZAGRADA", "DOLAR", "DVOTACKA", "PLUS", "MINUS", "ZAREZ",
  "$accept", "program", "literal_vr", "literal_addr", "simbol_vr",
  "simbol_addr", "reg_addr", "reg_lit_addr", "reg_sim_addr", "reg_vr",
  "labela", "instrukcija", "izraz", "lista_simbola",
  "lista_simbola_ili_literala", "direktiva", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     180,   -42,   -42,   -42,   -21,   -42,   -21,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,   -28,   -30,   -31,   -30,    20,    34,    34,
      35,    19,    26,    37,    41,   -42,    18,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,    43,    45,    46,
     -42,   -42,    47,    48,    49,    50,    51,   -42,    52,    53,
      54,    55,    56,    67,    28,    57,    59,    60,    62,    63,
      65,    68,    69,    70,    71,    72,   -42,   -42,    73,    73,
     -42,   -42,   -42,    74,   -42,   -42,    75,   -42,   -42,   -42,
     -42,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -39,   -42,   -42,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,   -27,   -30,    83,    85,    29,
      31,    77,    78,    79,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -21,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -41,   -21,   -21,   -21,
      87,    88,    32,    33,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    17,    18,    19,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     7,     5,     6,
      11,     9,    21,    20,    24,    23,    15,     0,     0,     0,
      31,    32,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    66,    71,    72,
      73,    70,    69,    74,    75,    76,     0,     1,     4,     2,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    34,    35,    36,    37,    39,
      40,    41,    42,    43,    12,     0,    44,    46,    45,    47,
      49,    50,    51,    48,    52,    53,    54,    55,    56,    57,
      58,    65,    67,    68,    64,    63,    77,     0,     0,     0,
       0,     0,     0,     0,    26,    25,    28,    27,    30,    29,
      13,    14,    60,    59,    62,    61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,   -42,    -6,   -42,    -3,     0,    13,    21,    66,
      97,    98,   -42,   106,   -42,   101
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    36,    65,    42,    67,    43,    69,    70,    71,    47,
      37,    38,   156,    78,    83,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    40,    40,    45,   134,   162,   163,   135,    40,    46,
      74,    46,    41,    41,    63,    63,    64,    66,    87,    41,
      68,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    81,    28,
      29,    30,    31,    32,    33,    34,    35,   105,   152,    82,
     154,   172,   174,    77,    80,    76,    84,    85,   106,   153,
      86,   155,   173,   175,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    72,
      73,    91,    75,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   107,   104,   108,   109,   144,
     110,   111,   145,   112,   151,   146,   113,   114,   115,   116,
     117,   118,   119,   120,   150,   157,   158,   159,   147,   160,
     170,   171,   161,    88,    89,    79,   148,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   164,   166,   168,   165,   167,   169,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
       0,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,     0,   149,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,    32,    33,    34,    35
};

static const yytype_int16 yycheck[] =
{
       6,    29,    29,     6,    43,    46,    47,    46,    29,    39,
      41,    39,    40,    40,    42,    42,    44,    23,     0,    40,
      23,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    29,    31,
      32,    33,    34,    35,    36,    37,    38,    29,    29,    40,
      29,    29,    29,    29,    29,    45,    40,    30,    40,    40,
      29,    40,    40,    40,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    48,    26,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    39,    48,    48,   115,
      48,    48,   115,    48,    29,   115,    48,    48,    48,    48,
      48,    48,    48,    48,    41,    48,    48,    48,   115,   135,
      43,    43,   135,    36,    36,    29,   115,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,   159,   157,   158,   159,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,   116,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    31,    32,
      33,    34,    35,    36,    37,    38,    50,    59,    60,    64,
      29,    40,    52,    54,    52,    54,    39,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    42,    44,    51,    52,    53,    54,    55,
      56,    57,    58,    58,    41,    58,    45,    29,    62,    62,
      29,    29,    40,    63,    40,    30,    29,     0,    59,    60,
      64,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    39,    29,    40,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    43,    46,    58,    58,    58,    58,
      58,    58,    58,    58,    52,    54,    55,    56,    57,    58,
      41,    29,    29,    40,    29,    40,    61,    48,    48,    48,
      52,    54,    46,    47,    52,    54,    52,    54,    52,    54,
      43,    43,    29,    40,    29,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    50,    50,    50,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     1,     1,     2,     1,
       2,     1,     3,     5,     5,     1,     2,     1,     1,     1,
       2,     2,     1,     2,     2,     6,     6,     6,     6,     6,
       6,     2,     2,     4,     4,     4,     4,     4,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       3,     3,     3,     1,     1,     3,     1,     3,     3,     1,
       1,     2,     2,     2,     2,     2,     2,     4,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 8: /* literal_vr: DOLAR BROJ  */
#line 49 "misc/parser.y"
                                {(yyval.num) = (yyvsp[0].num);}
#line 1245 "src/assembler/parser.tab.cpp"
    break;

  case 9: /* literal_addr: BROJ  */
#line 50 "misc/parser.y"
                                {(yyval.num) = (yyvsp[0].num);}
#line 1251 "src/assembler/parser.tab.cpp"
    break;

  case 10: /* simbol_vr: DOLAR REC  */
#line 52 "misc/parser.y"
                                {(yyval.str) = (yyvsp[0].str);}
#line 1257 "src/assembler/parser.tab.cpp"
    break;

  case 11: /* simbol_addr: REC  */
#line 53 "misc/parser.y"
                                {(yyval.str) = (yyvsp[0].str);}
#line 1263 "src/assembler/parser.tab.cpp"
    break;

  case 12: /* reg_addr: LEVA_ZAGRADA REG DESNA_ZAGRADA  */
#line 55 "misc/parser.y"
                                                                        {(yyval.num) = (yyvsp[-1].num);}
#line 1269 "src/assembler/parser.tab.cpp"
    break;

  case 13: /* reg_lit_addr: LEVA_ZAGRADA REG PLUS literal_addr DESNA_ZAGRADA  */
#line 56 "misc/parser.y"
                                                                        {reg_lit* temp = new reg_lit; temp->reg = (yyvsp[-3].num); temp->literal = (yyvsp[-1].num); (yyval.rl_addr) = temp;}
#line 1275 "src/assembler/parser.tab.cpp"
    break;

  case 14: /* reg_sim_addr: LEVA_ZAGRADA REG PLUS simbol_addr DESNA_ZAGRADA  */
#line 57 "misc/parser.y"
                                                                        {reg_sim* temp = new reg_sim; temp->reg = (yyvsp[-3].num); temp->simbol = (yyvsp[-1].str); (yyval.rs_addr) = temp;}
#line 1281 "src/assembler/parser.tab.cpp"
    break;

  case 15: /* reg_vr: REG  */
#line 58 "misc/parser.y"
                                                                        {(yyval.num) = (yyvsp[0].num);}
#line 1287 "src/assembler/parser.tab.cpp"
    break;

  case 16: /* labela: REC DVOTACKA  */
#line 60 "misc/parser.y"
                                {resolve_label((yyvsp[-1].str));ToggleOstream::stream() << *(yyvsp[-1].str) << ":" << std::endl;}
#line 1293 "src/assembler/parser.tab.cpp"
    break;

  case 17: /* instrukcija: HALT  */
#line 62 "misc/parser.y"
                                        {inst_halt(); ToggleOstream::stream() << "Halt" << std::endl;}
#line 1299 "src/assembler/parser.tab.cpp"
    break;

  case 18: /* instrukcija: INT  */
#line 63 "misc/parser.y"
                                        {inst_int(); ToggleOstream::stream() << "Int" << std::endl;}
#line 1305 "src/assembler/parser.tab.cpp"
    break;

  case 19: /* instrukcija: IRET  */
#line 64 "misc/parser.y"
                                        {inst_iret();ToggleOstream::stream() << "Iret" << std::endl;}
#line 1311 "src/assembler/parser.tab.cpp"
    break;

  case 20: /* instrukcija: CALL simbol_addr  */
#line 65 "misc/parser.y"
                                        {inst_call_sym((yyvsp[0].str));ToggleOstream::stream() << "Call " << *(yyvsp[0].str) << std::endl;}
#line 1317 "src/assembler/parser.tab.cpp"
    break;

  case 21: /* instrukcija: CALL literal_addr  */
#line 66 "misc/parser.y"
                                        {inst_call_lit((yyvsp[0].num));ToggleOstream::stream() << "Call " << (yyvsp[0].num) << std::endl;}
#line 1323 "src/assembler/parser.tab.cpp"
    break;

  case 22: /* instrukcija: RET  */
#line 67 "misc/parser.y"
                                        {inst_ret();ToggleOstream::stream() << "Ret" << std::endl;}
#line 1329 "src/assembler/parser.tab.cpp"
    break;

  case 23: /* instrukcija: JMP simbol_addr  */
#line 68 "misc/parser.y"
                                        {inst_jmp_sym((yyvsp[0].str));ToggleOstream::stream() << "Jmp " << *(yyvsp[0].str) << std::endl;}
#line 1335 "src/assembler/parser.tab.cpp"
    break;

  case 24: /* instrukcija: JMP literal_addr  */
#line 69 "misc/parser.y"
                                        {inst_jmp_lit((yyvsp[0].num));ToggleOstream::stream() << "Jmp " << (yyvsp[0].num) << std::endl;}
#line 1341 "src/assembler/parser.tab.cpp"
    break;

  case 25: /* instrukcija: BEQ reg_vr ZAREZ reg_vr ZAREZ simbol_addr  */
#line 70 "misc/parser.y"
                                                                        {inst_beq_sym((yyvsp[-4].num),(yyvsp[-2].num),(yyvsp[0].str));ToggleOstream::stream() << "Beq " << (yyvsp[-4].num) << " " << (yyvsp[-2].num) << " " << *(yyvsp[0].str) << std::endl;}
#line 1347 "src/assembler/parser.tab.cpp"
    break;

  case 26: /* instrukcija: BEQ reg_vr ZAREZ reg_vr ZAREZ literal_addr  */
#line 71 "misc/parser.y"
                                                                        {inst_beq_lit((yyvsp[-4].num),(yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "Beq " << (yyvsp[-4].num) << " " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1353 "src/assembler/parser.tab.cpp"
    break;

  case 27: /* instrukcija: BNE reg_vr ZAREZ reg_vr ZAREZ simbol_addr  */
#line 72 "misc/parser.y"
                                                                        {inst_bne_sym((yyvsp[-4].num),(yyvsp[-2].num),(yyvsp[0].str));ToggleOstream::stream() << "Bne " << (yyvsp[-4].num) << " " << (yyvsp[-2].num) << " " << *(yyvsp[0].str) << std::endl;}
#line 1359 "src/assembler/parser.tab.cpp"
    break;

  case 28: /* instrukcija: BNE reg_vr ZAREZ reg_vr ZAREZ literal_addr  */
#line 73 "misc/parser.y"
                                                                        {inst_bne_lit((yyvsp[-4].num),(yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "Bne " << (yyvsp[-4].num) << " " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1365 "src/assembler/parser.tab.cpp"
    break;

  case 29: /* instrukcija: BGT reg_vr ZAREZ reg_vr ZAREZ simbol_addr  */
#line 74 "misc/parser.y"
                                                                        {inst_bgt_sym((yyvsp[-4].num),(yyvsp[-2].num),(yyvsp[0].str));ToggleOstream::stream() << "Bgt " << (yyvsp[-4].num) << " " << (yyvsp[-2].num) << " " << *(yyvsp[0].str) << std::endl;}
#line 1371 "src/assembler/parser.tab.cpp"
    break;

  case 30: /* instrukcija: BGT reg_vr ZAREZ reg_vr ZAREZ literal_addr  */
#line 75 "misc/parser.y"
                                                                        {inst_bgt_lit((yyvsp[-4].num),(yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "Bgt " << (yyvsp[-4].num) << " " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1377 "src/assembler/parser.tab.cpp"
    break;

  case 31: /* instrukcija: PUSH reg_vr  */
#line 76 "misc/parser.y"
                                                                {inst_push((yyvsp[0].num));ToggleOstream::stream() << "Push " << (yyvsp[0].num) << std::endl;}
#line 1383 "src/assembler/parser.tab.cpp"
    break;

  case 32: /* instrukcija: POP reg_vr  */
#line 77 "misc/parser.y"
                                                                {inst_pop((yyvsp[0].num));ToggleOstream::stream() << "Pop " << (yyvsp[0].num) << std::endl;}
#line 1389 "src/assembler/parser.tab.cpp"
    break;

  case 33: /* instrukcija: XCHG reg_vr ZAREZ reg_vr  */
#line 78 "misc/parser.y"
                                                                {inst_xchg((yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "Xchg " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1395 "src/assembler/parser.tab.cpp"
    break;

  case 34: /* instrukcija: ADD reg_vr ZAREZ reg_vr  */
#line 79 "misc/parser.y"
                                                                {inst_add((yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "Add " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1401 "src/assembler/parser.tab.cpp"
    break;

  case 35: /* instrukcija: SUB reg_vr ZAREZ reg_vr  */
#line 80 "misc/parser.y"
                                                                {inst_sub((yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "Sub " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1407 "src/assembler/parser.tab.cpp"
    break;

  case 36: /* instrukcija: MUL reg_vr ZAREZ reg_vr  */
#line 81 "misc/parser.y"
                                                                {inst_mul((yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "Mul " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1413 "src/assembler/parser.tab.cpp"
    break;

  case 37: /* instrukcija: DIV reg_vr ZAREZ reg_vr  */
#line 82 "misc/parser.y"
                                                                {inst_div((yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "Div " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1419 "src/assembler/parser.tab.cpp"
    break;

  case 38: /* instrukcija: NOT reg_vr  */
#line 83 "misc/parser.y"
                                                                {inst_not((yyvsp[0].num));ToggleOstream::stream() << "Not " << (yyvsp[0].num) << std::endl;}
#line 1425 "src/assembler/parser.tab.cpp"
    break;

  case 39: /* instrukcija: AND reg_vr ZAREZ reg_vr  */
#line 84 "misc/parser.y"
                                                                {inst_and((yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "And " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1431 "src/assembler/parser.tab.cpp"
    break;

  case 40: /* instrukcija: OR reg_vr ZAREZ reg_vr  */
#line 85 "misc/parser.y"
                                                                {inst_or((yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "Or " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1437 "src/assembler/parser.tab.cpp"
    break;

  case 41: /* instrukcija: XOR reg_vr ZAREZ reg_vr  */
#line 86 "misc/parser.y"
                                                                {inst_xor((yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "Xor " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1443 "src/assembler/parser.tab.cpp"
    break;

  case 42: /* instrukcija: SHL reg_vr ZAREZ reg_vr  */
#line 87 "misc/parser.y"
                                                                {inst_shl((yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "Shl " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1449 "src/assembler/parser.tab.cpp"
    break;

  case 43: /* instrukcija: SHR reg_vr ZAREZ reg_vr  */
#line 88 "misc/parser.y"
                                                                {inst_shr((yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "Shr " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1455 "src/assembler/parser.tab.cpp"
    break;

  case 44: /* instrukcija: LD literal_vr ZAREZ reg_vr  */
#line 89 "misc/parser.y"
                                                                {inst_ld_lit_vr((yyvsp[0].num),(yyvsp[-2].num));ToggleOstream::stream() << "Ld " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1461 "src/assembler/parser.tab.cpp"
    break;

  case 45: /* instrukcija: LD simbol_vr ZAREZ reg_vr  */
#line 90 "misc/parser.y"
                                                                {inst_ld_sim_vr((yyvsp[0].num),(yyvsp[-2].str));ToggleOstream::stream() << "Ld " << *(yyvsp[-2].str) << " " << (yyvsp[0].num) << std::endl;}
#line 1467 "src/assembler/parser.tab.cpp"
    break;

  case 46: /* instrukcija: LD literal_addr ZAREZ reg_vr  */
#line 91 "misc/parser.y"
                                                                {inst_ld_lit_addr((yyvsp[0].num),(yyvsp[-2].num));ToggleOstream::stream() << "Ld " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1473 "src/assembler/parser.tab.cpp"
    break;

  case 47: /* instrukcija: LD simbol_addr ZAREZ reg_vr  */
#line 92 "misc/parser.y"
                                                                {inst_ld_sim_addr((yyvsp[0].num),(yyvsp[-2].str));ToggleOstream::stream() << "Ld " << *(yyvsp[-2].str) << " " << (yyvsp[0].num) << std::endl;}
#line 1479 "src/assembler/parser.tab.cpp"
    break;

  case 48: /* instrukcija: LD reg_vr ZAREZ reg_vr  */
#line 93 "misc/parser.y"
                                                                {inst_ld_reg_vr((yyvsp[0].num),(yyvsp[-2].num));ToggleOstream::stream() << "Ld " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1485 "src/assembler/parser.tab.cpp"
    break;

  case 49: /* instrukcija: LD reg_addr ZAREZ reg_vr  */
#line 94 "misc/parser.y"
                                                                {inst_ld_reg_addr((yyvsp[0].num),(yyvsp[-2].num));ToggleOstream::stream() << "Ld " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1491 "src/assembler/parser.tab.cpp"
    break;

  case 50: /* instrukcija: LD reg_lit_addr ZAREZ reg_vr  */
#line 95 "misc/parser.y"
                                                                {inst_ld_reg_lit_addr((yyvsp[0].num),(yyvsp[-2].rl_addr));ToggleOstream::stream() << "Ld " << (yyvsp[-2].rl_addr) << " " << (yyvsp[0].num) << std::endl;}
#line 1497 "src/assembler/parser.tab.cpp"
    break;

  case 51: /* instrukcija: LD reg_sim_addr ZAREZ reg_vr  */
#line 96 "misc/parser.y"
                                                                {inst_ld_reg_sim_addr((yyvsp[0].num),(yyvsp[-2].rs_addr));ToggleOstream::stream() << "Ld " << (yyvsp[-2].rs_addr) << " " << (yyvsp[0].num) << std::endl;}
#line 1503 "src/assembler/parser.tab.cpp"
    break;

  case 52: /* instrukcija: ST reg_vr ZAREZ literal_addr  */
#line 97 "misc/parser.y"
                                                                {inst_st_lit_addr((yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "St " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1509 "src/assembler/parser.tab.cpp"
    break;

  case 53: /* instrukcija: ST reg_vr ZAREZ simbol_addr  */
#line 98 "misc/parser.y"
                                                                {inst_st_sim_addr((yyvsp[-2].num),(yyvsp[0].str));ToggleOstream::stream() << "St " << (yyvsp[-2].num) << " " << *(yyvsp[0].str) << std::endl;}
#line 1515 "src/assembler/parser.tab.cpp"
    break;

  case 54: /* instrukcija: ST reg_vr ZAREZ reg_addr  */
#line 99 "misc/parser.y"
                                                                {inst_st_reg_addr((yyvsp[-2].num),(yyvsp[0].num));ToggleOstream::stream() << "St " << (yyvsp[-2].num) << " " << (yyvsp[0].num) << std::endl;}
#line 1521 "src/assembler/parser.tab.cpp"
    break;

  case 55: /* instrukcija: ST reg_vr ZAREZ reg_lit_addr  */
#line 100 "misc/parser.y"
                                                                {inst_st_reg_lit_addr((yyvsp[-2].num),(yyvsp[0].rl_addr));ToggleOstream::stream() << "St " << (yyvsp[-2].num) << " " << (yyvsp[0].rl_addr) << std::endl;}
#line 1527 "src/assembler/parser.tab.cpp"
    break;

  case 56: /* instrukcija: ST reg_vr ZAREZ reg_sim_addr  */
#line 101 "misc/parser.y"
                                                                {inst_st_reg_sim_addr((yyvsp[-2].num),(yyvsp[0].rs_addr));ToggleOstream::stream() << "St " << (yyvsp[-2].num) << " " << (yyvsp[0].rs_addr) << std::endl;}
#line 1533 "src/assembler/parser.tab.cpp"
    break;

  case 57: /* instrukcija: CSRRD SREG ZAREZ reg_vr  */
#line 102 "misc/parser.y"
                                                                {inst_csrrd((yyvsp[0].num),(yyvsp[-2].type));ToggleOstream::stream() << "CSRRD " << (yyvsp[-2].type) << " " << (yyvsp[0].num) << std::endl;}
#line 1539 "src/assembler/parser.tab.cpp"
    break;

  case 58: /* instrukcija: CSRWR reg_vr ZAREZ SREG  */
#line 103 "misc/parser.y"
                                                                {inst_csrwr((yyvsp[-2].num),(yyvsp[0].type));ToggleOstream::stream() << "CSRWR " << (yyvsp[-2].num) << " " << (yyvsp[0].type) << std::endl;}
#line 1545 "src/assembler/parser.tab.cpp"
    break;

  case 59: /* izraz: izraz PLUS BROJ  */
#line 105 "misc/parser.y"
                                        {(yyvsp[-2].izraz_list)->emplace_back((yyvsp[0].num),true); (yyval.izraz_list) = (yyvsp[-2].izraz_list);}
#line 1551 "src/assembler/parser.tab.cpp"
    break;

  case 60: /* izraz: izraz PLUS REC  */
#line 106 "misc/parser.y"
                                        {(yyvsp[-2].izraz_list)->emplace_back((yyvsp[0].str),true); (yyval.izraz_list) = (yyvsp[-2].izraz_list);}
#line 1557 "src/assembler/parser.tab.cpp"
    break;

  case 61: /* izraz: izraz MINUS BROJ  */
#line 107 "misc/parser.y"
                                        {(yyvsp[-2].izraz_list)->emplace_back((yyvsp[0].num),false); (yyval.izraz_list) = (yyvsp[-2].izraz_list);}
#line 1563 "src/assembler/parser.tab.cpp"
    break;

  case 62: /* izraz: izraz MINUS REC  */
#line 108 "misc/parser.y"
                                        {(yyvsp[-2].izraz_list)->emplace_back((yyvsp[0].str),false); (yyval.izraz_list) = (yyvsp[-2].izraz_list);}
#line 1569 "src/assembler/parser.tab.cpp"
    break;

  case 63: /* izraz: BROJ  */
#line 109 "misc/parser.y"
                                        {(yyval.izraz_list) = new std::vector<sim_or_lit_izraz>(); (yyval.izraz_list)->emplace_back((yyvsp[0].num),true);}
#line 1575 "src/assembler/parser.tab.cpp"
    break;

  case 64: /* izraz: REC  */
#line 110 "misc/parser.y"
                                        {(yyval.izraz_list) = new std::vector<sim_or_lit_izraz>(); (yyval.izraz_list)->emplace_back((yyvsp[0].str),true);}
#line 1581 "src/assembler/parser.tab.cpp"
    break;

  case 65: /* lista_simbola: lista_simbola ZAREZ REC  */
#line 112 "misc/parser.y"
                                                {(yyvsp[-2].list_simbol)->push_back((yyvsp[0].str)); (yyval.list_simbol) = (yyvsp[-2].list_simbol);}
#line 1587 "src/assembler/parser.tab.cpp"
    break;

  case 66: /* lista_simbola: REC  */
#line 113 "misc/parser.y"
                                                {(yyval.list_simbol) = new std::vector<std::string*>(); (yyval.list_simbol)->push_back((yyvsp[0].str));}
#line 1593 "src/assembler/parser.tab.cpp"
    break;

  case 67: /* lista_simbola_ili_literala: lista_simbola_ili_literala ZAREZ REC  */
#line 115 "misc/parser.y"
                                                                                        {(yyvsp[-2].list_simbol_or_literal)->emplace_back((yyvsp[0].str)); (yyval.list_simbol_or_literal) = (yyvsp[-2].list_simbol_or_literal);}
#line 1599 "src/assembler/parser.tab.cpp"
    break;

  case 68: /* lista_simbola_ili_literala: lista_simbola_ili_literala ZAREZ BROJ  */
#line 116 "misc/parser.y"
                                                                                        {(yyvsp[-2].list_simbol_or_literal)->emplace_back((yyvsp[0].num)); (yyval.list_simbol_or_literal) = (yyvsp[-2].list_simbol_or_literal);}
#line 1605 "src/assembler/parser.tab.cpp"
    break;

  case 69: /* lista_simbola_ili_literala: BROJ  */
#line 117 "misc/parser.y"
                                        {(yyval.list_simbol_or_literal) = new std::vector<sim_or_lit>(); (yyval.list_simbol_or_literal)->emplace_back((yyvsp[0].num));}
#line 1611 "src/assembler/parser.tab.cpp"
    break;

  case 70: /* lista_simbola_ili_literala: REC  */
#line 118 "misc/parser.y"
                                        {(yyval.list_simbol_or_literal) = new std::vector<sim_or_lit>(); (yyval.list_simbol_or_literal)->emplace_back((yyvsp[0].str));}
#line 1617 "src/assembler/parser.tab.cpp"
    break;

  case 71: /* direktiva: GLOBAL lista_simbola  */
#line 120 "misc/parser.y"
                                                        {resolve_global((yyvsp[0].list_simbol));	ToggleOstream::stream() << "Global" << std::endl;}
#line 1623 "src/assembler/parser.tab.cpp"
    break;

  case 72: /* direktiva: EXTERN lista_simbola  */
#line 121 "misc/parser.y"
                                                        {resolve_extern((yyvsp[0].list_simbol));	ToggleOstream::stream() << "Extern" << std::endl;}
#line 1629 "src/assembler/parser.tab.cpp"
    break;

  case 73: /* direktiva: SECTION REC  */
#line 122 "misc/parser.y"
                                                        {resolve_section((yyvsp[0].str));	ToggleOstream::stream() << "Section" << std::endl;}
#line 1635 "src/assembler/parser.tab.cpp"
    break;

  case 74: /* direktiva: WORD lista_simbola_ili_literala  */
#line 123 "misc/parser.y"
                                                        {resolve_word((yyvsp[0].list_simbol_or_literal));	ToggleOstream::stream() << "Word" << std::endl;}
#line 1641 "src/assembler/parser.tab.cpp"
    break;

  case 75: /* direktiva: SKIP BROJ  */
#line 124 "misc/parser.y"
                                                        {resolve_skip((uint32_t)(yyvsp[0].num));	ToggleOstream::stream() << "Skip" << std::endl;}
#line 1647 "src/assembler/parser.tab.cpp"
    break;

  case 76: /* direktiva: ASCII STRING  */
#line 125 "misc/parser.y"
                                                        {resolve_ascii((yyvsp[0].str));	ToggleOstream::stream() << "Ascii" << std::endl;}
#line 1653 "src/assembler/parser.tab.cpp"
    break;

  case 77: /* direktiva: EQU REC ZAREZ izraz  */
#line 126 "misc/parser.y"
                                                        {resolve_equ((yyvsp[-2].str),(yyvsp[0].izraz_list));	ToggleOstream::stream() << "Equ" << std::endl;}
#line 1659 "src/assembler/parser.tab.cpp"
    break;

  case 78: /* direktiva: END  */
#line 127 "misc/parser.y"
                                                        { return 0;}
#line 1665 "src/assembler/parser.tab.cpp"
    break;


#line 1669 "src/assembler/parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 129 "misc/parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Parser error: %s\n", s);
    return;
}

