/* A Bison parser, made by GNU Bison 3.7.6.  */

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
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.ypp"

	#include <iostream>
	#include "hw3_output.hpp"
	#include "Node.h"
	#include "ScopeStacks.h"
	#include "MemoryManager.hpp"
	
	using namespace std;
	int yylex();
	void yyerror(const char*);
	extern int yylineno;

	ScopeStacks scopeStacks;
	CodeBuffer& buff = CodeBuffer::instance();
	MemoryManager manager;
	using std::string;
	
	bool IsLegalAssignment(EType type1, EType type2);
	void Start();
	void truncRes(Type* type);
	string Phi(Type* expr);
	

#line 95 "parser.tab.cpp"

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
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_BYTE = 5,                       /* BYTE  */
  YYSYMBOL_B = 6,                          /* B  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_TRUE = 8,                       /* TRUE  */
  YYSYMBOL_FALSE = 9,                      /* FALSE  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_BREAK = 12,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 13,                  /* CONTINUE  */
  YYSYMBOL_SC = 14,                        /* SC  */
  YYSYMBOL_COMMA = 15,                     /* COMMA  */
  YYSYMBOL_ID = 16,                        /* ID  */
  YYSYMBOL_NUM = 17,                       /* NUM  */
  YYSYMBOL_STRING = 18,                    /* STRING  */
  YYSYMBOL_ASSIGN = 19,                    /* ASSIGN  */
  YYSYMBOL_TERNARY = 20,                   /* TERNARY  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_RELOP_EQ = 25,                  /* RELOP_EQ  */
  YYSYMBOL_RELOP_REL = 26,                 /* RELOP_REL  */
  YYSYMBOL_BINOP_SUM = 27,                 /* BINOP_SUM  */
  YYSYMBOL_BINOP_MUL = 28,                 /* BINOP_MUL  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_LBRACE = 30,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 31,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 32,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 33,                    /* RPAREN  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_Program = 35,                   /* Program  */
  YYSYMBOL_36_1 = 36,                      /* $@1  */
  YYSYMBOL_Funcs = 37,                     /* Funcs  */
  YYSYMBOL_FuncDecl = 38,                  /* FuncDecl  */
  YYSYMBOL_39_2 = 39,                      /* $@2  */
  YYSYMBOL_RetType = 40,                   /* RetType  */
  YYSYMBOL_Formals = 41,                   /* Formals  */
  YYSYMBOL_FormalsList = 42,               /* FormalsList  */
  YYSYMBOL_FormalsDecl = 43,               /* FormalsDecl  */
  YYSYMBOL_Statements = 44,                /* Statements  */
  YYSYMBOL_Statement = 45,                 /* Statement  */
  YYSYMBOL_Call = 46,                      /* Call  */
  YYSYMBOL_ExpList = 47,                   /* ExpList  */
  YYSYMBOL_48_3 = 48,                      /* $@3  */
  YYSYMBOL_Type = 49,                      /* Type  */
  YYSYMBOL_Exp = 50,                       /* Exp  */
  YYSYMBOL_BoolExp = 51,                   /* BoolExp  */
  YYSYMBOL_M = 52,                         /* M  */
  YYSYMBOL_N = 53,                         /* N  */
  YYSYMBOL_OPEN_MARKER = 54,               /* OPEN_MARKER  */
  YYSYMBOL_WHILE_OPEN_MARKER = 55,         /* WHILE_OPEN_MARKER  */
  YYSYMBOL_CLOSE_MARKER = 56               /* CLOSE_MARKER  */
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    57,    77,    78,    82,    81,   168,   169,
     172,   173,   176,   182,   190,   197,   201,   209,   215,   242,
     288,   319,   327,   339,   359,   371,   387,   405,   417,   431,
     487,   525,   535,   534,   547,   548,   549,   553,   565,   638,
     692,   726,   768,   786,   800,   817,   837,   851,   865,   878,
     898,   919,   944,   970,   990,  1005,  1011,  1019,  1022,  1032
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
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "INT", "BYTE",
  "B", "BOOL", "TRUE", "FALSE", "RETURN", "WHILE", "BREAK", "CONTINUE",
  "SC", "COMMA", "ID", "NUM", "STRING", "ASSIGN", "TERNARY", "IF", "ELSE",
  "OR", "AND", "RELOP_EQ", "RELOP_REL", "BINOP_SUM", "BINOP_MUL", "NOT",
  "LBRACE", "RBRACE", "LPAREN", "RPAREN", "$accept", "Program", "$@1",
  "Funcs", "FuncDecl", "$@2", "RetType", "Formals", "FormalsList",
  "FormalsDecl", "Statements", "Statement", "Call", "ExpList", "$@3",
  "Type", "Exp", "BoolExp", "M", "N", "OPEN_MARKER", "WHILE_OPEN_MARKER",
  "CLOSE_MARKER", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
#endif

#define YYPACT_NINF (-108)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-33)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -108,     4,    70,  -108,  -108,  -108,  -108,  -108,  -108,    70,
      -8,  -108,  -108,   -22,    57,   -12,  -108,    -4,     6,  -108,
      57,  -108,     0,  -108,   104,   115,  -108,    52,    53,   -14,
      37,  -108,  -108,  -108,    65,    56,  -108,  -108,  -108,    48,
      76,  -108,   132,    57,  -108,   131,  -108,  -108,  -108,   132,
     110,   132,   104,  -108,  -108,    44,  -108,  -108,    55,  -108,
    -108,  -108,  -108,  -108,   132,   132,   132,   132,    59,   146,
    -108,    64,   168,    12,    66,    75,    91,  -108,   132,   132,
     132,    78,   132,   132,    58,    58,    62,  -108,   132,  -108,
    -108,    98,  -108,  -108,  -108,  -108,  -108,   154,  -108,   176,
    -108,   160,    23,    97,   132,  -108,  -108,   104,  -108,  -108,
     132,  -108,  -108,   104,   102,  -108,  -108,  -108,   104,   114,
     116,  -108,  -108,   132,  -108,  -108,    12,  -108,  -108,   104,
    -108,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     4,     1,     9,    34,    35,    36,     3,     4,
       0,     8,     5,     0,    10,     0,    11,    12,     0,     6,
       0,    14,     0,    13,     0,     0,    56,     0,     0,     0,
       0,    57,    56,    15,     0,     0,    46,    47,    22,    41,
      43,    45,     0,    56,    42,     0,    55,    27,    28,     0,
       0,     0,     0,    55,    21,     0,    44,    48,     0,    55,
      23,    56,    55,    55,     0,     0,     0,     0,     0,     0,
      30,     0,    31,    54,     0,    56,     0,    18,     0,     0,
       0,     0,     0,     0,    51,    52,    40,    39,     0,    20,
      29,     0,    55,    59,    55,     7,    16,     0,    53,     0,
      55,    50,    49,     0,     0,    57,    17,     0,    19,    37,
       0,    58,    33,     0,     0,    55,    59,    55,     0,    24,
       0,    56,    56,     0,    59,    55,    38,    26,    57,     0,
      59,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,  -108,   128,  -108,  -108,  -108,  -108,   126,  -108,
      99,   -42,   -24,    49,  -108,    11,   -23,   -81,   -47,   -29,
    -104,  -108,  -107
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     8,     9,    22,    10,    15,    16,    17,
      32,    33,    44,    71,    91,    35,    73,    74,    68,    46,
      52,   115,   106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,   113,    45,    53,     3,    49,    76,   103,    13,   119,
      14,    20,    80,    11,    59,    82,    83,   127,    50,    57,
      11,    19,    21,   131,   129,    18,    69,    72,    34,   114,
      24,    18,    81,    61,    96,    62,    63,    64,    65,    66,
      67,    84,    85,    86,    87,   105,    94,   107,    64,    65,
      66,    67,    34,   110,    58,    97,    98,    99,    77,   101,
     102,     5,     6,    78,     7,    96,    47,    48,   118,    51,
     120,   116,    55,     4,     5,     6,   121,     7,   128,    54,
      50,    72,    56,    34,    65,    66,    67,   130,    79,    34,
      67,    88,   124,   125,    34,     5,     6,    90,     7,    92,
     126,    25,    26,    27,    28,    34,    93,    29,     5,     6,
     100,     7,    30,   104,    25,    26,    27,    28,    36,    37,
      29,    31,    95,    36,    37,    30,    39,    40,    41,    38,
     111,    39,    40,    41,    31,   117,   122,    12,   123,    42,
      36,    37,    43,    70,    42,    60,    23,    43,    39,    40,
      41,    75,    61,   112,    62,    63,    64,    65,    66,    67,
      89,    42,     0,     0,    43,     0,     0,    61,   108,    62,
      63,    64,    65,    66,    67,    61,     0,    62,    63,    64,
      65,    66,    67,   -32,    63,    64,    65,    66,    67,    61,
       0,    62,    63,    64,    65,    66,    67,    61,     0,    62,
      63,    64,    65,    66,    67,     0,     0,     0,     0,   109
};

