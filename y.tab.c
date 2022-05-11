/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "compiler_hw2.y" /* yacc.c:339  */

    #include "compiler_hw_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    typedef struct symtable_node symtable_type;
    struct symtable_node{
        int level;
        int index;
        char* name;
        char* type;
        int address;
        int lineno;
        char* func_sig;
        symtable_type* next;
    };

    typedef struct symtable_stack_node symtable_stack_type;
    struct symtable_stack_node{
        symtable_type* table;
        int level;
        symtable_stack_type* next;
    };

    static void create_symbol();
    static void insert_symbol(char* name, char* type, char* Func_sig);
    static symtable_type* lookup_symbol(char * name);
    static void dump_symbol();
    /* Global variables */
    bool HAS_ERROR = false;

    char *str_funct_name;
    char *funct_parameter;

#line 117 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    NEWLINE = 259,
    INT = 260,
    FLOAT = 261,
    BOOL = 262,
    STRING = 263,
    INC = 264,
    DEC = 265,
    GEQ = 266,
    LOR = 267,
    LAND = 268,
    EQ = 269,
    LEQ = 270,
    NEQ = 271,
    ADD_ASSIGN = 272,
    SUB_ASSIGN = 273,
    MUL_ASSIGN = 274,
    DIV_ASSIGN = 275,
    MOD_ASSIGN = 276,
    IF = 277,
    ELSE = 278,
    FOR = 279,
    SWITCH = 280,
    CASE = 281,
    FUNC = 282,
    PRINT = 283,
    PACKAGE = 284,
    RETURN = 285,
    PRINTLN = 286,
    DEFAULT = 287,
    INT_LIT = 288,
    STRING_LIT = 289,
    BOOL_LIT = 290,
    FLOAT_LIT = 291,
    IDENT = 292
  };
#endif
/* Tokens.  */
#define VAR 258
#define NEWLINE 259
#define INT 260
#define FLOAT 261
#define BOOL 262
#define STRING 263
#define INC 264
#define DEC 265
#define GEQ 266
#define LOR 267
#define LAND 268
#define EQ 269
#define LEQ 270
#define NEQ 271
#define ADD_ASSIGN 272
#define SUB_ASSIGN 273
#define MUL_ASSIGN 274
#define DIV_ASSIGN 275
#define MOD_ASSIGN 276
#define IF 277
#define ELSE 278
#define FOR 279
#define SWITCH 280
#define CASE 281
#define FUNC 282
#define PRINT 283
#define PACKAGE 284
#define RETURN 285
#define PRINTLN 286
#define DEFAULT 287
#define INT_LIT 288
#define STRING_LIT 289
#define BOOL_LIT 290
#define FLOAT_LIT 291
#define IDENT 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 61 "compiler_hw2.y" /* yacc.c:355  */

    struct{
	union{
 		int i_val;
		float f_val;
		char *s_val;
		bool b_val;
        }value;
    	char * type;
    }item;   

