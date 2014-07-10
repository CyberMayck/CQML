
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
#include <stdio.h>

int* createElement(int *a, char b, int *c, char * d);
int* createList(int *a, char b, int *c, char * d);
int* createAttribute(int *a, char b, char *c, char * d);
void makeSource(int *a);
//typedef struct SrcNode SrcNode;
//SrcNode* MakeNode0(char * text);
//SrcNode* MakeNode1(SrcNode* child1);
//SrcNode* MakeNode2(SrcNode* child1,SrcNode* child2);
//SrcNode* MakeNode3(SrcNode* child1,SrcNode* child2,SrcNode* child3);
//SrcNode* MakeNode4(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4);
int* MakeNode0ID(char * text);
int* MakeNode0(char * text);
int* MakeNode1(int* child1);
int* MakeNode2(int* child1,int* child2);
int* MakeNode3(int* child1,int* child2,int* child3);
int* MakeNode4(int* child1,int* child2,int* child3,int* child4);


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
     CHAR = 289,
     SHORT = 290,
     INT = 291,
     LONG = 292,
     SIGNED = 293,
     UNSIGNED = 294,
     FLOAT = 295,
     DOUBLE = 296,
     CONST = 297,
     VOLATILE = 298,
     VOID = 299,
     STRUCT = 300,
     UNION = 301,
     ENUM = 302,
     ELLIPSIS = 303,
     CASE = 304,
     DEFAULT = 305,
     IF = 306,
     ELSE = 307,
     SWITCH = 308,
     WHILE = 309,
     DO = 310,
     FOR = 311,
     GOTO = 312,
     CONTINUE = 313,
     BREAK = 314,
     RETURN = 315
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
#line 179 "cqml_grammar.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 191 "cqml_grammar.tab.c"

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
#define YYLAST   1341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  224
/* YYNRULES -- Number of states.  */
#define YYNSTATES  370

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,     2,     2,     2,    78,    71,     2,
      65,    66,    72,    73,    70,    74,    69,    77,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    63,
      79,    84,    80,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    67,     2,    68,    81,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,    82,    62,    75,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    15,    19,    23,    26,
      28,    30,    32,    38,    42,    44,    46,    48,    52,    54,
      59,    63,    68,    72,    76,    79,    82,    84,    88,    90,
      93,    96,    99,   102,   107,   109,   111,   113,   115,   117,
     119,   121,   126,   128,   132,   136,   140,   142,   146,   150,
     152,   156,   160,   162,   166,   170,   174,   178,   180,   184,
     188,   190,   194,   196,   200,   202,   206,   208,   212,   214,
     218,   220,   226,   228,   232,   234,   236,   238,   240,   242,
     244,   246,   248,   250,   252,   254,   256,   260,   262,   265,
     269,   271,   274,   276,   279,   281,   284,   286,   290,   292,
     296,   298,   300,   302,   304,   306,   308,   310,   312,   314,
     316,   318,   320,   322,   324,   326,   328,   330,   336,   341,
     344,   346,   348,   350,   353,   357,   360,   362,   365,   367,
     369,   373,   375,   378,   382,   387,   393,   396,   398,   402,
     404,   408,   410,   412,   415,   417,   419,   423,   428,   432,
     437,   442,   446,   448,   451,   454,   458,   460,   463,   465,
     469,   471,   475,   478,   481,   483,   485,   489,   491,   494,
     496,   498,   501,   505,   508,   512,   516,   521,   524,   528,
     532,   537,   539,   543,   548,   550,   554,   556,   558,   560,
     562,   564,   566,   570,   575,   579,   582,   586,   590,   595,
     597,   600,   602,   605,   607,   610,   616,   624,   630,   636,
     644,   651,   659,   663,   666,   669,   672,   676,   678,   681,
     683,   685,   690,   694,   698
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      86,     0,    -1,    87,    -1,    88,    87,    -1,    88,    -1,
       3,    61,    89,    62,    -1,     3,    61,    62,    -1,    90,
      63,    89,    -1,    90,    63,    -1,    88,    -1,    91,    -1,
      92,    -1,     3,    64,    61,   153,    62,    -1,     3,    64,
     112,    -1,     3,    -1,     4,    -1,     5,    -1,    65,   112,
      66,    -1,    93,    -1,    94,    67,   112,    68,    -1,    94,
      65,    66,    -1,    94,    65,    95,    66,    -1,    94,    69,
       3,    -1,    94,     7,     3,    -1,    94,     8,    -1,    94,
       9,    -1,   110,    -1,    95,    70,   110,    -1,    94,    -1,
       8,    96,    -1,     9,    96,    -1,    97,    98,    -1,     6,
      96,    -1,     6,    65,   139,    66,    -1,    71,    -1,    72,
      -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,    96,
      -1,    65,   139,    66,    98,    -1,    98,    -1,    99,    72,
      98,    -1,    99,    77,    98,    -1,    99,    78,    98,    -1,
      99,    -1,   100,    73,    99,    -1,   100,    74,    99,    -1,
     100,    -1,   101,    10,   100,    -1,   101,    11,   100,    -1,
     101,    -1,   102,    79,   101,    -1,   102,    80,   101,    -1,
     102,    12,   101,    -1,   102,    13,   101,    -1,   102,    -1,
     103,    14,   102,    -1,   103,    15,   102,    -1,   103,    -1,
     104,    71,   103,    -1,   104,    -1,   105,    81,   104,    -1,
     105,    -1,   106,    82,   105,    -1,   106,    -1,   107,    16,
     106,    -1,   107,    -1,   108,    17,   107,    -1,   108,    -1,
     108,    83,   112,    64,   109,    -1,   109,    -1,    96,   111,
     110,    -1,    84,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,
      26,    -1,    27,    -1,   110,    -1,   112,    70,   110,    -1,
     109,    -1,   115,    63,    -1,   115,   116,    63,    -1,   118,
      -1,   118,   115,    -1,   119,    -1,   119,   115,    -1,   130,
      -1,   130,   115,    -1,   117,    -1,   116,    70,   117,    -1,
     131,    -1,   131,    84,   142,    -1,    29,    -1,    30,    -1,
      31,    -1,    32,    -1,    33,    -1,    44,    -1,    34,    -1,
      35,    -1,    36,    -1,    37,    -1,    40,    -1,    41,    -1,
      38,    -1,    39,    -1,   120,    -1,   127,    -1,    28,    -1,
     121,     3,    61,   122,    62,    -1,   121,    61,   122,    62,
      -1,   121,     3,    -1,    45,    -1,    46,    -1,   123,    -1,
     122,   123,    -1,   124,   125,    63,    -1,   119,   124,    -1,
     119,    -1,   130,   124,    -1,   130,    -1,   126,    -1,   125,
      70,   126,    -1,   131,    -1,    64,   113,    -1,   131,    64,
     113,    -1,    47,    61,   128,    62,    -1,    47,     3,    61,
     128,    62,    -1,    47,     3,    -1,   129,    -1,   128,    70,
     129,    -1,     3,    -1,     3,    84,   113,    -1,    42,    -1,
      43,    -1,   133,   132,    -1,   132,    -1,     3,    -1,    65,
     131,    66,    -1,   132,    67,   113,    68,    -1,   132,    67,
      68,    -1,   132,    65,   135,    66,    -1,   132,    65,   138,
      66,    -1,   132,    65,    66,    -1,    72,    -1,    72,   134,
      -1,    72,   133,    -1,    72,   134,   133,    -1,   130,    -1,
     134,   130,    -1,   136,    -1,   136,    70,    48,    -1,   137,
      -1,   136,    70,   137,    -1,   115,   131,    -1,   115,   140,
      -1,   115,    -1,     3,    -1,   138,    70,     3,    -1,   124,
      -1,   124,   140,    -1,   133,    -1,   141,    -1,   133,   141,
      -1,    65,   140,    66,    -1,    67,    68,    -1,    67,   113,
      68,    -1,   141,    67,    68,    -1,   141,    67,   113,    68,
      -1,    65,    66,    -1,    65,   135,    66,    -1,   141,    65,
      66,    -1,   141,    65,   135,    66,    -1,   110,    -1,    61,
     143,    62,    -1,    61,   143,    70,    62,    -1,   142,    -1,
     143,    70,   142,    -1,   145,    -1,   146,    -1,   149,    -1,
     150,    -1,   151,    -1,   152,    -1,     3,    64,   144,    -1,
      49,   113,    64,   144,    -1,    50,    64,   144,    -1,    61,
      62,    -1,    61,   148,    62,    -1,    61,   147,    62,    -1,
      61,   147,   148,    62,    -1,   114,    -1,   147,   114,    -1,
     144,    -1,   148,   144,    -1,    63,    -1,   112,    63,    -1,
      51,    65,   112,    66,   144,    -1,    51,    65,   112,    66,
     144,    52,   144,    -1,    53,    65,   112,    66,   144,    -1,
      54,    65,   112,    66,   144,    -1,    55,   144,    54,    65,
     112,    66,    63,    -1,    56,    65,   149,   149,    66,   144,
      -1,    56,    65,   149,   149,   112,    66,   144,    -1,    57,
       3,    63,    -1,    58,    63,    -1,    59,    63,    -1,    60,
      63,    -1,    60,   112,    63,    -1,   154,    -1,   153,   154,
      -1,   155,    -1,   114,    -1,   115,   131,   147,   146,    -1,
     115,   131,   146,    -1,   131,   147,   146,    -1,   131,   146,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    25,    25,    30,    32,    37,    39,    44,    46,    52,
      54,    55,    60,    64,    69,    71,    73,    75,    80,    82,
      84,    86,    88,    90,    92,    94,    99,   101,   106,   108,
     110,   112,   114,   116,   121,   123,   125,   127,   129,   131,
     136,   138,   144,   146,   148,   150,   155,   157,   159,   164,
     166,   168,   173,   175,   177,   179,   181,   186,   188,   190,
     195,   197,   202,   204,   209,   211,   216,   218,   223,   225,
     230,   232,   237,   239,   244,   246,   248,   250,   252,   254,
     256,   258,   260,   262,   264,   269,   271,   276,   281,   282,
     286,   287,   288,   289,   290,   291,   295,   296,   300,   301,
     305,   306,   307,   308,   309,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   328,   329,   330,
     334,   335,   339,   340,   344,   348,   349,   350,   351,   355,
     356,   360,   361,   362,   366,   367,   368,   372,   373,   377,
     378,   382,   383,   387,   388,   392,   393,   394,   395,   396,
     397,   398,   402,   403,   404,   405,   409,   410,   415,   416,
     420,   421,   425,   426,   427,   431,   432,   436,   437,   441,
     442,   443,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   459,   460,   461,   465,   466,   470,   471,   472,   473,
     474,   475,   479,   480,   481,   485,   486,   487,   488,   492,
     493,   497,   498,   502,   503,   507,   508,   509,   513,   514,
     515,   516,   520,   521,   522,   523,   524,   528,   529,   533,
     534,   538,   539,   540,   541
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
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "'{'", "'}'", "';'", "':'", "'('", "')'",
  "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "$accept",
  "start_point", "element_list", "element", "attribute_or_subelement_list",
  "attribute_or_element", "event_handler", "attribute",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
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
     315,   123,   125,    59,    58,    40,    41,    91,    93,    46,
      44,    38,    42,    43,    45,   126,    33,    47,    37,    60,
      62,    94,   124,    63,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    90,    91,    92,    93,    93,    93,    93,    94,    94,
      94,    94,    94,    94,    94,    94,    95,    95,    96,    96,
      96,    96,    96,    96,    97,    97,    97,    97,    97,    97,
      98,    98,    99,    99,    99,    99,   100,   100,   100,   101,
     101,   101,   102,   102,   102,   102,   102,   103,   103,   103,
     104,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     109,   109,   110,   110,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   112,   112,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   116,   116,   117,   117,
     118,   118,   118,   118,   118,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   120,   120,   120,
     121,   121,   122,   122,   123,   124,   124,   124,   124,   125,
     125,   126,   126,   126,   127,   127,   127,   128,   128,   129,
     129,   130,   130,   131,   131,   132,   132,   132,   132,   132,
     132,   132,   133,   133,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   137,   138,   138,   139,   139,   140,
     140,   140,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   142,   142,   142,   143,   143,   144,   144,   144,   144,
     144,   144,   145,   145,   145,   146,   146,   146,   146,   147,
     147,   148,   148,   149,   149,   150,   150,   150,   151,   151,
     151,   151,   152,   152,   152,   152,   152,   153,   153,   154,
     154,   155,   155,   155,   155
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     4,     3,     3,     2,     1,
       1,     1,     5,     3,     1,     1,     1,     3,     1,     4,
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
       6,     7,     3,     2,     2,     2,     3,     1,     2,     1,
       1,     4,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     0,     6,
       9,     0,     0,    10,    11,     0,     5,     8,    14,    15,
      16,     0,     0,     0,     0,     0,    34,    35,    36,    37,
      38,    39,    18,    28,    40,     0,    42,    46,    49,    52,
      57,    60,    62,    64,    66,    68,    70,    72,    85,    13,
       7,     0,    32,     0,    29,    30,   145,   116,   100,   101,
     102,   103,   104,   106,   107,   108,   109,   112,   113,   110,
     111,   141,   142,   105,   120,   121,     0,     0,   152,   220,
       0,    90,    92,   114,     0,   115,    94,     0,   144,     0,
       0,   217,   219,     0,   126,   167,   128,     0,     0,    24,
      25,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    74,     0,    40,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
       0,     0,   156,   154,   153,    88,     0,    96,    98,    91,
      93,   119,     0,    95,     0,   199,     0,   224,     0,     0,
       0,   143,    12,   218,    17,   125,     0,     0,   169,   168,
     170,   127,     0,    23,    20,     0,    26,     0,    22,    73,
      43,    44,    45,    47,    48,    50,    51,    55,    56,    53,
      54,    58,    59,    61,    63,    65,    67,    69,     0,    86,
      33,     0,   139,     0,   137,   146,   157,   155,    89,     0,
       0,   222,     0,     0,     0,   122,     0,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   195,
     203,     0,   201,   186,   187,     0,     0,   188,   189,   190,
     191,    98,   200,   223,   165,   151,   164,     0,   158,   160,
       0,   148,    87,     0,   177,     0,     0,   173,     0,   171,
       0,     0,    41,    21,     0,    19,     0,     0,     0,   134,
       0,    97,     0,   181,    99,   221,     0,   118,   123,     0,
       0,   129,   131,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   213,   214,   215,     0,   204,   197,     0,   196,
     202,     0,   162,   169,   163,   149,     0,   150,     0,   147,
     178,   172,   174,   179,     0,   175,     0,    27,    71,   135,
     140,   138,   184,     0,   117,   132,   124,     0,     0,   192,
       0,   194,     0,     0,     0,     0,     0,   212,   216,   198,
     159,   161,   166,   180,   176,   182,     0,   130,   133,   193,
       0,     0,     0,     0,     0,   183,   185,   205,   207,   208,
       0,     0,     0,     0,     0,   210,     0,   206,   209,   211
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    11,    12,    13,    14,    32,    33,
     175,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,   115,   231,   253,   155,
     156,   146,   147,    81,    82,    83,    84,   214,   215,   216,
     280,   281,    85,   203,   204,    86,    87,    88,    89,   144,
     255,   248,   249,   250,    97,   256,   170,   274,   323,   232,
     233,   234,   158,   236,   237,   238,   239,   240,    90,    91,
      92
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -278
static const yytype_int16 yypact[] =
{
      28,    16,    41,  -278,    28,    55,  -278,  -278,    78,  -278,
    -278,     3,    62,  -278,  -278,   640,  -278,   166,  -278,  -278,
    -278,   768,   842,   842,   993,   460,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,   180,   868,   854,  -278,   118,    81,    43,
      57,   229,   114,    82,   123,   198,     7,  -278,  -278,   148,
    -278,   460,  -278,   854,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,    17,    92,     4,  -278,
      20,  1274,  1274,  -278,    58,  -278,  1274,  1219,   150,    26,
     948,  -278,  -278,    -4,  1294,   -16,  1294,   163,   223,  -278,
    -278,   231,   854,   247,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,   854,  -278,  -278,   854,   854,
     854,   854,   854,   854,   854,   854,   854,   854,   854,   854,
     854,   854,   854,   854,   854,   854,   854,   854,   188,   202,
     262,   200,  -278,  -278,     4,  -278,   -35,  -278,   836,  -278,
    -278,   206,  1294,  -278,   312,  -278,    20,  -278,  1219,  1038,
     328,   150,  -278,  -278,  -278,  -278,  1077,   402,   160,  -278,
     165,  -278,   854,  -278,  -278,   105,  -278,   183,  -278,  -278,
    -278,  -278,  -278,   118,   118,    81,    81,    43,    43,    43,
      43,    57,    57,   229,   114,    82,   123,   198,    80,  -278,
    -278,   262,   184,   -28,  -278,  -278,  -278,  -278,  -278,    92,
     714,  -278,  1219,  1294,  1155,  -278,    94,   210,   854,   211,
     214,   215,   216,   608,   217,   281,   222,   227,   728,  -278,
    -278,   102,  -278,  -278,  -278,   386,   505,  -278,  -278,  -278,
    -278,   207,  -278,  -278,  -278,  -278,   119,   220,   224,  -278,
     111,  -278,  -278,   225,  -278,   232,   233,  -278,   241,   165,
    1122,   476,  -278,  -278,   854,  -278,   854,   -22,   854,  -278,
     262,  -278,   714,  -278,  -278,  -278,  1184,  -278,  -278,   854,
     104,  -278,   236,   608,   237,   608,   854,   854,   854,   256,
     742,   248,  -278,  -278,  -278,   110,  -278,  -278,   534,  -278,
    -278,   903,  -278,    68,  -278,  -278,  1253,  -278,   292,  -278,
    -278,  -278,  -278,  -278,   246,  -278,   245,  -278,  -278,  -278,
    -278,  -278,  -278,   -10,  -278,  -278,  -278,    94,   854,  -278,
     608,  -278,   131,   136,   137,   249,   742,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,   624,  -278,  -278,  -278,
     608,   608,   608,   854,   754,  -278,  -278,   267,  -278,  -278,
     138,   608,   146,   608,   259,  -278,   608,  -278,  -278,  -278
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -278,  -278,   319,    22,   307,  -278,  -278,  -278,  -278,  -278,
    -278,   -20,  -278,    10,   139,   134,    95,   140,   194,   195,
     193,   196,   243,  -278,  -134,   -94,  -278,   -15,  -100,    -2,
     -18,  -278,   120,  -278,   -14,  -278,  -278,   115,  -182,    30,
    -278,     8,  -278,   159,   106,   -21,   -63,   -84,   -70,  -278,
    -140,  -278,    73,  -278,   313,   -86,  -152,  -260,  -278,   -74,
    -278,   -69,  -104,   145,  -277,  -278,  -278,  -278,  -278,   291,
    -278
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      49,    52,    54,    55,    96,   161,    80,   176,   143,   169,
      93,    94,   322,   336,   141,   116,   259,   148,   157,   247,
     139,   179,    79,    56,   135,   168,   252,    10,   208,    56,
      96,     1,   278,   252,   269,   209,    93,    94,    93,    10,
     319,     6,   270,   199,   212,   117,    71,    72,   270,   166,
     235,   167,   345,   123,   124,    95,    78,   142,     8,   354,
     346,   151,   164,   149,   150,    16,   137,   258,   153,   125,
     126,    56,    80,    96,   207,    96,    78,     5,   140,   211,
      94,    95,    94,   145,   252,    77,   356,   177,    79,   243,
     136,    77,    78,   241,   278,    56,   168,    56,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   273,     9,   284,   152,
     314,   198,    56,   206,   165,    17,   171,   252,   180,   181,
     182,    96,   318,   301,   252,   167,   127,   128,    94,     5,
     116,   246,    15,   275,   266,   252,   241,   116,   246,   289,
     137,   259,   116,   282,   121,   122,   242,    77,   279,    77,
     304,   316,   300,   132,    78,   296,    78,   326,   320,     8,
     317,   263,   137,   338,   327,   264,   303,   307,   273,   325,
     137,   308,   262,   302,   301,   131,   167,    98,    99,   100,
     118,    78,    96,    96,   252,   119,   120,   350,   116,    94,
      94,   137,   351,   352,   364,   133,   137,   137,   137,   329,
     242,   331,   366,   295,   134,   159,   137,   160,   137,   161,
     187,   188,   189,   190,   300,   166,   173,   167,   348,   172,
     260,   303,   261,   242,    18,    19,    20,    21,   141,    22,
      23,   116,   246,   129,   130,   101,   116,   102,   116,   103,
     178,   265,   273,   137,   200,    96,   349,   185,   186,   116,
     183,   184,    94,   201,   282,   202,   205,   213,   268,   191,
     192,   332,   333,   334,   283,   285,   357,   358,   359,   286,
     287,   288,   290,   246,   291,   292,   305,   365,   246,   367,
     293,   210,   369,   309,   306,   342,    25,   174,   310,   311,
     328,   330,    26,    27,    28,    29,    30,    31,   116,   312,
     335,   337,   343,   344,   353,   217,    19,    20,    21,   363,
      22,    23,   368,     7,    50,   193,   195,   194,   276,   271,
     196,    18,    19,    20,    21,   347,    22,    23,   360,   362,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
     267,   218,   219,   220,   138,   221,   222,   223,   224,   225,
     226,   227,   228,   154,   229,   230,   321,    25,   197,   341,
     298,   163,     0,    26,    27,    28,    29,    30,    31,   217,
      19,    20,    21,    25,    22,    23,   251,     0,     0,    26,
      27,    28,    29,    30,    31,    18,    19,    20,    21,     0,
      22,    23,     0,     0,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,     0,   218,   219,   220,     0,   221,
     222,   223,   224,   225,   226,   227,   228,   154,   297,   230,
       0,    25,     0,     0,     0,     0,     0,    26,    27,    28,
      29,    30,    31,    18,    19,    20,    21,    25,    22,    23,
     257,     0,     0,    26,    27,    28,    29,    30,    31,    18,
      19,    20,    21,     0,    22,    23,     0,     0,    57,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,   217,    19,
      20,    21,     0,    22,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,     0,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,   217,    19,    20,
      21,    25,    22,    23,   315,     0,     0,    26,    27,    28,
      29,    30,    31,     0,   218,   219,   220,     0,   221,   222,
     223,   224,   225,   226,   227,   228,   154,   299,   230,     0,
      25,     0,     0,     0,     0,     0,    26,    27,    28,    29,
      30,    31,     0,   218,   219,   220,     0,   221,   222,   223,
     224,   225,   226,   227,   228,   154,   339,   230,     0,    25,
       0,     0,     0,     0,     0,    26,    27,    28,    29,    30,
      31,   217,    19,    20,    21,     0,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    20,
      21,     0,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    19,    20,    21,     0,    22,    23,
       0,     0,     0,     0,     0,     0,     0,   218,   219,   220,
       0,   221,   222,   223,   224,   225,   226,   227,   228,   154,
       0,   230,     0,    25,     0,     0,     0,     0,     0,    26,
      27,    28,    29,    30,    31,   272,   355,     0,     0,    25,
       0,     0,     0,     0,     0,    26,    27,    28,    29,    30,
      31,    24,     0,     0,     0,    25,     0,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,    18,    19,    20,
      21,     0,    22,    23,     0,     0,     0,     0,     0,     0,
       0,    18,    19,    20,    21,     0,    22,    23,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,     0,
      22,    23,     0,     0,     0,     0,     0,    18,    19,    20,
      21,     0,    22,    23,     0,     0,     0,     0,     0,     0,
       0,    18,    19,    20,    21,   272,    22,    23,     0,    25,
       0,     0,     0,     0,     0,    26,    27,    28,    29,    30,
      31,   294,     0,    25,     0,     0,     0,     0,     0,    26,
      27,    28,    29,    30,    31,   230,     0,    25,     0,     0,
       0,     0,     0,    26,    27,    28,    29,    30,    31,    25,
     361,     0,     0,     0,     0,    26,    27,    28,    29,    30,
      31,     0,     0,    51,     0,     0,     0,     0,     0,    26,
      27,    28,    29,    30,    31,    18,    19,    20,    21,     0,
      22,    23,     0,     0,     0,     0,     0,    18,    19,    20,
      21,     0,    22,    23,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     0,   154,     0,     0,
       0,     0,     0,     0,     0,     0,    56,    53,     0,     0,
       0,     0,     0,    26,    27,    28,    29,    30,    31,    25,
     210,     0,     0,     0,     0,    26,    27,    28,    29,    30,
      31,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    56,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   301,   254,
     167,     0,     0,     0,     0,    78,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,     0,     0,    77,     0,     0,     0,     0,     0,     0,
      78,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,     0,     0,    78,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,   254,   167,     0,     0,     0,     0,    78,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,   313,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,     0,     0,     0,   277,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   324,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,   340,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    57,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

static const yytype_int16 yycheck[] =
{
      15,    21,    22,    23,    25,    89,    24,   101,    78,    95,
      25,    25,   272,   290,    77,    35,   168,    80,    87,   159,
       3,   115,    24,     3,    17,    95,   160,     5,    63,     3,
      51,     3,   214,   167,    62,    70,    51,    51,    53,    17,
      62,     0,    70,   137,   148,    35,    42,    43,    70,    65,
     154,    67,    62,    10,    11,    25,    72,    78,     3,   336,
      70,     3,    66,    81,    82,    62,    70,   167,    86,    12,
      13,     3,    90,    94,   144,    96,    72,    61,    61,   148,
      94,    51,    96,    63,   218,    65,   346,   102,    90,   158,
      83,    65,    72,   156,   276,     3,   166,     3,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   210,    62,   218,    61,
     260,   136,     3,   144,    94,    63,    96,   261,   118,   119,
     120,   152,   266,    65,   268,    67,    79,    80,   152,    61,
     160,   159,    64,   212,    64,   279,   209,   167,   166,   223,
      70,   303,   172,   216,    73,    74,   158,    65,    64,    65,
     246,   261,   236,    81,    72,    63,    72,    63,   268,     3,
     264,    66,    70,    63,    70,    70,   246,    66,   272,   279,
      70,    70,   172,   246,    65,    71,    67,     7,     8,     9,
      72,    72,   213,   214,   328,    77,    78,    66,   218,   213,
     214,    70,    66,    66,    66,    82,    70,    70,    70,   283,
     212,   285,    66,   228,    16,    65,    70,    67,    70,   303,
     125,   126,   127,   128,   298,    65,     3,    67,   328,    66,
      65,   301,    67,   235,     3,     4,     5,     6,   301,     8,
       9,   261,   260,    14,    15,    65,   266,    67,   268,    69,
       3,    68,   346,    70,    66,   276,   330,   123,   124,   279,
     121,   122,   276,    61,   327,     3,    66,    61,    84,   129,
     130,   286,   287,   288,    64,    64,   350,   351,   352,    65,
      65,    65,    65,   301,     3,    63,    66,   361,   306,   363,
      63,    84,   366,    68,    70,     3,    65,    66,    66,    66,
      64,    64,    71,    72,    73,    74,    75,    76,   328,    68,
      54,    63,    66,    68,    65,     3,     4,     5,     6,    52,
       8,     9,    63,     4,    17,   131,   133,   132,   213,   209,
     134,     3,     4,     5,     6,   327,     8,     9,   353,   354,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
     201,    49,    50,    51,    51,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,   270,    65,   135,   306,
     235,    90,    -1,    71,    72,    73,    74,    75,    76,     3,
       4,     5,     6,    65,     8,     9,    68,    -1,    -1,    71,
      72,    73,    74,    75,    76,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,     3,     4,     5,     6,    65,     8,     9,
      68,    -1,    -1,    71,    72,    73,    74,    75,    76,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,     3,     4,     5,
       6,    65,     8,     9,    68,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,    49,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    -1,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    63,    -1,    65,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    61,    62,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    61,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    61,     8,     9,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    63,    -1,    65,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    63,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    65,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    65,
      84,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     3,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    -1,    -1,    72,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    -1,    -1,    72,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    66,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    62,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    86,    87,    88,    61,     0,    87,     3,    62,
      88,    89,    90,    91,    92,    64,    62,    63,     3,     4,
       5,     6,     8,     9,    61,    65,    71,    72,    73,    74,
      75,    76,    93,    94,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   112,
      89,    65,    96,    65,    96,    96,     3,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    65,    72,   114,
     115,   118,   119,   120,   121,   127,   130,   131,   132,   133,
     153,   154,   155,   112,   119,   124,   130,   139,     7,     8,
       9,    65,    67,    69,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    84,   111,    96,    98,    72,    77,
      78,    73,    74,    10,    11,    12,    13,    79,    80,    14,
      15,    71,    81,    82,    16,    17,    83,    70,   139,     3,
      61,   131,   130,   133,   134,    63,   116,   117,   131,   115,
     115,     3,    61,   115,    61,   114,   115,   146,   147,    65,
      67,   132,    62,   154,    66,   124,    65,    67,   133,   140,
     141,   124,    66,     3,    66,    95,   110,   112,     3,   110,
      98,    98,    98,    99,    99,   100,   100,   101,   101,   101,
     101,   102,   102,   103,   104,   105,   106,   107,   112,   110,
      66,    61,     3,   128,   129,    66,   130,   133,    63,    70,
      84,   146,   147,    61,   122,   123,   124,     3,    49,    50,
      51,    53,    54,    55,    56,    57,    58,    59,    60,    62,
      63,   112,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   131,   114,   146,     3,    66,   115,   135,   136,   137,
     138,    68,   109,   113,    66,   135,   140,    68,   113,   141,
      65,    67,    98,    66,    70,    68,    64,   128,    84,    62,
      70,   117,    61,   110,   142,   146,   122,    62,   123,    64,
     125,   126,   131,    64,   113,    64,    65,    65,    65,   144,
      65,     3,    63,    63,    63,   112,    63,    62,   148,    62,
     144,    65,   131,   133,   140,    66,    70,    66,    70,    68,
      66,    66,    68,    66,   135,    68,   113,   110,   109,    62,
     113,   129,   142,   143,    62,   113,    63,    70,    64,   144,
      64,   144,   112,   112,   112,    54,   149,    63,    63,    62,
      48,   137,     3,    66,    68,    62,    70,   126,   113,   144,
      66,    66,    66,    65,   149,    62,   142,   144,   144,   144,
     112,    66,   112,    52,    66,   144,    66,   144,    63,   144
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
    { makeSource( (yyvsp[(1) - (1)].data.val)); ;}
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

  case 11:

/* Line 1455 of yacc.c  */
#line 56 "cqml_grammar.g"
    { (yyval.data.val) = (yyvsp[(1) - (1)].data.val); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 65 "cqml_grammar.g"
    { (yyval.data.val) = createAttribute( (yyvsp[(1) - (3)].data.val) , 'l', (yyvsp[(1) - (3)].data.val), (yyvsp[(3) - (3)].data.val));  ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 70 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0ID((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 72 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 74 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 76 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3(MakeNode0("("), (yyvsp[(2) - (3)].data.val) ,MakeNode0(")")); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 81 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 83 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("["), (yyvsp[(3) - (4)].data.val),MakeNode0("]")); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 85 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("(") ,MakeNode0(")")); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 87 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4((yyvsp[(1) - (4)].data.val), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 89 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("."), MakeNode0ID((yyvsp[(3) - (3)].data.lexem))); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 91 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), MakeNode0ID((yyvsp[(3) - (3)].data.lexem))); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 93 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0((yyvsp[(2) - (2)].data.lexem))); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 95 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), MakeNode0((yyvsp[(2) - (2)].data.lexem))); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 100 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 102 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 107 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 109 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 111 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 113 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2((yyvsp[(1) - (2)].data.val), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 115 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode2(MakeNode0((yyvsp[(1) - (2)].data.lexem)), (yyvsp[(2) - (2)].data.val)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 117 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4(MakeNode0((yyvsp[(1) - (4)].data.lexem)), MakeNode0("("), (yyvsp[(3) - (4)].data.val), MakeNode0(")")); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 122 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("&"); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 124 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("*"); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 126 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("+"); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 128 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("-"); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 130 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("~"); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 132 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("!"); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 137 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 139 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode4(MakeNode0("("), (yyvsp[(2) - (4)].data.val), MakeNode0(")"), (yyvsp[(4) - (4)].data.val)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 145 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 147 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("*"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 149 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("/"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 151 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("%"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 156 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 158 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("+"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 160 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("-"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 165 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 167 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 169 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 174 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 176 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("<"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 178 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(">"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 180 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 182 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 187 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 189 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 191 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 196 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 198 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("&"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 203 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 205 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("^"), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 210 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 212 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0("|"), (yyvsp[(3) - (3)].data.val)); ;}
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
#line 224 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 226 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0((yyvsp[(2) - (3)].data.lexem)), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 231 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 233 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (5)].data.val), MakeNode0("?"), MakeNode3((yyvsp[(3) - (5)].data.val), MakeNode0(":"),(yyvsp[(5) - (5)].data.val))); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 238 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 240 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), (yyvsp[(2) - (3)].data.val), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 245 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0("="); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 247 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 249 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 251 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 253 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 255 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 257 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 259 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 261 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 263 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 265 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode0((yyvsp[(1) - (1)].data.lexem)); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 270 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 272 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode3((yyvsp[(1) - (3)].data.val), MakeNode0(","), (yyvsp[(3) - (3)].data.val)); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 277 "cqml_grammar.g"
    { (yyval.data.val) = MakeNode1((yyvsp[(1) - (1)].data.val)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2552 "cqml_grammar.tab.c"
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
#line 544 "cqml_grammar.g"

#include <stdio.h>

int* createElement(int *a, char b, int *c, char * d);
int* createList(int *a, char b, int *c, char * d);
int* createAttribute(int *a, char b, char *c, char * d);
void makeSource(int *a);
//typedef struct SrcNode SrcNode;
//SrcNode* MakeNode0(char * text);
//SrcNode* MakeNode1(SrcNode* child1);
//SrcNode* MakeNode2(SrcNode* child1,SrcNode* child2);
//SrcNode* MakeNode3(SrcNode* child1,SrcNode* child2,SrcNode* child3);
//SrcNode* MakeNode4(SrcNode* child1,SrcNode* child2,SrcNode* child3,SrcNode* child4);
int* MakeNode0ID(char * text);
int* MakeNode0(char * text);
int* MakeNode1(int* child1);
int* MakeNode2(int* child1,int* child2);
int* MakeNode3(int* child1,int* child2,int* child3);
int* MakeNode4(int* child1,int* child2,int* child3,int* child4);

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

