
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
     INCLUDE = 307,
     CASE = 308,
     DEFAULT = 309,
     IF = 310,
     ELSE = 311,
     SWITCH = 312,
     WHILE = 313,
     DO = 314,
     FOR = 315,
     GOTO = 316,
     CONTINUE = 317,
     BREAK = 318,
     RETURN = 319
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
#line 183 "cqml_grammar.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 195 "cqml_grammar.tab.c"

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNRULES -- Number of states.  */
#define YYNSTATES  377

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    80,     2,     2,     2,    82,    75,     2,
      70,    71,    76,    77,    74,    78,    69,    81,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,    67,
      83,    88,    84,    87,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,    73,    85,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,    86,    66,    79,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    15,    20,    23,
      28,    32,    36,    39,    41,    43,    45,    47,    51,    55,
      59,    63,    67,    71,    77,    79,    81,    83,    87,    89,
      94,    98,   103,   107,   111,   114,   117,   119,   123,   125,
     128,   131,   134,   137,   142,   144,   146,   148,   150,   152,
     154,   156,   161,   163,   167,   171,   175,   177,   181,   185,
     187,   191,   195,   197,   201,   205,   209,   213,   215,   219,
     223,   225,   229,   231,   235,   237,   241,   243,   247,   249,
     253,   255,   261,   263,   267,   269,   271,   273,   275,   277,
     279,   281,   283,   285,   287,   289,   291,   295,   297,   300,
     304,   306,   309,   311,   314,   316,   319,   321,   325,   327,
     331,   333,   335,   337,   339,   341,   343,   345,   347,   349,
     351,   353,   355,   357,   359,   361,   363,   365,   371,   376,
     379,   381,   383,   385,   388,   392,   395,   397,   400,   402,
     404,   408,   410,   413,   417,   422,   428,   431,   433,   437,
     439,   443,   445,   447,   450,   452,   454,   458,   463,   467,
     472,   477,   481,   483,   486,   489,   493,   495,   498,   500,
     504,   506,   510,   513,   516,   518,   520,   524,   526,   529,
     531,   533,   536,   540,   543,   547,   551,   556,   559,   563,
     567,   572,   574,   578,   583,   585,   589,   591,   593,   595,
     597,   599,   601,   605,   610,   614,   617,   621,   625,   630,
     632,   635,   637,   640,   642,   645,   651,   659,   665,   671,
     679,   686,   694,   698,   701,   704,   707
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      90,     0,    -1,    91,    -1,    92,    94,    -1,    94,    -1,
      93,    92,    -1,    93,    -1,    50,     5,    51,     3,    -1,
      52,     5,    -1,     3,    65,    95,    66,    -1,     3,    65,
      66,    -1,    96,    67,    95,    -1,    96,    67,    -1,    94,
      -1,    97,    -1,    99,    -1,    98,    -1,     3,    68,   153,
      -1,    34,     3,    99,    -1,    34,   126,    99,    -1,    34,
       3,     3,    -1,    34,   126,     3,    -1,     3,    68,   116,
      -1,     3,    69,     3,    68,   116,    -1,     3,    -1,     4,
      -1,     5,    -1,    70,   119,    71,    -1,   100,    -1,   101,
      72,   119,    73,    -1,   101,    70,    71,    -1,   101,    70,
     102,    71,    -1,   101,    69,     3,    -1,   101,     7,     3,
      -1,   101,     8,    -1,   101,     9,    -1,   117,    -1,   102,
      74,   117,    -1,   101,    -1,     8,   103,    -1,     9,   103,
      -1,   104,   105,    -1,     6,   103,    -1,     6,    70,   146,
      71,    -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,
      79,    -1,    80,    -1,   103,    -1,    70,   146,    71,   105,
      -1,   105,    -1,   106,    76,   105,    -1,   106,    81,   105,
      -1,   106,    82,   105,    -1,   106,    -1,   107,    77,   106,
      -1,   107,    78,   106,    -1,   107,    -1,   108,    10,   107,
      -1,   108,    11,   107,    -1,   108,    -1,   109,    83,   108,
      -1,   109,    84,   108,    -1,   109,    12,   108,    -1,   109,
      13,   108,    -1,   109,    -1,   110,    14,   109,    -1,   110,
      15,   109,    -1,   110,    -1,   111,    75,   110,    -1,   111,
      -1,   112,    85,   111,    -1,   112,    -1,   113,    86,   112,
      -1,   113,    -1,   114,    16,   113,    -1,   114,    -1,   115,
      17,   114,    -1,   115,    -1,   115,    87,   119,    68,   116,
      -1,   116,    -1,   103,   118,   117,    -1,    88,    -1,    18,
      -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,    23,
      -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,   117,
      -1,   119,    74,   117,    -1,   116,    -1,   122,    67,    -1,
     122,   123,    67,    -1,   125,    -1,   125,   122,    -1,   126,
      -1,   126,   122,    -1,   137,    -1,   137,   122,    -1,   124,
      -1,   123,    74,   124,    -1,   138,    -1,   138,    88,   149,
      -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,    33,
      -1,    45,    -1,    35,    -1,    36,    -1,    37,    -1,    38,
      -1,    41,    -1,    42,    -1,    39,    -1,    40,    -1,   127,
      -1,   134,    -1,    28,    -1,   128,     3,    65,   129,    66,
      -1,   128,    65,   129,    66,    -1,   128,     3,    -1,    46,
      -1,    47,    -1,   130,    -1,   129,   130,    -1,   131,   132,
      67,    -1,   126,   131,    -1,   126,    -1,   137,   131,    -1,
     137,    -1,   133,    -1,   132,    74,   133,    -1,   138,    -1,
      68,   120,    -1,   138,    68,   120,    -1,    48,    65,   135,
      66,    -1,    48,     3,    65,   135,    66,    -1,    48,     3,
      -1,   136,    -1,   135,    74,   136,    -1,     3,    -1,     3,
      88,   120,    -1,    43,    -1,    44,    -1,   140,   139,    -1,
     139,    -1,     3,    -1,    70,   138,    71,    -1,   139,    72,
     120,    73,    -1,   139,    72,    73,    -1,   139,    70,   142,
      71,    -1,   139,    70,   145,    71,    -1,   139,    70,    71,
      -1,    76,    -1,    76,   141,    -1,    76,   140,    -1,    76,
     141,   140,    -1,   137,    -1,   141,   137,    -1,   143,    -1,
     143,    74,    49,    -1,   144,    -1,   143,    74,   144,    -1,
     122,   138,    -1,   122,   147,    -1,   122,    -1,     3,    -1,
     145,    74,     3,    -1,   131,    -1,   131,   147,    -1,   140,
      -1,   148,    -1,   140,   148,    -1,    70,   147,    71,    -1,
      72,    73,    -1,    72,   120,    73,    -1,   148,    72,    73,
      -1,   148,    72,   120,    73,    -1,    70,    71,    -1,    70,
     142,    71,    -1,   148,    70,    71,    -1,   148,    70,   142,
      71,    -1,   117,    -1,    65,   150,    66,    -1,    65,   150,
      74,    66,    -1,   149,    -1,   150,    74,   149,    -1,   152,
      -1,   153,    -1,   156,    -1,   157,    -1,   158,    -1,   159,
      -1,     3,    68,   151,    -1,    53,   120,    68,   151,    -1,
      54,    68,   151,    -1,    65,    66,    -1,    65,   155,    66,
      -1,    65,   154,    66,    -1,    65,   154,   155,    66,    -1,
     121,    -1,   154,   121,    -1,   151,    -1,   155,   151,    -1,
      67,    -1,   119,    67,    -1,    55,    70,   119,    71,   151,
      -1,    55,    70,   119,    71,   151,    56,   151,    -1,    57,
      70,   119,    71,   151,    -1,    58,    70,   119,    71,   151,
      -1,    59,   151,    58,    70,   119,    71,    67,    -1,    60,
      70,   156,   156,    71,   151,    -1,    60,    70,   156,   156,
     119,    71,   151,    -1,    61,     3,    67,    -1,    62,    67,
      -1,    63,    67,    -1,    64,    67,    -1,    64,   119,    67,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    26,    26,    31,    33,    38,    40,    45,    47,    52,
      54,    59,    61,    67,    69,    71,    73,    78,    83,    85,
      87,    89,    94,    96,   101,   103,   105,   107,   112,   114,
     116,   118,   120,   122,   124,   126,   131,   133,   138,   140,
     142,   144,   146,   148,   153,   155,   157,   159,   161,   163,
     168,   170,   176,   178,   180,   182,   187,   189,   191,   196,
     198,   200,   205,   207,   209,   211,   213,   218,   220,   222,
     227,   229,   234,   236,   241,   243,   248,   250,   255,   257,
     262,   264,   269,   271,   276,   278,   280,   282,   284,   286,
     288,   290,   292,   294,   296,   301,   303,   308,   313,   315,
     320,   322,   324,   326,   328,   330,   335,   337,   342,   344,
     349,   351,   353,   355,   357,   362,   364,   366,   368,   370,
     372,   374,   376,   378,   380,   382,   384,   389,   390,   391,
     395,   396,   400,   401,   405,   409,   410,   411,   412,   416,
     417,   421,   422,   423,   427,   428,   429,   433,   434,   438,
     439,   443,   445,   450,   452,   457,   458,   460,   462,   464,
     466,   468,   473,   475,   477,   479,   484,   486,   492,   494,
     499,   501,   506,   508,   510,   515,   517,   522,   523,   527,
     529,   531,   536,   538,   540,   542,   544,   546,   548,   550,
     552,   557,   559,   561,   566,   568,   573,   575,   577,   579,
     581,   583,   588,   590,   592,   597,   599,   601,   603,   608,
     610,   615,   617,   622,   624,   629,   631,   633,   638,   640,
     642,   644,   649,   651,   653,   655,   657
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
  "ENUM", "ELLIPSIS", "IMPORT", "AS", "INCLUDE", "CASE", "DEFAULT", "IF",
  "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK",
  "RETURN", "'{'", "'}'", "';'", "':'", "'.'", "'('", "')'", "'['", "']'",
  "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "'='", "$accept", "start_point",
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
     315,   316,   317,   318,   319,   123,   125,    59,    58,    46,
      40,    41,    91,    93,    44,    38,    42,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    63,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    95,    95,    96,    96,    96,    96,    97,    98,    98,
      98,    98,    99,    99,   100,   100,   100,   100,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   102,   103,   103,
     103,   103,   103,   103,   104,   104,   104,   104,   104,   104,
     105,   105,   106,   106,   106,   106,   107,   107,   107,   108,
     108,   108,   109,   109,   109,   109,   109,   110,   110,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   119,   119,   120,   121,   121,
     122,   122,   122,   122,   122,   122,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   127,   127,   127,
     128,   128,   129,   129,   130,   131,   131,   131,   131,   132,
     132,   133,   133,   133,   134,   134,   134,   135,   135,   136,
     136,   137,   137,   138,   138,   139,   139,   139,   139,   139,
     139,   139,   140,   140,   140,   140,   141,   141,   142,   142,
     143,   143,   144,   144,   144,   145,   145,   146,   146,   147,
     147,   147,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   149,   149,   149,   150,   150,   151,   151,   151,   151,
     151,   151,   152,   152,   152,   153,   153,   153,   153,   154,
     154,   155,   155,   156,   156,   157,   157,   157,   158,   158,
     158,   158,   159,   159,   159,   159,   159
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     4,     2,     4,
       3,     3,     2,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     5,     1,     1,     1,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     4,     2,
       1,     1,     1,     2,     3,     2,     1,     2,     1,     1,
       3,     1,     2,     3,     4,     5,     2,     1,     3,     1,
       3,     1,     1,     2,     1,     1,     3,     4,     3,     4,
       4,     3,     1,     2,     2,     3,     1,     2,     1,     3,
       1,     3,     2,     2,     1,     1,     3,     1,     2,     1,
       1,     2,     3,     2,     3,     3,     4,     2,     3,     3,
       4,     1,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     4,     3,     2,     3,     3,     4,     1,
       2,     1,     2,     1,     2,     5,     7,     5,     5,     7,
       6,     7,     3,     2,     2,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     0,     6,     4,     0,
       0,     8,     1,     3,     5,     0,     0,    10,    13,     0,
       0,    14,    16,    15,     0,     0,     0,     0,   126,   116,
     117,   118,   119,   122,   123,   120,   121,   115,   130,   131,
       0,     0,   124,     0,   125,     9,    12,     7,    24,    25,
      26,     0,     0,     0,     0,     0,    44,    45,    46,    47,
      48,    49,    28,    38,    50,     0,    52,    56,    59,    62,
      67,    70,    72,    74,    76,    78,    80,    22,    17,     0,
      20,    18,   146,     0,    21,    19,   129,     0,    11,     0,
      42,     0,    39,    40,    24,   110,   111,   112,   113,   114,
     151,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,   213,    50,    82,    95,     0,   209,
       0,   100,   102,   104,   211,   196,   197,     0,     0,   198,
     199,   200,   201,     0,   136,   177,   138,     0,     0,    34,
      35,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   147,
       0,     0,   132,     0,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     0,   223,   224,   225,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    84,
       0,   214,     0,   155,    98,     0,   162,     0,   106,   108,
     154,     0,   101,   103,   105,   207,   210,     0,   206,   212,
      27,   135,     0,     0,   179,   178,   180,   137,     0,    33,
      32,    30,     0,    36,     0,    53,    54,    55,    57,    58,
      60,    61,    65,    66,    63,    64,    68,    69,    71,    73,
      75,    77,    79,     0,    23,     0,     0,   144,     0,     0,
     128,   133,     0,     0,   139,   141,    43,   202,     0,   204,
       0,     0,     0,     0,     0,   222,   226,    83,    96,     0,
     166,   164,   163,    99,     0,     0,     0,     0,   153,   208,
     187,   174,     0,   168,   170,     0,   183,     0,   181,     0,
       0,    51,    31,     0,    29,     0,   145,   150,   148,   127,
     142,   134,     0,     0,   203,     0,     0,     0,     0,     0,
     156,   167,   165,   107,     0,   191,   109,   175,   161,     0,
       0,   158,     0,     0,   172,   179,   173,   188,     0,   182,
     184,   189,     0,   185,     0,    37,    81,   140,   143,   215,
     217,   218,     0,     0,     0,   194,     0,   159,   160,     0,
     157,   169,   171,   190,   186,     0,     0,   220,     0,   192,
       0,   176,   216,   219,   221,   193,   195
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    18,    19,    20,    21,    22,
      23,    62,    63,   232,   115,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,   116,   117,   200,
     118,   177,   119,   291,   207,   208,   121,   122,    42,    43,
     171,   172,   173,   263,   264,    44,   168,   169,   123,   209,
     210,   211,   282,   292,   293,   294,   330,   137,   295,   226,
     326,   356,   124,   125,   126,   127,   128,   129,   130,   131,
     132
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -309
static const yytype_int16 yypact[] =
{
       8,   -46,    30,    61,    71,  -309,   114,    -6,  -309,    14,
     144,  -309,  -309,  -309,  -309,    86,   937,  -309,  -309,   136,
      85,  -309,  -309,  -309,   207,   636,   227,   235,  -309,  -309,
    -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,
      11,   242,  -309,    28,  -309,  -309,    18,  -309,  -309,  -309,
    -309,   777,   788,   788,   292,   448,  -309,  -309,  -309,  -309,
    -309,  -309,  -309,   156,  -309,   837,  -309,   168,   193,   263,
      62,   269,   184,   166,   181,   253,    -9,  -309,  -309,   208,
     218,  -309,   213,   278,   218,  -309,   224,  1086,  -309,   448,
    -309,   837,  -309,  -309,   231,  -309,  -309,  -309,  -309,  -309,
    -309,  -309,   837,   236,   237,   241,   245,   604,   246,   309,
     250,   251,   388,  -309,  -309,   487,  -309,  -309,   -37,  -309,
     115,  1065,  1065,  1065,  -309,  -309,  -309,   370,   494,  -309,
    -309,  -309,  -309,   -18,  1086,   164,  1086,   248,   323,  -309,
    -309,   338,   466,   837,  -309,   837,   837,   837,   837,   837,
     837,   837,   837,   837,   837,   837,   837,   837,   837,   837,
     837,   837,   837,   837,   837,   837,   278,   254,   -32,  -309,
    1086,   979,  -309,    29,   272,   604,  -309,   276,   604,   837,
     837,   837,   290,   699,   293,  -309,  -309,  -309,    99,  -309,
    -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,
     837,  -309,   837,  -309,  -309,    33,   -21,   103,  -309,   273,
      36,    12,  -309,  -309,  -309,  -309,  -309,   526,  -309,  -309,
    -309,  -309,   891,   647,    97,  -309,   157,  -309,   837,  -309,
    -309,  -309,   -10,  -309,   219,  -309,  -309,  -309,   168,   168,
     193,   193,   263,   263,   263,   263,    62,    62,   269,   184,
     166,   181,   253,   113,  -309,   -17,   837,  -309,   278,  1011,
    -309,  -309,   837,   104,  -309,   295,  -309,  -309,   604,  -309,
      82,   119,   186,   294,   699,  -309,  -309,  -309,  -309,   306,
    -309,  -309,   -21,  -309,    33,   725,   847,   736,    36,  -309,
    -309,   116,   310,   291,  -309,   311,  -309,   307,   157,   958,
     747,  -309,  -309,   837,  -309,   837,  -309,  -309,  -309,  -309,
    -309,  -309,    29,   837,  -309,   604,   604,   604,   837,   759,
    -309,  -309,  -309,  -309,   725,  -309,  -309,  -309,  -309,   312,
     187,  -309,   313,   176,  -309,    15,  -309,  -309,  1043,  -309,
    -309,  -309,   314,  -309,   315,  -309,  -309,  -309,  -309,   328,
    -309,  -309,   192,   604,   194,  -309,   -15,  -309,  -309,   363,
    -309,  -309,  -309,  -309,  -309,   604,   320,  -309,   604,  -309,
     620,  -309,  -309,  -309,  -309,  -309,  -309
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -309,  -309,  -309,   382,  -309,    63,   344,  -309,  -309,  -309,
      -3,  -309,  -309,  -309,   -25,  -309,   -56,   154,   155,   101,
     153,   261,   262,   244,   234,   258,  -309,   -23,  -135,  -309,
      -5,  -217,   299,   -11,  -309,   138,  -309,    13,  -309,  -309,
     268,  -161,   -42,  -309,   127,  -309,   275,   185,    26,  -132,
    -191,  -134,  -309,  -274,  -309,   106,  -309,   353,  -130,  -221,
    -308,  -309,   -74,  -309,   434,  -309,   333,  -179,  -309,  -309,
    -309
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      64,   224,    77,   298,   274,   225,   297,   233,   162,   144,
     261,     1,   329,   135,    82,   203,   355,    15,   203,     9,
     288,    15,   100,   101,    81,   342,    90,    92,    93,    41,
     201,    86,   203,   182,   257,    10,   203,   202,    85,   307,
      64,   265,   258,   120,     2,   310,     3,   135,    16,   306,
     133,   369,    16,   220,   219,   206,   202,   258,     2,   370,
       3,   302,   376,     8,   303,   277,    11,   278,   134,    13,
     332,    12,   281,   279,   152,   153,    83,    64,   163,   176,
      17,   136,   205,   344,   133,   333,   133,   223,   224,   235,
     236,   237,   221,    87,   227,   319,   348,   262,   261,   205,
     134,   267,   134,   205,   269,   206,   286,   188,   287,   206,
     212,   213,   214,   136,   298,   136,   120,     1,   203,   203,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,   234,    64,
      64,   254,    77,   219,   288,   154,   155,   134,   322,   134,
     325,     9,    46,   315,    25,    26,   202,   335,   253,   334,
     136,   336,   136,   138,   139,   140,   276,   222,   345,   223,
     283,   311,   301,   202,   270,   271,   272,   284,   312,   203,
     265,   305,   204,   134,   134,   205,   333,   202,   223,   325,
     316,   206,   206,   202,   314,    24,   136,   136,    64,   335,
     176,   279,    45,    64,    28,    95,    96,    97,    98,    99,
      47,    29,    30,    31,    32,    33,    34,    35,    36,   100,
     101,    37,    38,    39,    40,   141,   142,   299,   143,   300,
      79,    64,   280,   176,   222,   325,   223,    64,    80,   176,
     206,   349,   350,   351,   145,    84,   333,   290,   223,   146,
     147,   159,   206,   242,   243,   244,   245,   317,   358,   158,
     202,   359,    64,   366,   176,   368,   202,   160,   202,   161,
     148,   149,   134,   150,   151,    64,   164,   176,   166,   367,
      64,   167,   346,   156,   157,   136,   165,    26,    64,   170,
     176,   372,   304,   202,   374,    94,    49,    50,    51,   175,
      52,    53,   238,   239,   178,   240,   241,   179,   321,   246,
     247,   180,   184,   352,   354,   181,   183,   185,   186,   228,
      28,    95,    96,    97,    98,    99,   229,    29,    30,    31,
      32,    33,    34,    35,    36,   100,   101,    37,    38,    39,
      40,   230,   256,   266,   268,   102,   103,   104,   273,   105,
     106,   107,   108,   109,   110,   111,   112,    54,   113,   114,
     275,   285,    55,   313,   318,   338,   371,    56,    57,    58,
      59,    60,    61,    94,    49,    50,    51,   320,    52,    53,
     340,   337,   339,   357,   365,   363,   360,   373,   364,    14,
      88,    48,    49,    50,    51,   251,    52,    53,    28,    95,
      96,    97,    98,    99,   250,    29,    30,    31,    32,    33,
      34,    35,    36,   100,   101,    37,    38,    39,    40,   248,
     252,   249,   323,   102,   103,   104,   216,   105,   106,   107,
     108,   109,   110,   111,   112,    54,   215,   114,   259,   347,
      55,   255,   174,   308,   362,    56,    57,    58,    59,    60,
      61,    48,    49,    50,    51,   187,    52,    53,    55,    78,
     217,     0,     0,    56,    57,    58,    59,    60,    61,    48,
      49,    50,    51,     0,    52,    53,    28,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,   100,   101,    37,    38,    39,    40,    94,    49,    50,
      51,     0,    52,    53,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,     0,     0,     0,    55,     0,
       0,     0,     0,    56,    57,    58,    59,    60,    61,    94,
      49,    50,    51,     0,    52,    53,    55,   231,     0,     0,
       0,    56,    57,    58,    59,    60,    61,   102,   103,   104,
       0,   105,   106,   107,   108,   109,   110,   111,   112,    54,
     218,   114,     0,     0,    55,     0,     0,     0,     0,    56,
      57,    58,    59,    60,    61,   199,     0,     0,     0,   102,
     103,   104,     0,   105,   106,   107,   108,   109,   110,   111,
     112,    54,   289,   114,     0,     0,    55,     0,     0,     0,
       0,    56,    57,    58,    59,    60,    61,    94,    49,    50,
      51,     0,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,     0,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,     0,    52,    53,     0,     0,     0,     0,
      48,    49,    50,    51,     0,    52,    53,   102,   103,   104,
       0,   105,   106,   107,   108,   109,   110,   111,   112,    54,
       0,   114,     0,     0,    55,     0,     0,     0,     0,    56,
      57,    58,    59,    60,    61,   324,   375,     0,     0,     0,
      55,     0,     0,     0,     0,    56,    57,    58,    59,    60,
      61,    54,    48,    49,    50,    51,    55,    52,    53,     0,
       0,    56,    57,    58,    59,    60,    61,    55,     0,     0,
     296,     0,    56,    57,    58,    59,    60,    61,    48,    49,
      50,    51,     0,    52,    53,     0,     0,     0,     0,    48,
      49,    50,    51,     0,    52,    53,     0,     0,     0,     0,
      48,    49,    50,    51,     0,    52,    53,     0,     0,     0,
       0,     0,    48,    49,    50,    51,   114,    52,    53,    55,
       0,     0,     0,     0,    56,    57,    58,    59,    60,    61,
      48,    49,    50,    51,     0,    52,    53,     0,     0,     0,
     324,    48,    49,    50,    51,    55,    52,    53,     0,     0,
      56,    57,    58,    59,    60,    61,    55,     0,     0,   331,
       0,    56,    57,    58,    59,    60,    61,    55,     0,     0,
     343,     0,    56,    57,    58,    59,    60,    61,     0,    55,
     353,     0,     0,     0,    56,    57,    58,    59,    60,    61,
      48,    49,    50,    51,     0,    52,    53,    89,     0,     0,
     327,     0,    56,    57,    58,    59,    60,    61,    91,     0,
       0,     0,     0,    56,    57,    58,    59,    60,    61,     0,
       0,     0,     0,     0,     0,    28,    95,    96,    97,    98,
      99,     0,    29,    30,    31,    32,    33,    34,    35,    36,
     100,   101,    37,    38,    39,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,    56,    57,    58,    59,    60,    61,   328,    28,
      95,    96,    97,    98,    99,     0,    29,    30,    31,    32,
      33,    34,    35,    36,   100,   101,    37,    38,    39,    40,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   290,   223,     0,    28,     0,   206,     0,     0,
       0,     0,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,    37,    38,    39,    40,    28,    95,    96,    97,
      98,    99,     0,    29,    30,    31,    32,    33,    34,    35,
      36,   100,   101,    37,    38,    39,    40,    28,     0,     0,
       0,     0,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,   100,   101,    37,    38,    39,    40,     0,   341,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
       0,     0,     0,     0,     0,   260,    29,    30,    31,    32,
      33,    34,    35,    36,   100,   101,    37,    38,    39,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    95,    96,    97,    98,    99,   309,    29,    30,
      31,    32,    33,    34,    35,    36,   100,   101,    37,    38,
      39,    40,   361,    28,    95,    96,    97,    98,    99,     0,
      29,    30,    31,    32,    33,    34,    35,    36,   100,   101,
      37,    38,    39,    40,    28,     0,     0,     0,     0,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,   100,
     101,    37,    38,    39,    40
};