#line 243 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 260 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   205

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    50,     2,     2,    48,     2,     2,
      38,    39,    46,    44,    53,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
      42,    51,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    40,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   106,   107,   111,   112,   113,   117,   121,
     125,   134,   143,   147,   151,   152,   153,   154,   158,   159,
     162,   163,   167,   168,   172,   173,   177,   178,   182,   183,
     187,   188,   192,   193,   197,   201,   202,   203,   204,   208,
     209,   213,   214,   218,   219,   220,   224,   225,   226,   230,
     231,   235,   237,   242,   247,   253,   258,   264,   271,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   297,
     301,   302,   306,   307,   308,   309,   310,   311,   315,   319,
     322,   326,   327,   331,   332,   333,   337,   341,   342,   346,
     350,   354,   358,   362,   363,   367,   371,   372,   376,   377,
     378,   379,   383,   384,   385,   389,   390,   394,   395
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "NEWLINE", "INT", "FLOAT", "BOOL",
  "STRING", "INC", "DEC", "GEQ", "LOR", "LAND", "EQ", "LEQ", "NEQ",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "IF", "ELSE", "FOR", "SWITCH", "CASE", "FUNC", "PRINT", "PACKAGE",
  "RETURN", "PRINTLN", "DEFAULT", "INT_LIT", "STRING_LIT", "BOOL_LIT",
  "FLOAT_LIT", "IDENT", "'('", "')'", "'}'", "'{'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "'\"'", "'='", "';'", "','",
  "$accept", "Program", "GlobalStatementList", "GlobalStatement",
  "PackageStmt", "FunctionDeclStmt", "FuncParameter", "FuncOpen",
  "FuncBlock", "FunctionUpBlock", "UnaryExpr", "cast_expression",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "assignment_expression", "Expression", "rel_op",
  "equ_op", "add_op", "mul_op", "unary_op", "PrimaryExpr", "Operand",
  "Literal", "ConversionExpr", "Statement", "SimpleStmt",
  "DeclarationStmt", "assign_op", "ExpressionStmt", "Block", "BlockUp",
  "StatementList", "IfStmt", "Condition", "ForStmt", "ForClause",
  "InitStmt", "PostStmt", "SwitchStmt", "CaseStmt", "CaseUp", "ReturnType",
  "Type", "ParameterList", "ReturnStmt", "PrintStmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    40,    41,
     125,   123,    60,    62,    43,    45,    42,    47,    37,    33,
      34,    61,    59,    44
};
# endif

#define YYPACT_NINF -56

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-56)))

#define YYTABLE_NINF -87

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -56,     6,    10,    59,    11,   -56,    60,   -56,    25,
     -56,   -56,   -56,   -56,   -56,    30,    21,    21,   -22,   -56,
     -56,   -56,   -56,    24,   -56,   -56,   -56,    31,   -56,   -56,
     109,    21,    35,   -56,   155,   155,   155,    41,    37,   155,
      39,    32,   -56,   -56,   -56,   -56,   155,   -56,   -56,   -56,
     -56,    44,     2,   -56,   -14,    -8,     3,    28,    66,    68,
     -56,   -56,   155,   -56,   -56,   -56,   -56,   109,    77,    78,
     -56,   -56,   109,    43,   -56,   -56,   -56,   -56,    32,    46,
      81,    82,   -56,    21,   -56,    32,    47,   -56,    32,    32,
      38,    32,   -56,   155,   -56,   155,   -56,    48,    17,    45,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   155,   -56,
     -56,   -56,   155,   -56,   -56,   155,   -56,   -56,   -56,   -56,
     155,   -56,   -56,   155,   155,   155,    40,   -56,   -56,   -56,
     -56,    49,   -56,   -56,   155,   -56,   -56,    42,    71,   -56,
     -56,   155,   -56,    57,    58,   -56,   155,   -56,   -56,   -56,
     -14,    -8,     3,    28,    66,   -56,    61,   155,    -6,    50,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   155,   -56,   -56
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     0,     0,     0,     2,     4,     0,     6,     0,
      11,     8,     1,     3,     5,   102,    96,     0,     0,    98,
      99,   101,   100,     0,    97,   103,    10,     0,    13,     9,
       0,     0,     0,    68,     0,     0,     0,     0,     0,   106,
       0,     0,    54,    56,    55,    52,     0,    80,    46,    47,
      48,     0,    18,    20,    22,    24,    26,    28,    30,    32,
      34,    78,     0,    14,    49,    51,    50,    82,     0,     0,
      69,    61,     0,     0,    62,    63,    64,    65,     0,     0,
       0,     0,   104,     0,    86,     0,    78,    90,     0,     0,
       0,     0,    95,     0,   105,     0,    94,     0,     0,     0,
      15,    16,    73,    74,    75,    76,    77,    72,     0,    43,
      44,    45,     0,    41,    42,     0,    38,    36,    35,    37,
       0,    39,    40,     0,     0,     0,    18,    17,    81,    60,
      59,     0,    12,    93,     0,    67,    66,    70,    83,    88,
      87,     0,    92,     0,     0,    53,     0,    57,    33,    21,
      23,    25,    27,    29,    31,    79,     0,     0,     0,     0,
     107,   108,    19,    58,    71,    85,    84,     0,    91,    89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,   -56,    93,   -56,   -56,   -56,   -56,   -56,   -56,
     -54,   -55,   -16,   -17,   -19,   -18,   -20,   -56,    -1,   -33,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -35,   -56,   -56,   -56,   -37,   -56,   -42,   -49,   -30,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,    -7,   -56,   -56,
     -56
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    16,     9,    29,    30,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
     120,   123,   115,   112,    62,    63,    64,    65,    66,    67,
      68,    69,   108,    70,    71,    72,    73,    74,    85,    75,
      89,    90,   169,    76,    77,    78,    23,    79,    18,    80,
      81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,    84,    86,    91,    96,    88,    94,   127,   126,    24,
      25,   100,   101,    97,   116,     1,    34,    26,   117,   102,
     103,   104,   105,   106,    82,   128,    19,    20,    21,    22,
     131,    27,   109,   110,   111,    47,   113,   114,     2,    98,
       3,   133,   121,    10,   122,   118,   119,    11,   138,   100,
     101,   139,   140,   107,   142,   134,   146,   149,   126,    12,
     143,   126,   144,    15,    14,    28,   126,    17,    31,   126,
     126,   126,    83,    47,    92,    93,   137,    95,    99,   124,
     125,   129,   130,   132,   134,   135,   136,   145,   -86,   155,
     141,   162,   126,   157,   158,   147,   160,   161,    13,   150,
     163,   156,   167,   151,   152,   154,   153,   148,    84,   166,
       0,   159,    32,    33,    19,    20,    21,    22,     0,     0,
       0,   165,     0,     0,   164,     0,     0,     0,     0,     0,
       0,    34,   168,    35,    36,    37,     0,    38,     0,    39,
      40,    41,    42,     0,    43,    44,    45,    46,     0,     0,
      47,     0,     0,    48,    49,     0,     0,     0,    50,    51,
      19,    20,    21,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,     0,
      43,    44,    45,    46,     0,     0,     0,     0,     0,    48,
      49,     0,     0,     0,    50,    51
};

