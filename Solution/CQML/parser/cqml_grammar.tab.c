
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */
#include "parser_tree.h"

/* Line 189 of yacc.c  */
#line 73 "cqml_grammar.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     TYPE_NAME = 283,
     TYPEDEF = 284,
     EXTERN = 285,
     STATIC = 286,
     AUTO = 287,
     REGISTER = 288,
     PROPERTY = 289,
     CHAR = 290,
     SHORT = 291,
     INT = 292,
     LONG = 293,
     SIGNED = 294,
     UNSIGNED = 295,
     FLOAT = 296,
     DOUBLE = 297,
     CONST = 298,
     VOLATILE = 299,
     VOID = 300,
     STRUCT = 301,
     UNION = 302,
     ENUM = 303,
     ELLIPSIS = 304,
     CASE = 305,
     DEFAULT = 306,
     IF = 307,
     ELSE = 308,
     SWITCH = 309,
     WHILE = 310,
     DO = 311,
     FOR = 312,
     GOTO = 313,
     CONTINUE = 314,
     BREAK = 315,
     RETURN = 316
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 15 "cqml_grammar.g"

	struct
	{
	int* val;
	char * lexem;
	} data;



/* Line 214 of yacc.c  */
#line 180 "cqml_grammar.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 192 "cqml_grammar.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  219
/* YYNRULES -- Number of states.  */
#define YYNSTATES  361

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    77,     2,     2,     2,    79,    72,     2,
      66,    67,    73,    74,    71,    75,    70,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    65,    64,
      80,    85,    81,    84,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    82,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,    83,    63,    76,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    15,    19,    23,    26,
      28,    30,    32,    34,    38,    42,    46,    50,    52,    54,
      56,    60,    62,    67,    71,    76,    80,    84,    87,    90,
      92,    96,    98,   101,   104,   107,   110,   115,   117,   119,
     121,   123,   125,   127,   129,   134,   136,   140,   144,   148,
     150,   154,   158,   160,   164,   168,   170,   174,   178,   182,
     186,   188,   192,   196,   198,   202,   204,   208,   210,   214,
     216,   220,   222,   226,   228,   234,   236,   240,   242,   244,
     246,   248,   250,   252,   254,   256,   258,   260,   262,   264,
     268,   270,   273,   277,   279,   282,   284,   287,   289,   292,
     294,   298,   300,   304,   306,   308,   310,   312,   314,   316,
     318,   320,   322,   324,   326,   328,   330,   332,   334,   336,
     338,   344,   349,   352,   354,   356,   358,   361,   365,   368,
     370,   373,   375,   377,   381,   383,   386,   390,   395,   401,
     404,   406,   410,   412,   416,   418,   420,   423,   425,   427,
     431,   436,   440,   445,   450,   454,   456,   459,   462,   466,
     468,   471,   473,   477,   479,   483,   486,   489,   491,   493,
     497,   499,   502,   504,   506,   509,   513,   516,   520,   524,
     529,   532,   536,   540,   545,   547,   551,   556,   558,   562,
     564,   566,   568,   570,   572,   574,   578,   583,   587,   590,
     594,   598,   603,   605,   608,   610,   613,   615,   618,   624,
     632,   638,   644,   652,   659,   667,   671,   674,   677,   680
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      87,     0,    -1,    88,    -1,    89,    88,    -1,    89,    -1,
       3,    62,    90,    63,    -1,     3,    62,    63,    -1,    91,
      64,    90,    -1,    91,    64,    -1,    89,    -1,    92,    -1,
      94,    -1,    93,    -1,     3,    65,   148,    -1,    34,     3,
      94,    -1,    34,     3,     3,    -1,     3,    65,   114,    -1,
       3,    -1,     4,    -1,     5,    -1,    66,   114,    67,    -1,
      95,    -1,    96,    68,   114,    69,    -1,    96,    66,    67,
      -1,    96,    66,    97,    67,    -1,    96,    70,     3,    -1,
      96,     7,     3,    -1,    96,     8,    -1,    96,     9,    -1,
     112,    -1,    97,    71,   112,    -1,    96,    -1,     8,    98,
      -1,     9,    98,    -1,    99,   100,    -1,     6,    98,    -1,
       6,    66,   141,    67,    -1,    72,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    98,    -1,    66,
     141,    67,   100,    -1,   100,    -1,   101,    73,   100,    -1,
     101,    78,   100,    -1,   101,    79,   100,    -1,   101,    -1,
     102,    74,   101,    -1,   102,    75,   101,    -1,   102,    -1,
     103,    10,   102,    -1,   103,    11,   102,    -1,   103,    -1,
     104,    80,   103,    -1,   104,    81,   103,    -1,   104,    12,
     103,    -1,   104,    13,   103,    -1,   104,    -1,   105,    14,
     104,    -1,   105,    15,   104,    -1,   105,    -1,   106,    72,
     105,    -1,   106,    -1,   107,    82,   106,    -1,   107,    -1,
     108,    83,   107,    -1,   108,    -1,   109,    16,   108,    -1,
     109,    -1,   110,    17,   109,    -1,   110,    -1,   110,    84,
     114,    65,   111,    -1,   111,    -1,    98,   113,   112,    -1,
      85,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      22,    -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,   112,    -1,   114,    71,   112,    -1,   111,    -1,
     117,    64,    -1,   117,   118,    64,    -1,   120,    -1,   120,
     117,    -1,   121,    -1,   121,   117,    -1,   132,    -1,   132,
     117,    -1,   119,    -1,   118,    71,   119,    -1,   133,    -1,
     133,    85,   144,    -1,    29,    -1,    30,    -1,    31,    -1,
      32,    -1,    33,    -1,    45,    -1,    35,    -1,    36,    -1,
      37,    -1,    38,    -1,    41,    -1,    42,    -1,    39,    -1,
      40,    -1,   122,    -1,   129,    -1,    28,    -1,   123,     3,
      62,   124,    63,    -1,   123,    62,   124,    63,    -1,   123,
       3,    -1,    46,    -1,    47,    -1,   125,    -1,   124,   125,
      -1,   126,   127,    64,    -1,   121,   126,    -1,   121,    -1,
     132,   126,    -1,   132,    -1,   128,    -1,   127,    71,   128,
      -1,   133,    -1,    65,   115,    -1,   133,    65,   115,    -1,
      48,    62,   130,    63,    -1,    48,     3,    62,   130,    63,
      -1,    48,     3,    -1,   131,    -1,   130,    71,   131,    -1,
       3,    -1,     3,    85,   115,    -1,    43,    -1,    44,    -1,
     135,   134,    -1,   134,    -1,     3,    -1,    66,   133,    67,
      -1,   134,    68,   115,    69,    -1,   134,    68,    69,    -1,
     134,    66,   137,    67,    -1,   134,    66,   140,    67,    -1,
     134,    66,    67,    -1,    73,    -1,    73,   136,    -1,    73,
     135,    -1,    73,   136,   135,    -1,   132,    -1,   136,   132,
      -1,   138,    -1,   138,    71,    49,    -1,   139,    -1,   138,
      71,   139,    -1,   117,   133,    -1,   117,   142,    -1,   117,
      -1,     3,    -1,   140,    71,     3,    -1,   126,    -1,   126,
     142,    -1,   135,    -1,   143,    -1,   135,   143,    -1,    66,
     142,    67,    -1,    68,    69,    -1,    68,   115,    69,    -1,
     143,    68,    69,    -1,   143,    68,   115,    69,    -1,    66,
      67,    -1,    66,   137,    67,    -1,   143,    66,    67,    -1,
     143,    66,   137,    67,    -1,   112,    -1,    62,   145,    63,
      -1,    62,   145,    71,    63,    -1,   144,    -1,   145,    71,
     144,    -1,   147,    -1,   148,    -1,   151,    -1,   152,    -1,
     153,    -1,   154,    -1,     3,    65,   146,    -1,    50,   115,
      65,   146,    -1,    51,    65,   146,    -1,    62,    63,    -1,
      62,   150,    63,    -1,    62,   149,    63,    -1,    62,   149,
     150,    63,    -1,   116,    -1,   149,   116,    -1,   146,    -1,
     150,   146,    -1,    64,    -1,   114,    64,    -1,    52,    66,
     114,    67,   146,    -1,    52,    66,   114,    67,   146,    53,
     146,    -1,    54,    66,   114,    67,   146,    -1,    55,    66,
     114,    67,   146,    -1,    56,   146,    55,    66,   114,    67,
      64,    -1,    57,    66,   151,   151,    67,   146,    -1,    57,
      66,   151,   151,   114,    67,   146,    -1,    58,     3,    64,
      -1,    59,    64,    -1,    60,    64,    -1,    61,    64,    -1,
      61,   114,    64,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    25,    25,    30,    32,    37,    39,    44,    46,    52,
      54,    56,    58,    63,    68,    70,    75,    80,    82,    84,
      86,    91,    93,    95,    97,    99,   101,   103,   105,   110,
     112,   117,   119,   121,   123,   125,   127,   132,   134,   136,
     138,   140,   142,   147,   149,   155,   157,   159,   161,   166,
     168,   170,   175,   177,   179,   184,   186,   188,   190,   192,
     197,   199,   201,   206,   208,   213,   215,   220,   222,   227,
     229,   234,   236,   241,   243,   248,   250,   255,   257,   259,
     261,   263,   265,   267,   269,   271,   273,   275,   280,   282,
     287,   292,   294,   299,   301,   303,   305,   307,   309,   314,
     316,   321,   323,   328,   330,   332,   334,   336,   341,   343,
     345,   347,   349,   351,   353,   355,   357,   359,   361,   363,
     368,   369,   370,   374,   375,   379,   380,   384,   388,   389,
     390,   391,   395,   396,   400,   401,   402,   406,   407,   408,
     412,   413,   417,   418,   422,   424,   429,   431,   436,   437,
     439,   441,   443,   445,   447,   452,   454,   456,   458,   463,
     465,   471,   473,   478,   480,   485,   487,   489,   494,   496,
     501,   502,   506,   508,   510,   515,   517,   519,   521,   523,
     525,   527,   529,   531,   536,   538,   540,   545,   547,   552,
     554,   556,   558,   560,   562,   567,   569,   571,   576,   578,
     580,   582,   587,   589,   594,   596,   601,   603,   608,   610,
     612,   617,   619,   621,   623,   628,   630,   632,   634,   636
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER",
  "PROPERTY", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "'{'", "'}'", "';'",
  "':'", "'('", "')'", "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'",
  "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'",
  "'='", "$accept", "start_point", "element_list", "element",
  "attribute_or_subelement_list", "attribute_or_element", "event_handler",
  "property", "attribute", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   123,   125,    59,    58,    40,    41,    91,    93,
      46,    44,    38,    42,    43,    45,   126,    33,    47,    37,
      60,    62,    94,   124,    63,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    91,    91,    92,    93,    93,    94,    95,    95,    95,
      95,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    98,    98,    98,    98,    99,    99,    99,
      99,    99,    99,   100,   100,   101,   101,   101,   101,   102,
     102,   102,   103,   103,   103,   104,   104,   104,   104,   104,
     105,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   112,   112,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   114,   114,
     115,   116,   116,   117,   117,   117,   117,   117,   117,   118,
     118,   119,   119,   120,   120,   120,   120,   120,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     122,   122,   122,   123,   123,   124,   124,   125,   126,   126,
     126,   126,   127,   127,   128,   128,   128,   129,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   134,
     134,   134,   134,   134,   134,   135,   135,   135,   135,   136,
     136,   137,   137,   138,   138,   139,   139,   139,   140,   140,
     141,   141,   142,   142,   142,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   144,   144,   144,   145,   145,   146,
     146,   146,   146,   146,   146,   147,   147,   147,   148,   148,
     148,   148,   149,   149,   150,   150,   151,   151,   152,   152,
     152,   153,   153,   153,   153,   154,   154,   154,   154,   154
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     4,     3,     3,     2,     1,
       1,     1,     1,     3,     3,     3,     3,     1,     1,     1,
       3,     1,     4,     3,     4,     3,     3,     2,     2,     1,
       3,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     3,     1,     2,     1,     2,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     2,     1,     1,     1,     2,     3,     2,     1,
       2,     1,     1,     3,     1,     2,     3,     4,     5,     2,
       1,     3,     1,     3,     1,     1,     2,     1,     1,     3,
       4,     3,     4,     4,     3,     1,     2,     2,     3,     1,
       2,     1,     3,     1,     3,     2,     2,     1,     1,     3,
       1,     2,     1,     1,     2,     3,     2,     3,     3,     4,
       2,     3,     3,     4,     1,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     3,
       3,     4,     1,     2,     1,     2,     1,     2,     5,     7,
       5,     5,     7,     6,     7,     3,     2,     2,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     0,     0,
       6,     9,     0,     0,    10,    12,    11,     0,     0,     5,
       8,    17,    18,    19,     0,     0,     0,     0,     0,    37,
      38,    39,    40,    41,    42,    21,    31,    43,     0,    45,
      49,    52,    55,    60,    63,    65,    67,    69,    71,    73,
      75,    88,    16,    13,    15,    14,     7,     0,    35,     0,
      32,    33,    17,   119,   103,   104,   105,   106,   107,   109,
     110,   111,   112,   115,   116,   113,   114,   144,   145,   108,
     123,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   198,   206,     0,   202,     0,    93,
      95,   117,     0,   118,    97,   204,   189,   190,     0,     0,
     191,   192,   193,   194,     0,   129,   170,   131,     0,     0,
      27,    28,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    77,     0,    43,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   139,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,   216,   217,   218,     0,   207,   148,    91,
       0,   155,     0,    99,   101,   147,     0,    94,    96,   122,
       0,    98,   200,   203,     0,   199,   205,    20,   128,     0,
       0,   172,   171,   173,   130,     0,    26,    23,     0,    29,
       0,    25,    76,    46,    47,    48,    50,    51,    53,    54,
      58,    59,    56,    57,    61,    62,    64,    66,    68,    70,
      72,     0,    89,    36,   195,     0,   142,     0,   140,     0,
     197,     0,     0,     0,     0,     0,   215,   219,     0,   159,
     157,   156,    92,     0,     0,     0,     0,   146,     0,     0,
     125,     0,   201,   180,   167,     0,   161,   163,     0,   176,
       0,   174,     0,     0,    44,    24,     0,    22,     0,     0,
       0,   137,     0,   196,     0,     0,     0,     0,     0,   149,
     160,   158,   100,     0,   184,   102,   168,   154,     0,     0,
     151,     0,     0,   121,   126,     0,     0,   132,   134,     0,
     165,   172,   166,   181,     0,   175,   177,   182,     0,   178,
       0,    30,    74,   138,   143,   141,   208,   210,   211,     0,
       0,     0,   187,     0,   152,   153,     0,   150,   120,   135,
     127,     0,     0,   162,   164,   183,   179,     0,     0,   213,
       0,   185,     0,   169,   133,   136,   209,   212,   214,   186,
     188
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    12,    13,    14,    15,    16,    35,
      36,   208,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,   136,    96,   165,
      97,   264,   182,   183,    99,   100,   101,   102,   259,   260,
     261,   306,   307,   103,   237,   238,   104,   184,   185,   186,
     251,   265,   266,   267,   299,   118,   268,   203,   295,   333,
     105,   106,   107,   108,   109,   110,   111,   112,   113
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -239
static const yytype_int16 yypact[] =
{
      30,     0,    54,  -239,    30,    12,  -239,  -239,     6,    70,
    -239,  -239,    99,    22,  -239,  -239,  -239,   597,   143,  -239,
      21,  -239,  -239,  -239,   801,   813,   813,   265,   415,  -239,
    -239,  -239,  -239,  -239,  -239,  -239,   175,   198,   825,  -239,
      91,   173,   240,    92,   238,    95,    96,   102,   188,    19,
    -239,  -239,   160,  -239,   149,  -239,  -239,   415,  -239,   825,
    -239,  -239,   170,  -239,  -239,  -239,  -239,  -239,  -239,  -239,
    -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,
    -239,  -239,    36,   825,   177,   174,   178,   189,   565,   193,
     259,   203,   208,   672,  -239,  -239,    -8,  -239,    14,  1082,
    1082,  -239,    73,  -239,  1082,  -239,  -239,  -239,   340,   461,
    -239,  -239,  -239,  -239,    90,  1103,   -26,  1103,   209,   279,
    -239,  -239,   684,   825,   285,  -239,  -239,  -239,  -239,  -239,
    -239,  -239,  -239,  -239,  -239,  -239,   825,  -239,  -239,   825,
     825,   825,   825,   825,   825,   825,   825,   825,   825,   825,
     825,   825,   825,   825,   825,   825,   825,   825,   825,   825,
     224,   565,   230,   296,  -239,   249,   565,   825,   825,   825,
     275,   698,   268,  -239,  -239,  -239,    -6,  -239,  -239,  -239,
      34,   -13,     3,  -239,   248,    83,    17,  -239,  -239,   272,
    1103,  -239,  -239,  -239,   490,  -239,  -239,  -239,  -239,   923,
     281,    86,  -239,   144,  -239,   825,  -239,  -239,   108,  -239,
     125,  -239,  -239,  -239,  -239,  -239,    91,    91,   173,   173,
     240,   240,   240,   240,    92,    92,   238,    95,    96,   102,
     188,   -43,  -239,  -239,  -239,   296,   250,   -19,  -239,   565,
    -239,   119,   120,   121,   270,   698,  -239,  -239,   284,  -239,
    -239,   -13,  -239,    34,   714,   817,   356,    83,  1103,  1002,
    -239,   142,  -239,  -239,    23,   299,   292,  -239,   300,  -239,
     283,   144,   969,   431,  -239,  -239,   825,  -239,   825,   -14,
     825,  -239,   296,  -239,   565,   565,   565,   825,   726,  -239,
    -239,  -239,  -239,   714,  -239,  -239,  -239,  -239,   307,   126,
    -239,   320,  1031,  -239,  -239,   825,     8,  -239,   328,   877,
    -239,    40,  -239,  -239,  1060,  -239,  -239,  -239,   338,  -239,
     339,  -239,  -239,  -239,  -239,  -239,   354,  -239,  -239,   128,
     565,   138,  -239,    -2,  -239,  -239,   406,  -239,  -239,  -239,
    -239,   142,   825,  -239,  -239,  -239,  -239,   565,   346,  -239,
     565,  -239,   581,  -239,  -239,  -239,  -239,  -239,  -239,  -239,
    -239
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -239,  -239,   407,    33,   418,  -239,  -239,  -239,   408,  -239,
    -239,  -239,   -24,  -239,   -28,   115,   116,    81,   114,   289,
     274,   288,   290,   291,  -239,   -67,  -113,  -239,    -9,  -171,
     336,    39,  -239,   195,  -239,   -22,  -239,  -239,   191,  -238,
     -16,  -239,   105,  -239,   233,   190,   -25,  -167,  -175,  -111,
    -239,  -221,  -239,   157,  -239,   416,   -98,  -174,  -149,  -239,
     -84,  -239,   457,  -239,   367,  -164,  -239,  -239,  -239
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      58,    60,    61,   117,   170,   201,   115,   245,    52,   209,
     138,   257,   116,   248,   137,     8,   164,   178,   202,   114,
     178,   304,   278,   212,     8,   196,   178,   271,   158,   270,
      77,    78,   117,     1,   298,   115,   156,   178,    11,   162,
     199,   116,   200,   178,   281,   232,     9,   181,   114,   323,
     114,   318,   282,    11,     6,     9,   177,   282,   247,   137,
     181,   351,     5,   158,   304,   158,    98,   252,     5,   352,
     250,    17,   340,    18,   253,    10,   189,   234,   179,   341,
     180,   288,   240,   180,   176,   301,    20,   181,   201,   309,
     117,   200,   117,   115,   308,   115,   181,   310,   163,   198,
     180,   204,   320,   157,   146,   147,   309,   181,   200,   324,
     196,   213,   214,   215,   210,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   164,   339,   190,   257,   271,   187,   188,
     291,   294,   248,   191,   332,   178,    54,    98,   231,   255,
      52,   256,   199,   311,   200,   283,   249,   197,   241,   242,
     243,   158,    19,   321,   139,   117,   312,   152,   115,   140,
     141,   355,   148,   149,   308,   275,   137,   274,   153,   276,
     294,   137,   119,   120,   121,   154,   284,   285,   286,   164,
     158,   158,   158,   335,   277,   348,   158,   336,   311,   158,
     326,   327,   328,   360,   155,   350,   164,   305,   180,   158,
     272,   322,   273,   164,   159,   181,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   290,   220,   221,   222,
     223,   158,   137,   117,   117,   161,   115,   115,   164,   294,
     167,   122,   166,   123,   168,   124,   349,   142,   143,   137,
     144,   145,   150,   151,   137,   169,   137,   216,   217,   171,
     218,   219,   172,   356,   224,   225,   358,   173,    62,    22,
      23,    24,   174,    25,    26,   164,   205,   117,   329,   331,
     115,   137,   206,   135,    21,    22,    23,    24,   211,    25,
      26,   233,   235,    63,    64,    65,    66,    67,    68,   236,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   239,    83,    84,    85,   137,    86,
      87,    88,    89,    90,    91,    92,    93,    27,    94,    95,
     244,    28,   246,   254,   258,   280,   287,    29,    30,    31,
      32,    33,    34,    62,    22,    23,    24,    28,    25,    26,
     269,   289,   316,    29,    30,    31,    32,    33,    34,    21,
      22,    23,    24,   314,    25,    26,   313,   315,    63,    64,
      65,    66,    67,    68,   334,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   337,
      83,    84,    85,   342,    86,    87,    88,    89,    90,    91,
      92,    93,    27,   192,    95,   345,    28,   347,   346,   353,
     357,     7,    29,    30,    31,    32,    33,    34,    21,    22,
      23,    24,    28,    25,    26,   300,    55,   227,    29,    30,
      31,    32,    33,    34,    21,    22,    23,    24,    56,    25,
      26,   226,   228,    63,   193,   229,   354,   230,   292,   302,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    62,    22,    23,    24,   279,    25,
      26,   344,   325,   160,    53,   194,     0,     0,     0,     0,
       0,    28,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    62,    22,    23,    24,    28,    25,    26,
     319,     0,     0,    29,    30,    31,    32,    33,    34,     0,
       0,    83,    84,    85,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    27,   195,    95,     0,    28,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,     0,
      83,    84,    85,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    27,   262,    95,     0,    28,     0,     0,     0,
       0,     0,    29,    30,    31,    32,    33,    34,    62,    22,
      23,    24,     0,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,    22,    23,    24,     0,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    22,    23,    24,     0,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    27,     0,    95,
       0,    28,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,   293,   359,     0,     0,    28,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    27,
       0,     0,     0,    28,     0,     0,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    21,    22,    23,    24,     0,
      25,    26,     0,     0,     0,     0,     0,    21,    22,    23,
      24,     0,    25,    26,     0,     0,     0,     0,     0,     0,
       0,    21,    22,    23,    24,     0,    25,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    22,    23,
      24,     0,    25,    26,     0,     0,     0,     0,     0,    21,
      22,    23,    24,     0,    25,    26,   175,     0,    28,     0,
       0,     0,     0,     0,    29,    30,    31,    32,    33,    34,
      28,   207,     0,     0,     0,     0,    29,    30,    31,    32,
      33,    34,    95,     0,    28,     0,     0,     0,     0,     0,
      29,    30,    31,    32,    33,    34,   293,     0,     0,     0,
      28,     0,     0,     0,     0,     0,    29,    30,    31,    32,
      33,    34,    28,   330,     0,     0,     0,     0,    29,    30,
      31,    32,    33,    34,    21,    22,    23,    24,     0,    25,
      26,     0,     0,     0,     0,     0,    21,    22,    23,    24,
     296,    25,    26,     0,     0,     0,     0,     0,    21,    22,
      23,    24,     0,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,    57,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    59,
     178,     0,     0,     0,   297,    29,    30,    31,    32,    33,
      34,    28,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,     0,     0,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   309,   263,   200,     0,     0,     0,     0,
     181,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   199,
     263,   200,     0,     0,     0,     0,   181,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,     0,     0,     0,     0,   317,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,     0,     0,     0,     0,   303,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,   338,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   343,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    63,     0,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82
};

