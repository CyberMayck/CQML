
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
     IMPORT = 305,
     AS = 306,
     CASE = 307,
     DEFAULT = 308,
     IF = 309,
     ELSE = 310,
     SWITCH = 311,
     WHILE = 312,
     DO = 313,
     FOR = 314,
     GOTO = 315,
     CONTINUE = 316,
     BREAK = 317,
     RETURN = 318
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 16 "cqml_grammar.g"

	struct
	{
	int* val;
	char * lexem;
	} data;



/* Line 214 of yacc.c  */
#line 182 "cqml_grammar.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 194 "cqml_grammar.tab.c"

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  225
/* YYNRULES -- Number of states.  */
#define YYNSTATES  375

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    79,     2,     2,     2,    81,    74,     2,
      69,    70,    75,    76,    73,    77,    68,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    66,
      82,    87,    83,    86,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    71,     2,    72,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,    85,    65,    78,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    15,    20,    25,
      29,    33,    36,    38,    40,    42,    44,    48,    52,    56,
      60,    64,    68,    74,    76,    78,    80,    84,    86,    91,
      95,   100,   104,   108,   111,   114,   116,   120,   122,   125,
     128,   131,   134,   139,   141,   143,   145,   147,   149,   151,
     153,   158,   160,   164,   168,   172,   174,   178,   182,   184,
     188,   192,   194,   198,   202,   206,   210,   212,   216,   220,
     222,   226,   228,   232,   234,   238,   240,   244,   246,   250,
     252,   258,   260,   264,   266,   268,   270,   272,   274,   276,
     278,   280,   282,   284,   286,   288,   292,   294,   297,   301,
     303,   306,   308,   311,   313,   316,   318,   322,   324,   328,
     330,   332,   334,   336,   338,   340,   342,   344,   346,   348,
     350,   352,   354,   356,   358,   360,   362,   368,   373,   376,
     378,   380,   382,   385,   389,   392,   394,   397,   399,   401,
     405,   407,   410,   414,   419,   425,   428,   430,   434,   436,
     440,   442,   444,   447,   449,   451,   455,   460,   464,   469,
     474,   478,   480,   483,   486,   490,   492,   495,   497,   501,
     503,   507,   510,   513,   515,   517,   521,   523,   526,   528,
     530,   533,   537,   540,   544,   548,   553,   556,   560,   564,
     569,   571,   575,   580,   582,   586,   588,   590,   592,   594,
     596,   598,   602,   607,   611,   614,   618,   622,   627,   629,
     632,   634,   637,   639,   642,   648,   656,   662,   668,   676,
     683,   691,   695,   698,   701,   704
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      89,     0,    -1,    90,    -1,    91,    93,    -1,    93,    -1,
      92,    91,    -1,    92,    -1,    50,     5,    51,     3,    -1,
       3,    64,    94,    65,    -1,     3,    64,    65,    -1,    95,
      66,    94,    -1,    95,    66,    -1,    93,    -1,    96,    -1,
      98,    -1,    97,    -1,     3,    67,   152,    -1,    34,     3,
      98,    -1,    34,   125,    98,    -1,    34,     3,     3,    -1,
      34,   125,     3,    -1,     3,    67,   118,    -1,     3,    68,
       3,    67,   118,    -1,     3,    -1,     4,    -1,     5,    -1,
      69,   118,    70,    -1,    99,    -1,   100,    71,   118,    72,
      -1,   100,    69,    70,    -1,   100,    69,   101,    70,    -1,
     100,    68,     3,    -1,   100,     7,     3,    -1,   100,     8,
      -1,   100,     9,    -1,   116,    -1,   101,    73,   116,    -1,
     100,    -1,     8,   102,    -1,     9,   102,    -1,   103,   104,
      -1,     6,   102,    -1,     6,    69,   145,    70,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,   102,    -1,    69,   145,    70,   104,    -1,   104,    -1,
     105,    75,   104,    -1,   105,    80,   104,    -1,   105,    81,
     104,    -1,   105,    -1,   106,    76,   105,    -1,   106,    77,
     105,    -1,   106,    -1,   107,    10,   106,    -1,   107,    11,
     106,    -1,   107,    -1,   108,    82,   107,    -1,   108,    83,
     107,    -1,   108,    12,   107,    -1,   108,    13,   107,    -1,
     108,    -1,   109,    14,   108,    -1,   109,    15,   108,    -1,
     109,    -1,   110,    74,   109,    -1,   110,    -1,   111,    84,
     110,    -1,   111,    -1,   112,    85,   111,    -1,   112,    -1,
     113,    16,   112,    -1,   113,    -1,   114,    17,   113,    -1,
     114,    -1,   114,    86,   118,    67,   115,    -1,   115,    -1,
     102,   117,   116,    -1,    87,    -1,    18,    -1,    19,    -1,
      20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,
      25,    -1,    26,    -1,    27,    -1,   116,    -1,   118,    73,
     116,    -1,   115,    -1,   121,    66,    -1,   121,   122,    66,
      -1,   124,    -1,   124,   121,    -1,   125,    -1,   125,   121,
      -1,   136,    -1,   136,   121,    -1,   123,    -1,   122,    73,
     123,    -1,   137,    -1,   137,    87,   148,    -1,    29,    -1,
      30,    -1,    31,    -1,    32,    -1,    33,    -1,    45,    -1,
      35,    -1,    36,    -1,    37,    -1,    38,    -1,    41,    -1,
      42,    -1,    39,    -1,    40,    -1,   126,    -1,   133,    -1,
      28,    -1,   127,     3,    64,   128,    65,    -1,   127,    64,
     128,    65,    -1,   127,     3,    -1,    46,    -1,    47,    -1,
     129,    -1,   128,   129,    -1,   130,   131,    66,    -1,   125,
     130,    -1,   125,    -1,   136,   130,    -1,   136,    -1,   132,
      -1,   131,    73,   132,    -1,   137,    -1,    67,   119,    -1,
     137,    67,   119,    -1,    48,    64,   134,    65,    -1,    48,
       3,    64,   134,    65,    -1,    48,     3,    -1,   135,    -1,
     134,    73,   135,    -1,     3,    -1,     3,    87,   119,    -1,
      43,    -1,    44,    -1,   139,   138,    -1,   138,    -1,     3,
      -1,    69,   137,    70,    -1,   138,    71,   119,    72,    -1,
     138,    71,    72,    -1,   138,    69,   141,    70,    -1,   138,
      69,   144,    70,    -1,   138,    69,    70,    -1,    75,    -1,
      75,   140,    -1,    75,   139,    -1,    75,   140,   139,    -1,
     136,    -1,   140,   136,    -1,   142,    -1,   142,    73,    49,
      -1,   143,    -1,   142,    73,   143,    -1,   121,   137,    -1,
     121,   146,    -1,   121,    -1,     3,    -1,   144,    73,     3,
      -1,   130,    -1,   130,   146,    -1,   139,    -1,   147,    -1,
     139,   147,    -1,    69,   146,    70,    -1,    71,    72,    -1,
      71,   119,    72,    -1,   147,    71,    72,    -1,   147,    71,
     119,    72,    -1,    69,    70,    -1,    69,   141,    70,    -1,
     147,    69,    70,    -1,   147,    69,   141,    70,    -1,   116,
      -1,    64,   149,    65,    -1,    64,   149,    73,    65,    -1,
     148,    -1,   149,    73,   148,    -1,   151,    -1,   152,    -1,
     155,    -1,   156,    -1,   157,    -1,   158,    -1,     3,    67,
     150,    -1,    52,   119,    67,   150,    -1,    53,    67,   150,
      -1,    64,    65,    -1,    64,   154,    65,    -1,    64,   153,
      65,    -1,    64,   153,   154,    65,    -1,   120,    -1,   153,
     120,    -1,   150,    -1,   154,   150,    -1,    66,    -1,   118,
      66,    -1,    54,    69,   118,    70,   150,    -1,    54,    69,
     118,    70,   150,    55,   150,    -1,    56,    69,   118,    70,
     150,    -1,    57,    69,   118,    70,   150,    -1,    58,   150,
      57,    69,   118,    70,    66,    -1,    59,    69,   155,   155,
      70,   150,    -1,    59,    69,   155,   155,   118,    70,   150,
      -1,    60,     3,    66,    -1,    61,    66,    -1,    62,    66,
      -1,    63,    66,    -1,    63,   118,    66,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    26,    26,    31,    33,    38,    40,    45,    50,    52,
      57,    59,    65,    67,    69,    71,    76,    81,    83,    85,
      87,    92,    94,    99,   101,   103,   105,   110,   112,   114,
     116,   118,   120,   122,   124,   129,   131,   136,   138,   140,
     142,   144,   146,   151,   153,   155,   157,   159,   161,   166,
     168,   174,   176,   178,   180,   185,   187,   189,   194,   196,
     198,   203,   205,   207,   209,   211,   216,   218,   220,   225,
     227,   232,   234,   239,   241,   246,   248,   253,   255,   260,
     262,   267,   269,   274,   276,   278,   280,   282,   284,   286,
     288,   290,   292,   294,   299,   301,   306,   311,   313,   318,
     320,   322,   324,   326,   328,   333,   335,   340,   342,   347,
     349,   351,   353,   355,   360,   362,   364,   366,   368,   370,
     372,   374,   376,   378,   380,   382,   387,   388,   389,   393,
     394,   398,   399,   403,   407,   408,   409,   410,   414,   415,
     419,   420,   421,   425,   426,   427,   431,   432,   436,   437,
     441,   443,   448,   450,   455,   456,   458,   460,   462,   464,
     466,   471,   473,   475,   477,   482,   484,   490,   492,   497,
     499,   504,   506,   508,   513,   515,   520,   521,   525,   527,
     529,   534,   536,   538,   540,   542,   544,   546,   548,   550,
     555,   557,   559,   564,   566,   571,   573,   575,   577,   579,
     581,   586,   588,   590,   595,   597,   599,   601,   606,   608,
     613,   615,   620,   622,   627,   629,   631,   636,   638,   640,
     642,   647,   649,   651,   653,   655
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
  "ENUM", "ELLIPSIS", "IMPORT", "AS", "CASE", "DEFAULT", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN",
  "'{'", "'}'", "';'", "':'", "'.'", "'('", "')'", "'['", "']'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "'='", "$accept", "start_point",
  "element_or_import_list", "import_list", "import", "element",
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
     315,   316,   317,   318,   123,   125,    59,    58,    46,    40,
      41,    91,    93,    44,    38,    42,    43,    45,   126,    33,
      47,    37,    60,    62,    94,   124,    63,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    90,    91,    91,    92,    93,    93,
      94,    94,    95,    95,    95,    95,    96,    97,    97,    97,
      97,    98,    98,    99,    99,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   100,   101,   101,   102,   102,   102,
     102,   102,   102,   103,   103,   103,   103,   103,   103,   104,
     104,   105,   105,   105,   105,   106,   106,   106,   107,   107,
     107,   108,   108,   108,   108,   108,   109,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   118,   118,   119,   120,   120,   121,
     121,   121,   121,   121,   121,   122,   122,   123,   123,   124,
     124,   124,   124,   124,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   126,   126,   126,   127,
     127,   128,   128,   129,   130,   130,   130,   130,   131,   131,
     132,   132,   132,   133,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   138,   138,   138,   138,   138,   138,
     138,   139,   139,   139,   139,   140,   140,   141,   141,   142,
     142,   143,   143,   143,   144,   144,   145,   145,   146,   146,
     146,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     148,   148,   148,   149,   149,   150,   150,   150,   150,   150,
     150,   151,   151,   151,   152,   152,   152,   152,   153,   153,
     154,   154,   155,   155,   156,   156,   156,   157,   157,   157,
     157,   158,   158,   158,   158,   158
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     4,     4,     3,
       3,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     5,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     3,     1,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       2,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       1,     1,     2,     3,     2,     1,     2,     1,     1,     3,
       1,     2,     3,     4,     5,     2,     1,     3,     1,     3,
       1,     1,     2,     1,     1,     3,     4,     3,     4,     4,
       3,     1,     2,     2,     3,     1,     2,     1,     3,     1,
       3,     2,     2,     1,     1,     3,     1,     2,     1,     1,
       2,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     3,     2,     2,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     0,     6,     4,     0,     0,
       1,     3,     5,     0,     0,     9,    12,     0,     0,    13,
      15,    14,     0,     0,     0,     0,   125,   115,   116,   117,
     118,   121,   122,   119,   120,   114,   129,   130,     0,     0,
     123,     0,   124,     8,    11,     7,    23,    24,    25,     0,
       0,     0,     0,     0,    43,    44,    45,    46,    47,    48,
      27,    37,    49,     0,    51,    55,    58,    61,    66,    69,
      71,    73,    75,    77,    79,    81,    94,    21,    16,     0,
      19,    17,   145,     0,    20,    18,   128,     0,    10,     0,
      41,     0,    38,    39,    23,   109,   110,   111,   112,   113,
     150,   151,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   204,   212,     0,   208,     0,    99,   101,
     103,   210,   195,   196,     0,     0,   197,   198,   199,   200,
       0,   135,   176,   137,     0,     0,    33,    34,     0,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    83,     0,    49,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,     0,
     146,     0,     0,   131,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,     0,
     213,   154,    97,     0,   161,     0,   105,   107,   153,     0,
     100,   102,   104,   206,   209,     0,   205,   211,    26,   134,
       0,     0,   178,   177,   179,   136,     0,    32,    31,    29,
       0,    35,     0,    82,    52,    53,    54,    56,    57,    59,
      60,    64,    65,    62,    63,    67,    68,    70,    72,    74,
      76,    78,     0,    95,    22,     0,     0,   143,     0,     0,
     127,   132,     0,     0,   138,   140,    42,   201,     0,   203,
       0,     0,     0,     0,     0,   221,   225,     0,   165,   163,
     162,    98,     0,     0,     0,     0,   152,   207,   186,   173,
       0,   167,   169,     0,   182,     0,   180,     0,     0,    50,
      30,     0,    28,     0,   144,   149,   147,   126,   141,   133,
       0,     0,   202,     0,     0,     0,     0,     0,   155,   166,
     164,   106,     0,   190,   108,   174,   160,     0,     0,   157,
       0,     0,   171,   178,   172,   187,     0,   181,   183,   188,
       0,   184,     0,    36,    80,   139,   142,   214,   216,   217,
       0,     0,     0,   193,     0,   158,   159,     0,   156,   168,
     170,   189,   185,     0,     0,   219,     0,   191,     0,   175,
     215,   218,   220,   192,   194
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    16,    17,    18,    19,    20,
      21,    60,    61,   230,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,   152,
     115,   188,   116,   289,   205,   206,   118,   119,    40,    41,
     182,   183,   184,   263,   264,    42,   179,   180,   120,   207,
     208,   209,   280,   290,   291,   292,   328,   134,   293,   224,
     324,   354,   121,   122,   123,   124,   125,   126,   127,   128,
     129
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -305
static const yytype_int16 yypact[] =
{
      19,   -25,    52,    70,  -305,    94,    63,  -305,    45,    91,
    -305,  -305,  -305,   137,   799,  -305,  -305,    82,   145,  -305,
    -305,  -305,   155,   607,   211,   229,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,    28,   233,
    -305,    47,  -305,  -305,    22,  -305,  -305,  -305,  -305,   747,
     795,   795,   267,   421,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,   166,   172,   806,  -305,   101,   174,   242,    32,   241,
     184,   180,   182,   263,    -8,  -305,  -305,   216,  -305,   217,
     195,  -305,   228,   298,   195,  -305,   252,  1101,  -305,   421,
    -305,   806,  -305,  -305,   250,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,   806,   251,   253,   265,   266,   575,   268,   335,
     273,   274,   362,  -305,  -305,   -15,  -305,    79,  1080,  1080,
    1080,  -305,  -305,  -305,   344,   467,  -305,  -305,  -305,  -305,
     -32,  1101,   146,  1101,   285,   359,  -305,  -305,   360,   439,
     806,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,   806,  -305,  -305,   806,   806,   806,   806,   806,
     806,   806,   806,   806,   806,   806,   806,   806,   806,   806,
     806,   806,   806,   806,   806,   806,   806,   298,   277,   -11,
    -305,  1101,   996,  -305,    74,   299,   575,  -305,   311,   575,
     806,   806,   806,   336,   669,   328,  -305,  -305,  -305,   -13,
    -305,  -305,  -305,    37,   -20,     1,  -305,   308,   153,    18,
    -305,  -305,  -305,  -305,  -305,   498,  -305,  -305,  -305,  -305,
     927,   282,   175,  -305,   178,  -305,   806,  -305,  -305,  -305,
      93,  -305,   196,  -305,  -305,  -305,  -305,   101,   101,   174,
     174,   242,   242,   242,   242,    32,    32,   241,   184,   180,
     182,   263,   -38,  -305,   216,     8,   806,  -305,   298,  1027,
    -305,  -305,   806,   106,  -305,   332,  -305,  -305,   575,  -305,
     113,   133,   150,   342,   669,  -305,  -305,   345,  -305,  -305,
     -20,  -305,    37,   685,   906,   696,   153,  -305,  -305,   141,
     346,   339,  -305,   347,  -305,   361,   178,   975,   707,  -305,
    -305,   806,  -305,   806,  -305,  -305,  -305,  -305,  -305,  -305,
      74,   806,  -305,   575,   575,   575,   806,   718,  -305,  -305,
    -305,  -305,   685,  -305,  -305,  -305,  -305,   364,   168,  -305,
     363,   858,  -305,    25,  -305,  -305,  1058,  -305,  -305,  -305,
     376,  -305,   378,  -305,  -305,  -305,  -305,   377,  -305,  -305,
     169,   575,   170,  -305,    92,  -305,  -305,   411,  -305,  -305,
    -305,  -305,  -305,   575,   385,  -305,   575,  -305,   591,  -305,
    -305,  -305,  -305,  -305,  -305
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -305,  -305,  -305,   446,  -305,    71,   409,  -305,  -305,  -305,
       7,  -305,  -305,  -305,   -37,  -305,   -56,   119,   120,    65,
     116,   286,   305,   307,   284,   306,  -305,   -85,  -137,  -305,
     -23,  -213,   355,   -16,  -305,   198,  -305,     6,  -305,  -305,
     300,  -171,   -47,  -305,   173,  -305,   309,   224,   -26,  -151,
    -193,  -129,  -305,  -250,  -305,   148,  -305,   396,  -128,  -217,
    -304,  -305,  -106,  -305,   464,  -305,   365,  -184,  -305,  -305,
    -305
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      77,   193,   231,   222,   223,   296,   132,   154,   295,   172,
     274,   261,    90,    92,    93,   233,   286,   187,   353,   217,
      39,   201,     1,   100,   101,    13,   153,   133,   201,   303,
     130,    82,    81,   265,   327,   174,   117,   253,   218,     8,
     201,   174,   132,   305,   162,   163,    85,   340,    13,   308,
      86,   200,   277,   276,   257,   204,    14,     9,   174,   131,
     174,   133,   258,   133,   374,   153,   130,   281,   130,     2,
      10,     7,   330,   304,   282,   279,    11,   201,   173,    14,
     267,   258,   201,   269,   219,   342,   225,   203,   261,   199,
     317,   222,    83,   131,   331,   131,   221,     1,   346,   234,
     235,   236,   210,   211,   212,   133,   203,   133,   117,   217,
      15,    87,   204,     2,   164,   165,   296,   232,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   187,   131,   332,   131,
     286,   262,    22,   203,   201,   202,   323,    43,   203,   204,
     252,   320,   254,    77,   204,   133,   133,   367,    45,   265,
     333,   334,   312,   300,   343,   368,   301,   270,   271,   272,
     299,   187,   309,   135,   136,   137,   155,   187,   278,   310,
     277,   156,   157,   313,   153,   323,   174,   131,   131,   153,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     187,     8,   333,   314,    23,    24,   174,   347,   348,   349,
     331,    44,   221,   187,    79,   220,   204,   221,   344,   153,
     315,   204,   284,   174,   285,   153,   187,   241,   242,   243,
     244,   323,    80,   133,   138,   139,    84,   140,   356,   364,
     366,   357,   174,   174,   220,   365,   221,   297,   153,   298,
     158,   159,   160,   161,   319,   166,   167,   370,   168,   151,
     372,   153,   176,    24,   169,   131,   153,   170,   302,   174,
      94,    47,    48,    49,   153,    50,    51,   237,   238,   171,
     239,   240,   245,   246,   175,    46,    47,    48,    49,   174,
      50,    51,   177,   350,   352,    26,    95,    96,    97,    98,
      99,   178,    27,    28,    29,    30,    31,    32,    33,    34,
     100,   101,    35,    36,    37,    38,   181,   186,   189,   102,
     103,   104,   190,   105,   106,   107,   108,   109,   110,   111,
     112,    52,   113,   114,   191,   192,    53,   194,   195,   196,
     197,    54,    55,    56,    57,    58,    59,    94,    47,    48,
      49,    53,    50,    51,   294,   226,    54,    55,    56,    57,
      58,    59,   227,   228,   256,    46,    47,    48,    49,   266,
      50,    51,    26,    95,    96,    97,    98,    99,   268,    27,
      28,    29,    30,    31,    32,    33,    34,   100,   101,    35,
      36,    37,    38,   273,   275,   283,   102,   103,   104,   311,
     105,   106,   107,   108,   109,   110,   111,   112,    52,   213,
     114,   316,   336,    53,   369,   318,   335,   337,    54,    55,
      56,    57,    58,    59,    46,    47,    48,    49,   198,    50,
      51,    53,   363,   338,   355,   358,    54,    55,    56,    57,
      58,    59,    46,    47,    48,    49,   361,    50,    51,    26,
     362,   371,    12,    88,   247,   250,    27,    28,    29,    30,
      31,    32,    33,    34,   100,   101,    35,    36,    37,    38,
      94,    47,    48,    49,   248,    50,    51,   249,   251,   214,
     321,   259,   306,   345,   360,   185,   255,    78,     0,   215,
      53,     0,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    94,    47,    48,    49,     0,    50,    51,    53,   229,
       0,     0,     0,    54,    55,    56,    57,    58,    59,   102,
     103,   104,     0,   105,   106,   107,   108,   109,   110,   111,
     112,    52,   216,   114,     0,     0,    53,     0,     0,     0,
       0,    54,    55,    56,    57,    58,    59,     0,     0,     0,
     102,   103,   104,     0,   105,   106,   107,   108,   109,   110,
     111,   112,    52,   287,   114,     0,     0,    53,     0,     0,
       0,     0,    54,    55,    56,    57,    58,    59,    94,    47,
      48,    49,     0,    50,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,    49,     0,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    47,    48,    49,     0,    50,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
       0,   105,   106,   107,   108,   109,   110,   111,   112,    52,
       0,   114,     0,     0,    53,     0,     0,     0,     0,    54,
      55,    56,    57,    58,    59,   322,   373,     0,     0,     0,
      53,     0,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    52,    46,    47,    48,    49,    53,    50,    51,     0,
       0,    54,    55,    56,    57,    58,    59,     0,    46,    47,
      48,    49,     0,    50,    51,     0,     0,     0,     0,    46,
      47,    48,    49,     0,    50,    51,     0,     0,     0,     0,
      46,    47,    48,    49,     0,    50,    51,     0,     0,     0,
       0,    46,    47,    48,    49,     0,    50,    51,     0,     0,
       0,     0,     0,     0,     0,   114,     0,     0,    53,     0,
       0,     0,     0,    54,    55,    56,    57,    58,    59,   322,
      46,    47,    48,    49,    53,    50,    51,     0,     0,    54,
      55,    56,    57,    58,    59,    53,     0,     0,   329,     0,
      54,    55,    56,    57,    58,    59,    53,     0,     0,   341,
       0,    54,    55,    56,    57,    58,    59,    53,   351,     0,
       0,     0,    54,    55,    56,    57,    58,    59,    46,    47,
      48,    49,    25,    50,    51,     0,     0,     0,     0,    46,
      47,    48,    49,     0,    50,    51,    89,     0,     0,     0,
       0,    54,    55,    56,    57,    58,    59,    26,     0,     0,
       0,     0,     0,     0,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     0,    35,    36,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,     0,     0,    91,     0,     0,     0,     0,    54,
      55,    56,    57,    58,    59,    53,     0,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    26,    95,    96,    97,
      98,    99,     0,    27,    28,    29,    30,    31,    32,    33,
      34,   100,   101,    35,    36,    37,    38,     0,     0,   325,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   331,   288,   221,
       0,     0,     0,   204,    26,    95,    96,    97,    98,    99,
       0,    27,    28,    29,    30,    31,    32,    33,    34,   100,
     101,    35,    36,    37,    38,    26,    95,    96,    97,    98,
      99,     0,    27,    28,    29,    30,    31,    32,    33,    34,
     100,   101,    35,    36,    37,    38,   326,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   288,   221,     0,
       0,     0,   204,    26,    95,    96,    97,    98,    99,     0,
      27,    28,    29,    30,    31,    32,    33,    34,   100,   101,
      35,    36,    37,    38,    26,     0,     0,     0,     0,     0,
       0,    27,    28,    29,    30,    31,    32,    33,    34,   100,
     101,    35,    36,    37,    38,   339,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,   260,    27,    28,    29,    30,    31,    32,    33,    34,
     100,   101,    35,    36,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,    95,    96,    97,
      98,    99,   307,    27,    28,    29,    30,    31,    32,    33,
      34,   100,   101,    35,    36,    37,    38,   359,    26,    95,
      96,    97,    98,    99,     0,    27,    28,    29,    30,    31,
      32,    33,    34,   100,   101,    35,    36,    37,    38,    26,
       0,     0,     0,     0,     0,     0,    27,    28,    29,    30,
      31,    32,    33,    34,   100,   101,    35,    36,    37,    38
};