static const yytype_int16 yycheck[] =
{
      35,    34,    35,    36,    41,    35,    39,    62,    62,    16,
      17,     9,    10,    46,    11,     4,    22,    39,    15,    17,
      18,    19,    20,    21,    31,    67,     5,     6,     7,     8,
      72,    53,    46,    47,    48,    41,    44,    45,    27,    46,
      29,    78,    14,    37,    16,    42,    43,    37,    85,     9,
      10,    88,    89,    51,    91,    38,    39,   112,   112,     0,
      93,   115,    95,    38,     4,    41,   120,    37,    37,   123,
     124,   125,    37,    41,    33,    38,    83,    38,    34,    13,
      12,     4,     4,    40,    38,     4,     4,    39,    41,    40,
      52,   146,   146,    51,    23,    50,    39,    39,     5,   115,
      39,   134,    52,   120,   123,   125,   124,   108,   141,   158,
      -1,   141,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,   158,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    22,   167,    24,    25,    26,    -1,    28,    -1,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    -1,
      41,    -1,    -1,    44,    45,    -1,    -1,    -1,    49,    50,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    27,    29,    55,    56,    57,    58,    59,    61,
      37,    37,     0,    57,     4,    38,    60,    37,   102,     5,
       6,     7,     8,   100,   101,   101,    39,    53,    41,    62,
      63,    37,     3,     4,    22,    24,    25,    26,    28,    30,
      31,    32,    33,    35,    36,    37,    38,    41,    44,    45,
      49,    50,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    78,    79,    80,    81,    82,    83,    84,    85,
      87,    88,    89,    90,    91,    93,    97,    98,    99,   101,
     103,   104,   101,    37,    73,    92,    73,    84,    92,    94,
      95,    73,    33,    38,    73,    38,    88,    73,   101,    34,
       9,    10,    17,    18,    19,    20,    21,    51,    86,    46,
      47,    48,    77,    44,    45,    76,    11,    15,    42,    43,
      74,    14,    16,    75,    13,    12,    64,    65,    90,     4,
       4,    90,    40,    88,    38,     4,     4,   101,    88,    88,
      88,    52,    88,    73,    73,    39,    39,    50,    72,    65,
      66,    67,    68,    69,    70,    40,    73,    51,    23,    92,
      39,    39,    65,    39,    73,    88,    91,    52,    84,    96
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    58,    59,
      60,    61,    62,    63,    64,    64,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    74,    74,    74,    74,    75,
      75,    76,    76,    77,    77,    77,    78,    78,    78,    79,
      79,    80,    80,    80,    81,    81,    81,    81,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    84,
      85,    85,    86,    86,    86,    86,    86,    86,    87,    88,
      89,    90,    90,    91,    91,    91,    92,    93,    93,    94,
      95,    96,    97,    98,    98,    99,   100,   100,   101,   101,
     101,   101,   102,   102,   102,   103,   103,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     2,     4,
       3,     2,     3,     1,     1,     2,     2,     2,     1,     4,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     4,     2,
       2,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       3,     5,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     1,     3,     5,     5,     1,     3,     3,     5,
       1,     1,     3,     2,     2,     2,     0,     1,     1,     1,
       1,     1,     0,     2,     4,     2,     1,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 102 "compiler_hw2.y" /* yacc.c:1646  */
    {dump_symbol();}
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 117 "compiler_hw2.y" /* yacc.c:1646  */
    {create_symbol(); printf("package: %s\n", (yyvsp[0].item.value.s_val));}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 125 "compiler_hw2.y" /* yacc.c:1646  */
    { int size = sizeof(char)*2 + sizeof((yyvsp[-1].item.value.s_val))+1;
				funct_parameter = (char*)malloc(sizeof(size));
					strcpy(funct_parameter, "()V"); // Here need to change!!!!!!
					//funct_parameter[size-1]= ')';
					//strcpy(funct_parameter+1,$<value.s_val>2);
					printf("func_signature: %s\n",funct_parameter);}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "compiler_hw2.y" /* yacc.c:1646  */
    {
			printf("func: %s\n", (yyvsp[0].item.value.s_val));
			create_symbol();
			str_funct_name = (char *)malloc( strlen((yyvsp[0].item.value.s_val)) + 1);
			strcpy(str_funct_name, (yyvsp[0].item.value.s_val));
		     }
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 143 "compiler_hw2.y" /* yacc.c:1646  */
    { dump_symbol(); }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 147 "compiler_hw2.y" /* yacc.c:1646  */
    { insert_symbol(str_funct_name,"func","()V"); }
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 152 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("INC\n");}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 153 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("DEC\n");}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 154 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("%s\n", (yyvsp[-1].item.value.s_val));}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 163 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("%s\n", (yyvsp[-1].item.value.s_val));}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 168 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("%s\n", (yyvsp[-1].item.value.s_val));}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 173 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("%s\n", (yyvsp[-1].item.value.s_val));}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 178 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("%s\n", (yyvsp[-1].item.value.s_val));}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 183 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("LAND\n");}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 188 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("LOR\n"); (yyval.item.type) = "bool";}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 193 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("%s\n", (yyvsp[-1].item.value.s_val));}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 201 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="LTR"; }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 203 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="GTR"; }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 208 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.item.value.s_val)="EQL";}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 209 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.item.value.s_val)="NEQ";}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 213 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="ADD"; }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 214 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="SUB"; }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 218 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="MUL"; }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 219 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="QUO"; }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 220 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="REM"; }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 224 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="POS"; }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 225 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="NEG"; }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 226 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="NOT"; }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 230 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.item.value) = (yyvsp[0].item.value); (yyval.item.type)=(yyvsp[0].item.type); }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 235 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value) = (yyvsp[0].item.value); (yyval.item.type) = (yyvsp[0].item.type);}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 237 "compiler_hw2.y" /* yacc.c:1646  */
    {	(yyval.item.value) = (yyvsp[0].item.value); (yyval.item.type) = (yyvsp[0].item.type);
			symtable_type* tmp_table = lookup_symbol((yyvsp[0].item.value.s_val));
			printf("IDENT (name=%s, address=%d)\n",(yyvsp[0].item.value.s_val),tmp_table->address);
			(yyval.item.type) = tmp_table->type;}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 242 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.item.value) = (yyvsp[-2].item.value); (yyval.item.type) = (yyvsp[-2].item.type);
				/*printf("hello operand literal %s\n",$<item.type>1);*/}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 247 "compiler_hw2.y" /* yacc.c:1646  */
    {
				printf("INT_LIT %d\n",         (yyval.item.value.i_val));
				(yyval.item.value)= (yyvsp[0].item.value);
				(yyval.item.type) = "int32";
				/*printf("show INT LIT return type %s\n",$<item.type>1);*/
			}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 253 "compiler_hw2.y" /* yacc.c:1646  */
    {	printf("FLOAT_LIT %f\n",       (yyval.item.value.f_val));
                                 (yyval.item.value)= (yyvsp[0].item.value);
                                 (yyval.item.type) = "float32";
                         }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 258 "compiler_hw2.y" /* yacc.c:1646  */
    {
				if((yyval.item.value.b_val) == true) printf("TRUE 1\n");
				else printf("FALSE 0\n");
				(yyval.item.value)= (yyvsp[0].item.value);
				(yyval.item.type) = "bool";
			}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 264 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("STRING_LIT %s\n", (yyvsp[-1].item.value.s_val));
				(yyval.item.value)= (yyvsp[-1].item.value);
				(yyval.item.type) = "string";
			}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 271 "compiler_hw2.y" /* yacc.c:1646  */
    {
		if (strcmp((yyvsp[-1].item.type), "float32") == 0 && strcmp((yyvsp[-3].item.value.s_val), "int32") == 0){
            		printf("f2i\n");
            		(yyval.item.type) = "int32";
        	}
        	else if (strcmp((yyvsp[-1].item.type), "int32") == 0 && strcmp((yyvsp[-3].item.value.s_val), "float32") == 0){
            		printf("i2f\n");
            		(yyval.item.type) = "float32";
        	}
		}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 301 "compiler_hw2.y" /* yacc.c:1646  */
    { insert_symbol((yyvsp[-1].item.value.s_val), (yyvsp[0].item.value.s_val), "-");}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 302 "compiler_hw2.y" /* yacc.c:1646  */
    { insert_symbol((yyvsp[-3].item.value.s_val), (yyvsp[-2].item.value.s_val), "-");}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 306 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="ASSIGN"; }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 307 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="ADD"; }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 308 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="SUB"; }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 309 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="MUL"; }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 310 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="QUO"; }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 311 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val)="REM"; }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 319 "compiler_hw2.y" /* yacc.c:1646  */
    {dump_symbol();}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 322 "compiler_hw2.y" /* yacc.c:1646  */
    { create_symbol();}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 367 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("case %d\n", (yyvsp[0].item.value.i_val));}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 371 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.item.value.s_val) = "V";}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 372 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.item.value.s_val) = (yyvsp[0].item.value.s_val);}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 376 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.item.value.s_val) = "int32";}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 377 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.item.value.s_val) = "float32";}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 378 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.item.value.s_val) = "string";}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 379 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.item.value.s_val) = "bool";}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 383 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val) = ""; }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 384 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.item.value.s_val) = (yyvsp[0].item.value.s_val);}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 385 "compiler_hw2.y" /* yacc.c:1646  */
    { strcat((yyval.item.value.s_val), (yyvsp[0].item.value.s_val)); }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 394 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("PRINT %s\n", (yyvsp[-1].item.type));}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 395 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("PRINTLN %s\n", (yyvsp[-1].item.type));}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1870 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  return yyresult;
}
#line 398 "compiler_hw2.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;
    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

