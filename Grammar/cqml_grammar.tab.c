
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
     CQML_TYPE = 284,
     TYPEDEF = 285,
     EXTERN = 286,
     STATIC = 287,
     AUTO = 288,
     REGISTER = 289,
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
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 176 "cqml_grammar.tab.g"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1359

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  223
/* YYNRULES -- Number of states.  */
#define YYNSTATES  369

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
       0,     0,     3,     6,     8,    13,    17,    21,    24,    26,
      28,    30,    36,    40,    42,    44,    46,    50,    52,    57,
      61,    66,    70,    74,    77,    80,    82,    86,    88,    91,
      94,    97,   100,   105,   107,   109,   111,   113,   115,   117,
     119,   124,   126,   130,   134,   138,   140,   144,   148,   150,
     154,   158,   160,   164,   168,   172,   176,   178,   182,   186,
     188,   192,   194,   198,   200,   204,   206,   210,   212,   216,
     218,   224,   226,   230,   232,   234,   236,   238,   240,   242,
     244,   246,   248,   250,   252,   254,   258,   260,   263,   267,
     269,   272,   274,   277,   279,   282,   284,   288,   290,   294,
     296,   298,   300,   302,   304,   306,   308,   310,   312,   314,
     316,   318,   320,   322,   324,   326,   328,   334,   339,   342,
     344,   346,   348,   351,   355,   358,   360,   363,   365,   367,
     371,   373,   376,   380,   385,   391,   394,   396,   400,   402,
     406,   408,   410,   413,   415,   417,   421,   426,   430,   435,
     440,   444,   446,   449,   452,   456,   458,   461,   463,   467,
     469,   473,   476,   479,   481,   483,   487,   489,   492,   494,
     496,   499,   503,   506,   510,   514,   519,   522,   526,   530,
     535,   537,   541,   546,   548,   552,   554,   556,   558,   560,
     562,   564,   568,   573,   577,   580,   584,   588,   593,   595,
     598,   600,   603,   605,   608,   614,   622,   628,   634,   642,
     649,   657,   661,   664,   667,   670,   674,   676,   679,   681,
     683,   688,   692,   696
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      87,     0,    -1,    88,    87,    -1,    88,    -1,    29,    62,
      89,    63,    -1,    29,    62,    63,    -1,    90,    64,    89,
      -1,    90,    64,    -1,    88,    -1,    91,    -1,    92,    -1,
       3,    65,    62,   153,    63,    -1,     3,    65,   112,    -1,
       3,    -1,     4,    -1,     5,    -1,    66,   112,    67,    -1,
      93,    -1,    94,    68,   112,    69,    -1,    94,    66,    67,
      -1,    94,    66,    95,    67,    -1,    94,    70,     3,    -1,
      94,     7,     3,    -1,    94,     8,    -1,    94,     9,    -1,
     110,    -1,    95,    71,   110,    -1,    94,    -1,     8,    96,
      -1,     9,    96,    -1,    97,    98,    -1,     6,    96,    -1,
       6,    66,   139,    67,    -1,    72,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    96,    -1,    66,
     139,    67,    98,    -1,    98,    -1,    99,    73,    98,    -1,
      99,    78,    98,    -1,    99,    79,    98,    -1,    99,    -1,
     100,    74,    99,    -1,   100,    75,    99,    -1,   100,    -1,
     101,    10,   100,    -1,   101,    11,   100,    -1,   101,    -1,
     102,    80,   101,    -1,   102,    81,   101,    -1,   102,    12,
     101,    -1,   102,    13,   101,    -1,   102,    -1,   103,    14,
     102,    -1,   103,    15,   102,    -1,   103,    -1,   104,    72,
     103,    -1,   104,    -1,   105,    82,   104,    -1,   105,    -1,
     106,    83,   105,    -1,   106,    -1,   107,    16,   106,    -1,
     107,    -1,   108,    17,   107,    -1,   108,    -1,   108,    84,
     112,    65,   109,    -1,   109,    -1,    96,   111,   110,    -1,
      85,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      22,    -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,   110,    -1,   112,    71,   110,    -1,   109,    -1,
     115,    64,    -1,   115,   116,    64,    -1,   118,    -1,   118,
     115,    -1,   119,    -1,   119,   115,    -1,   130,    -1,   130,
     115,    -1,   117,    -1,   116,    71,   117,    -1,   131,    -1,
     131,    85,   142,    -1,    30,    -1,    31,    -1,    32,    -1,
      33,    -1,    34,    -1,    45,    -1,    35,    -1,    36,    -1,
      37,    -1,    38,    -1,    41,    -1,    42,    -1,    39,    -1,
      40,    -1,   120,    -1,   127,    -1,    28,    -1,   121,     3,
      62,   122,    63,    -1,   121,    62,   122,    63,    -1,   121,
       3,    -1,    46,    -1,    47,    -1,   123,    -1,   122,   123,
      -1,   124,   125,    64,    -1,   119,   124,    -1,   119,    -1,
     130,   124,    -1,   130,    -1,   126,    -1,   125,    71,   126,
      -1,   131,    -1,    65,   113,    -1,   131,    65,   113,    -1,
      48,    62,   128,    63,    -1,    48,     3,    62,   128,    63,
      -1,    48,     3,    -1,   129,    -1,   128,    71,   129,    -1,
       3,    -1,     3,    85,   113,    -1,    43,    -1,    44,    -1,
     133,   132,    -1,   132,    -1,     3,    -1,    66,   131,    67,
      -1,   132,    68,   113,    69,    -1,   132,    68,    69,    -1,
     132,    66,   135,    67,    -1,   132,    66,   138,    67,    -1,
     132,    66,    67,    -1,    73,    -1,    73,   134,    -1,    73,
     133,    -1,    73,   134,   133,    -1,   130,    -1,   134,   130,
      -1,   136,    -1,   136,    71,    49,    -1,   137,    -1,   136,
      71,   137,    -1,   115,   131,    -1,   115,   140,    -1,   115,
      -1,     3,    -1,   138,    71,     3,    -1,   124,    -1,   124,
     140,    -1,   133,    -1,   141,    -1,   133,   141,    -1,    66,
     140,    67,    -1,    68,    69,    -1,    68,   113,    69,    -1,
     141,    68,    69,    -1,   141,    68,   113,    69,    -1,    66,
      67,    -1,    66,   135,    67,    -1,   141,    66,    67,    -1,
     141,    66,   135,    67,    -1,   110,    -1,    62,   143,    63,
      -1,    62,   143,    71,    63,    -1,   142,    -1,   143,    71,
     142,    -1,   145,    -1,   146,    -1,   149,    -1,   150,    -1,
     151,    -1,   152,    -1,     3,    65,   144,    -1,    50,   113,
      65,   144,    -1,    51,    65,   144,    -1,    62,    63,    -1,
      62,   148,    63,    -1,    62,   147,    63,    -1,    62,   147,
     148,    63,    -1,   114,    -1,   147,   114,    -1,   144,    -1,
     148,   144,    -1,    64,    -1,   112,    64,    -1,    52,    66,
     112,    67,   144,    -1,    52,    66,   112,    67,   144,    53,
     144,    -1,    54,    66,   112,    67,   144,    -1,    55,    66,
     112,    67,   144,    -1,    56,   144,    55,    66,   112,    67,
      64,    -1,    57,    66,   149,   149,    67,   144,    -1,    57,
      66,   149,   149,   112,    67,   144,    -1,    58,     3,    64,
      -1,    59,    64,    -1,    60,    64,    -1,    61,    64,    -1,
      61,   112,    64,    -1,   154,    -1,   153,   154,    -1,   155,
      -1,   114,    -1,   115,   131,   147,   146,    -1,   115,   131,
     146,    -1,   131,   147,   146,    -1,   131,   146,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    17,    17,    18,    22,    23,    27,    28,    33,    34,
      35,    39,    43,    47,    48,    49,    50,    54,    55,    56,
      57,    58,    59,    60,    61,    65,    66,    70,    71,    72,
      73,    74,    75,    79,    80,    81,    82,    83,    84,    88,
      89,    93,    94,    95,    96,   100,   101,   102,   106,   107,
     108,   112,   113,   114,   115,   116,   120,   121,   122,   126,
     127,   131,   132,   136,   137,   141,   142,   146,   147,   151,
     152,   156,   157,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   175,   176,   180,   184,   185,   189,
     190,   191,   192,   193,   194,   198,   199,   203,   204,   208,
     209,   210,   211,   212,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   231,   232,   233,   237,
     238,   242,   243,   247,   251,   252,   253,   254,   258,   259,
     263,   264,   265,   269,   270,   271,   275,   276,   280,   281,
     285,   286,   290,   291,   295,   296,   297,   298,   299,   300,
     301,   305,   306,   307,   308,   312,   313,   318,   319,   323,
     324,   328,   329,   330,   334,   335,   339,   340,   344,   345,
     346,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     362,   363,   364,   368,   369,   373,   374,   375,   376,   377,
     378,   382,   383,   384,   388,   389,   390,   391,   395,   396,
     400,   401,   405,   406,   410,   411,   412,   416,   417,   418,
     419,   423,   424,   425,   426,   427,   431,   432,   436,   437,
     441,   442,   443,   444
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
  "TYPE_NAME", "CQML_TYPE", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "'{'", "'}'", "';'",
  "':'", "'('", "')'", "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'",
  "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'",
  "'='", "$accept", "element_list", "element",
  "attribute_or_subelement_list", "attribute_or_element", "event_handler",
  "attribute", "primary_expression", "postfix_expression",
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
  "jump_statement", "pure_c_code", "external_declaration",
  "function_definition", 0
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
       0,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      90,    91,    92,    93,    93,    93,    93,    94,    94,    94,
      94,    94,    94,    94,    94,    95,    95,    96,    96,    96,
      96,    96,    96,    97,    97,    97,    97,    97,    97,    98,
      98,    99,    99,    99,    99,   100,   100,   100,   101,   101,
     101,   102,   102,   102,   102,   102,   103,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   112,   112,   113,   114,   114,   115,
     115,   115,   115,   115,   115,   116,   116,   117,   117,   118,
     118,   118,   118,   118,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   120,   120,   120,   121,
     121,   122,   122,   123,   124,   124,   124,   124,   125,   125,
     126,   126,   126,   127,   127,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   132,   132,   132,   132,   132,   132,
     132,   133,   133,   133,   133,   134,   134,   135,   135,   136,
     136,   137,   137,   137,   138,   138,   139,   139,   140,   140,
     140,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     142,   142,   142,   143,   143,   144,   144,   144,   144,   144,
     144,   145,   145,   145,   146,   146,   146,   146,   147,   147,
     148,   148,   149,   149,   150,   150,   150,   151,   151,   151,
     151,   152,   152,   152,   152,   152,   153,   153,   154,   154,
     155,   155,   155,   155
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     4,     3,     3,     2,     1,     1,
       1,     5,     3,     1,     1,     1,     3,     1,     4,     3,
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
       7,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       4,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     2,     0,     5,     8,
       0,     0,     9,    10,     0,     4,     7,    13,    14,    15,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      38,    17,    27,    39,     0,    41,    45,    48,    51,    56,
      59,    61,    63,    65,    67,    69,    71,    84,    12,     6,
       0,    31,     0,    28,    29,   144,   115,    99,   100,   101,
     102,   103,   105,   106,   107,   108,   111,   112,   109,   110,
     140,   141,   104,   119,   120,     0,     0,   151,   219,     0,
      89,    91,   113,     0,   114,    93,     0,   143,     0,     0,
     216,   218,     0,   125,   166,   127,     0,     0,    23,    24,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    73,     0,    39,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
       0,   155,   153,   152,    87,     0,    95,    97,    90,    92,
     118,     0,    94,     0,   198,     0,   223,     0,     0,     0,
     142,    11,   217,    16,   124,     0,     0,   168,   167,   169,
     126,     0,    22,    19,     0,    25,     0,    21,    72,    42,
      43,    44,    46,    47,    49,    50,    54,    55,    52,    53,
      57,    58,    60,    62,    64,    66,    68,     0,    85,    32,
       0,   138,     0,   136,   145,   156,   154,    88,     0,     0,
     221,     0,     0,     0,   121,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   194,   202,
       0,   200,   185,   186,     0,     0,   187,   188,   189,   190,
      97,   199,   222,   164,   150,   163,     0,   157,   159,     0,
     147,    86,     0,   176,     0,     0,   172,     0,   170,     0,
       0,    40,    20,     0,    18,     0,     0,     0,   133,     0,
      96,     0,   180,    98,   220,     0,   117,   122,     0,     0,
     128,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   212,   213,   214,     0,   203,   196,     0,   195,   201,
       0,   161,   168,   162,   148,     0,   149,     0,   146,   177,
     171,   173,   178,     0,   174,     0,    26,    70,   134,   139,
     137,   183,     0,   116,   131,   123,     0,     0,   191,     0,
     193,     0,     0,     0,     0,     0,   211,   215,   197,   158,
     160,   165,   179,   175,   181,     0,   129,   132,   192,     0,
       0,     0,     0,     0,   182,   184,   204,   206,   207,     0,
       0,     0,     0,     0,   209,     0,   205,   208,   210
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    11,    12,    13,    31,    32,   174,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   114,   230,   252,   154,   155,
     145,   146,    80,    81,    82,    83,   213,   214,   215,   279,
     280,    84,   202,   203,    85,    86,    87,    88,   143,   254,
     247,   248,   249,    96,   255,   169,   273,   322,   231,   232,
     233,   157,   235,   236,   237,   238,   239,    89,    90,    91
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -270
static const yytype_int16 yypact[] =
{
       2,   -34,    44,     2,    32,  -270,  -270,   -18,  -270,  -270,
      70,    -2,  -270,  -270,   644,  -270,    29,  -270,  -270,  -270,
     850,   862,   862,  1018,   462,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,   164,   276,   874,  -270,   107,   161,   229,   123,
     230,    67,   -31,    59,   138,     7,  -270,  -270,    95,  -270,
     462,  -270,   874,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,   119,    24,    -4,  -270,    91,
    1290,  1290,  -270,   134,  -270,  1290,  1235,   109,    26,   972,
    -270,  -270,    92,  1311,   101,  1311,   117,   187,  -270,  -270,
     719,   874,   212,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,   874,  -270,  -270,   874,   874,   874,
     874,   874,   874,   874,   874,   874,   874,   874,   874,   874,
     874,   874,   874,   874,   874,   874,   874,   160,   167,   234,
     176,  -270,  -270,    -4,  -270,   -12,  -270,  1062,  -270,  -270,
     185,  1311,  -270,   312,  -270,    91,  -270,  1235,   866,   328,
     109,  -270,  -270,  -270,  -270,  1095,   403,   139,  -270,   157,
    -270,   874,  -270,  -270,   130,  -270,   120,  -270,  -270,  -270,
    -270,  -270,   107,   107,   161,   161,   229,   229,   229,   229,
     123,   123,   230,    67,   -31,    59,   138,     0,  -270,  -270,
     234,   166,   -22,  -270,  -270,  -270,  -270,  -270,    24,   735,
    -270,  1235,  1311,  1172,  -270,   122,   192,   874,   193,   197,
     199,   204,   612,   208,   272,   215,   216,   749,  -270,  -270,
     -11,  -270,  -270,  -270,   387,   508,  -270,  -270,  -270,  -270,
     196,  -270,  -270,  -270,  -270,    10,   217,   211,  -270,   135,
    -270,  -270,   221,  -270,   218,   219,  -270,   222,   157,  1139,
     478,  -270,  -270,   874,  -270,   874,   -21,   874,  -270,   234,
    -270,   735,  -270,  -270,  -270,  1201,  -270,  -270,   874,     6,
    -270,   228,   612,   239,   612,   874,   874,   874,   250,   763,
     242,  -270,  -270,  -270,    94,  -270,  -270,   537,  -270,  -270,
     926,  -270,    51,  -270,  -270,  1268,  -270,   304,  -270,  -270,
    -270,  -270,  -270,   243,  -270,   240,  -270,  -270,  -270,  -270,
    -270,  -270,   -15,  -270,  -270,  -270,   122,   874,  -270,   612,
    -270,   141,   147,   149,   245,   763,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,   628,  -270,  -270,  -270,   612,
     612,   612,   874,   775,  -270,  -270,   259,  -270,  -270,   150,
     612,   155,   612,   249,  -270,   612,  -270,  -270,  -270
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -270,   311,    30,   303,  -270,  -270,  -270,  -270,  -270,  -270,
     -19,  -270,    11,   129,   131,   142,   132,   194,   191,   195,
     190,   201,  -270,  -133,   -93,  -270,   -14,   -99,    -1,   -17,
    -270,   118,  -270,   -13,  -270,  -270,   113,  -190,    31,  -270,
       3,  -270,   128,    61,   -20,   -62,   -83,   -69,  -270,  -139,
    -270,    36,  -270,   315,   -85,  -151,  -259,  -270,   -73,  -270,
     -68,    -3,   143,  -269,  -270,  -270,  -270,  -270,   290,  -270
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      48,    51,    53,    54,    95,   160,    79,   175,   142,   168,
      92,    93,   321,    55,   140,   115,   258,   147,   156,   246,
     335,   178,    78,   277,   134,   167,   251,    55,     4,    55,
      95,     1,     7,   251,     9,     7,    92,    93,    92,    70,
      71,   268,   318,   198,     5,   116,     9,    14,   344,   269,
     269,   131,   207,   295,    55,    94,   345,   141,     1,   208,
     136,     1,    16,   148,   149,   265,   353,   257,   152,    77,
     325,   136,    79,    95,   206,    95,   300,   326,   166,   210,
      93,    94,    93,    77,   251,   277,   355,   176,    78,   242,
      76,   135,    76,   240,    55,     8,   167,    77,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   272,   300,   283,   166,
     313,   197,   138,   205,   164,    55,   170,   251,   179,   180,
     181,    95,   317,    15,   251,   124,   125,   150,    93,   130,
     115,   245,   132,   274,   211,   251,   240,   115,   245,   288,
     234,   258,   115,   281,   133,   144,   241,    76,   337,   163,
     303,   315,   299,   136,    77,   136,   136,   165,   319,   166,
     316,    97,    98,    99,    77,   158,   302,   159,   272,   324,
     117,   139,   261,   301,   171,   118,   119,   278,    76,   264,
     172,   136,    95,    95,   251,    77,   151,   262,   115,    93,
      93,   263,   306,   126,   127,   165,   307,   166,   349,   328,
     241,   330,   136,   294,   350,   177,   351,   363,   136,   160,
     136,   136,   365,   259,   299,   260,   136,   199,   347,   200,
     100,   302,   101,   241,   102,   120,   121,   201,   140,   122,
     123,   115,   245,   204,   128,   129,   115,   212,   115,   182,
     183,   267,   272,   184,   185,    95,   348,   282,   284,   115,
     190,   191,    93,   285,   281,   286,   186,   187,   188,   189,
     287,   331,   332,   333,   289,   290,   356,   357,   358,   291,
     292,   209,   305,   245,   304,   309,   310,   364,   245,   366,
     308,   311,   368,   327,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   329,   334,   336,   341,   115,   343,
     342,   352,   362,   367,     6,   216,    18,    19,    20,    49,
      21,    22,   193,   195,   192,   275,   270,   194,   266,   346,
     320,    17,    18,    19,    20,   196,    21,    22,   359,   361,
      56,   340,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   113,   217,   218,   219,   137,   220,   221,   222,   223,
     224,   225,   226,   227,   153,   228,   229,   297,    24,   162,
       0,     0,     0,     0,    25,    26,    27,    28,    29,    30,
     216,    18,    19,    20,    24,    21,    22,   250,     0,     0,
      25,    26,    27,    28,    29,    30,    17,    18,    19,    20,
       0,    21,    22,     0,     0,    56,     0,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     0,   217,   218,   219,
       0,   220,   221,   222,   223,   224,   225,   226,   227,   153,
     296,   229,     0,    24,     0,     0,     0,     0,     0,    25,
      26,    27,    28,    29,    30,    17,    18,    19,    20,    24,
      21,    22,   256,     0,     0,    25,    26,    27,    28,    29,
      30,    17,    18,    19,    20,     0,    21,    22,     0,     0,
      56,     0,     0,     0,     0,     0,     0,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   216,    18,    19,    20,     0,    21,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,     0,     0,    25,    26,    27,    28,    29,    30,
     216,    18,    19,    20,    24,    21,    22,   314,     0,     0,
      25,    26,    27,    28,    29,    30,     0,     0,   217,   218,
     219,     0,   220,   221,   222,   223,   224,   225,   226,   227,
     153,   298,   229,     0,    24,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,     0,   217,   218,   219,
       0,   220,   221,   222,   223,   224,   225,   226,   227,   153,
     338,   229,     0,    24,     0,     0,     0,     0,     0,    25,
      26,    27,    28,    29,    30,   216,    18,    19,    20,     0,
      21,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,    20,     0,    21,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,    19,
      20,     0,    21,    22,     0,     0,     0,     0,     0,     0,
       0,     0,   217,   218,   219,     0,   220,   221,   222,   223,
     224,   225,   226,   227,   153,     0,   229,     0,    24,     0,
       0,     0,     0,     0,    25,    26,    27,    28,    29,    30,
     271,   354,     0,     0,    24,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,    23,     0,     0,     0,
      24,     0,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,    17,    18,    19,    20,     0,    21,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,    20,     0,    21,    22,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    19,    20,     0,    21,    22,     0,
       0,     0,     0,     0,     0,     0,    17,    18,    19,    20,
       0,    21,    22,     0,     0,     0,     0,     0,    17,    18,
      19,    20,     0,    21,    22,    24,   173,     0,     0,     0,
       0,    25,    26,    27,    28,    29,    30,   271,     0,     0,
       0,    24,     0,     0,     0,     0,     0,    25,    26,    27,
      28,    29,    30,   293,     0,    24,     0,     0,     0,     0,
       0,    25,    26,    27,    28,    29,    30,   229,     0,    24,
       0,     0,     0,     0,     0,    25,    26,    27,    28,    29,
      30,    24,   360,     0,     0,     0,     0,    25,    26,    27,
      28,    29,    30,    17,    18,    19,    20,     0,    21,    22,
       0,     0,     0,     0,     0,    17,    18,    19,    20,   243,
      21,    22,     0,     0,     0,     0,     0,    17,    18,    19,
      20,     0,    21,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,     0,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    50,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,    52,    55,
       0,     0,     0,   244,    25,    26,    27,    28,    29,    30,
      24,     0,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,     0,     0,    56,     0,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   300,   253,   166,     0,     0,     0,     0,    77,
      56,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,     0,     0,    76,     0,
       0,     0,     0,     0,     0,    77,    56,     0,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,     0,     0,     0,
      56,    77,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,   153,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,     0,   209,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   253,   166,     0,     0,     0,    56,    77,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,   312,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,   276,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,   323,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,   153,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   339,    56,     0,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    56,
       0,     0,     0,     0,     0,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75
};