static const yytype_int16 yycheck[] =
{
      24,   105,    25,    32,     0,    19,    53,    88,    16,   116,
      32,    15,    59,     2,    43,    62,    63,   124,    32,    42,
       9,    33,    16,   130,   128,    14,    49,    50,    52,   110,
      30,    20,    61,    21,    76,    23,    24,    25,    26,    27,
      28,    64,    65,    66,    67,    92,    75,    94,    25,    26,
      27,    28,    76,   100,    43,    78,    79,    80,    14,    82,
      83,     4,     5,    19,     7,   107,    14,    14,   115,    32,
     117,   113,    16,     3,     4,     5,   118,     7,   125,    14,
      32,   104,     6,   107,    26,    27,    28,   129,    33,   113,
      28,    32,   121,   122,   118,     4,     5,    33,     7,    33,
     123,    10,    11,    12,    13,   129,    31,    16,     4,     5,
      32,     7,    21,    15,    10,    11,    12,    13,     8,     9,
      16,    30,    31,     8,     9,    21,    16,    17,    18,    14,
      33,    16,    17,    18,    30,    33,    22,     9,    22,    29,
       8,     9,    32,    33,    29,    14,    20,    32,    16,    17,
      18,    52,    21,   104,    23,    24,    25,    26,    27,    28,
      14,    29,    -1,    -1,    32,    -1,    -1,    21,    14,    23,
      24,    25,    26,    27,    28,    21,    -1,    23,    24,    25,
      26,    27,    28,    15,    24,    25,    26,    27,    28,    21,
      -1,    23,    24,    25,    26,    27,    28,    21,    -1,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    35,    36,     0,     3,     4,     5,     7,    37,    38,
      40,    49,    37,    16,    32,    41,    42,    43,    49,    33,
      15,    16,    39,    42,    30,    10,    11,    12,    13,    16,
      21,    30,    44,    45,    46,    49,     8,     9,    14,    16,
      17,    18,    29,    32,    46,    50,    53,    14,    14,    19,
      32,    32,    54,    53,    14,    16,     6,    50,    49,    53,
      14,    21,    23,    24,    25,    26,    27,    28,    52,    50,
      33,    47,    50,    50,    51,    44,    52,    14,    19,    33,
      52,    53,    52,    52,    50,    50,    50,    50,    32,    14,
      33,    48,    33,    31,    53,    31,    45,    50,    50,    50,
      32,    50,    50,    51,    15,    52,    56,    52,    14,    33,
      52,    33,    47,    54,    51,    55,    45,    33,    52,    56,
      52,    45,    22,    22,    53,    53,    50,    56,    52,    54,
      45,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    36,    35,    37,    37,    39,    38,    40,    40,
      41,    41,    42,    42,    43,    44,    44,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    46,
      46,    47,    48,    47,    49,    49,    49,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    52,    53,    54,    55,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     0,    11,     1,     1,
       0,     1,     1,     3,     2,     1,     4,     5,     3,     5,
       4,     2,     2,     3,     8,    14,    11,     2,     2,     4,
       3,     1,     0,     4,     1,     1,     1,     5,    10,     3,
       3,     1,     1,     1,     2,     1,     1,     1,     2,     4,
       4,     3,     3,     4,     1,     0,     0,     0,     0,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* $@1: %empty  */
#line 57 "parser.ypp"
          {Start();}
#line 1242 "parser.tab.cpp"
    break;

  case 3: /* Program: $@1 Funcs  */
#line 57 "parser.ypp"
                           {
			if (yychar == YYEOF) {
						
						
						Symbol sym;
						
						bool exists = scopeStacks.tablesStack.findId("main", sym);

						if(!exists || !sym.argTypes.empty() || sym.retType != EVOID)
						{
							output::errorMainMissing();
							exit(1);
						}
						scopeStacks.closeScope();
						buff.printGlobalBuffer();
						buff.printCodeBuffer();
					}
		}
#line 1265 "parser.tab.cpp"
    break;

  case 4: /* Funcs: %empty  */
#line 77 "parser.ypp"
               {}
#line 1271 "parser.tab.cpp"
    break;

  case 5: /* Funcs: FuncDecl Funcs  */
#line 78 "parser.ypp"
                                 {}
#line 1277 "parser.tab.cpp"
    break;

  case 6: /* $@2: %empty  */
#line 82 "parser.ypp"
                        {
				Symbol sym;
				// check if it defined before
				bool exists = scopeStacks.tablesStack.findId(((Id*)yyvsp[-3])->name, sym);
				if(exists)
				{
					output::errorDef(yylineno, ((Id*)yyvsp[-3])->name);
					exit(1);
				}
				
				
				std::vector<EType> typesList;
				
				std::vector<string> namesList; 
				
				((ArgumentList*)yyvsp[-1])->createLists(typesList, namesList);
				
				sym = Symbol(((Id*)yyvsp[-3])->name, typesList, namesList, ((Type*)yyvsp[-4])->type);
				
				scopeStacks.addSymbol(sym);
				
				string returnType = "i32";
				if (((Type*)yyvsp[-4])->type == EVOID)
				{
					returnType = "void";
				}
				
				string funcDefinition = "define " + returnType + "@" + ((Id*)yyvsp[-3])->name;
				
				int argsNum = ((ArgumentList*)yyvsp[-1])->arguments.size();
				if (argsNum == 0) {
				funcDefinition += "() {";
				}
				else {
					funcDefinition += "(";
					for (int i = 0; i < argsNum - 1; i++)
					{
						funcDefinition += "i32, ";
					}
					funcDefinition += "i32) {";
				}
				buff.emit(funcDefinition);

				scopeStacks.openScope();
				
				string ar = manager.createActivationRecord();
				buff.emit(ar + " = alloca [50 x i32]");

				int offset = -1;
				for(auto it = ((ArgumentList*)(yyvsp[-1]))->arguments.begin(); it!=((ArgumentList*)(yyvsp[-1]))->arguments.end(); it++)
				{
					Symbol tempSym;
					Argument arg = *it;
					// check if it defined before
					bool exists = scopeStacks.tablesStack.findId(arg.name, tempSym);
					if(exists)
					{
						output::errorDef(yylineno, arg.name);
						exit(1);
					}
					
					string toActualVar = "%" + to_string(-offset - 1);
					sym = Symbol(arg.name, arg.type, offset, toActualVar);
					
					offset -= 1;
					
					scopeStacks.tablesStack.scopes.back().symTable.push_back(sym);
				}
			}
#line 1351 "parser.tab.cpp"
    break;

  case 7: /* FuncDecl: RetType ID LPAREN Formals RPAREN $@2 LBRACE Statements N M RBRACE  */
#line 152 "parser.ypp"
                        { 
				scopeStacks.closeScope();
				buff.bpatch(buff.merge(((Statement*)yyvsp[-3])->nextList, ((N*)yyvsp[-2])->nextList), ((M*)yyvsp[-1])->quad);
				//fff
				if (((Type*)yyvsp[-10])->type == EVOID)
				{
					buff.emit("ret void");
				}
				else
				{
					buff.emit("ret i32 0");
				}
				buff.emit("}");
			}
#line 1370 "parser.tab.cpp"
    break;

  case 8: /* RetType: Type  */
#line 168 "parser.ypp"
               {yyval = yyvsp[0];}
#line 1376 "parser.tab.cpp"
    break;

  case 9: /* RetType: VOID  */
#line 169 "parser.ypp"
                       {yyval = new Type(EVOID);}
#line 1382 "parser.tab.cpp"
    break;

  case 10: /* Formals: %empty  */
#line 172 "parser.ypp"
                 {yyval = new ArgumentList();}
#line 1388 "parser.tab.cpp"
    break;

  case 11: /* Formals: FormalsList  */
#line 173 "parser.ypp"
                              {yyval = yyvsp[0];}
#line 1394 "parser.tab.cpp"
    break;

  case 12: /* FormalsList: FormalsDecl  */
#line 176 "parser.ypp"
                          {
					yyval = new ArgumentList();
					((ArgumentList*)yyval)->addArgument(*((Argument*)yyvsp[0]));
					
					delete yyvsp[0];
					}
#line 1405 "parser.tab.cpp"
    break;

  case 13: /* FormalsList: FormalsDecl COMMA FormalsList  */
#line 182 "parser.ypp"
                                                        {					
					((ArgumentList*)yyvsp[0])->addArgument(*((Argument*)yyvsp[-2]));
					yyval = yyvsp[0];
					
					delete yyvsp[-2];
					}
#line 1416 "parser.tab.cpp"
    break;

  case 14: /* FormalsDecl: Type ID  */
#line 190 "parser.ypp"
                      {yyval = new Argument(((Type*)yyvsp[-1])->type, ((Id*)yyvsp[0])->name);
				delete yyvsp[-1];
				
				delete yyvsp[0];
				}
#line 1426 "parser.tab.cpp"
    break;

  case 15: /* Statements: Statement  */
#line 198 "parser.ypp"
                        {
				yyval = yyvsp[0];
			}
#line 1434 "parser.tab.cpp"
    break;

  case 16: /* Statements: Statements N M Statement  */
#line 202 "parser.ypp"
                        {
				buff.bpatch(((Statement*)yyvsp[-3])->nextList, ((M*)yyvsp[-1])->quad);
				buff.bpatch(((N*)yyvsp[-2])->nextList,((M*)yyvsp[-1])->quad);
				yyval = yyvsp[0];
			}
#line 1444 "parser.tab.cpp"
    break;

  case 17: /* Statement: LBRACE OPEN_MARKER Statements RBRACE CLOSE_MARKER  */
#line 210 "parser.ypp"
                        {
				yyval = yyvsp[-2];
			}
#line 1452 "parser.tab.cpp"
    break;

  case 18: /* Statement: Type ID SC  */
#line 215 "parser.ypp"
                                     {				
				Symbol sym;
				// check if it defined before
				bool exists = scopeStacks.tablesStack.findId(((Id*)yyvsp[-1])->name, sym);

				if(exists)
				{
					output::errorDef(yylineno, ((Id*)yyvsp[-1])->name);
					exit(1);
				}
				string reg = manager.createReg();

				sym = Symbol(((Id*)yyvsp[-1])->name,((Type*)yyvsp[-2])->type, scopeStacks.offsetsStack.getOffset(), reg);
				scopeStacks.addSymbol(sym);
				string stringOffset = to_string(sym.offset);
				string regEquals = "getelementptr [50 x i32], [50 x i32]* " + manager.getActivationRecord() + ", i32 0, i32 " + stringOffset;
				buff.emit(reg + " = " + regEquals);
				string storeOp = "store i32 0, i32* " + reg;
				buff.emit(storeOp);
				yyval = new Statement();
				
				delete yyvsp[-2];	
				delete yyvsp[-1];
				}
#line 1481 "parser.tab.cpp"
    break;

  case 19: /* Statement: Type ID ASSIGN Exp SC  */
#line 242 "parser.ypp"
                                                {
				Symbol sym;
				// check if it defined before
				bool exists = scopeStacks.tablesStack.findId(((Id*)yyvsp[-3])->name, sym);
				
				if(exists)
				{
					output::errorDef(yylineno, ((Id*)yyvsp[-3])->name);
					exit(1);
				}
				
				if(!IsLegalAssignment(((Type*)yyvsp[-4])->type, ((Type*)yyvsp[-1])->type)) {
					output::errorMismatch(yylineno);
					exit(1);
				}

				//hook
				buff.bpatch( ((Type*)yyvsp[-1])->hookQuad,  ((Type*)yyvsp[-1])->hookLabel);




				string reg = manager.createReg();
				
				sym = Symbol(((Id*)yyvsp[-3])->name,((Type*)yyvsp[-4])->type, scopeStacks.offsetsStack.getOffset(), reg);
				scopeStacks.addSymbol(sym);
				
				string exprReg = (((Type*)yyvsp[-4])->type == EBOOL) ? Phi((Type*)yyvsp[-1]) : ((Node*)yyvsp[-1])->reg;
				
				string stringOffset = to_string(sym.offset);
				string currentAR = manager.getActivationRecord();
				string regEquals = "getelementptr [50 x i32], [50 x i32]* " + currentAR + ", i32 0, i32 " + stringOffset;
				buff.emit(reg + " = " + regEquals);
				string storeOp = "store i32 " + exprReg + ", i32* " + reg;
				buff.emit(storeOp);
	
				
				
				yyval = new Statement();
				delete yyvsp[-4];
				delete yyvsp[-3];
				delete yyvsp[-1];
				}
#line 1529 "parser.tab.cpp"
    break;

  case 20: /* Statement: ID ASSIGN Exp SC  */
#line 288 "parser.ypp"
                                           {				
				Symbol sym;
				// check if it defined before
				bool exists = scopeStacks.tablesStack.findId(((Id*)yyvsp[-3])->name, sym);

				if(!exists || sym.type==EFUNC)
				{
					
					output::errorUndef(yylineno, ((Id*)yyvsp[-3])->name);
					exit(1);
				}

				if(!IsLegalAssignment(sym.type, ((Type*)yyvsp[-1])->type)) {
					output::errorMismatch(yylineno);
					exit(1);
				}
				//hook
				buff.bpatch( ((Type*)yyvsp[-1])->hookQuad, ((Type*)yyvsp[-1])->hookLabel);
				


				string exprReg = (sym.type == EBOOL) ? Phi((Type*)yyvsp[-1]) : ((Node*)yyvsp[-1])->reg;
				string storeOp = "store i32 " + exprReg + ", i32* " + sym.reg;
				buff.emit(storeOp);

				yyval = new Statement();
				delete yyvsp[-3];
				delete yyvsp[-1];
				}
#line 1563 "parser.tab.cpp"
    break;

  case 21: /* Statement: Call SC  */
#line 320 "parser.ypp"
                        {
                buff.bpatch( ((Type*)yyvsp[-1])->hookQuad, ((Type*)yyvsp[-1])->hookLabel);
				yyval = new Statement();
				delete yyvsp[-1];
			}
#line 1573 "parser.tab.cpp"
    break;

  case 22: /* Statement: RETURN SC  */
#line 327 "parser.ypp"
                                    {				
				if(scopeStacks.tablesStack.lastFuncRetType()!= EVOID)
					{
						output::errorMismatch(yylineno);
						exit(1);
					}
					buff.emit("ret void");
					yyval = new Statement();
				}
#line 1587 "parser.tab.cpp"
    break;

  case 23: /* Statement: RETURN Exp SC  */
#line 339 "parser.ypp"
                                        {
				if(scopeStacks.tablesStack.lastFuncRetType() == EVOID || !IsLegalAssignment(scopeStacks.tablesStack.lastFuncRetType(), ((Type*)yyvsp[-1])->type))
				{
					output::errorMismatch(yylineno);
					
					exit(1);
				}
				buff.bpatch( ((Type*)yyvsp[-1])->hookQuad,((Type*)yyvsp[-1])->hookLabel);
				
				
				string exprReg = (((Type*)yyvsp[-1])->type == EBOOL) ? Phi((Type*)yyvsp[-1]) : ((Node*)yyvsp[-1])->reg;
				buff.emit("ret i32 " + exprReg);
				
				yyval = new Statement();
				delete yyvsp[-1];
				
				}
#line 1609 "parser.tab.cpp"
    break;

  case 24: /* Statement: IF LPAREN BoolExp RPAREN M OPEN_MARKER Statement CLOSE_MARKER  */
#line 360 "parser.ypp"
                        {
				
				buff.bpatch(((Type*)yyvsp[-5])->trueList,((M*)yyvsp[-3])->quad);
				vector<jumpPair> nextList = buff.merge(((Type*)yyvsp[-5])->falseList, ((Statement*)yyvsp[-1])->nextList);
				yyval = new Statement(nextList);
				
				delete yyvsp[-5];
				delete yyvsp[-3];
				delete yyvsp[-1];
			}
#line 1624 "parser.tab.cpp"
    break;

  case 25: /* Statement: IF LPAREN BoolExp RPAREN M OPEN_MARKER Statement CLOSE_MARKER ELSE N M OPEN_MARKER Statement CLOSE_MARKER  */
#line 372 "parser.ypp"
                        {
				buff.bpatch(((Type*)yyvsp[-11])->trueList,((M*)yyvsp[-9])->quad);
				buff.bpatch(((Type*)yyvsp[-11])->falseList,((M*)yyvsp[-3])->quad);
				
				vector<jumpPair> almostNextList = buff.merge(((Statement*)yyvsp[-7])->nextList, ((N*)yyvsp[-4])->nextList);
				yyval = new Statement(buff.merge(almostNextList, ((Statement*)yyvsp[-1])->nextList));
			
				delete yyvsp[-11];
				delete yyvsp[-9];
				delete yyvsp[-7];
				delete yyvsp[-4];
				delete yyvsp[-3];
				delete yyvsp[-1];
			}
#line 1643 "parser.tab.cpp"
    break;

  case 26: /* Statement: WHILE N M LPAREN BoolExp RPAREN WHILE_OPEN_MARKER M Statement N CLOSE_MARKER  */
#line 388 "parser.ypp"
                        {
				buff.bpatch(((Type*)yyvsp[-6])->trueList,((M*)yyvsp[-3])->quad);
				buff.bpatch(((N*)yyvsp[-1])->nextList,((M*)yyvsp[-8])->quad);
				buff.bpatch(((N*)yyvsp[-9])->nextList, ((M*)yyvsp[-8])->quad);
				vector<jumpPair> contList = buff.merge(((Statement*)yyvsp[-2])->nextList, scopeStacks.contsTopAndPop());
				buff.bpatch(contList, ((M*)yyvsp[-8])->quad);
				
				yyval = new Statement(buff.merge(((Type*)yyvsp[-6])->falseList, scopeStacks.brksTopAndPop()));
				
				delete yyvsp[-9];
				delete yyvsp[-8];
				delete yyvsp[-6];
				delete yyvsp[-3];
				delete yyvsp[-2];

			}
#line 1664 "parser.tab.cpp"
    break;

  case 27: /* Statement: BREAK SC  */
#line 405 "parser.ypp"
                                   {
				if(!scopeStacks.isWhileScope())
				{
					output::errorUnexpectedBreak(yylineno);
					exit(1);
				}
				
				int quad = buff.emit("br label @");
				vector<jumpPair> brk = buff.makelist({quad, FIRST});
				scopeStacks.brks.push(buff.merge(scopeStacks.brksTopAndPop(), brk));
				yyval = new Statement();
			}
#line 1681 "parser.tab.cpp"
    break;

  case 28: /* Statement: CONTINUE SC  */
#line 417 "parser.ypp"
                                      {			
				if(!scopeStacks.isWhileScope())
				{
					output::errorUnexpectedContinue(yylineno);
					exit(1);
				}
				
				int quad = buff.emit("br label @");
				vector<jumpPair> cont = buff.makelist({quad, FIRST});
				scopeStacks.conts.push(buff.merge(scopeStacks.contsTopAndPop(), cont));
				yyval = new Statement();
			}
#line 1698 "parser.tab.cpp"
    break;

  case 29: /* Call: ID LPAREN ExpList RPAREN  */
#line 431 "parser.ypp"
                                {
                //hook
                vector<pair<int,BranchLabelIndex>> hookQuad = buff.makelist({buff.emit("br label @ ; call_param"), FIRST});
                string hookLabel = buff.genLabel();

				Symbol sym;
				// check if it defined before
				bool exists = scopeStacks.tablesStack.findId(((Id*)yyvsp[-3])->name, sym);
				if(!exists || sym.type != EFUNC)
				{
					output::errorUndefFunc(yylineno, ((Id*)yyvsp[-3])->name);
					exit(1);
				}

				if (!sym.checkArgTypes(*((TypeList*)yyvsp[-1]))){
					vector<string> typeList = sym.typeStringList();
					output::errorPrototypeMismatch(yylineno, sym.name, typeList);
					exit(1);
				}
				
				
				list<pair<EType,string>>::iterator iter = ((TypeList*)yyvsp[-1])->typesAndRegs.begin();
				string reg = manager.createReg();
				if (((Id*)yyvsp[-3])->name != "print")
				{
					string returnType = sym.retType != EVOID ? "i32" : "void";
					string call;
					if(returnType != "void")
					{
						call += reg + " = ";
					}
					call += "call " + returnType + " @" + ((Id*)yyvsp[-3])->name + "(";
					int argNum = (((TypeList*)yyvsp[-1])->typesAndRegs).size();
					
					for (int i = 0; i < argNum-1; i++, iter++)
					{
						call += "i32 " +  (*iter).second + ", ";
					}
					call += "i32 " +  (*iter).second + ")";
					buff.emit(call);
				}
				else
				{
					buff.emit("call void @print(i8* " + (*iter).second + ")");
				}
				yyval = new Type(sym.retType);
				((Type*)yyval)->reg = reg;
                ((Type*)yyval)->hookQuad = hookQuad;
                ((Type*)yyval)->hookLabel = hookLabel;
                buff.emit(";call_param "+((Type*)yyval)->hookLabel);

				delete yyvsp[-3];
				delete yyvsp[-1];

			}
#line 1758 "parser.tab.cpp"
    break;

  case 30: /* Call: ID LPAREN RPAREN  */
#line 487 "parser.ypp"
                           {
                //hook
                vector<pair<int,BranchLabelIndex>> hookQuad = buff.makelist({buff.emit("br label @ ; call"), FIRST});
                string hookLabel = buff.genLabel();

				Symbol sym;
				// check if it defined before
				bool exists = scopeStacks.tablesStack.findId(((Id*)yyvsp[-2])->name, sym);
				if(!exists || sym.type != EFUNC)
				{
					output::errorUndefFunc(yylineno, ((Id*)yyvsp[-2])->name);
					exit(1);
				}

				if (!sym.argTypes.empty()){
					vector<string> typeList = sym.typeStringList();
					output::errorPrototypeMismatch(yylineno, sym.name, typeList);
					exit(1);
				}

				yyval = new Type(sym.retType);
				
				string retVal = sym.retType == EVOID ? "void" : "i32";
				string assignIfNeeded = "";
				if (sym.retType != EVOID) {
					string reg = manager.createReg();
					assignIfNeeded = reg + " = ";
					((Type*)yyval)->reg = reg;
				}
				buff.emit(assignIfNeeded + "call " + retVal + " @" + ((Id*)yyvsp[-2])->name + "()");
				
				((Type*)yyval)->hookQuad = hookQuad;
                ((Type*)yyval)->hookLabel = hookLabel;

				delete yyvsp[-2];
				}
#line 1799 "parser.tab.cpp"
    break;

  case 31: /* ExpList: Exp  */
#line 525 "parser.ypp"
              {
			
			buff.bpatch( ((Type*)yyvsp[0])->hookQuad, ((Type*)yyvsp[0])->hookLabel);
			
			yyval = new TypeList();
			string exprReg = (((Type*)yyvsp[0])->type == EBOOL) ? Phi(((Type*)yyvsp[0])) : ((Type*)yyvsp[0])->reg;
			((TypeList*)yyval)->addTypeAndReg(((Type*)yyvsp[0])->type, exprReg);
			delete yyvsp[0];
		}
#line 1813 "parser.tab.cpp"
    break;

  case 32: /* $@3: %empty  */
#line 535 "parser.ypp"
                {
			buff.bpatch( ((Type*)yyvsp[0])->hookQuad, ((Type*)yyvsp[0])->hookLabel);
			
			((Type*)yyvsp[0])->reg = (((Type*)yyvsp[0])->type == EBOOL) ? Phi(((Type*)yyvsp[0])) : ((Node*)yyvsp[0])->reg;
		}
#line 1823 "parser.tab.cpp"
    break;

  case 33: /* ExpList: Exp $@3 COMMA ExpList  */
#line 540 "parser.ypp"
                                      {			
			((TypeList*)yyvsp[0])->addTypeAndReg(((Type*)yyvsp[-3])->type, ((Type*)yyvsp[-3])->reg);
			yyval = yyvsp[0];
			delete yyvsp[-3];
			}
#line 1833 "parser.tab.cpp"
    break;

  case 34: /* Type: INT  */
#line 547 "parser.ypp"
              {yyval = new Type(EINT);}
#line 1839 "parser.tab.cpp"
    break;

  case 35: /* Type: BYTE  */
#line 548 "parser.ypp"
                       {yyval = new Type(EBYTE);}
#line 1845 "parser.tab.cpp"
    break;

  case 36: /* Type: BOOL  */
#line 549 "parser.ypp"
                       {yyval = new Type(EBOOL);}
#line 1851 "parser.tab.cpp"
    break;

  case 37: /* Exp: LPAREN N M Exp RPAREN  */
#line 553 "parser.ypp"
                            {
	yyval = yyvsp[-1];
    if( ((Type*)yyvsp[-1])->isTernary) {
        ((Type*)yyval)->hookQuad = ((N*)yyvsp[-3])->nextList;
        ((Type*)yyval)->hookLabel = ((M*)yyvsp[-2])->quad;
    } else {
        buff.bpatch(((N*)yyvsp[-3])->nextList, ((M*)yyvsp[-2])->quad);
    };
    ((Type*)yyval)->isTernary = false;
    buff.emit("; Exp : LPAREN Exp RPAREN:    " + ((Type*)yyval)->hookLabel + " " + ((Type*)yyvsp[-1])->hookLabel);
    }
#line 1867 "parser.tab.cpp"
    break;

  case 38: /* Exp: Exp IF N LPAREN M BoolExp RPAREN M ELSE Exp  */
#line 565 "parser.ypp"
                                                                     {
				if (((Type*)yyvsp[-9])->type == EBOOL && ((Type*)yyvsp[0])->type == EBOOL) {
					yyval = new Type(EBOOL,buff.merge(((Type*)yyvsp[-9])->trueList, ((Type*)yyvsp[0])->trueList),buff.merge(((Type*)yyvsp[-9])->falseList, ((Type*)yyvsp[0])->falseList));
                    ((Type*)yyval)->trueList = buff.merge(((Type*)yyval)->trueList, ((N*)yyvsp[-7])->nextList);
                }
                else if (((Type*)yyvsp[-9])->type == ESTRING && ((Type*)yyvsp[0])->type == ESTRING) {
					yyval = new Type(ESTRING);
				}
				else if( !((Type*)yyvsp[-9])->isNum() || !((Type*)yyvsp[0])->isNum())
				{
					output::errorMismatch(yylineno);
					exit(1);
				}	 
				else if (((Type*)yyvsp[-9])->type == EINT || ((Type*)yyvsp[0])->type == EINT) {
					yyval = new Type(EINT);
				}
				else {
					yyval = new Type(EBYTE);
				}
				
				//hook
				// ((Type*)$$)->hookQuad = buff.makelist({buff.emit("br label @ ;2"), FIRST});
				// ((Type*)$$)->hookLabel = buff.genLabel();
				
				// ((Type*)$$)->hookLabel = ((Type*)$10)->hookLabel;

                int end;
				if( ((Type*)yyvsp[-9])->isNum() || ((Type*)yyvsp[-9])->type == ESTRING) { // not a bool
				    end = buff.emit("br label @ ;1");
                }
				
				
				buff.emit("; ((M*)$5)->quad : "+((M*)yyvsp[-5])->quad);
				buff.emit("; ((Type*)$1)->hookLabel : "+((Type*)yyvsp[-9])->hookLabel);
				buff.emit("; ((Type*)$10)->hookLabel : "+((Type*)yyvsp[0])->hookLabel);
				buff.bpatch(((Type*)yyvsp[-9])->hookQuad, ((M*)yyvsp[-5])->quad);
				
				buff.bpatch(((Type*)yyvsp[-4])->trueList, ((Type*)yyvsp[-9])->hookLabel);
				buff.bpatch(((Type*)yyvsp[-4])->falseList,((M*)yyvsp[-2])->quad);
                if (!(((Type*)yyvsp[0])->isTernary)) {
                    buff.emit("; !isTernary");
                    buff.emit("; "+((Type*)yyvsp[0])->hookLabel);
				    buff.bpatch(((Type*)yyvsp[0])->hookQuad,((Type*)yyvsp[0])->hookLabel);
                }

				if( ((Type*)yyvsp[-9])->isNum() || ((Type*)yyvsp[-9])->type == ESTRING) { // not a bool
                    string trueReg = ((Type*)yyvsp[-9])->reg;
                    string falseReg = ((Type*)yyvsp[0])->reg;
                    string resultReg = manager.createReg();
                    string trueLabel = buff.genLabel();
                    int gotoendQuad = buff.emit("br label @ ;3");
                    string falseLabel = buff.genLabel();
                    int gotoendQuad2 = buff.emit("br label @ ;4");
                    string endLabel = buff.genLabel();
                    buff.bpatch( ((N*)yyvsp[-7])->nextList, trueLabel);
                    buff.bpatch(buff.makelist({end, FIRST}), falseLabel);
                    buff.bpatch(buff.makelist({gotoendQuad, FIRST}), endLabel);	
                    buff.bpatch(buff.makelist({gotoendQuad2, FIRST}), endLabel);	

                    if (((Type*)yyvsp[-9])->isNum()) {
                        buff.emit(resultReg + " = phi i32 ["+trueReg+", %" + trueLabel + "], ["+falseReg+", %" + falseLabel + "]");
                    }else if (((Type*)yyvsp[-9])->type == ESTRING) {
                        buff.emit(resultReg + " = phi i8* ["+trueReg+", %" + trueLabel + "], ["+falseReg+", %" + falseLabel + "]");
                    }

                    ((Type*)yyval)->reg = resultReg;
				}

                ((Type*)yyval)->isTernary = true;

				delete yyvsp[-9];
				delete yyvsp[0];
			}
#line 1945 "parser.tab.cpp"
    break;

  case 39: /* Exp: Exp BINOP_MUL Exp  */
#line 638 "parser.ypp"
                            {
				if(!((Type*)yyvsp[-2])->isNum() || !((Type*)yyvsp[0])->isNum())
				{
					output::errorMismatch(yylineno);
					exit(1);
				}
				if (((Type*)yyvsp[-2])->type == EINT || ((Type*)yyvsp[0])->type == EINT) {
					yyval = new Type(EINT);
				}
				else {
					yyval = new Type(EBYTE);
				}
				//hook
				buff.bpatch( ((Type*)yyvsp[0])->hookQuad, ((Type*)yyvsp[0])->hookLabel);

				((Type*)yyval)->hookQuad = ((Type*)yyvsp[-2])->hookQuad;
				((Type*)yyval)->hookLabel = ((Type*)yyvsp[-2])->hookLabel;


				string res = manager.createReg();
				string oper =((Oper*)yyvsp[-1])->oper;
				oper = (oper != "*") ? "udiv" : "mul";
				if (oper == "udiv") {
					if (((Type*)yyval)->type == EINT) {
						oper = "sdiv";
					}
					
					string isZeroReg = manager.createReg();
					buff.emit(isZeroReg + " = icmp eq i32 0, " + ((Type*)yyvsp[0]) -> reg);
					int branch = buff.emit("br i1 "+ isZeroReg + ", label @, label @");
					string itsZero = buff.genLabel();
					buff.emit("call void @print(i8* getelementptr( [23 x i8], [23 x i8]* @.zeroDivException, i32 0, i32 0))");
					buff.emit("call void @exit(i32 1)");
					int zeroQuad = buff.emit("br label @");
					string itsNotZero = buff.genLabel();
					buff.bpatch(buff.merge(buff.makelist({branch, SECOND}), buff.makelist({zeroQuad, FIRST})) , itsNotZero);
					buff.bpatch(buff.makelist({branch, FIRST}), itsZero);
				}

				string resEquals = " = " + oper + " i32 " + ((Type*)yyvsp[-2])->reg + ", " + ((Type*)yyvsp[0])->reg;

				buff.emit(res + resEquals);
				((Type*)yyval)->reg = res;

				if(((Type*)yyval)->type == EBYTE) truncRes(((Type*)yyval));
				

				
				delete yyvsp[-2];
				delete yyvsp[-1];
				delete yyvsp[0];
			}
#line 2002 "parser.tab.cpp"
    break;

  case 40: /* Exp: Exp BINOP_SUM Exp  */
#line 692 "parser.ypp"
                            {
				if(!((Type*)yyvsp[-2])->isNum() || !((Type*)yyvsp[0])->isNum())
				{
					output::errorMismatch(yylineno);
					exit(1);
				}
				if (((Type*)yyvsp[-2])->type == EINT || ((Type*)yyvsp[0])->type == EINT) {
					yyval = new Type(EINT);
				}
				else {
					yyval = new Type(EBYTE);
				}
				//hook
				buff.bpatch( ((Type*)yyvsp[0])->hookQuad, ((Type*)yyvsp[0])->hookLabel);

				((Type*)yyval)->hookQuad = ((Type*)yyvsp[-2])->hookQuad;
				((Type*)yyval)->hookLabel = ((Type*)yyvsp[-2])->hookLabel;

				string res = manager.createReg();
				string oper =((Oper*)yyvsp[-1])->oper;
				oper = (oper != "-") ? "add" : "sub";
				string resEquals = " = " + oper + " i32 " + ((Type*)yyvsp[-2])->reg + ", " + ((Type*)yyvsp[0])->reg;
			
				buff.emit(res + resEquals);

				yyval->reg = res;
				
				if(((Type*)yyval)->type == EBYTE) truncRes((Type*)yyval);
				
				delete yyvsp[-2];
				delete yyvsp[0];
				}
#line 2039 "parser.tab.cpp"
    break;

  case 41: /* Exp: ID  */
#line 726 "parser.ypp"
             {
				Symbol sym;
				// check if it defined before
				bool exists = scopeStacks.tablesStack.findId(((Id*)yyvsp[0])->name, sym);

				if(!exists || sym.type == EFUNC)
				{
					output::errorUndef(yylineno, ((Id*)yyvsp[0])->name);
					exit(1);
				}
				//hook
                vector<pair<int,BranchLabelIndex>> hookQuad = buff.makelist({buff.emit("br label @"), FIRST});
                string hookLabel = buff.genLabel();

				string reg = sym.reg;

				if (sym.offset >= 0) {
					reg = manager.createReg();
					string loadOp = "load i32, i32* " + sym.reg;
					buff.emit(reg + " = " + loadOp);
				}
				
				yyval = new Type(sym.type);
                yyval->hookQuad = hookQuad;
                yyval->hookLabel = hookLabel;

				if (sym.type == EBOOL) {
					string cmpReg = manager.createReg();
					string cmp = "icmp eq i32 " + reg + ", 1";
					buff.emit(cmpReg + " = " + cmp);
					int quad = buff.emit("br i1 " + cmpReg + ", label @, label @");
					((Type*)yyval)->falseList = buff.makelist({quad, SECOND});
					((Type*)yyval)->trueList = buff.makelist({quad, FIRST});

				}

				((Type*)yyval)->reg = reg;
				
				delete yyvsp[0];
			}
#line 2084 "parser.tab.cpp"
    break;

  case 42: /* Exp: Call  */
#line 769 "parser.ypp"
        {
		if (((Type*)yyvsp[0])->type == EBOOL) {
			string isTrueReg = manager.createReg();
			string regEquals = "icmp eq i32 " + ((Type*)yyvsp[0])->reg + ", 1";
			buff.emit(isTrueReg + " = " + regEquals);
			string branchString = "br i1 " + isTrueReg + ", label @, label @";
			int quad = buff.emit(branchString);
			((Type*)yyvsp[0])->falseList = buff.makelist({quad, SECOND});
			((Type*)yyvsp[0])->trueList = buff.makelist({quad, FIRST});
		}
		yyval = yyvsp[0];
        ((Type*)yyval)->hookQuad = ((Type*)yyvsp[0])->hookQuad;
        ((Type*)yyval)->hookLabel = ((Type*)yyvsp[0])->hookLabel;
        buff.emit(";EXP:CALL "+((Type*)yyval)->hookLabel);
	}
#line 2104 "parser.tab.cpp"
    break;

  case 43: /* Exp: NUM  */
#line 787 "parser.ypp"
        {
		
		//hook
		vector<pair<int,BranchLabelIndex>> hookQuad = buff.makelist({buff.emit("br label @"), FIRST});
        string hookLabel = buff.genLabel();

		yyval = new Type(EINT);
        ((Type*)yyval)->hookQuad = hookQuad;
        ((Type*)yyval)->hookLabel = hookLabel;
		yyval -> reg = to_string(((Num*)yyvsp[0])->value);
	}
#line 2120 "parser.tab.cpp"
    break;

  case 44: /* Exp: NUM B  */
#line 800 "parser.ypp"
                {
				if (((Num*)yyvsp[-1])->value > 255){
		
					output::errorByteTooLarge(yylineno, std::to_string(((Num*)yyvsp[-1])->value));
					exit(1);
				}
				//hook
				vector<pair<int,BranchLabelIndex>> hookQuad = buff.makelist({buff.emit("br label @"), FIRST});
                string hookLabel = buff.genLabel();

				yyval = new Type(EBYTE);
                ((Type*)yyval)->hookQuad = hookQuad;
                ((Type*)yyval)->hookLabel = hookLabel;
				((Type*)yyval)->reg = to_string(((Num*)yyvsp[-1])->value);
			}
#line 2140 "parser.tab.cpp"
    break;

  case 45: /* Exp: STRING  */
#line 818 "parser.ypp"
        {	yyval = new Type(ESTRING);
		
		//hook
		((Type*)yyval)->hookQuad = buff.makelist({buff.emit("br label @ "), FIRST});
		((Type*)yyval)->hookLabel = buff.genLabel();
		
		string reg = manager.createReg();

		string stringID = manager.createString();
		string stringVal = (((String*)yyvsp[0])->val);
		stringVal.pop_back();

		string stringLen = to_string(stringVal.size());

		buff.emitGlobal(stringID + " = internal constant [" + stringLen + " x i8] c" + stringVal + "\\00\"");
		buff.emit(reg + " = getelementptr [" + stringLen + " x i8], [" + stringLen + " x i8]* " + stringID + ", i8 0, i8 0");
		((Type*)yyval)->reg = reg;
	}
#line 2163 "parser.tab.cpp"
    break;

  case 46: /* Exp: TRUE  */
#line 838 "parser.ypp"
        {
		//hook
        vector<pair<int,BranchLabelIndex>> hookQuad = buff.makelist({buff.emit("br label @"), FIRST});
        string hookLabel = buff.genLabel();
		
		int quad = buff.emit("br label @");
		yyval = new Type(EBOOL, buff.makelist({quad,FIRST}), vector<jumpPair>());
		((Type*)yyval)->hookQuad = hookQuad;
		((Type*)yyval)->hookLabel = hookLabel;
		((Type*)yyval)->reg = "1";

	}
#line 2180 "parser.tab.cpp"
    break;

  case 47: /* Exp: FALSE  */
#line 852 "parser.ypp"
        {
		//hook
        vector<pair<int,BranchLabelIndex>> hookQuad = buff.makelist({buff.emit("br label @"), FIRST});
        string hookLabel = buff.genLabel();

		int quad = buff.emit("br label @");
		yyval = new Type(EBOOL, vector<jumpPair>(), buff.makelist({quad, FIRST}));
        ((Type*)yyval)->hookQuad = hookQuad;
		((Type*)yyval)->hookLabel = hookLabel;
		((Type*)yyval)->reg = "0";
	}
#line 2196 "parser.tab.cpp"
    break;

  case 48: /* Exp: NOT Exp  */
#line 865 "parser.ypp"
                  {
				if (((Type*)yyvsp[0])->type != EBOOL) {
					output::errorMismatch(yylineno);
					exit(1);
				}
				//hook
				yyval = new Type(EBOOL, ((Type*)yyvsp[0])->falseList, ((Type*)yyvsp[0])->trueList);
                ((Type*)yyval)->hookQuad = (( Type*)yyvsp[0])->hookQuad;
		        ((Type*)yyval)->hookLabel = (( Type*)yyvsp[0])->hookLabel;
				delete yyvsp[0];
			}
#line 2212 "parser.tab.cpp"
    break;

  case 49: /* Exp: Exp AND M Exp  */
#line 878 "parser.ypp"
                        {
				if(((Type*)yyvsp[-3])->type != EBOOL || ((Type*)yyvsp[0])->type != EBOOL)
				{
					output::errorMismatch(yylineno);
					exit(1);
				}
				//hook
				buff.bpatch( ((Type*)yyvsp[0])->hookQuad, ((Type*)yyvsp[0])->hookLabel);
				
				buff.bpatch(((Type*)yyvsp[-3])->trueList, (((M*)yyvsp[-1])->quad));
				yyval = new Type(EBOOL, ((Type*)yyvsp[0])->trueList, buff.merge(((Type*)yyvsp[-3])->falseList, ((Type*)yyvsp[0])->falseList));
                ((Type*)yyval)->hookQuad = ((Type*)yyvsp[-3])->hookQuad;
                ((Type*)yyval)->hookLabel = ((Type*)yyvsp[-3])->hookLabel;

				delete yyvsp[-3];
				delete yyvsp[-1];
				delete yyvsp[0];
			}
#line 2235 "parser.tab.cpp"
    break;

  case 50: /* Exp: Exp OR M Exp  */
#line 899 "parser.ypp"
                {				
			if(((Type*)yyvsp[-3])->type!=EBOOL || ((Type*)yyvsp[0])->type!=EBOOL)
			{
				output::errorMismatch(yylineno);
				exit(1);
			}
			//hook
			buff.bpatch( ((Type*)yyvsp[0])->hookQuad, ((Type*)yyvsp[0])->hookLabel);

			buff.bpatch(((Type*)yyvsp[-3])->falseList, (((M*)yyvsp[-1])->quad));
			yyval = new Type(EBOOL, buff.merge(((Type*)yyvsp[-3])->trueList, ((Type*)yyvsp[0])->trueList), ((Type*)yyvsp[0])->falseList);
            ((Type*)yyval)->hookQuad = ((Type*)yyvsp[-3])->hookQuad;
            ((Type*)yyval)->hookLabel = ((Type*)yyvsp[-3])->hookLabel;

			delete yyvsp[-3];
			delete yyvsp[-1];
			delete yyvsp[0];
		}
#line 2258 "parser.tab.cpp"
    break;

  case 51: /* Exp: Exp RELOP_EQ Exp  */
#line 920 "parser.ypp"
                        {
				if(!(((Type*)yyvsp[-2])->isNum()) || !(((Type*)yyvsp[0])->isNum())) {
					output::errorMismatch(yylineno);
					exit(1);
				}
				//hook
				buff.bpatch( ((Type*)yyvsp[0])->hookQuad, ((Type*)yyvsp[0])->hookLabel);

				string oper = (((Oper*)yyvsp[-1])->oper != "==") ? "ne" : "eq";
				string reg = manager.createReg();

				buff.emit(reg + " = icmp "+ oper + " i32 " + ((Type*)yyvsp[-2])->reg + ", " + ((Type*)yyvsp[0])->reg);
				int quad = buff.emit("br i1 " + reg + ", label @, label @");

				yyval = new Type(EBOOL, buff.makelist({quad,FIRST}), buff.makelist({quad,SECOND}));	
                ((Type*)yyval)->hookQuad = ((Type*)yyvsp[-2])->hookQuad;
                ((Type*)yyval)->hookLabel = ((Type*)yyvsp[-2])->hookLabel;	
				((Type*)yyval)->reg = reg;
				delete yyvsp[-2];
				delete yyvsp[-1];
				delete yyvsp[0];
			}
#line 2285 "parser.tab.cpp"
    break;

  case 52: /* Exp: Exp RELOP_REL Exp  */
#line 944 "parser.ypp"
                            {
				if(!(((Type*)yyvsp[-2])->isNum()) || !(((Type*)yyvsp[0])->isNum())) {
					output::errorMismatch(yylineno);
					exit(1);
				}
				//hook
				buff.bpatch( ((Type*)yyvsp[0])->hookQuad, ((Type*)yyvsp[0])->hookLabel);

				string reg = manager.createReg();
				string oper = ((Oper*)yyvsp[-1])->oper;
				string stringOper = "sgt";
				if (oper == "<") stringOper = "slt";
				else if (oper == "<=") stringOper = "sle";
				else if (oper == ">=") stringOper = "sge";
				buff.emit(reg + " = icmp " + stringOper + " i32 " + ((Type*)yyvsp[-2])->reg + ", " + ((Type*)yyvsp[0])->reg);
				int quad = buff.emit("br i1 " + reg + ", label @, label @");
				yyval = new Type(EBOOL, buff.makelist({quad,FIRST}),buff.makelist({quad,SECOND}));
                ((Type*)yyval)->hookQuad = ((Type*)yyvsp[-2])->hookQuad;
                ((Type*)yyval)->hookLabel = ((Type*)yyvsp[-2])->hookLabel;
				((Type*)yyval)->reg = reg;

				delete yyvsp[-2];
				delete yyvsp[-1];
				delete yyvsp[0];}
#line 2314 "parser.tab.cpp"
    break;

  case 53: /* Exp: LPAREN Type RPAREN Exp  */
#line 971 "parser.ypp"
                        {
				if(!((Type*)yyvsp[-2])->isNum() || !((Type*)yyvsp[0])->isNum())
				{
					output::errorMismatch(yylineno);
					exit(1);
				}
				yyval = ((Type*)yyvsp[0]);
                
				//hook
				((Type*)yyval)->hookQuad = ((Type*)yyvsp[0])->hookQuad;
				((Type*)yyval)->hookLabel = ((Type*)yyvsp[0])->hookLabel;

				((Type*)yyval)->type = ((Type*)yyvsp[-2])->type;

				if(((Type*)yyval)->type == EBYTE) truncRes(((Type*)yyval));
				delete yyvsp[-2];
			}
#line 2336 "parser.tab.cpp"
    break;

  case 54: /* BoolExp: Exp  */
#line 991 "parser.ypp"
                        {
				// check expertion is boolean
				if (((Type*)yyvsp[0])->type != EBOOL) {
					output::errorMismatch(yylineno);
					exit(1);
				}
				//hook
			    buff.bpatch( ((Type*)yyvsp[0])->hookQuad, ((Type*)yyvsp[0])->hookLabel);
				yyval=yyvsp[0];
                // buff.emit("; BoolExp : Exp:    " + ((Type*)$$)->hookLabel + " " + ((Type*)$1)->hookLabel);
			}
#line 2352 "parser.tab.cpp"
    break;

  case 55: /* M: %empty  */
#line 1006 "parser.ypp"
                {
			yyval = new M(buff.genLabel());
		}
#line 2360 "parser.tab.cpp"
    break;

  case 56: /* N: %empty  */
#line 1012 "parser.ypp"
                {
			int quad = buff.emit("br label @");
			string stringQuad= to_string(quad);
			yyval = new N(stringQuad, buff.makelist({quad, FIRST}));
		}
#line 2370 "parser.tab.cpp"
    break;

  case 57: /* OPEN_MARKER: %empty  */
#line 1019 "parser.ypp"
                     {scopeStacks.openScope(scopeStacks.isWhileScope());}
#line 2376 "parser.tab.cpp"
    break;

  case 58: /* WHILE_OPEN_MARKER: %empty  */
#line 1023 "parser.ypp"
        {
		scopeStacks.openScope(true);
		vector<jumpPair> newCont = vector<jumpPair>();
		vector<jumpPair> newBrk = vector<jumpPair>();
		scopeStacks.conts.push(newCont);
		scopeStacks.brks.push(newBrk);
	}
#line 2388 "parser.tab.cpp"
    break;

  case 59: /* CLOSE_MARKER: %empty  */
#line 1032 "parser.ypp"
                      {scopeStacks.closeScope();}
#line 2394 "parser.tab.cpp"
    break;


#line 2398 "parser.tab.cpp"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1034 "parser.ypp"


int main()
{
	yyparse();
}


bool IsLegalAssignment(EType type1, EType type2){
	return ((type1 == EINT && type2 == EBYTE) || (type1 == type2));
}

void yyerror(const char * message)
{
	output::errorSyn(yylineno);
	exit(0);
}


void Start() {
	buff.emitGlobal("declare i32 @printf(i8*, ...)");
    buff.emitGlobal("declare void @exit(i32)");
    buff.emitGlobal("@.int_specifier = constant [4 x i8] c\"%d\\0A\\00\"");
    buff.emitGlobal("@.str_specifier = constant [4 x i8] c\"%s\\0A\\00\"");
    buff.emitGlobal("define void @printi(i32) {");
    buff.emitGlobal("call i32 (i8*, ...) @printf(i8* getelementptr ([4 x i8], [4 x i8]* @.int_specifier, i32 0, i32 0), i32 %0)");
    buff.emitGlobal("ret void");
    buff.emitGlobal("}");
    buff.emitGlobal("define void @print(i8*) {");
    buff.emitGlobal("call i32 (i8*, ...) @printf(i8* getelementptr ([4 x i8], [4 x i8]* @.str_specifier, i32 0, i32 0), i8* %0)");
    buff.emitGlobal("ret void");
    buff.emitGlobal("}");

	buff.emitGlobal("@.zeroDivException = constant [23 x i8] c\"Error division by zero\\00\"");
}

void truncRes(Type* type){
    string reg = manager.createReg();
	string toEmit = reg + " = and i32 255, " + type->reg;
    buff.emit(toEmit);
    type->reg = reg;
}

string Phi(Type* expr) {
	string trueLabel = buff.genLabel();
	int trueQuad = buff.emit("br label @ ");
	string falseLabel = buff.genLabel();
	int falseQuad = buff.emit("br label @ ");
	buff.bpatch(expr->falseList, falseLabel);
	buff.bpatch(expr->trueList, trueLabel);
	string lastLabel = buff.genLabel();
	buff.bpatch(buff.makelist({falseQuad, FIRST}), lastLabel);
	buff.bpatch(buff.makelist({trueQuad, FIRST}), lastLabel);
	string reg = manager.createReg();
	buff.emit(reg + " = phi i32 [1, %" + trueLabel + "], [0, %" + falseLabel + "]");

	return reg;
}