static const yytype_int16 yycheck[] =
{
      24,    25,    26,    28,    88,   116,    28,   171,    17,   122,
      38,   186,    28,   180,    38,     3,    83,     3,   116,    28,
       3,   259,    65,   136,     3,   109,     3,   201,    71,   200,
      43,    44,    57,     3,   255,    57,    17,     3,     5,     3,
      66,    57,    68,     3,    63,   158,    34,    73,    57,    63,
      59,   272,    71,    20,     0,    34,    64,    71,    64,    83,
      73,    63,    62,    71,   302,    71,    27,    64,    62,    71,
     181,    65,    64,     3,    71,    63,     3,   161,    64,    71,
      66,   245,   166,    66,    93,   256,    64,    73,   199,    66,
     115,    68,   117,   115,   261,   117,    73,   264,    62,   115,
      66,   117,   273,    84,    12,    13,    66,    73,    68,   280,
     194,   139,   140,   141,   123,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   200,   305,    62,   311,   311,    99,   100,
     251,   254,   309,   104,   293,     3,     3,   108,   157,    66,
     159,    68,    66,   264,    68,   239,   181,    67,   167,   168,
     169,    71,    63,   276,    73,   190,   264,    72,   190,    78,
      79,   342,    80,    81,   341,    67,   200,   205,    82,    71,
     293,   205,     7,     8,     9,    83,    67,    67,    67,   256,
      71,    71,    71,    67,    69,    67,    71,    71,   309,    71,
     284,   285,   286,   352,    16,    67,   273,    65,    66,    71,
      66,   278,    68,   280,    65,    73,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   251,   146,   147,   148,
     149,    71,   256,   258,   259,    65,   258,   259,   305,   352,
      66,    66,    65,    68,    66,    70,   330,    74,    75,   273,
      10,    11,    14,    15,   278,    66,   280,   142,   143,    66,
     144,   145,     3,   347,   150,   151,   350,    64,     3,     4,
       5,     6,    64,     8,     9,   342,    67,   302,   287,   288,
     302,   305,     3,    85,     3,     4,     5,     6,     3,     8,
       9,    67,    62,    28,    29,    30,    31,    32,    33,     3,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    65,    50,    51,    52,   342,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      55,    66,    64,    85,    62,    85,    66,    72,    73,    74,
      75,    76,    77,     3,     4,     5,     6,    66,     8,     9,
      69,    67,    69,    72,    73,    74,    75,    76,    77,     3,
       4,     5,     6,    71,     8,     9,    67,    67,    28,    29,
      30,    31,    32,    33,    67,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    69,
      50,    51,    52,    65,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    67,    66,    53,    69,     3,
      64,     4,    72,    73,    74,    75,    76,    77,     3,     4,
       5,     6,    66,     8,     9,    69,    18,   153,    72,    73,
      74,    75,    76,    77,     3,     4,     5,     6,    20,     8,
       9,   152,   154,    28,   108,   155,   341,   156,   253,   258,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     3,     4,     5,     6,   235,     8,
       9,   314,   282,    57,    17,   108,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,     3,     4,     5,     6,    66,     8,     9,
      69,    -1,    -1,    72,    73,    74,    75,    76,    77,    -1,
      -1,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,    -1,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    62,    63,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,    62,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    64,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
      66,    67,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    77,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    77,    62,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    77,    66,    67,    -1,    -1,    -1,    -1,    72,    73,
      74,    75,    76,    77,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       3,     8,     9,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,    66,
       3,    -1,    -1,    -1,    67,    72,    73,    74,    75,    76,
      77,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      73,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    73,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    67,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    63,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    63,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    87,    88,    89,    62,     0,    88,     3,    34,
      63,    89,    90,    91,    92,    93,    94,    65,     3,    63,
      64,     3,     4,     5,     6,     8,     9,    62,    66,    72,
      73,    74,    75,    76,    77,    95,    96,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   114,   148,     3,    94,    90,    66,    98,    66,
      98,    98,     3,    28,    29,    30,    31,    32,    33,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    50,    51,    52,    54,    55,    56,    57,
      58,    59,    60,    61,    63,    64,   114,   116,   117,   120,
     121,   122,   123,   129,   132,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   114,   121,   126,   132,   141,     7,
       8,     9,    66,    68,    70,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    85,   113,    98,   100,    73,
      78,    79,    74,    75,    10,    11,    12,    13,    80,    81,
      14,    15,    72,    82,    83,    16,    17,    84,    71,    65,
     141,    65,     3,    62,   111,   115,    65,    66,    66,    66,
     146,    66,     3,    64,    64,    64,   114,    64,     3,    64,
      66,    73,   118,   119,   133,   134,   135,   117,   117,     3,
      62,   117,    63,   116,   150,    63,   146,    67,   126,    66,
      68,   135,   142,   143,   126,    67,     3,    67,    97,   112,
     114,     3,   112,   100,   100,   100,   101,   101,   102,   102,
     103,   103,   103,   103,   104,   104,   105,   106,   107,   108,
     109,   114,   112,    67,   146,    62,     3,   130,   131,    65,
     146,   114,   114,   114,    55,   151,    64,    64,   133,   132,
     135,   136,    64,    71,    85,    66,    68,   134,    62,   124,
     125,   126,    63,    67,   117,   137,   138,   139,   142,    69,
     115,   143,    66,    68,   100,    67,    71,    69,    65,   130,
      85,    63,    71,   146,    67,    67,    67,    66,   151,    67,
     132,   135,   119,    62,   112,   144,     3,    67,   137,   140,
      69,   115,   124,    63,   125,    65,   127,   128,   133,    66,
     133,   135,   142,    67,    71,    67,    69,    67,   137,    69,
     115,   112,   111,    63,   115,   131,   146,   146,   146,   114,
      67,   114,   144,   145,    67,    67,    71,    69,    63,   115,
      64,    71,    65,    49,   139,    67,    69,    53,    67,   146,
      67,    63,    71,     3,   128,   115,   146,    64,   146,    63,
     144
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 26 "cqml_grammar.g"
    {  makeParseTree((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 31 "cqml_grammar.g"
    { (yyval.data.val) = createList( (yyvsp[(1) - (2)].data.val) , 'L', (yyvsp[(2) - (2)].data.val), 0); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 33 "cqml_grammar.g"
    { (yyval.data.val) = createList( (yyvsp[(1) - (1)].data.val) , 'l', 0, 0);  ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 38 "cqml_grammar.g"
    { (yyval.data.val) = createElement( (yyvsp[(1) - (4)].data.val) , 'R', (yyvsp[(3) - (4)].data.val), (yyvsp[(1) - (4)].data.lexem) ); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 40 "cqml_grammar.g"
    { (yyval.data.val) = createElement( (yyvsp[(1) - (3)].data.val) , 'r', 0, (yyvsp[(1) - (3)].data.lexem)); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 45 "cqml_grammar.g"
    { (yyval.data.val) = createList( (yyvsp[(1) - (3)].data.val) , 'L', (yyvsp[(3) - (3)].data.val), 0); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 47 "cqml_grammar.g"
    { (yyval.data.val) = createList( (yyvsp[(1) - (2)].data.val) , 'l', 0, 0);  ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 53 "cqml_grammar.g"
    { (yyval.data.val) = (yyvsp[(1) - (1)].data.val); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 55 "cqml_grammar.g"
    { (yyval.data.val) = (yyvsp[(1) - (1)].data.val); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 57 "cqml_grammar.g"
    { (yyval.data.val) = (yyvsp[(1) - (1)].data.val); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 59 "cqml_grammar.g"
    { (yyval.data.val) = (yyvsp[(1) - (1)].data.val); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 64 "cqml_grammar.g"
    { (yyval.data.val) = createHandler( (yyvsp[(1) - (3)].data.val) , 'l', (yyvsp[(1) - (3)].data.lexem), (yyvsp[(3) - (3)].data.val));  ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 69 "cqml_grammar.g"
    { (yyval.data.val) = createPropertyInit( (yyvsp[(2) - (3)].data.val) , (yyvsp[(3) - (3)].data.val) , (yyvsp[(2) - (3)].data.lexem));  ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 71 "cqml_grammar.g"
    { (yyval.data.val) = createProperty( (yyvsp[(2) - (3)].data.val) , (yyvsp[(2) - (3)].data.lexem) , (yyvsp[(3) - (3)].data.lexem));  ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 76 "cqml_grammar.g"
    { (yyval.data.val) = createAttribute( (yyvsp[(1) - (3)].data.val) , 'l', (yyvsp[(1) - (3)].data.lexem), (yyvsp[(3) - (3)].data.val));  ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 81 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0ID((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 83 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 85 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 87 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val) ,MakeNode0(")")); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 92 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 94 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("["), (yyvsp[(3) - (4)].data.val),MakeNode0("]")); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 96 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("(") ,MakeNode0(")")); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 98 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 100 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3Dot((yyvsp[(1) - (3)].data.val), MakeNode0("."), MakeNode0ID((yyvsp[(3) - (3)].data.lexem))); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 102 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), MakeNode0ID((yyvsp[(3) - (3)].data.lexem))); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 104 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0((yyvsp[(2) - (2)].data.lexem))); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 106 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0((yyvsp[(2) - (2)].data.lexem))); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 111 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 113 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 118 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 120 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 122 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 124 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 126 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 128 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4(MakeNode0((yyvsp[(1) - (4)].data.lexem)), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 133 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("&"); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 135 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("*"); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 137 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("+"); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 139 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("-"); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 141 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("~"); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 143 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("!"); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 148 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 150 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4(MakeNode0("("), (yyvsp[(2) - (4)].data.val), MakeNode0(")"), (yyvsp[(4) - (4)].data.val)); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 156 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 158 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("*"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 160 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("/"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 162 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("%"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 167 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 169 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("+"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 171 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("-"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 176 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 178 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 180 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 185 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 187 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("<"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 189 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(">"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 191 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 193 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 198 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 200 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 202 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 207 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 209 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("&"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 214 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 216 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("^"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 221 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 223 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("|"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 228 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 230 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 235 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 237 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 242 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 244 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (5)].data.val), MakeNode0("?"), MakeNode3((yyvsp[(3) - (5)].data.val), MakeNode0(":"),(yyvsp[(5) - (5)].data.val))); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 249 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 251 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), (yyvsp[(2) - (3)].data.val), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 256 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("="); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 258 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 260 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 262 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 264 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 266 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 268 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 270 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 272 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 274 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 276 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 281 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 283 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 288 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 293 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0(";")); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 295 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), (yyvsp[(2) - (3)].data.val), MakeNode0(";")); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 300 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 302 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 304 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 306 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 308 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 310 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 315 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 317 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 322 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 324 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("="), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 329 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 331 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 333 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 335 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 337 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 342 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 344 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 346 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 348 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 350 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 352 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 354 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 356 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 358 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 360 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 362 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 364 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 423 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 425 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 430 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 432 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 438 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val), MakeNode0(")")); ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 440 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("["), (yyvsp[(3) - (4)].data.val), MakeNode0("]")); ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 442 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("["), MakeNode0("]")); ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 444 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 446 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 448 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("("), MakeNode0(")")); ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 453 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("*"); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 455 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("*"), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 457 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("*"), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 459 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("*"), (yyvsp[(2) - (3)].data.val), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 464 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 466 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 472 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 474 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","),  MakeNode0((yyvsp[(3) - (3)].data.lexem))); ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 479 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 481 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","),  (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 486 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 488 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 490 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 495 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 497 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 507 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 509 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 511 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 516 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val), MakeNode0(")")); ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 518 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("["), MakeNode0("]")); ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 520 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("["), (yyvsp[(2) - (3)].data.val), MakeNode0("]")); ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 522 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("["), MakeNode0("]")); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 524 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("["), (yyvsp[(3) - (4)].data.val), MakeNode0("]")); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 526 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("("), MakeNode0(")")); ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 528 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val), MakeNode0(")")); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 530 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("("), MakeNode0(")")); ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 532 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 537 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 539 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("{"), (yyvsp[(2) - (3)].data.val), MakeNode0("}")); ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 541 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4(MakeNode0("{"), (yyvsp[(2) - (4)].data.val), MakeNode0(","), MakeNode0("}")); ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 546 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 548 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 553 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 555 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 557 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 559 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 561 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 563 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 568 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), MakeNode0(":"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 570 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.lexem), (yyvsp[(2) - (4)].data.val), MakeNode0(":"), (yyvsp[(4) - (4)].data.val)); ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 572 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), MakeNode0(":"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 577 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("{"), MakeNode0("}")); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 579 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("{"), (yyvsp[(2) - (3)].data.val), MakeNode0("}")); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 581 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("{"), (yyvsp[(2) - (3)].data.val), MakeNode0("}")); ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 583 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (4)].data.val), (yyvsp[(2) - (4)].data.val)); ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 588 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 590 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 595 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 597 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 602 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0(";"); ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 604 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0(";")); ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 609 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode5((yyvsp[(1) - (5)].data.lexem), MakeNode0("("), (yyvsp[(3) - (5)].data.val), MakeNode0(")"), (yyvsp[(5) - (5)].data.val)); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 611 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode7((yyvsp[(1) - (7)].data.lexem), MakeNode0("("), (yyvsp[(3) - (7)].data.val), MakeNode0(")"), (yyvsp[(5) - (7)].data.val), (yyvsp[(6) - (7)].data.lexem), (yyvsp[(7) - (7)].data.val)); ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 613 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode5((yyvsp[(1) - (5)].data.lexem), MakeNode0("("), (yyvsp[(3) - (5)].data.val), MakeNode0(")"), (yyvsp[(5) - (5)].data.val)); ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 618 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode5((yyvsp[(1) - (5)].data.lexem), MakeNode0("("), (yyvsp[(3) - (5)].data.val), MakeNode0(")"), (yyvsp[(5) - (5)].data.val)); ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 620 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode7((yyvsp[(1) - (7)].data.lexem), (yyvsp[(2) - (7)].data.val), (yyvsp[(3) - (7)].data.lexem), MakeNode0("("), (yyvsp[(5) - (7)].data.val), MakeNode0(")"),  MakeNode0(";")); ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 622 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode6((yyvsp[(1) - (6)].data.lexem), MakeNode0("("), (yyvsp[(3) - (6)].data.val), (yyvsp[(4) - (6)].data.val), MakeNode0(")"), (yyvsp[(6) - (6)].data.val)); ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 624 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode7((yyvsp[(1) - (7)].data.lexem), MakeNode0("("), (yyvsp[(3) - (7)].data.val), (yyvsp[(4) - (7)].data.val), (yyvsp[(5) - (7)].data.val), MakeNode0(")"), (yyvsp[(7) - (7)].data.val)); ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 629 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), (yyvsp[(2) - (3)].data.lexem), MakeNode0(";")); ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 631 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.lexem), MakeNode0(";")); ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 633 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.lexem), MakeNode0(";")); ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 635 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.lexem), MakeNode0(";")); ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 637 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), (yyvsp[(2) - (3)].data.val), MakeNode0(";")); ;}
    break;



/* Line 1455 of yacc.c  */
#line 3255 "cqml_grammar.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 665 "cqml_grammar.g"


extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