static const yytype_int16 yycheck[] =
{
      14,    20,    21,    22,    24,    88,    23,   100,    77,    94,
      24,    24,   271,     3,    76,    34,   167,    79,    86,   158,
     289,   114,    23,   213,    17,    94,   159,     3,    62,     3,
      50,    29,     3,   166,     4,     3,    50,    50,    52,    43,
      44,    63,    63,   136,     0,    34,    16,    65,    63,    71,
      71,    82,    64,    64,     3,    24,    71,    77,    29,    71,
      71,    29,    64,    80,    81,    65,   335,   166,    85,    73,
      64,    71,    89,    93,   143,    95,    66,    71,    68,   147,
      93,    50,    95,    73,   217,   275,   345,   101,    89,   157,
      66,    84,    66,   155,     3,    63,   165,    73,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   209,    66,   217,    68,
     259,   135,     3,   143,    93,     3,    95,   260,   117,   118,
     119,   151,   265,    63,   267,    12,    13,     3,   151,    72,
     159,   158,    83,   211,   147,   278,   208,   166,   165,   222,
     153,   302,   171,   215,    16,    64,   157,    66,    64,    67,
     245,   260,   235,    71,    73,    71,    71,    66,   267,    68,
     263,     7,     8,     9,    73,    66,   245,    68,   271,   278,
      73,    62,   171,   245,    67,    78,    79,    65,    66,    69,
       3,    71,   212,   213,   327,    73,    62,    67,   217,   212,
     213,    71,    67,    80,    81,    66,    71,    68,    67,   282,
     211,   284,    71,   227,    67,     3,    67,    67,    71,   302,
      71,    71,    67,    66,   297,    68,    71,    67,   327,    62,
      66,   300,    68,   234,    70,    74,    75,     3,   300,    10,
      11,   260,   259,    67,    14,    15,   265,    62,   267,   120,
     121,    85,   345,   122,   123,   275,   329,    65,    65,   278,
     128,   129,   275,    66,   326,    66,   124,   125,   126,   127,
      66,   285,   286,   287,    66,     3,   349,   350,   351,    64,
      64,    85,    71,   300,    67,    67,    67,   360,   305,   362,
      69,    69,   365,    65,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    65,    55,    64,     3,   327,    69,
      67,    66,    53,    64,     3,     3,     4,     5,     6,    16,
       8,     9,   131,   133,   130,   212,   208,   132,   200,   326,
     269,     3,     4,     5,     6,   134,     8,     9,   352,   353,
      28,   305,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    85,    50,    51,    52,    50,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   234,    66,    89,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
       3,     4,     5,     6,    66,     8,     9,    69,    -1,    -1,
      72,    73,    74,    75,    76,    77,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,     3,     4,     5,     6,    66,
       8,     9,    69,    -1,    -1,    72,    73,    74,    75,    76,
      77,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
       3,     4,     5,     6,    66,     8,     9,    69,    -1,    -1,
      72,    73,    74,    75,    76,    77,    -1,    -1,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    77,    -1,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
      62,    63,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    77,    62,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    77,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    66,    67,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    62,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    64,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    64,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    66,    67,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     3,
       8,     9,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    66,     3,
      -1,    -1,    -1,    67,    72,    73,    74,    75,    76,    77,
      66,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    77,    -1,    -1,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    73,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      28,    73,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    62,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    28,    73,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    67,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    63,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    63,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    62,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    87,    88,    62,     0,    87,     3,    63,    88,
      89,    90,    91,    92,    65,    63,    64,     3,     4,     5,
       6,     8,     9,    62,    66,    72,    73,    74,    75,    76,
      77,    93,    94,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   112,    89,
      66,    96,    66,    96,    96,     3,    28,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    66,    73,   114,   115,
     118,   119,   120,   121,   127,   130,   131,   132,   133,   153,
     154,   155,   112,   119,   124,   130,   139,     7,     8,     9,
      66,    68,    70,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    85,   111,    96,    98,    73,    78,    79,
      74,    75,    10,    11,    12,    13,    80,    81,    14,    15,
      72,    82,    83,    16,    17,    84,    71,   139,     3,    62,
     131,   130,   133,   134,    64,   116,   117,   131,   115,   115,
       3,    62,   115,    62,   114,   115,   146,   147,    66,    68,
     132,    63,   154,    67,   124,    66,    68,   133,   140,   141,
     124,    67,     3,    67,    95,   110,   112,     3,   110,    98,
      98,    98,    99,    99,   100,   100,   101,   101,   101,   101,
     102,   102,   103,   104,   105,   106,   107,   112,   110,    67,
      62,     3,   128,   129,    67,   130,   133,    64,    71,    85,
     146,   147,    62,   122,   123,   124,     3,    50,    51,    52,
      54,    55,    56,    57,    58,    59,    60,    61,    63,    64,
     112,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     131,   114,   146,     3,    67,   115,   135,   136,   137,   138,
      69,   109,   113,    67,   135,   140,    69,   113,   141,    66,
      68,    98,    67,    71,    69,    65,   128,    85,    63,    71,
     117,    62,   110,   142,   146,   122,    63,   123,    65,   125,
     126,   131,    65,   113,    65,    66,    66,    66,   144,    66,
       3,    64,    64,    64,   112,    64,    63,   148,    63,   144,
      66,   131,   133,   140,    67,    71,    67,    71,    69,    67,
      67,    69,    67,   135,    69,   113,   110,   109,    63,   113,
     129,   142,   143,    63,   113,    64,    71,    65,   144,    65,
     144,   112,   112,   112,    55,   149,    64,    64,    63,    49,
     137,     3,    67,    69,    63,    71,   126,   113,   144,    67,
      67,    67,    66,   149,    63,   142,   144,   144,   144,   112,
      67,   112,    53,    67,   144,    67,   144,    64,   144
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
      

/* Line 1455 of yacc.c  */
#line 1948 "cqml_grammar.tab.g"
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
#line 447 "cqml_grammar.g"

#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
