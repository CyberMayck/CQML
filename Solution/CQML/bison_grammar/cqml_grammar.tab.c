
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
#define YYLAST   1194

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  222
/* YYNRULES -- Number of states.  */
#define YYNSTATES  368

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
      68,    69,    75,    76,    73,    77,    72,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    66,
      82,    87,    83,    86,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,    71,    84,     2,     2,     2,     2,     2,
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
      60,    62,    64,    66,    70,    72,    77,    81,    86,    90,
      94,    97,   100,   102,   106,   108,   111,   114,   117,   120,
     125,   127,   129,   131,   133,   135,   137,   139,   144,   146,
     150,   154,   158,   160,   164,   168,   170,   174,   178,   180,
     184,   188,   192,   196,   198,   202,   206,   208,   212,   214,
     218,   220,   224,   226,   230,   232,   236,   238,   244,   246,
     250,   252,   254,   256,   258,   260,   262,   264,   266,   268,
     270,   272,   274,   278,   280,   283,   287,   289,   292,   294,
     297,   299,   302,   304,   308,   310,   314,   316,   318,   320,
     322,   324,   326,   328,   330,   332,   334,   336,   338,   340,
     342,   344,   346,   348,   354,   359,   362,   364,   366,   368,
     371,   375,   378,   380,   383,   385,   387,   391,   393,   396,
     400,   405,   411,   414,   416,   420,   422,   426,   428,   430,
     433,   435,   437,   441,   446,   450,   455,   460,   464,   466,
     469,   472,   476,   478,   481,   483,   487,   489,   493,   496,
     499,   501,   503,   507,   509,   512,   514,   516,   519,   523,
     526,   530,   534,   539,   542,   546,   550,   555,   557,   561,
     566,   568,   572,   574,   576,   578,   580,   582,   584,   588,
     593,   597,   600,   604,   608,   613,   615,   618,   620,   623,
     625,   628,   634,   642,   648,   654,   662,   669,   677,   681,
     684,   687,   690
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      89,     0,    -1,    90,    -1,    91,    93,    -1,    93,    -1,
      92,    91,    -1,    92,    -1,    50,     5,    51,     3,    -1,
       3,    64,    94,    65,    -1,     3,    64,    65,    -1,    95,
      66,    94,    -1,    95,    66,    -1,    93,    -1,    96,    -1,
      98,    -1,    97,    -1,     3,    67,   152,    -1,    34,     3,
      98,    -1,    34,     3,     3,    -1,     3,    67,   118,    -1,
       3,    -1,     4,    -1,     5,    -1,    68,   118,    69,    -1,
      99,    -1,   100,    70,   118,    71,    -1,   100,    68,    69,
      -1,   100,    68,   101,    69,    -1,   100,    72,     3,    -1,
     100,     7,     3,    -1,   100,     8,    -1,   100,     9,    -1,
     116,    -1,   101,    73,   116,    -1,   100,    -1,     8,   102,
      -1,     9,   102,    -1,   103,   104,    -1,     6,   102,    -1,
       6,    68,   145,    69,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,   102,    -1,    68,
     145,    69,   104,    -1,   104,    -1,   105,    75,   104,    -1,
     105,    80,   104,    -1,   105,    81,   104,    -1,   105,    -1,
     106,    76,   105,    -1,   106,    77,   105,    -1,   106,    -1,
     107,    10,   106,    -1,   107,    11,   106,    -1,   107,    -1,
     108,    82,   107,    -1,   108,    83,   107,    -1,   108,    12,
     107,    -1,   108,    13,   107,    -1,   108,    -1,   109,    14,
     108,    -1,   109,    15,   108,    -1,   109,    -1,   110,    74,
     109,    -1,   110,    -1,   111,    84,   110,    -1,   111,    -1,
     112,    85,   111,    -1,   112,    -1,   113,    16,   112,    -1,
     113,    -1,   114,    17,   113,    -1,   114,    -1,   114,    86,
     118,    67,   115,    -1,   115,    -1,   102,   117,   116,    -1,
      87,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      22,    -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,   116,    -1,   118,    73,   116,    -1,   115,    -1,
     121,    66,    -1,   121,   122,    66,    -1,   124,    -1,   124,
     121,    -1,   125,    -1,   125,   121,    -1,   136,    -1,   136,
     121,    -1,   123,    -1,   122,    73,   123,    -1,   137,    -1,
     137,    87,   148,    -1,    29,    -1,    30,    -1,    31,    -1,
      32,    -1,    33,    -1,    45,    -1,    35,    -1,    36,    -1,
      37,    -1,    38,    -1,    41,    -1,    42,    -1,    39,    -1,
      40,    -1,   126,    -1,   133,    -1,    28,    -1,   127,     3,
      64,   128,    65,    -1,   127,    64,   128,    65,    -1,   127,
       3,    -1,    46,    -1,    47,    -1,   129,    -1,   128,   129,
      -1,   130,   131,    66,    -1,   125,   130,    -1,   125,    -1,
     136,   130,    -1,   136,    -1,   132,    -1,   131,    73,   132,
      -1,   137,    -1,    67,   119,    -1,   137,    67,   119,    -1,
      48,    64,   134,    65,    -1,    48,     3,    64,   134,    65,
      -1,    48,     3,    -1,   135,    -1,   134,    73,   135,    -1,
       3,    -1,     3,    87,   119,    -1,    43,    -1,    44,    -1,
     139,   138,    -1,   138,    -1,     3,    -1,    68,   137,    69,
      -1,   138,    70,   119,    71,    -1,   138,    70,    71,    -1,
     138,    68,   141,    69,    -1,   138,    68,   144,    69,    -1,
     138,    68,    69,    -1,    75,    -1,    75,   140,    -1,    75,
     139,    -1,    75,   140,   139,    -1,   136,    -1,   140,   136,
      -1,   142,    -1,   142,    73,    49,    -1,   143,    -1,   142,
      73,   143,    -1,   121,   137,    -1,   121,   146,    -1,   121,
      -1,     3,    -1,   144,    73,     3,    -1,   130,    -1,   130,
     146,    -1,   139,    -1,   147,    -1,   139,   147,    -1,    68,
     146,    69,    -1,    70,    71,    -1,    70,   119,    71,    -1,
     147,    70,    71,    -1,   147,    70,   119,    71,    -1,    68,
      69,    -1,    68,   141,    69,    -1,   147,    68,    69,    -1,
     147,    68,   141,    69,    -1,   116,    -1,    64,   149,    65,
      -1,    64,   149,    73,    65,    -1,   148,    -1,   149,    73,
     148,    -1,   151,    -1,   152,    -1,   155,    -1,   156,    -1,
     157,    -1,   158,    -1,     3,    67,   150,    -1,    52,   119,
      67,   150,    -1,    53,    67,   150,    -1,    64,    65,    -1,
      64,   154,    65,    -1,    64,   153,    65,    -1,    64,   153,
     154,    65,    -1,   120,    -1,   153,   120,    -1,   150,    -1,
     154,   150,    -1,    66,    -1,   118,    66,    -1,    54,    68,
     118,    69,   150,    -1,    54,    68,   118,    69,   150,    55,
     150,    -1,    56,    68,   118,    69,   150,    -1,    57,    68,
     118,    69,   150,    -1,    58,   150,    57,    68,   118,    69,
      66,    -1,    59,    68,   155,   155,    69,   150,    -1,    59,
      68,   155,   155,   118,    69,   150,    -1,    60,     3,    66,
      -1,    61,    66,    -1,    62,    66,    -1,    63,    66,    -1,
      63,   118,    66,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    26,    26,    31,    33,    38,    40,    45,    50,    52,
      57,    59,    65,    67,    69,    71,    76,    81,    83,    88,
      93,    95,    97,    99,   104,   106,   108,   110,   112,   114,
     116,   118,   123,   125,   130,   132,   134,   136,   138,   140,
     145,   147,   149,   151,   153,   155,   160,   162,   168,   170,
     172,   174,   179,   181,   183,   188,   190,   192,   197,   199,
     201,   203,   205,   210,   212,   214,   219,   221,   226,   228,
     233,   235,   240,   242,   247,   249,   254,   256,   261,   263,
     268,   270,   272,   274,   276,   278,   280,   282,   284,   286,
     288,   293,   295,   300,   305,   307,   312,   314,   316,   318,
     320,   322,   327,   329,   334,   336,   341,   343,   345,   347,
     349,   354,   356,   358,   360,   362,   364,   366,   368,   370,
     372,   374,   376,   381,   382,   383,   387,   388,   392,   393,
     397,   401,   402,   403,   404,   408,   409,   413,   414,   415,
     419,   420,   421,   425,   426,   430,   431,   435,   437,   442,
     444,   449,   450,   452,   454,   456,   458,   460,   465,   467,
     469,   471,   476,   478,   484,   486,   491,   493,   498,   500,
     502,   507,   509,   514,   515,   519,   521,   523,   528,   530,
     532,   534,   536,   538,   540,   542,   544,   549,   551,   553,
     558,   560,   565,   567,   569,   571,   573,   575,   580,   582,
     584,   589,   591,   593,   595,   600,   602,   607,   609,   614,
     616,   621,   623,   625,   630,   632,   634,   636,   641,   643,
     645,   647,   649
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
  "'{'", "'}'", "';'", "':'", "'('", "')'", "'['", "']'", "'.'", "','",
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
     315,   316,   317,   318,   123,   125,    59,    58,    40,    41,
      91,    93,    46,    44,    38,    42,    43,    45,   126,    33,
      47,    37,    60,    62,    94,   124,    63,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    90,    91,    91,    92,    93,    93,
      94,    94,    95,    95,    95,    95,    96,    97,    97,    98,
      99,    99,    99,    99,   100,   100,   100,   100,   100,   100,
     100,   100,   101,   101,   102,   102,   102,   102,   102,   102,
     103,   103,   103,   103,   103,   103,   104,   104,   105,   105,
     105,   105,   106,   106,   106,   107,   107,   107,   108,   108,
     108,   108,   108,   109,   109,   109,   110,   110,   111,   111,
     112,   112,   113,   113,   114,   114,   115,   115,   116,   116,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   118,   118,   119,   120,   120,   121,   121,   121,   121,
     121,   121,   122,   122,   123,   123,   124,   124,   124,   124,
     124,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   126,   127,   127,   128,   128,
     129,   130,   130,   130,   130,   131,   131,   132,   132,   132,
     133,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   138,   138,   138,   138,   138,   138,   139,   139,
     139,   139,   140,   140,   141,   141,   142,   142,   143,   143,
     143,   144,   144,   145,   145,   146,   146,   146,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   148,   148,   148,
     149,   149,   150,   150,   150,   150,   150,   150,   151,   151,
     151,   152,   152,   152,   152,   153,   153,   154,   154,   155,
     155,   156,   156,   156,   157,   157,   157,   157,   158,   158,
     158,   158,   158
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     4,     4,     3,
       3,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       1,     1,     1,     3,     1,     4,     3,     4,     3,     3,
       2,     2,     1,     3,     1,     2,     2,     2,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     3,     1,     2,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4,     2,     1,     1,     1,     2,
       3,     2,     1,     2,     1,     1,     3,     1,     2,     3,
       4,     5,     2,     1,     3,     1,     3,     1,     1,     2,
       1,     1,     3,     4,     3,     4,     4,     3,     1,     2,
       2,     3,     1,     2,     1,     3,     1,     3,     2,     2,
       1,     1,     3,     1,     2,     1,     1,     2,     3,     2,
       3,     3,     4,     2,     3,     3,     4,     1,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     2,     3,     3,     4,     1,     2,     1,     2,     1,
       2,     5,     7,     5,     5,     7,     6,     7,     3,     2,
       2,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     0,     6,     4,     0,     0,
       1,     3,     5,     0,     0,     9,    12,     0,     0,    13,
      15,    14,     0,     0,     0,     8,    11,     7,    20,    21,
      22,     0,     0,     0,     0,     0,    40,    41,    42,    43,
      44,    45,    24,    34,    46,     0,    48,    52,    55,    58,
      63,    66,    68,    70,    72,    74,    76,    78,    91,    19,
      16,    18,    17,    10,     0,    38,     0,    35,    36,    20,
     122,   106,   107,   108,   109,   110,   112,   113,   114,   115,
     118,   119,   116,   117,   147,   148,   111,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,   209,     0,   205,     0,    96,    98,   120,     0,
     121,   100,   207,   192,   193,     0,     0,   194,   195,   196,
     197,     0,   132,   173,   134,     0,     0,    30,    31,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    80,     0,    46,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
       0,    93,     0,     0,     0,     0,     0,     0,     0,     0,
     219,   220,   221,     0,   210,   151,    94,     0,   158,     0,
     102,   104,   150,     0,    97,    99,   125,     0,   101,   203,
     206,     0,   202,   208,    23,   131,     0,     0,   175,   174,
     176,   133,     0,    29,    26,     0,    32,     0,    28,    79,
      49,    50,    51,    53,    54,    56,    57,    61,    62,    59,
      60,    64,    65,    67,    69,    71,    73,    75,     0,    92,
      39,   198,     0,   145,     0,   143,     0,   200,     0,     0,
       0,     0,     0,   218,   222,     0,   162,   160,   159,    95,
       0,     0,     0,     0,   149,     0,     0,   128,     0,   204,
     183,   170,     0,   164,   166,     0,   179,     0,   177,     0,
       0,    47,    27,     0,    25,     0,     0,     0,   140,     0,
     199,     0,     0,     0,     0,     0,   152,   163,   161,   103,
       0,   187,   105,   171,   157,     0,     0,   154,     0,     0,
     124,   129,     0,     0,   135,   137,     0,   168,   175,   169,
     184,     0,   178,   180,   185,     0,   181,     0,    33,    77,
     141,   146,   144,   211,   213,   214,     0,     0,     0,   190,
       0,   155,   156,     0,   153,   123,   138,   130,     0,     0,
     165,   167,   186,   182,     0,     0,   216,     0,   188,     0,
     172,   136,   139,   212,   215,   217,   189,   191
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    16,    17,    18,    19,    20,
      21,    42,    43,   215,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,   143,
     103,   172,   104,   271,   189,   190,   106,   107,   108,   109,
     266,   267,   268,   313,   314,   110,   244,   245,   111,   191,
     192,   193,   258,   272,   273,   274,   306,   125,   275,   210,
     302,   340,   112,   113,   114,   115,   116,   117,   118,   119,
     120
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -255
static const yytype_int16 yypact[] =
{
      50,    10,    73,   108,  -255,   132,   114,  -255,    18,   127,
    -255,  -255,  -255,    85,   167,  -255,  -255,   110,   156,  -255,
    -255,  -255,   182,   624,   226,  -255,    23,  -255,  -255,  -255,
    -255,   832,   844,   844,   284,   438,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,   175,   477,   856,  -255,   -17,   128,   204,
      63,   210,   161,   158,   159,   232,     0,  -255,  -255,   177,
    -255,   184,  -255,  -255,   438,  -255,   856,  -255,  -255,   185,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,    17,
     856,   186,   187,   189,   190,   592,   191,   257,   195,   196,
     701,  -255,  -255,    -5,  -255,     5,  1125,  1125,  -255,    27,
    -255,  1125,  -255,  -255,  -255,   361,   484,  -255,  -255,  -255,
    -255,   -13,  1146,   -26,  1146,   198,   261,  -255,  -255,   713,
     856,   262,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,   856,  -255,  -255,   856,   856,   856,   856,
     856,   856,   856,   856,   856,   856,   856,   856,   856,   856,
     856,   856,   856,   856,   856,   856,   856,   199,   592,   205,
     267,  -255,   206,   592,   856,   856,   856,   214,   727,   208,
    -255,  -255,  -255,    -4,  -255,  -255,  -255,   104,   -10,     6,
    -255,   197,   -30,    19,  -255,  -255,   212,  1146,  -255,  -255,
    -255,   515,  -255,  -255,  -255,  -255,   958,   300,   142,  -255,
     153,  -255,   856,  -255,  -255,   100,  -255,   123,  -255,  -255,
    -255,  -255,  -255,   -17,   -17,   128,   128,   204,   204,   204,
     204,    63,    63,   210,   161,   158,   159,   232,    84,  -255,
    -255,  -255,   267,   207,   -37,  -255,   592,  -255,   117,   118,
     119,   215,   727,  -255,  -255,   203,  -255,  -255,   -10,  -255,
     104,   743,   848,   377,   -30,  1146,  1041,  -255,   141,  -255,
    -255,    28,   213,   218,  -255,   216,  -255,   224,   153,  1006,
     454,  -255,  -255,   856,  -255,   856,   -22,   856,  -255,   267,
    -255,   592,   592,   592,   856,   755,  -255,  -255,  -255,  -255,
     743,  -255,  -255,  -255,  -255,   217,   124,  -255,   225,  1072,
    -255,  -255,   856,    88,  -255,   230,   910,  -255,    36,  -255,
    -255,  1103,  -255,  -255,  -255,   229,  -255,   228,  -255,  -255,
    -255,  -255,  -255,   245,  -255,  -255,   126,   592,   134,  -255,
     -18,  -255,  -255,   298,  -255,  -255,  -255,  -255,   141,   856,
    -255,  -255,  -255,  -255,   592,   236,  -255,   592,  -255,   608,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -255,  -255,  -255,   301,  -255,   162,   285,  -255,  -255,  -255,
     286,  -255,  -255,  -255,   -31,  -255,   -35,    78,    79,    64,
      83,   174,   179,   173,   192,   172,  -255,   -74,  -120,  -255,
     -16,  -178,   238,    32,  -255,    91,  -255,   -29,  -255,  -255,
      90,  -242,   -23,  -255,     8,  -255,   115,    95,   -32,  -174,
    -182,  -118,  -255,  -225,  -255,    51,  -255,   309,  -105,  -181,
    -254,  -255,   -91,  -255,   364,  -255,   273,  -163,  -255,  -255,
    -255
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      65,    67,    68,   124,   177,   208,   122,    59,   185,   216,
     145,   264,   123,   255,   144,   252,   171,   163,   209,   121,
     169,    13,   185,   219,   311,   203,    13,   278,   288,   277,
     196,   185,   124,    84,    85,   122,   289,   305,   262,   185,
     263,   123,   206,   330,   207,   239,   339,   358,   121,   188,
     121,   289,    14,     1,   325,   359,   204,    14,   146,   144,
     165,   184,   254,   147,   148,   188,   105,   311,   165,   165,
     257,   186,   259,   187,     8,   153,   154,   241,     9,   260,
     188,   170,   247,    15,   183,   308,   164,   187,   208,   295,
     124,   197,   124,   122,   315,   122,   316,   317,   207,   205,
       2,   211,   327,   188,   316,   367,   207,   185,    10,   331,
     203,   220,   221,   222,   217,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   171,   346,     1,   264,   278,   194,   195,
     298,   301,   255,   198,   185,   155,   156,   105,   238,     8,
      59,   285,    23,   318,   347,   290,   256,   165,   248,   249,
     250,   348,     7,   328,     2,   124,   319,    11,   122,   282,
      24,   362,   187,   283,   315,    25,   144,   281,    22,   188,
     301,   144,   126,   127,   128,    27,   291,   292,   293,   171,
     165,   165,   165,   342,   284,   355,   165,   343,   318,   165,
     333,   334,   335,   357,   149,   150,   171,   165,   312,   187,
     206,   329,   207,   171,   151,   152,   188,   227,   228,   229,
     230,   279,    26,   280,   157,   158,   297,   223,   224,    61,
     225,   226,   144,   124,   124,   159,   122,   122,   171,   301,
     231,   232,   160,   129,   161,   130,   356,   131,   162,   144,
     165,   166,   168,   173,   144,   174,   144,   175,   176,   178,
     179,   180,   181,   363,   213,   218,   365,   212,   240,   242,
     243,   251,   296,   246,   253,   171,   265,   124,   336,   338,
     122,   144,   320,   294,   261,   322,   341,    69,    29,    30,
      31,   321,    32,    33,   287,   323,   344,   349,   352,   353,
     354,   360,   364,    28,    29,    30,    31,    12,    32,    33,
      62,    63,    70,    71,    72,    73,    74,    75,   144,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,   233,   235,   237,    90,    91,    92,   234,
      93,    94,    95,    96,    97,    98,    99,   100,    34,   101,
     102,   299,    35,   200,   236,   309,   361,   286,    36,    37,
      38,    39,    40,    41,    69,    29,    30,    31,    35,    32,
      33,   276,   351,   167,    36,    37,    38,    39,    40,    41,
      28,    29,    30,    31,   332,    32,    33,    60,   201,    70,
      71,    72,    73,    74,    75,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,    90,    91,    92,     0,    93,    94,    95,
      96,    97,    98,    99,   100,    34,   199,   102,     0,    35,
       0,     0,     0,     0,     0,    36,    37,    38,    39,    40,
      41,    28,    29,    30,    31,    35,    32,    33,   307,     0,
       0,    36,    37,    38,    39,    40,    41,    28,    29,    30,
      31,     0,    32,    33,     0,     0,    70,     0,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    69,    29,    30,
      31,     0,    32,    33,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,    35,     0,     0,     0,
       0,     0,    36,    37,    38,    39,    40,    41,    69,    29,
      30,    31,    35,    32,    33,   326,     0,     0,    36,    37,
      38,    39,    40,    41,     0,     0,    90,    91,    92,     0,
      93,    94,    95,    96,    97,    98,    99,   100,    34,   202,
     102,     0,    35,     0,     0,     0,     0,     0,    36,    37,
      38,    39,    40,    41,   142,     0,     0,    90,    91,    92,
       0,    93,    94,    95,    96,    97,    98,    99,   100,    34,
     269,   102,     0,    35,     0,     0,     0,     0,     0,    36,
      37,    38,    39,    40,    41,    69,    29,    30,    31,     0,
      32,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,    31,     0,    32,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    30,
      31,     0,    32,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,     0,    93,    94,
      95,    96,    97,    98,    99,   100,    34,     0,   102,     0,
      35,     0,     0,     0,     0,     0,    36,    37,    38,    39,
      40,    41,   300,   366,     0,     0,    35,     0,     0,     0,
       0,     0,    36,    37,    38,    39,    40,    41,    34,     0,
       0,     0,    35,     0,     0,     0,     0,     0,    36,    37,
      38,    39,    40,    41,    28,    29,    30,    31,     0,    32,
      33,     0,     0,     0,     0,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,     0,     0,     0,     0,     0,
      28,    29,    30,    31,     0,    32,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    29,    30,    31,
       0,    32,    33,     0,     0,     0,     0,     0,    28,    29,
      30,    31,     0,    32,    33,     0,     0,   182,     0,    35,
       0,     0,     0,     0,     0,    36,    37,    38,    39,    40,
      41,    35,   214,     0,     0,     0,     0,    36,    37,    38,
      39,    40,    41,   102,     0,    35,     0,     0,     0,     0,
       0,    36,    37,    38,    39,    40,    41,   300,     0,     0,
       0,    35,     0,     0,     0,     0,     0,    36,    37,    38,
      39,    40,    41,    35,   337,     0,     0,     0,     0,    36,
      37,    38,    39,    40,    41,    28,    29,    30,    31,     0,
      32,    33,     0,     0,     0,     0,     0,    28,    29,    30,
      31,   303,    32,    33,     0,     0,     0,     0,     0,    28,
      29,    30,    31,     0,    32,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      64,     0,     0,     0,     0,     0,    36,    37,    38,    39,
      40,    41,    66,   185,     0,     0,     0,   304,    36,    37,
      38,    39,    40,    41,    35,     0,     0,     0,     0,     0,
      36,    37,    38,    39,    40,    41,     0,     0,    70,    71,
      72,    73,    74,    75,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   316,   270,
     207,     0,     0,     0,     0,   188,    70,    71,    72,    73,
      74,    75,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   206,   270,   207,     0,
       0,     0,     0,   188,    70,    71,    72,    73,    74,    75,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,     0,   324,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,     0,     0,   310,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    74,    75,   345,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   350,    70,    71,    72,    73,    74,    75,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    70,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89
};