static const yytype_int16 yycheck[] =
{
      23,   107,   139,   132,   132,   222,    53,    63,   221,    17,
     194,   182,    49,    50,    51,   152,   209,   102,   322,   125,
      14,     3,     3,    43,    44,     3,    63,    53,     3,    67,
      53,     3,    25,   184,   284,    73,    52,   174,    70,    64,
       3,    73,    89,   256,    12,    13,    39,   297,     3,   262,
       3,    66,   203,    66,    65,    75,    34,     5,    73,    53,
      73,    87,    73,    89,   368,   102,    89,    66,    91,    50,
       0,     0,   285,    65,    73,   204,     5,     3,    86,    34,
     186,    73,     3,   189,   131,   298,   133,    69,   259,   112,
     274,   220,    64,    87,    69,    89,    71,     3,   311,   155,
     156,   157,   118,   119,   120,   131,    69,   133,   124,   215,
      65,    64,    75,    50,    82,    83,   333,   140,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   221,   131,   289,   133,
     333,    67,    51,    69,     3,    66,   283,    65,    69,    75,
     173,   280,   175,   176,    75,   181,   182,    65,     3,   310,
     289,   289,   268,    70,   301,    73,    73,   190,   191,   192,
     226,   256,    66,     7,     8,     9,    75,   262,   204,    73,
     331,    80,    81,    70,   221,   322,    73,   181,   182,   226,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     285,    64,   331,    70,    67,    68,    73,   313,   314,   315,
      69,    66,    71,   298,     3,    69,    75,    71,   303,   256,
      70,    75,    69,    73,    71,   262,   311,   162,   163,   164,
     165,   368,     3,   259,    68,    69,     3,    71,    70,    70,
      70,    73,    73,    73,    69,   351,    71,    69,   285,    71,
      76,    77,    10,    11,   280,    14,    15,   363,    74,    87,
     366,   298,    67,    68,    84,   259,   303,    85,    72,    73,
       3,     4,     5,     6,   311,     8,     9,   158,   159,    16,
     160,   161,   166,   167,    67,     3,     4,     5,     6,    73,
       8,     9,    64,   316,   317,    28,    29,    30,    31,    32,
      33,     3,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    64,    67,    67,    52,
      53,    54,    69,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    69,    69,    69,    69,     3,    66,
      66,    74,    75,    76,    77,    78,    79,     3,     4,     5,
       6,    69,     8,     9,    72,    70,    74,    75,    76,    77,
      78,    79,     3,     3,    87,     3,     4,     5,     6,    70,
       8,     9,    28,    29,    30,    31,    32,    33,    67,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    57,    66,    87,    52,    53,    54,    67,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    69,    73,    69,     3,    70,    70,    70,    74,    75,
      76,    77,    78,    79,     3,     4,     5,     6,    66,     8,
       9,    69,    55,    72,    70,    72,    74,    75,    76,    77,
      78,    79,     3,     4,     5,     6,    70,     8,     9,    28,
      72,    66,     6,    44,   168,   171,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       3,     4,     5,     6,   169,     8,     9,   170,   172,   124,
     282,   181,   258,   310,   336,    89,   177,    23,    -1,   124,
      69,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,     3,     4,     5,     6,    -1,     8,     9,    69,    70,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    -1,    -1,    -1,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    -1,    -1,    69,    -1,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    64,    65,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    64,     3,     4,     5,     6,    69,     8,     9,    -1,
      -1,    74,    75,    76,    77,    78,    79,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    64,
       3,     4,     5,     6,    69,     8,     9,    -1,    -1,    74,
      75,    76,    77,    78,    79,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    77,    78,    79,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    78,    79,    69,    70,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,     3,     4,
       5,     6,     3,     8,     9,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    69,    -1,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    69,    -1,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    69,    -1,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      -1,    -1,    -1,    75,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    -1,
      -1,    -1,    75,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    65,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    65,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    50,    89,    90,    91,    92,    93,    64,     5,
       0,    93,    91,     3,    34,    65,    93,    94,    95,    96,
      97,    98,    51,    67,    68,     3,    28,    35,    36,    37,
      38,    39,    40,    41,    42,    45,    46,    47,    48,   125,
     126,   127,   133,    65,    66,     3,     3,     4,     5,     6,
       8,     9,    64,    69,    74,    75,    76,    77,    78,    79,
      99,   100,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   118,   152,     3,
       3,    98,     3,    64,     3,    98,     3,    64,    94,    69,
     102,    69,   102,   102,     3,    29,    30,    31,    32,    33,
      43,    44,    52,    53,    54,    56,    57,    58,    59,    60,
      61,    62,    63,    65,    66,   118,   120,   121,   124,   125,
     136,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     118,   125,   130,   136,   145,     7,     8,     9,    68,    69,
      71,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    87,   117,   102,   104,    75,    80,    81,    76,    77,
      10,    11,    12,    13,    82,    83,    14,    15,    74,    84,
      85,    16,    17,    86,    73,    67,    67,    64,     3,   134,
     135,    64,   128,   129,   130,   145,    67,   115,   119,    67,
      69,    69,    69,   150,    69,     3,    66,    66,    66,   118,
      66,     3,    66,    69,    75,   122,   123,   137,   138,   139,
     121,   121,   121,    65,   120,   154,    65,   150,    70,   130,
      69,    71,   139,   146,   147,   130,    70,     3,     3,    70,
     101,   116,   118,   116,   104,   104,   104,   105,   105,   106,
     106,   107,   107,   107,   107,   108,   108,   109,   110,   111,
     112,   113,   118,   116,   118,   134,    87,    65,    73,   128,
      65,   129,    67,   131,   132,   137,    70,   150,    67,   150,
     118,   118,   118,    57,   155,    66,    66,   137,   136,   139,
     140,    66,    73,    87,    69,    71,   138,    65,    70,   121,
     141,   142,   143,   146,    72,   119,   147,    69,    71,   104,
      70,    73,    72,    67,    65,   119,   135,    65,   119,    66,
      73,    67,   150,    70,    70,    70,    69,   155,    70,   136,
     139,   123,    64,   116,   148,     3,    70,   141,   144,    72,
     119,    69,   137,   139,   146,    70,    73,    70,    72,    70,
     141,    72,   119,   116,   115,   132,   119,   150,   150,   150,
     118,    70,   118,   148,   149,    70,    70,    73,    72,    49,
     143,    70,    72,    55,    70,   150,    70,    65,    73,     3,
     150,    66,   150,    65,   148
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
#line 27 "cqml_grammar.g"
    {  makeParseTree((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 32 "cqml_grammar.g"
    { (yyval.data.val) = createList( (yyvsp[(2) - (2)].data.val) , 'L', (yyvsp[(1) - (2)].data.val), 0); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 34 "cqml_grammar.g"
    { (yyval.data.val) = createList( (yyvsp[(1) - (1)].data.val) , 'l', 0, 0);  ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 39 "cqml_grammar.g"
    { (yyval.data.val) = createList( (yyvsp[(1) - (2)].data.val) , 'L', (yyvsp[(2) - (2)].data.val), 0); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 41 "cqml_grammar.g"
    { (yyval.data.val) = createList( (yyvsp[(1) - (1)].data.val) , 'l', 0, 0);  ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 46 "cqml_grammar.g"
    { (yyval.data.val) = createImport( (yyvsp[(2) - (4)].data.lexem), (yyvsp[(4) - (4)].data.lexem)); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 51 "cqml_grammar.g"
    { (yyval.data.val) = createElement( (yyvsp[(1) - (4)].data.val) , 'R', (yyvsp[(3) - (4)].data.val), (yyvsp[(1) - (4)].data.lexem) ); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 53 "cqml_grammar.g"
    { (yyval.data.val) = createElement( (yyvsp[(1) - (3)].data.val) , 'r', 0, (yyvsp[(1) - (3)].data.lexem)); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 58 "cqml_grammar.g"
    { (yyval.data.val) = createList( (yyvsp[(1) - (3)].data.val) , 'L', (yyvsp[(3) - (3)].data.val), 0); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 60 "cqml_grammar.g"
    { (yyval.data.val) = createList( (yyvsp[(1) - (2)].data.val) , 'l', 0, 0);  ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 66 "cqml_grammar.g"
    { (yyval.data.val) = (yyvsp[(1) - (1)].data.val); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 68 "cqml_grammar.g"
    { (yyval.data.val) = (yyvsp[(1) - (1)].data.val); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 70 "cqml_grammar.g"
    { (yyval.data.val) = (yyvsp[(1) - (1)].data.val); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 72 "cqml_grammar.g"
    { (yyval.data.val) = (yyvsp[(1) - (1)].data.val); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 77 "cqml_grammar.g"
    { (yyval.data.val) = createHandler( (yyvsp[(1) - (3)].data.val) , 'l', (yyvsp[(1) - (3)].data.lexem), (yyvsp[(3) - (3)].data.val));  ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 82 "cqml_grammar.g"
    { (yyval.data.val) = createPropertyInit( (yyvsp[(2) - (3)].data.val) , (yyvsp[(3) - (3)].data.val) , (yyvsp[(2) - (3)].data.lexem));  ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 84 "cqml_grammar.g"
    { (yyval.data.val) = createPropertyInit( (yyvsp[(2) - (3)].data.val) , (yyvsp[(3) - (3)].data.val) , (yyvsp[(2) - (3)].data.lexem));  ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 86 "cqml_grammar.g"
    { (yyval.data.val) = createProperty( (yyvsp[(2) - (3)].data.val) , (yyvsp[(2) - (3)].data.lexem) , (yyvsp[(3) - (3)].data.lexem));  ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 88 "cqml_grammar.g"
    { (yyval.data.val) = createProperty( (yyvsp[(2) - (3)].data.val) , (yyvsp[(2) - (3)].data.lexem) , (yyvsp[(3) - (3)].data.lexem));  ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 93 "cqml_grammar.g"
    { (yyval.data.val) = createAttribute( (yyvsp[(1) - (3)].data.val) , 'l', (yyvsp[(1) - (3)].data.lexem), (yyvsp[(3) - (3)].data.val));  ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 95 "cqml_grammar.g"
    { (yyval.data.val) = createAttribute2( (yyvsp[(1) - (5)].data.val) , 'l', (yyvsp[(3) - (5)].data.lexem), (yyvsp[(1) - (5)].data.lexem), (yyvsp[(5) - (5)].data.val));  ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 100 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0ID((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 102 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 104 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 106 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val) ,MakeNode0(")")); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 111 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 113 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("["), (yyvsp[(3) - (4)].data.val),MakeNode0("]")); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 115 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("(") ,MakeNode0(")")); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 117 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 119 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3Dot((yyvsp[(1) - (3)].data.val), MakeNode0("."), MakeNode0ID((yyvsp[(3) - (3)].data.lexem))); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 121 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), MakeNode0ID((yyvsp[(3) - (3)].data.lexem))); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 123 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0((yyvsp[(2) - (2)].data.lexem))); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 125 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0((yyvsp[(2) - (2)].data.lexem))); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 130 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 132 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 137 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 139 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 141 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 143 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 145 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 147 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4(MakeNode0((yyvsp[(1) - (4)].data.lexem)), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 152 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("&"); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 154 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("*"); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 156 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("+"); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 158 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("-"); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 160 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("~"); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 162 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("!"); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 167 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 169 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4(MakeNode0("("), (yyvsp[(2) - (4)].data.val), MakeNode0(")"), (yyvsp[(4) - (4)].data.val)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 175 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 177 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("*"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 179 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("/"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 181 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("%"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 186 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 188 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("+"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 190 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("-"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 195 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 197 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 199 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 204 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 206 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("<"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 208 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(">"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 210 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 212 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 217 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 219 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 221 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 226 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 228 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("&"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 233 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 235 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("^"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 240 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 242 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("|"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 247 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 249 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 254 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 256 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 261 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 263 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (5)].data.val), MakeNode0("?"), MakeNode3((yyvsp[(3) - (5)].data.val), MakeNode0(":"),(yyvsp[(5) - (5)].data.val))); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 268 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 270 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), (yyvsp[(2) - (3)].data.val), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 275 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("="); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 277 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 279 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 281 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 283 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 285 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 287 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 289 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 291 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 293 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 295 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 300 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 302 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 307 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 312 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0(";")); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 314 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), (yyvsp[(2) - (3)].data.val), MakeNode0(";")); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 319 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 321 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 323 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 325 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 327 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 329 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 334 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 336 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 341 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 343 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("="), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 348 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 350 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 352 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 354 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 356 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 361 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 363 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 365 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 367 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 369 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 371 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 373 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 375 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 377 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 379 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 381 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 383 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 442 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 444 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 449 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 451 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 457 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val), MakeNode0(")")); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 459 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("["), (yyvsp[(3) - (4)].data.val), MakeNode0("]")); ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 461 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("["), MakeNode0("]")); ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 463 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 465 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 467 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("("), MakeNode0(")")); ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 472 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("*"); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 474 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("*"), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 476 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("*"), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 478 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("*"), (yyvsp[(2) - (3)].data.val), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 483 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 485 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 491 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 493 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","),  MakeNode0((yyvsp[(3) - (3)].data.lexem))); ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 498 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 500 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","),  (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 505 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 507 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 509 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 514 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 516 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 526 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 528 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 530 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 535 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val), MakeNode0(")")); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 537 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("["), MakeNode0("]")); ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 539 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("["), (yyvsp[(2) - (3)].data.val), MakeNode0("]")); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 541 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("["), MakeNode0("]")); ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 543 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("["), (yyvsp[(3) - (4)].data.val), MakeNode0("]")); ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 545 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("("), MakeNode0(")")); ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 547 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val), MakeNode0(")")); ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 549 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("("), MakeNode0(")")); ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 551 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 556 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 558 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("{"), (yyvsp[(2) - (3)].data.val), MakeNode0("}")); ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 560 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4(MakeNode0("{"), (yyvsp[(2) - (4)].data.val), MakeNode0(","), MakeNode0("}")); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 565 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 567 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 572 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 574 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 576 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 578 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 580 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 582 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 587 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), MakeNode0(":"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 589 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.lexem), (yyvsp[(2) - (4)].data.val), MakeNode0(":"), (yyvsp[(4) - (4)].data.val)); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 591 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), MakeNode0(":"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 596 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("{"), MakeNode0("}")); ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 598 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("{"), (yyvsp[(2) - (3)].data.val), MakeNode0("}")); ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 600 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("{"), (yyvsp[(2) - (3)].data.val), MakeNode0("}")); ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 602 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (4)].data.val), (yyvsp[(2) - (4)].data.val)); ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 607 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 609 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 614 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 616 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 621 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0(";"); ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 623 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0(";")); ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 628 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode5((yyvsp[(1) - (5)].data.lexem), MakeNode0("("), (yyvsp[(3) - (5)].data.val), MakeNode0(")"), (yyvsp[(5) - (5)].data.val)); ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 630 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode7((yyvsp[(1) - (7)].data.lexem), MakeNode0("("), (yyvsp[(3) - (7)].data.val), MakeNode0(")"), (yyvsp[(5) - (7)].data.val), (yyvsp[(6) - (7)].data.lexem), (yyvsp[(7) - (7)].data.val)); ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 632 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode5((yyvsp[(1) - (5)].data.lexem), MakeNode0("("), (yyvsp[(3) - (5)].data.val), MakeNode0(")"), (yyvsp[(5) - (5)].data.val)); ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 637 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode5((yyvsp[(1) - (5)].data.lexem), MakeNode0("("), (yyvsp[(3) - (5)].data.val), MakeNode0(")"), (yyvsp[(5) - (5)].data.val)); ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 639 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode7((yyvsp[(1) - (7)].data.lexem), (yyvsp[(2) - (7)].data.val), (yyvsp[(3) - (7)].data.lexem), MakeNode0("("), (yyvsp[(5) - (7)].data.val), MakeNode0(")"),  MakeNode0(";")); ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 641 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode6((yyvsp[(1) - (6)].data.lexem), MakeNode0("("), (yyvsp[(3) - (6)].data.val), (yyvsp[(4) - (6)].data.val), MakeNode0(")"), (yyvsp[(6) - (6)].data.val)); ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 643 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode7((yyvsp[(1) - (7)].data.lexem), MakeNode0("("), (yyvsp[(3) - (7)].data.val), (yyvsp[(4) - (7)].data.val), (yyvsp[(5) - (7)].data.val), MakeNode0(")"), (yyvsp[(7) - (7)].data.val)); ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 648 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), (yyvsp[(2) - (3)].data.lexem), MakeNode0(";")); ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 650 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.lexem), MakeNode0(";")); ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 652 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.lexem), MakeNode0(";")); ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 654 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.lexem), MakeNode0(";")); ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 656 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), (yyvsp[(2) - (3)].data.val), MakeNode0(";")); ;}
    break;



/* Line 1455 of yacc.c  */
#line 3309 "cqml_grammar.tab.c"
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
#line 684 "cqml_grammar.g"


extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