static const yytype_int16 yycheck[] =
{
      25,   135,    25,   224,   183,   135,   223,   142,    17,    65,
     171,     3,   286,    55,     3,     3,   324,     3,     3,    65,
     211,     3,    43,    44,    27,   299,    51,    52,    53,    16,
      67,     3,     3,   107,    66,     5,     3,    74,    41,   256,
      65,   173,    74,    54,    50,   262,    52,    89,    34,    66,
      55,    66,    34,    71,   128,    76,    74,    74,    50,    74,
      52,    71,   370,     0,    74,   200,     5,   202,    55,     6,
     287,     0,   206,   205,    12,    13,    65,   102,    87,   102,
      66,    55,    70,   300,    89,    70,    91,    72,   222,   145,
     146,   147,   134,    65,   136,   274,   313,    68,   259,    70,
      87,   175,    89,    70,   178,    76,    70,   112,    72,    76,
     121,   122,   123,    87,   335,    89,   127,     3,     3,     3,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   143,   164,
     165,   164,   165,   217,   335,    83,    84,   134,   282,   136,
     285,    65,    67,    71,    68,    69,    74,   291,   163,   291,
     134,   291,   136,     7,     8,     9,    67,    70,   303,    72,
      67,    67,   228,    74,   179,   180,   181,    74,    74,     3,
     312,    68,    67,   170,   171,    70,    70,    74,    72,   324,
      71,    76,    76,    74,   268,    51,   170,   171,   223,   333,
     223,   333,    66,   228,    28,    29,    30,    31,    32,    33,
       3,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    69,    70,    70,    72,    72,
       3,   256,   206,   256,    70,   370,    72,   262,     3,   262,
      76,   315,   316,   317,    76,     3,    70,    71,    72,    81,
      82,    85,    76,   152,   153,   154,   155,    71,    71,    75,
      74,    74,   287,    71,   287,    71,    74,    86,    74,    16,
      77,    78,   259,    10,    11,   300,    68,   300,    65,   353,
     305,     3,   305,    14,    15,   259,    68,    69,   313,    65,
     313,   365,    73,    74,   368,     3,     4,     5,     6,    68,
       8,     9,   148,   149,    68,   150,   151,    70,   282,   156,
     157,    70,     3,   318,   319,    70,    70,    67,    67,    71,
      28,    29,    30,    31,    32,    33,     3,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     3,    88,    71,    68,    53,    54,    55,    58,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      67,    88,    70,    68,    70,    74,     3,    75,    76,    77,
      78,    79,    80,     3,     4,     5,     6,    71,     8,     9,
      73,    71,    71,    71,    56,    71,    73,    67,    73,     7,
      46,     3,     4,     5,     6,   161,     8,     9,    28,    29,
      30,    31,    32,    33,   160,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,   158,
     162,   159,   284,    53,    54,    55,   127,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   170,   312,
      70,   166,    89,   258,   338,    75,    76,    77,    78,    79,
      80,     3,     4,     5,     6,    67,     8,     9,    70,    25,
     127,    -1,    -1,    75,    76,    77,    78,    79,    80,     3,
       4,     5,     6,    -1,     8,     9,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     3,     4,     5,
       6,    -1,     8,     9,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,     3,
       4,     5,     6,    -1,     8,     9,    70,    71,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    88,    -1,    -1,    -1,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    65,    66,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    65,     3,     4,     5,     6,    70,     8,     9,    -1,
      -1,    75,    76,    77,    78,    79,    80,    70,    -1,    -1,
      73,    -1,    75,    76,    77,    78,    79,    80,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    67,     8,     9,    70,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      65,     3,     4,     5,     6,    70,     8,     9,    -1,    -1,
      75,    76,    77,    78,    79,    80,    70,    -1,    -1,    73,
      -1,    75,    76,    77,    78,    79,    80,    70,    -1,    -1,
      73,    -1,    75,    76,    77,    78,    79,    80,    -1,    70,
      71,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
       3,     4,     5,     6,    -1,     8,     9,    70,    -1,    -1,
       3,    -1,    75,    76,    77,    78,    79,    80,    70,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    71,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    28,    -1,    76,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    45,    46,    47,    48,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    66,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    66,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    50,    52,    90,    91,    92,    93,    94,    65,
       5,     5,     0,    94,    92,     3,    34,    66,    94,    95,
      96,    97,    98,    99,    51,    68,    69,     3,    28,    35,
      36,    37,    38,    39,    40,    41,    42,    45,    46,    47,
      48,   126,   127,   128,   134,    66,    67,     3,     3,     4,
       5,     6,     8,     9,    65,    70,    75,    76,    77,    78,
      79,    80,   100,   101,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   153,     3,
       3,    99,     3,    65,     3,    99,     3,    65,    95,    70,
     103,    70,   103,   103,     3,    29,    30,    31,    32,    33,
      43,    44,    53,    54,    55,    57,    58,    59,    60,    61,
      62,    63,    64,    66,    67,   103,   116,   117,   119,   121,
     122,   125,   126,   137,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   119,   126,   131,   137,   146,     7,     8,
       9,    69,    70,    72,   105,    76,    81,    82,    77,    78,
      10,    11,    12,    13,    83,    84,    14,    15,    75,    85,
      86,    16,    17,    87,    68,    68,    65,     3,   135,   136,
      65,   129,   130,   131,   146,    68,   116,   120,    68,    70,
      70,    70,   151,    70,     3,    67,    67,    67,   119,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    88,
     118,    67,    74,     3,    67,    70,    76,   123,   124,   138,
     139,   140,   122,   122,   122,    66,   121,   155,    66,   151,
      71,   131,    70,    72,   140,   147,   148,   131,    71,     3,
       3,    71,   102,   117,   119,   105,   105,   105,   106,   106,
     107,   107,   108,   108,   108,   108,   109,   109,   110,   111,
     112,   113,   114,   119,   116,   135,    88,    66,    74,   129,
      66,   130,    68,   132,   133,   138,    71,   151,    68,   151,
     119,   119,   119,    58,   156,    67,    67,   117,   117,   138,
     137,   140,   141,    67,    74,    88,    70,    72,   139,    66,
      71,   122,   142,   143,   144,   147,    73,   120,   148,    70,
      72,   105,    71,    74,    73,    68,    66,   120,   136,    66,
     120,    67,    74,    68,   151,    71,    71,    71,    70,   156,
      71,   137,   140,   124,    65,   117,   149,     3,    71,   142,
     145,    73,   120,    70,   138,   140,   147,    71,    74,    71,
      73,    71,   142,    73,   120,   117,   116,   133,   120,   151,
     151,   151,   119,    71,   119,   149,   150,    71,    71,    74,
      73,    49,   144,    71,    73,    56,    71,   151,    71,    66,
      74,     3,   151,    67,   151,    66,   149
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
#line 48 "cqml_grammar.g"
    { (yyval.data.val) = createInclude( (yyvsp[(2) - (2)].data.lexem)); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 53 "cqml_grammar.g"
    { (yyval.data.val) = createElement( (yyvsp[(1) - (4)].data.val) , 'R', (yyvsp[(3) - (4)].data.val), (yyvsp[(1) - (4)].data.lexem) ); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 55 "cqml_grammar.g"
    { (yyval.data.val) = createElement( (yyvsp[(1) - (3)].data.val) , 'r', 0, (yyvsp[(1) - (3)].data.lexem)); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 60 "cqml_grammar.g"
    { (yyval.data.val) = createList( (yyvsp[(1) - (3)].data.val) , 'L', (yyvsp[(3) - (3)].data.val), 0); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 62 "cqml_grammar.g"
    { (yyval.data.val) = createList( (yyvsp[(1) - (2)].data.val) , 'l', 0, 0);  ;}
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
#line 74 "cqml_grammar.g"
    { (yyval.data.val) = (yyvsp[(1) - (1)].data.val); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 79 "cqml_grammar.g"
    { (yyval.data.val) = createHandler( (yyvsp[(1) - (3)].data.val) , 'l', (yyvsp[(1) - (3)].data.lexem), (yyvsp[(3) - (3)].data.val));  ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 84 "cqml_grammar.g"
    { (yyval.data.val) = createPropertyInit( (yyvsp[(2) - (3)].data.val) , (yyvsp[(3) - (3)].data.val) , (yyvsp[(2) - (3)].data.lexem));  ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 86 "cqml_grammar.g"
    { (yyval.data.val) = createPropertyInit( (yyvsp[(2) - (3)].data.val) , (yyvsp[(3) - (3)].data.val) , (yyvsp[(2) - (3)].data.lexem));  ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 88 "cqml_grammar.g"
    { (yyval.data.val) = createProperty( (yyvsp[(2) - (3)].data.val) , (yyvsp[(2) - (3)].data.lexem) , (yyvsp[(3) - (3)].data.lexem));  ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 90 "cqml_grammar.g"
    { (yyval.data.val) = createProperty( (yyvsp[(2) - (3)].data.val) , (yyvsp[(2) - (3)].data.lexem) , (yyvsp[(3) - (3)].data.lexem));  ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 95 "cqml_grammar.g"
    { (yyval.data.val) = createAttribute( (yyvsp[(1) - (3)].data.val) , 'l', (yyvsp[(1) - (3)].data.lexem), (yyvsp[(3) - (3)].data.val));  ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 97 "cqml_grammar.g"
    { (yyval.data.val) = createAttribute2( (yyvsp[(1) - (5)].data.val) , 'l', (yyvsp[(3) - (5)].data.lexem), (yyvsp[(1) - (5)].data.lexem), (yyvsp[(5) - (5)].data.val));  ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 102 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0ID((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 104 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 106 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 108 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val) ,MakeNode0(")")); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 113 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 115 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("["), (yyvsp[(3) - (4)].data.val),MakeNode0("]")); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 117 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("(") ,MakeNode0(")")); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 119 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 121 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3Dot((yyvsp[(1) - (3)].data.val), MakeNode0("."), MakeNode0ID((yyvsp[(3) - (3)].data.lexem))); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 123 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), MakeNode0ID((yyvsp[(3) - (3)].data.lexem))); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 125 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0((yyvsp[(2) - (2)].data.lexem))); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 127 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0((yyvsp[(2) - (2)].data.lexem))); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 132 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 134 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 139 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 141 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 143 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 145 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 147 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 149 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4(MakeNode0((yyvsp[(1) - (4)].data.lexem)), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 154 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("&"); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 156 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("*"); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 158 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("+"); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 160 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("-"); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 162 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("~"); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 164 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("!"); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 169 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 171 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4(MakeNode0("("), (yyvsp[(2) - (4)].data.val), MakeNode0(")"), (yyvsp[(4) - (4)].data.val)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 177 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 179 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("*"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 181 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("/"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 183 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("%"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 188 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 190 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("+"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 192 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("-"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 197 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 199 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 201 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 206 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 208 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("<"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 210 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(">"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 212 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 214 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 219 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 221 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 223 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 228 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 230 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("&"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 235 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 237 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("^"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 242 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 244 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("|"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 249 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 251 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 256 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 258 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 263 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 265 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (5)].data.val), MakeNode0("?"), MakeNode3((yyvsp[(3) - (5)].data.val), MakeNode0(":"),(yyvsp[(5) - (5)].data.val))); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 270 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1A((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 272 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3A((yyvsp[(1) - (3)].data.val), (yyvsp[(2) - (3)].data.val), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 277 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("="); ;}
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
#line 297 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 302 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 304 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 309 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 314 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0(";")); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 316 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), (yyvsp[(2) - (3)].data.val), MakeNode0(";")); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 321 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 323 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 325 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 327 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 329 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 331 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 336 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 338 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 343 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 345 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("="), (yyvsp[(3) - (3)].data.val)); ;}
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
#line 358 "cqml_grammar.g"
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
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 381 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 383 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 385 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 444 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 446 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 451 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 453 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 459 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val), MakeNode0(")")); ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 461 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("["), (yyvsp[(3) - (4)].data.val), MakeNode0("]")); ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 463 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("["), MakeNode0("]")); ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 465 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 467 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 469 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("("), MakeNode0(")")); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 474 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("*"); ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 476 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("*"), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 478 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("*"), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 480 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("*"), (yyvsp[(2) - (3)].data.val), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 485 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 487 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 493 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 495 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","),  MakeNode0((yyvsp[(3) - (3)].data.lexem))); ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 500 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 502 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","),  (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 507 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 509 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 511 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 516 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 518 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 528 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 530 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 532 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 537 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val), MakeNode0(")")); ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 539 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("["), MakeNode0("]")); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 541 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("["), (yyvsp[(2) - (3)].data.val), MakeNode0("]")); ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 543 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("["), MakeNode0("]")); ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 545 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("["), (yyvsp[(3) - (4)].data.val), MakeNode0("]")); ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 547 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("("), MakeNode0(")")); ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 549 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val), MakeNode0(")")); ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 551 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("("), MakeNode0(")")); ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 553 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 558 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 560 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("{"), (yyvsp[(2) - (3)].data.val), MakeNode0("}")); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 562 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4(MakeNode0("{"), (yyvsp[(2) - (4)].data.val), MakeNode0(","), MakeNode0("}")); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 567 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 569 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 574 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1STATM((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 576 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1STATM((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 578 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1STATM((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 580 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1STATM((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 582 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1STATM((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 584 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1STATM((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 589 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), MakeNode0(":"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 591 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.lexem), (yyvsp[(2) - (4)].data.val), MakeNode0(":"), (yyvsp[(4) - (4)].data.val)); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 593 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), MakeNode0(":"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 598 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("{"), MakeNode0("}")); ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 600 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("{"), (yyvsp[(2) - (3)].data.val), MakeNode0("}")); ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 602 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("{"), (yyvsp[(2) - (3)].data.val), MakeNode0("}")); ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 604 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (4)].data.val), (yyvsp[(2) - (4)].data.val)); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 609 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 611 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 616 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 618 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 623 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0(";"); ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 625 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0(";")); ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 630 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode5((yyvsp[(1) - (5)].data.lexem), MakeNode0("("), (yyvsp[(3) - (5)].data.val), MakeNode0(")"), (yyvsp[(5) - (5)].data.val)); ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 632 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode7((yyvsp[(1) - (7)].data.lexem), MakeNode0("("), (yyvsp[(3) - (7)].data.val), MakeNode0(")"), (yyvsp[(5) - (7)].data.val), (yyvsp[(6) - (7)].data.lexem), (yyvsp[(7) - (7)].data.val)); ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 634 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode5((yyvsp[(1) - (5)].data.lexem), MakeNode0("("), (yyvsp[(3) - (5)].data.val), MakeNode0(")"), (yyvsp[(5) - (5)].data.val)); ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 639 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode5ITER((yyvsp[(1) - (5)].data.lexem), MakeNode0("("), (yyvsp[(3) - (5)].data.val), MakeNode0(")"), (yyvsp[(5) - (5)].data.val)); ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 641 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode7ITER((yyvsp[(1) - (7)].data.lexem), (yyvsp[(2) - (7)].data.val), (yyvsp[(3) - (7)].data.lexem), MakeNode0("("), (yyvsp[(5) - (7)].data.val), MakeNode0(")"),  MakeNode0(";")); ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 643 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode6ITER((yyvsp[(1) - (6)].data.lexem), MakeNode0("("), (yyvsp[(3) - (6)].data.val), (yyvsp[(4) - (6)].data.val), MakeNode0(")"), (yyvsp[(6) - (6)].data.val)); ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 645 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode7ITER((yyvsp[(1) - (7)].data.lexem), MakeNode0("("), (yyvsp[(3) - (7)].data.val), (yyvsp[(4) - (7)].data.val), (yyvsp[(5) - (7)].data.val), MakeNode0(")"), (yyvsp[(7) - (7)].data.val)); ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 650 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), (yyvsp[(2) - (3)].data.lexem), MakeNode0(";")); ;}
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
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.lexem), MakeNode0(";")); ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 658 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), (yyvsp[(2) - (3)].data.val), MakeNode0(";")); ;}
    break;



/* Line 1455 of yacc.c  */
#line 3316 "cqml_grammar.tab.c"
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
#line 686 "cqml_grammar.g"


extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