static const yytype_int16 yycheck[] =
{
      31,    32,    33,    35,    95,   123,    35,    23,     3,   129,
      45,   193,    35,   187,    45,   178,    90,    17,   123,    35,
       3,     3,     3,   143,   266,   116,     3,   208,    65,   207,
       3,     3,    64,    43,    44,    64,    73,   262,    68,     3,
      70,    64,    68,    65,    70,   165,   300,    65,    64,    75,
      66,    73,    34,     3,   279,    73,    69,    34,    75,    90,
      73,    66,    66,    80,    81,    75,    34,   309,    73,    73,
     188,    66,    66,    68,    64,    12,    13,   168,     5,    73,
      75,    64,   173,    65,   100,   263,    86,    68,   206,   252,
     122,    64,   124,   122,   268,   124,    68,   271,    70,   122,
      50,   124,   280,    75,    68,   359,    70,     3,     0,   287,
     201,   146,   147,   148,   130,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   207,   312,     3,   318,   318,   106,   107,
     258,   261,   316,   111,     3,    82,    83,   115,   164,    64,
     166,    67,    67,   271,    66,   246,   188,    73,   174,   175,
     176,    73,     0,   283,    50,   197,   271,     5,   197,    69,
       3,   349,    68,    73,   348,    65,   207,   212,    51,    75,
     300,   212,     7,     8,     9,     3,    69,    69,    69,   263,
      73,    73,    73,    69,    71,    69,    73,    73,   316,    73,
     291,   292,   293,    69,    76,    77,   280,    73,    67,    68,
      68,   285,    70,   287,    10,    11,    75,   153,   154,   155,
     156,    68,    66,    70,    14,    15,   258,   149,   150,     3,
     151,   152,   263,   265,   266,    74,   265,   266,   312,   359,
     157,   158,    84,    68,    85,    70,   337,    72,    16,   280,
      73,    67,    67,    67,   285,    68,   287,    68,    68,    68,
       3,    66,    66,   354,     3,     3,   357,    69,    69,    64,
       3,    57,    69,    67,    66,   349,    64,   309,   294,   295,
     309,   312,    69,    68,    87,    69,    69,     3,     4,     5,
       6,    73,     8,     9,    87,    71,    71,    67,    69,    71,
      55,     3,    66,     3,     4,     5,     6,     6,     8,     9,
      24,    26,    28,    29,    30,    31,    32,    33,   349,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,   159,   161,   163,    52,    53,    54,   160,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,   260,    68,   115,   162,   265,   348,   242,    74,    75,
      76,    77,    78,    79,     3,     4,     5,     6,    68,     8,
       9,    71,   321,    64,    74,    75,    76,    77,    78,    79,
       3,     4,     5,     6,   289,     8,     9,    23,   115,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,     3,     4,     5,     6,    68,     8,     9,    71,    -1,
      -1,    74,    75,    76,    77,    78,    79,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     3,     4,     5,
       6,    -1,     8,     9,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,     3,     4,
       5,     6,    68,     8,     9,    71,    -1,    -1,    74,    75,
      76,    77,    78,    79,    -1,    -1,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,
      76,    77,    78,    79,    87,    -1,    -1,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    64,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    64,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,
      76,    77,    78,    79,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    68,    69,    -1,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    79,    66,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    64,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    79,    68,    69,    -1,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     3,     8,     9,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    68,     3,    -1,    -1,    -1,    69,    74,    75,
      76,    77,    78,    79,    68,    -1,    -1,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    -1,    -1,    -1,    -1,    75,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    75,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    69,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    65,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    65,    35,    36,
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
       0,     3,    50,    89,    90,    91,    92,    93,    64,     5,
       0,    93,    91,     3,    34,    65,    93,    94,    95,    96,
      97,    98,    51,    67,     3,    65,    66,     3,     3,     4,
       5,     6,     8,     9,    64,    68,    74,    75,    76,    77,
      78,    79,    99,   100,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   118,
     152,     3,    98,    94,    68,   102,    68,   102,   102,     3,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      52,    53,    54,    56,    57,    58,    59,    60,    61,    62,
      63,    65,    66,   118,   120,   121,   124,   125,   126,   127,
     133,   136,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   118,   125,   130,   136,   145,     7,     8,     9,    68,
      70,    72,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    87,   117,   102,   104,    75,    80,    81,    76,
      77,    10,    11,    12,    13,    82,    83,    14,    15,    74,
      84,    85,    16,    17,    86,    73,    67,   145,    67,     3,
      64,   115,   119,    67,    68,    68,    68,   150,    68,     3,
      66,    66,    66,   118,    66,     3,    66,    68,    75,   122,
     123,   137,   138,   139,   121,   121,     3,    64,   121,    65,
     120,   154,    65,   150,    69,   130,    68,    70,   139,   146,
     147,   130,    69,     3,    69,   101,   116,   118,     3,   116,
     104,   104,   104,   105,   105,   106,   106,   107,   107,   107,
     107,   108,   108,   109,   110,   111,   112,   113,   118,   116,
      69,   150,    64,     3,   134,   135,    67,   150,   118,   118,
     118,    57,   155,    66,    66,   137,   136,   139,   140,    66,
      73,    87,    68,    70,   138,    64,   128,   129,   130,    65,
      69,   121,   141,   142,   143,   146,    71,   119,   147,    68,
      70,   104,    69,    73,    71,    67,   134,    87,    65,    73,
     150,    69,    69,    69,    68,   155,    69,   136,   139,   123,
      64,   116,   148,     3,    69,   141,   144,    71,   119,   128,
      65,   129,    67,   131,   132,   137,    68,   137,   139,   146,
      69,    73,    69,    71,    69,   141,    71,   119,   116,   115,
      65,   119,   135,   150,   150,   150,   118,    69,   118,   148,
     149,    69,    69,    73,    71,    65,   119,    66,    73,    67,
      49,   143,    69,    71,    55,    69,   150,    69,    65,    73,
       3,   132,   119,   150,    66,   150,    65,   148
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
    { (yyval.data.val) = createProperty( (yyvsp[(2) - (3)].data.val) , (yyvsp[(2) - (3)].data.lexem) , (yyvsp[(3) - (3)].data.lexem));  ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 89 "cqml_grammar.g"
    { (yyval.data.val) = createAttribute( (yyvsp[(1) - (3)].data.val) , 'l', (yyvsp[(1) - (3)].data.lexem), (yyvsp[(3) - (3)].data.val));  ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 94 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0ID((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 96 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 98 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 100 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val) ,MakeNode0(")")); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 105 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 107 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("["), (yyvsp[(3) - (4)].data.val),MakeNode0("]")); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 109 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("(") ,MakeNode0(")")); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 111 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 113 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3Dot((yyvsp[(1) - (3)].data.val), MakeNode0("."), MakeNode0ID((yyvsp[(3) - (3)].data.lexem))); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 115 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), MakeNode0ID((yyvsp[(3) - (3)].data.lexem))); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 117 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0((yyvsp[(2) - (2)].data.lexem))); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 119 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0((yyvsp[(2) - (2)].data.lexem))); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 124 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 126 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 131 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 133 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 135 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 137 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 139 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 141 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4(MakeNode0((yyvsp[(1) - (4)].data.lexem)), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 146 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("&"); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 148 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("*"); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 150 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("+"); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 152 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("-"); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 154 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("~"); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 156 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("!"); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 161 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 163 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4(MakeNode0("("), (yyvsp[(2) - (4)].data.val), MakeNode0(")"), (yyvsp[(4) - (4)].data.val)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 169 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 171 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("*"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 173 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("/"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 175 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("%"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 180 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 182 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("+"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 184 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("-"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 189 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 191 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 193 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 198 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 200 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("<"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 202 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(">"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 204 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 206 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 211 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 213 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 215 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 220 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 222 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("&"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 227 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 229 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("^"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 234 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 236 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("|"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 241 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 243 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 248 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 250 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 255 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 257 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (5)].data.val), MakeNode0("?"), MakeNode3((yyvsp[(3) - (5)].data.val), MakeNode0(":"),(yyvsp[(5) - (5)].data.val))); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 262 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 264 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), (yyvsp[(2) - (3)].data.val), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 269 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("="); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 271 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 273 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 275 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
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
#line 294 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 296 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 301 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 306 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0(";")); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 308 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), (yyvsp[(2) - (3)].data.val), MakeNode0(";")); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 313 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 315 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 317 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 319 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
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
#line 328 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 330 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 335 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 337 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("="), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 342 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 344 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 346 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
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
#line 355 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 357 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 359 "cqml_grammar.g"
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
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 375 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 377 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 436 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 438 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 443 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 445 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 451 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val), MakeNode0(")")); ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 453 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("["), (yyvsp[(3) - (4)].data.val), MakeNode0("]")); ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 455 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("["), MakeNode0("]")); ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 457 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 459 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 461 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("("), MakeNode0(")")); ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 466 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("*"); ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 468 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("*"), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 470 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("*"), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 472 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("*"), (yyvsp[(2) - (3)].data.val), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 477 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 479 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 485 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 487 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","),  MakeNode0((yyvsp[(3) - (3)].data.lexem))); ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 492 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 494 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","),  (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 499 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 501 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 503 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 508 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 510 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 520 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 522 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 524 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 529 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val), MakeNode0(")")); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 531 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("["), MakeNode0("]")); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 533 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("["), (yyvsp[(2) - (3)].data.val), MakeNode0("]")); ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 535 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("["), MakeNode0("]")); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 537 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("["), (yyvsp[(3) - (4)].data.val), MakeNode0("]")); ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 539 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("("), MakeNode0(")")); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 541 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val), MakeNode0(")")); ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 543 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("("), MakeNode0(")")); ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 545 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 550 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 552 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("{"), (yyvsp[(2) - (3)].data.val), MakeNode0("}")); ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 554 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4(MakeNode0("{"), (yyvsp[(2) - (4)].data.val), MakeNode0(","), MakeNode0("}")); ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 559 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 561 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 566 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 568 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 570 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
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
#line 581 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), MakeNode0(":"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 583 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.lexem), (yyvsp[(2) - (4)].data.val), MakeNode0(":"), (yyvsp[(4) - (4)].data.val)); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 585 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), MakeNode0(":"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 590 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0("{"), MakeNode0("}")); ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 592 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("{"), (yyvsp[(2) - (3)].data.val), MakeNode0("}")); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 594 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("{"), (yyvsp[(2) - (3)].data.val), MakeNode0("}")); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 596 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (4)].data.val), (yyvsp[(2) - (4)].data.val)); ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 601 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 603 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 608 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 610 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 615 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0(";"); ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 617 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0(";")); ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 622 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode5((yyvsp[(1) - (5)].data.lexem), MakeNode0("("), (yyvsp[(3) - (5)].data.val), MakeNode0(")"), (yyvsp[(5) - (5)].data.val)); ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 624 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode7((yyvsp[(1) - (7)].data.lexem), MakeNode0("("), (yyvsp[(3) - (7)].data.val), MakeNode0(")"), (yyvsp[(5) - (7)].data.val), (yyvsp[(6) - (7)].data.lexem), (yyvsp[(7) - (7)].data.val)); ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 626 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode5((yyvsp[(1) - (5)].data.lexem), MakeNode0("("), (yyvsp[(3) - (5)].data.val), MakeNode0(")"), (yyvsp[(5) - (5)].data.val)); ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 631 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode5((yyvsp[(1) - (5)].data.lexem), MakeNode0("("), (yyvsp[(3) - (5)].data.val), MakeNode0(")"), (yyvsp[(5) - (5)].data.val)); ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 633 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode7((yyvsp[(1) - (7)].data.lexem), (yyvsp[(2) - (7)].data.val), (yyvsp[(3) - (7)].data.lexem), MakeNode0("("), (yyvsp[(5) - (7)].data.val), MakeNode0(")"),  MakeNode0(";")); ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 635 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode6((yyvsp[(1) - (6)].data.lexem), MakeNode0("("), (yyvsp[(3) - (6)].data.val), (yyvsp[(4) - (6)].data.val), MakeNode0(")"), (yyvsp[(6) - (6)].data.val)); ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 637 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode7((yyvsp[(1) - (7)].data.lexem), MakeNode0("("), (yyvsp[(3) - (7)].data.val), (yyvsp[(4) - (7)].data.val), (yyvsp[(5) - (7)].data.val), MakeNode0(")"), (yyvsp[(7) - (7)].data.val)); ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 642 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), (yyvsp[(2) - (3)].data.lexem), MakeNode0(";")); ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 644 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.lexem), MakeNode0(";")); ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 646 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.lexem), MakeNode0(";")); ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 648 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.lexem), MakeNode0(";")); ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 650 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.lexem), (yyvsp[(2) - (3)].data.val), MakeNode0(";")); ;}
    break;



/* Line 1455 of yacc.c  */
#line 3294 "cqml_grammar.tab.c"
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
#line 678 "cqml_grammar.g"


extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