/* Symbol Table */
int global_level = -1;
int global_address = -1;

symtable_stack_type* stack_head = NULL; 

static void create_symbol() {
	// create a empty stack and set property
	global_level++;
	symtable_stack_type* tmp_stack = (symtable_stack_type *)malloc(sizeof(symtable_stack_type));
	tmp_stack -> table = NULL;
	tmp_stack -> level = global_level;
	// make it to be the head(newest) of current stack linked list
	tmp_stack -> next = stack_head;
	stack_head = tmp_stack;
	// print infomation
    	printf("> Create symbol table (scope level %d)\n", global_level);
}

static void insert_symbol(char* name, char* type, char* Func_sig) {
    	if(strcmp(type,"func")==0)
		printf("> Insert `%s` (addr: %d) to scope level %d\n", name, global_address, global_level-1);
	else
		printf("> Insert `%s` (addr: %d) to scope level %d\n", name, global_address, global_level);
	// Create a new table

	symtable_type* tmp_table = (symtable_type *)malloc(sizeof(symtable_type));
	
	tmp_table -> lineno = strcmp(type, "func")? yylineno : yylineno+1 ;
	tmp_table -> level = global_level;
	tmp_table -> address = global_address;
	global_address ++;
	
	tmp_table -> name = (char*) malloc (strlen(name) + 1);
        strcpy(tmp_table-> name, name);
	tmp_table -> func_sig = (char*)malloc(strlen(Func_sig) +1);
	strcpy(tmp_table->func_sig, Func_sig);
	tmp_table -> type = (char*)malloc(strlen(type) +1);
        strcpy(tmp_table->type, type);
	// Find the correct stack head
	symtable_stack_type* tmp_head = (symtable_stack_type*)malloc(0);
	if(strcmp(type,"func")==0)
		tmp_head = stack_head->next;
	else{
		tmp_head = stack_head;
	}
	// Make table to be the last one in head-stack
	if(!tmp_head->table){
		tmp_table -> index = 0;
		tmp_head -> table = tmp_table;
	}
	else{
		int last_index = 1;
		symtable_type* last_table = tmp_head -> table;
		while(last_table -> next){
			last_table = last_table -> next;
			last_index ++;
		}
		tmp_table -> index = last_index;
		last_table -> next = tmp_table;
		//tmp_tabletmp_table -> index = last_index;
	}
}

static symtable_type* lookup_symbol(char * name) {
	// from stack head
	symtable_stack_type* tmp_stack = stack_head;
	while(tmp_stack){
		// from the first table in this stack
		symtable_type* tmp_table = tmp_stack -> table;
		while(tmp_table){
			if(strcmp(tmp_table -> name,name)==0){
				return tmp_table;
			}
			tmp_table = tmp_table -> next;
		}
		tmp_stack = tmp_stack -> next;
	}
	return 0;
}

static void dump_symbol() {
	printf("\n> Dump symbol table (scope level: %d)\n", global_level);
	printf("%-10s%-10s%-10s%-10s%-10s%-10s\n","Index", "Name", "Type", "Addr", "Lineno", "Func_sig");
	// print all table in head stack
	symtable_type* tmp_table = stack_head -> table;
	while(tmp_table){
		printf("%-10d%-10s%-10s%-10d%-10d%-10s\n",tmp_table->index, tmp_table->name, tmp_table->type, tmp_table->address, tmp_table->lineno, tmp_table->func_sig );
		tmp_table = tmp_table->next;
	}
	printf("\n");
	// change head by -1
	stack_head = stack_head-> next;
	global_level --;
}
