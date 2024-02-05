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
#line 1 "iope.y"

#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <utility>
#include "SymbolTable.h"

using namespace std;

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);

SymbolTable st;
string scope = "global";
string current_type;
string current_scope;
string pack_name;

vector<VarInfo> current_vars;
vector<pair<VarInfo*, VecInfo*>> current_params;

vector<VecInfo> current_vecs;

vector<FuncInfo> current_funcs;
vector<AST*> current_exprs;

vector<int> current_dims;
vector<AST*> init_values_vec;

vector<VarInfo> pack_vars;
vector<VecInfo> pack_vecs;
stack<int> size_stack;  

#line 110 "iope.tab.c"

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

#include "iope.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BGIN = 3,                       /* BGIN  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_EXEC = 5,                       /* EXEC  */
  YYSYMBOL_DIE = 6,                        /* DIE  */
  YYSYMBOL_PACK = 7,                       /* PACK  */
  YYSYMBOL_ASSIGN = 8,                     /* ASSIGN  */
  YYSYMBOL_CONST = 9,                      /* CONST  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_AND = 13,                       /* AND  */
  YYSYMBOL_OR = 14,                        /* OR  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_EQG = 17,                       /* EQG  */
  YYSYMBOL_EQL = 18,                       /* EQL  */
  YYSYMBOL_NEQ = 19,                       /* NEQ  */
  YYSYMBOL_PACKS = 20,                     /* PACKS  */
  YYSYMBOL_END_PACKS = 21,                 /* END_PACKS  */
  YYSYMBOL_GLOBAL_V = 22,                  /* GLOBAL_V  */
  YYSYMBOL_END_GLOBAL_V = 23,              /* END_GLOBAL_V  */
  YYSYMBOL_GLOBAL_F = 24,                  /* GLOBAL_F  */
  YYSYMBOL_END_GLOBAL_F = 25,              /* END_GLOBAL_F  */
  YYSYMBOL_PACK_ACCESS = 26,               /* PACK_ACCESS  */
  YYSYMBOL_RET = 27,                       /* RET  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_TYPE = 29,                      /* TYPE  */
  YYSYMBOL_EVAL = 30,                      /* EVAL  */
  YYSYMBOL_TYPEOF = 31,                    /* TYPEOF  */
  YYSYMBOL_FLOAT = 32,                     /* FLOAT  */
  YYSYMBOL_STRING = 33,                    /* STRING  */
  YYSYMBOL_CHAR = 34,                      /* CHAR  */
  YYSYMBOL_TRU = 35,                       /* TRU  */
  YYSYMBOL_FOLS = 36,                      /* FOLS  */
  YYSYMBOL_ID = 37,                        /* ID  */
  YYSYMBOL_NR = 38,                        /* NR  */
  YYSYMBOL_39_ = 39,                       /* '<'  */
  YYSYMBOL_40_ = 40,                       /* '>'  */
  YYSYMBOL_41_ = 41,                       /* '+'  */
  YYSYMBOL_42_ = 42,                       /* '-'  */
  YYSYMBOL_43_ = 43,                       /* '*'  */
  YYSYMBOL_44_ = 44,                       /* '/'  */
  YYSYMBOL_45_ = 45,                       /* '%'  */
  YYSYMBOL_MINUS = 46,                     /* MINUS  */
  YYSYMBOL_47_ = 47,                       /* ';'  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_50_ = 50,                       /* ','  */
  YYSYMBOL_51_ = 51,                       /* '['  */
  YYSYMBOL_52_ = 52,                       /* ']'  */
  YYSYMBOL_53_ = 53,                       /* '{'  */
  YYSYMBOL_54_ = 54,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_progr = 56,                     /* progr  */
  YYSYMBOL_gen_packs = 57,                 /* gen_packs  */
  YYSYMBOL_gen_global_vals = 58,           /* gen_global_vals  */
  YYSYMBOL_gen_global_funcs = 59,          /* gen_global_funcs  */
  YYSYMBOL_declarations_pack = 60,         /* declarations_pack  */
  YYSYMBOL_decl_pack = 61,                 /* decl_pack  */
  YYSYMBOL_62_1 = 62,                      /* $@1  */
  YYSYMBOL_declarations = 63,              /* declarations  */
  YYSYMBOL_decl = 64,                      /* decl  */
  YYSYMBOL_65_2 = 65,                      /* $@2  */
  YYSYMBOL_66_3 = 66,                      /* $@3  */
  YYSYMBOL_67_4 = 67,                      /* $@4  */
  YYSYMBOL_68_5 = 68,                      /* $@5  */
  YYSYMBOL_list_param_packs = 69,          /* list_param_packs  */
  YYSYMBOL_param_pack = 70,                /* param_pack  */
  YYSYMBOL_declarations_v = 71,            /* declarations_v  */
  YYSYMBOL_decl_v = 72,                    /* decl_v  */
  YYSYMBOL_declarations_f = 73,            /* declarations_f  */
  YYSYMBOL_decl_f = 74,                    /* decl_f  */
  YYSYMBOL_75_6 = 75,                      /* $@6  */
  YYSYMBOL_76_7 = 76,                      /* $@7  */
  YYSYMBOL_77_8 = 77,                      /* $@8  */
  YYSYMBOL_78_9 = 78,                      /* $@9  */
  YYSYMBOL_list_param = 79,                /* list_param  */
  YYSYMBOL_param = 80,                     /* param  */
  YYSYMBOL_size = 81,                      /* size  */
  YYSYMBOL_block = 82,                     /* block  */
  YYSYMBOL_83_10 = 83,                     /* $@10  */
  YYSYMBOL_list = 84,                      /* list  */
  YYSYMBOL_statement = 85,                 /* statement  */
  YYSYMBOL_86_11 = 86,                     /* $@11  */
  YYSYMBOL_87_12 = 87,                     /* $@12  */
  YYSYMBOL_88_13 = 88,                     /* $@13  */
  YYSYMBOL_89_14 = 89,                     /* $@14  */
  YYSYMBOL_90_15 = 90,                     /* $@15  */
  YYSYMBOL_init_for_vec = 91,              /* init_for_vec  */
  YYSYMBOL_init_vec = 92,                  /* init_vec  */
  YYSYMBOL_call_param = 93,                /* call_param  */
  YYSYMBOL_expr = 94,                      /* expr  */
  YYSYMBOL_95_16 = 95,                     /* $@16  */
  YYSYMBOL_96_17 = 96,                     /* $@17  */
  YYSYMBOL_97_18 = 97,                     /* $@18  */
  YYSYMBOL_98_19 = 98                      /* $@19  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   694

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  295

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
       2,     2,     2,     2,     2,     2,     2,    45,     2,     2,
      48,    49,    43,    41,    50,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
      39,     2,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      35,    36,    37,    38,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    62,    63,    65,    66,    68,    69,    72,
      73,    76,    76,    81,    82,    84,    88,    93,    99,    99,
     105,   105,   112,   112,   118,   118,   124,   129,   135,   136,
     139,   143,   147,   148,   151,   155,   159,   165,   174,   187,
     188,   191,   191,   197,   197,   203,   203,   209,   209,   214,
     215,   218,   222,   227,   231,   238,   242,   248,   248,   256,
     257,   260,   264,   269,   275,   284,   293,   297,   301,   308,
     315,   322,   322,   336,   336,   350,   350,   364,   364,   387,
     387,   410,   414,   418,   427,   430,   434,   440,   443,   448,
     451,   454,   457,   460,   463,   466,   469,   472,   475,   478,
     481,   484,   487,   525,   528,   531,   534,   537,   540,   543,
     546,   549,   552,   572,   572,   587,   587,   602,   627,   627,
     651,   651,   675
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
  "\"end of file\"", "error", "\"invalid token\"", "BGIN", "END", "EXEC",
  "DIE", "PACK", "ASSIGN", "CONST", "IF", "FOR", "WHILE", "AND", "OR",
  "NOT", "EQ", "EQG", "EQL", "NEQ", "PACKS", "END_PACKS", "GLOBAL_V",
  "END_GLOBAL_V", "GLOBAL_F", "END_GLOBAL_F", "PACK_ACCESS", "RET", "ELSE",
  "TYPE", "EVAL", "TYPEOF", "FLOAT", "STRING", "CHAR", "TRU", "FOLS", "ID",
  "NR", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "MINUS", "';'",
  "'('", "')'", "','", "'['", "']'", "'{'", "'}'", "$accept", "progr",
  "gen_packs", "gen_global_vals", "gen_global_funcs", "declarations_pack",
  "decl_pack", "$@1", "declarations", "decl", "$@2", "$@3", "$@4", "$@5",
  "list_param_packs", "param_pack", "declarations_v", "decl_v",
  "declarations_f", "decl_f", "$@6", "$@7", "$@8", "$@9", "list_param",
  "param", "size", "block", "$@10", "list", "statement", "$@11", "$@12",
  "$@13", "$@14", "$@15", "init_for_vec", "init_vec", "call_param", "expr",
  "$@16", "$@17", "$@18", "$@19", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-151)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      82,  -151,    49,     1,    39,    59,  -151,  -151,  -151,  -151,
     657,   -28,    94,    14,    65,    51,     9,    81,    68,    75,
       2,    98,  -151,   112,    86,    95,   102,    88,   109,   106,
     107,    -5,   634,   124,  -151,   105,   126,  -151,   137,    -2,
      87,   128,  -151,   140,   131,   175,   134,  -151,   145,    88,
     146,    88,    88,   136,  -151,  -151,  -151,  -151,  -151,    19,
    -151,    88,    88,   616,     0,    88,    88,    88,   149,   141,
     153,  -151,   151,  -151,   189,  -151,  -151,   185,    88,   161,
     188,  -151,  -151,   159,     4,  -151,  -151,   198,   246,   202,
     257,   633,    88,   179,   168,   181,  -151,   291,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,   217,   302,   336,   616,   178,    88,   180,   176,  -151,
      60,    88,   616,   191,   174,     5,   203,   194,   237,   -21,
    -151,    88,   238,    88,   241,   347,    42,    88,   196,   197,
    -151,   633,   195,    96,    96,    96,    96,    96,    96,    21,
      21,  -151,  -151,   616,   174,  -151,  -151,   199,    50,   616,
    -151,   239,   222,   215,    15,   207,   616,   206,    88,  -151,
     255,    67,   229,   206,  -151,   264,    62,   616,   657,   616,
     657,  -151,   219,   231,    83,  -151,  -151,  -151,    88,   223,
    -151,    88,    88,   240,    -1,   242,   233,  -151,  -151,   -34,
     616,  -151,   275,   206,  -151,   657,  -151,  -151,   158,   234,
     193,    88,   235,   230,  -151,    99,  -151,   616,   616,     7,
      88,     8,   283,   206,   243,  -151,  -151,    88,  -151,   657,
    -151,  -151,   433,   657,   266,    88,  -151,   103,  -151,  -151,
    -151,    88,    13,   616,   280,   108,   174,  -151,   242,   616,
     442,   657,  -151,   471,   289,   392,  -151,   616,   299,   111,
    -151,   300,  -151,  -151,  -151,   480,  -151,   657,   274,  -151,
     309,   657,  -151,  -151,   509,   305,   657,  -151,   518,   657,
    -151,    88,   547,   657,  -151,   556,   381,  -151,   585,  -151,
     311,  -151,   657,   594,  -151
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    57,     0,     0,     0,     0,     2,     4,     6,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     9,     0,    34,
       0,     0,    32,     0,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   100,   101,   102,
     103,     0,     0,    83,    61,     0,     0,     0,     0,    73,
       0,    58,     0,    59,     0,     3,    10,     0,     0,     0,
      35,     5,    33,     0,     0,     7,    40,     0,     0,     0,
       0,    91,     0,     0,   113,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,     0,     0,    66,     0,     0,     0,     0,    60,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,   117,     0,     0,     0,
      92,    89,    90,    96,    97,    98,    99,    94,    95,   107,
     108,   109,   110,    64,     0,    81,    82,    77,     0,    87,
      76,     0,     0,     0,     0,     0,    38,    55,     0,    36,
       0,     0,     0,    51,    43,     0,     0,    65,     0,    71,
       0,   111,   118,     0,     0,   116,   112,    63,     0,     0,
      74,     0,     0,     0,    15,     0,     0,    13,    56,     0,
      85,    47,     0,    53,    52,     0,    41,    50,     0,     0,
       0,     0,     0,     0,   114,     0,    80,    88,    67,     0,
       0,     0,    16,    30,    12,    28,    14,     0,    84,     0,
      45,    54,     0,     0,    68,     0,    70,     0,   121,   122,
      78,     0,     0,    26,     0,     0,     0,    31,     0,    86,
       0,     0,    44,     0,     0,     0,   119,    27,     0,     0,
      20,     0,    17,    29,    48,     0,    42,     0,     0,    24,
       0,     0,    18,    46,     0,     0,     0,    22,     0,     0,
      69,     0,     0,     0,    21,     0,     0,    25,     0,    19,
       0,    23,     0,     0,    72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,  -151,   282,   284,  -151,   310,  -151,  -151,   162,
    -151,  -151,  -151,  -151,  -151,    77,  -151,   307,  -151,   308,
    -151,  -151,  -151,  -151,  -123,   160,   -59,   292,  -151,  -120,
     -32,  -151,  -151,  -151,  -151,  -151,  -150,  -151,  -125,   -26,
    -151,  -151,  -151,  -151
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,     6,     7,     8,    12,    13,    74,   164,   165,
     279,   271,   283,   276,   224,   225,    16,    17,    20,    21,
     233,   205,   251,   229,   129,   130,    80,     9,    10,    32,
      33,   209,   116,   117,   188,   189,   169,   199,   158,   159,
     137,   138,   211,   212
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      72,    63,   171,    67,   187,   111,    78,   220,   110,    34,
      14,    18,   184,   126,   126,   241,   227,   126,    14,   195,
     228,    68,   126,    88,   162,    90,    91,    45,   175,   176,
      15,    19,    40,   127,   127,    96,    97,   127,    15,   112,
     113,   114,   127,    69,   163,    93,    70,   221,    18,    79,
      79,    79,   122,   128,   170,   242,    11,   244,   208,    22,
     210,    37,   258,   215,   108,   109,   135,    94,    19,   162,
      95,   126,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   232,   237,     1,    39,   163,
     182,   127,     1,   183,    38,   166,   262,    43,   245,   190,
     191,    11,     2,    52,     3,   177,     4,   179,   198,   250,
       1,     4,    44,   253,   204,    35,   202,   176,    53,   259,
      54,    55,    56,    57,    58,    59,    60,     3,    42,     4,
      61,   265,   214,   191,    49,   222,    62,   106,   107,   108,
     109,    48,   200,    50,   231,    47,    64,   274,   240,   191,
      51,   278,   256,   191,    65,    66,   282,   261,   176,   285,
     270,   176,   234,   288,   247,   217,   218,    23,    24,    25,
      26,    73,   293,    76,    77,    82,    72,    83,    72,    84,
       1,    86,    87,    89,    92,    27,   115,    28,    29,    30,
     -75,   118,   120,   121,   243,    31,   124,   236,   119,   123,
      72,   249,    23,    24,    25,    26,   131,   125,    98,   255,
     133,   100,   101,   102,   103,   257,   136,  -115,    72,   139,
      27,    72,    28,    29,    30,   154,   157,   168,   161,   160,
      31,   173,   172,    72,   104,   105,   106,   107,   108,   109,
     174,   178,    72,   167,   180,   185,    72,   192,   -79,   186,
      72,   193,   194,    72,   197,   286,    72,    79,   201,    98,
      99,    72,   100,   101,   102,   103,   203,   206,  -120,   213,
      98,    99,   216,   100,   101,   102,   103,   219,   230,   223,
     226,   235,   239,   260,   238,   104,   105,   106,   107,   108,
     109,   246,   267,   248,   254,   132,   104,   105,   106,   107,
     108,   109,   269,   272,    98,    99,   134,   100,   101,   102,
     103,   275,   277,   281,   292,    98,    99,    75,   100,   101,
     102,   103,    36,    41,    81,   263,   196,     0,    46,     0,
     104,   105,   106,   107,   108,   109,   207,    85,     0,     0,
     140,   104,   105,   106,   107,   108,   109,     0,     0,    98,
      99,   155,   100,   101,   102,   103,     0,     0,     0,     0,
      98,    99,     0,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,     0,     0,     0,     0,   156,   104,   105,   106,   107,
     108,   109,     0,     0,    98,    99,   181,   100,   101,   102,
     103,     0,     0,     0,     0,    98,    99,     0,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
     290,   104,   105,   106,   107,   108,   109,   252,     0,   268,
       0,     0,    23,    24,    25,    26,   264,     0,     0,     0,
       0,    23,    24,    25,    26,     0,     0,     0,     0,     0,
      27,     0,    28,    29,    30,     0,     0,     0,     0,    27,
      31,    28,    29,    30,     0,   266,     0,     0,     0,    31,
      23,    24,    25,    26,   273,     0,     0,     0,     0,    23,
      24,    25,    26,     0,     0,     0,     0,     0,    27,     0,
      28,    29,    30,     0,     0,     0,     0,    27,    31,    28,
      29,    30,     0,   280,     0,     0,     0,    31,    23,    24,
      25,    26,   284,     0,     0,     0,     0,    23,    24,    25,
      26,     0,     0,     0,     0,     0,    27,     0,    28,    29,
      30,     0,     0,     0,     0,    27,    31,    28,    29,    30,
       0,   287,     0,     0,     0,    31,    23,    24,    25,    26,
     289,     0,     0,     0,     0,    23,    24,    25,    26,     0,
       0,     0,     0,     0,    27,     0,    28,    29,    30,     0,
       0,     0,     0,    27,    31,    28,    29,    30,     0,   291,
       0,     0,     0,    31,    23,    24,    25,    26,   294,     0,
       0,     0,     0,    23,    24,    25,    26,     0,     0,     0,
       0,     0,    27,     0,    28,    29,    30,     0,     0,     0,
       0,    27,    31,    28,    29,    30,     0,     0,     0,    98,
      99,    31,   100,   101,   102,   103,     0,     0,     0,     0,
      71,     0,     0,    23,    24,    25,    26,     0,     0,   100,
     101,   102,   103,     0,     0,   104,   105,   106,   107,   108,
     109,    27,     0,    28,    29,    30,    23,    24,    25,    26,
       0,    31,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,     0,    27,     0,    28,    29,    30,     0,
       0,     0,     0,     0,    31
};

static const yytype_int16 yycheck[] =
{
      32,    27,   125,     8,   154,    64,     8,     8,     8,    37,
       9,     9,   137,     9,     9,     8,    50,     9,     9,     4,
      54,    26,     9,    49,     9,    51,    52,    25,    49,    50,
      29,    29,    23,    29,    29,    61,    62,    29,    29,    65,
      66,    67,    29,    48,    29,    26,    51,    48,     9,    51,
      51,    51,    78,    49,    49,    48,     7,    49,   178,     0,
     180,    47,    49,   188,    43,    44,    92,    48,    29,     9,
      51,     9,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   205,   211,     5,    37,    29,
      48,    29,     5,    51,    29,   121,   246,    29,   221,    49,
      50,     7,    20,    15,    22,   131,    24,   133,   167,   229,
       5,    24,    37,   233,   173,    21,    49,    50,    30,   242,
      32,    33,    34,    35,    36,    37,    38,    22,    47,    24,
      42,   251,    49,    50,    48,   194,    48,    41,    42,    43,
      44,    29,   168,    48,   203,    47,    37,   267,    49,    50,
      48,   271,    49,    50,    48,    48,   276,    49,    50,   279,
      49,    50,     4,   283,   223,   191,   192,     9,    10,    11,
      12,    47,   292,    47,    37,    47,   208,    37,   210,    48,
       5,    47,    37,    37,    48,    27,    37,    29,    30,    31,
      49,    38,     3,     8,   220,    37,     8,     4,    47,    38,
     232,   227,     9,    10,    11,    12,     8,    48,    13,   235,
       8,    16,    17,    18,    19,   241,    37,    49,   250,    38,
      27,   253,    29,    30,    31,     8,    48,    53,    52,    49,
      37,    37,    29,   265,    39,    40,    41,    42,    43,    44,
       3,     3,   274,    52,     3,    49,   278,     8,    49,    52,
     282,    29,    37,   285,    47,   281,   288,    51,     3,    13,
      14,   293,    16,    17,    18,    19,    37,     3,    49,    38,
      13,    14,    49,    16,    17,    18,    19,    37,     3,    37,
      47,    47,    52,     3,    49,    39,    40,    41,    42,    43,
      44,     8,     3,    50,    28,    49,    39,    40,    41,    42,
      43,    44,     3,     3,    13,    14,    49,    16,    17,    18,
      19,    37,     3,     8,     3,    13,    14,    35,    16,    17,
      18,    19,    12,    16,    40,   248,   164,    -1,    20,    -1,
      39,    40,    41,    42,    43,    44,   176,    45,    -1,    -1,
      49,    39,    40,    41,    42,    43,    44,    -1,    -1,    13,
      14,    49,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      13,    14,    -1,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    49,    39,    40,    41,    42,
      43,    44,    -1,    -1,    13,    14,    49,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    13,    14,    -1,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      49,    39,    40,    41,    42,    43,    44,     4,    -1,    47,
      -1,    -1,     9,    10,    11,    12,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    29,    30,    31,    -1,    -1,    -1,    -1,    27,
      37,    29,    30,    31,    -1,     4,    -1,    -1,    -1,    37,
       9,    10,    11,    12,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      29,    30,    31,    -1,    -1,    -1,    -1,    27,    37,    29,
      30,    31,    -1,     4,    -1,    -1,    -1,    37,     9,    10,
      11,    12,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    27,    -1,    29,    30,
      31,    -1,    -1,    -1,    -1,    27,    37,    29,    30,    31,
      -1,     4,    -1,    -1,    -1,    37,     9,    10,    11,    12,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    29,    30,    31,    -1,
      -1,    -1,    -1,    27,    37,    29,    30,    31,    -1,     4,
      -1,    -1,    -1,    37,     9,    10,    11,    12,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    29,    30,    31,    -1,    -1,    -1,
      -1,    27,    37,    29,    30,    31,    -1,    -1,    -1,    13,
      14,    37,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
       6,    -1,    -1,     9,    10,    11,    12,    -1,    -1,    16,
      17,    18,    19,    -1,    -1,    39,    40,    41,    42,    43,
      44,    27,    -1,    29,    30,    31,     9,    10,    11,    12,
      -1,    37,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    20,    22,    24,    56,    57,    58,    59,    82,
      83,     7,    60,    61,     9,    29,    71,    72,     9,    29,
      73,    74,     0,     9,    10,    11,    12,    27,    29,    30,
      31,    37,    84,    85,    37,    21,    61,    47,    29,    37,
      23,    72,    47,    29,    37,    25,    74,    47,    29,    48,
      48,    48,    15,    30,    32,    33,    34,    35,    36,    37,
      38,    42,    48,    94,    37,    48,    48,     8,    26,    48,
      51,     6,    85,    47,    62,    58,    47,    37,     8,    51,
      81,    59,    47,    37,    48,    82,    47,    37,    94,    37,
      94,    94,    48,    26,    48,    51,    94,    94,    13,    14,
      16,    17,    18,    19,    39,    40,    41,    42,    43,    44,
       8,    81,    94,    94,    94,    37,    87,    88,    38,    47,
       3,     8,    94,    38,     8,    48,     9,    29,    49,    79,
      80,     8,    49,     8,    49,    94,    37,    95,    96,    38,
      49,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,     8,    49,    49,    48,    93,    94,
      49,    52,     9,    29,    63,    64,    94,    52,    53,    91,
      49,    79,    29,    37,     3,    49,    50,    94,     3,    94,
       3,    49,    48,    51,    93,    49,    52,    91,    89,    90,
      49,    50,     8,    29,    37,     4,    64,    47,    81,    92,
      94,     3,    49,    37,    81,    76,     3,    80,    84,    86,
      84,    97,    98,    38,    49,    93,    49,    94,    94,    37,
       8,    48,    81,    37,    69,    70,    47,    50,    54,    78,
       3,    81,    84,    75,     4,    47,     4,    93,    49,    52,
      49,     8,    48,    94,    49,    79,     8,    81,    50,    94,
      84,    77,     4,    84,    28,    94,    49,    94,    49,    79,
       3,    49,    91,    70,     4,    84,     4,     3,    47,     3,
      49,    66,     3,     4,    84,    37,    68,     3,    84,    65,
       4,     8,    84,    67,     4,    84,    94,     4,    84,     4,
      49,     4,     3,    84,     4
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    62,    61,    63,    63,    64,    64,    64,    65,    64,
      66,    64,    67,    64,    68,    64,    64,    64,    69,    69,
      70,    70,    71,    71,    72,    72,    72,    72,    72,    73,
      73,    75,    74,    76,    74,    77,    74,    78,    74,    79,
      79,    80,    80,    80,    80,    81,    81,    83,    82,    84,
      84,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    85,    87,    85,    88,    85,    89,    85,    90,
      85,    85,    85,    85,    91,    92,    92,    93,    93,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    95,    94,    96,    94,    94,    97,    94,
      98,    94,    94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     4,     1,     4,     1,     4,     1,     2,
       3,     0,     7,     2,     3,     2,     3,     5,     0,     9,
       0,     8,     0,    10,     0,     9,     4,     5,     1,     3,
       1,     2,     2,     3,     2,     3,     5,     4,     5,     2,
       3,     0,     9,     0,     8,     0,    10,     0,     9,     1,
       3,     2,     3,     3,     4,     3,     4,     0,     4,     2,
       3,     2,     3,     5,     4,     5,     3,     6,     7,    11,
       7,     0,    16,     0,     5,     0,     4,     0,     7,     0,
       6,     4,     4,     2,     3,     1,     3,     1,     3,     3,
       3,     2,     3,     2,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     4,     4,     0,     5,     0,     4,     3,     0,     7,
       0,     6,     6
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
  case 11: /* $@1: %empty  */
#line 76 "iope.y"
                  {pack_name = (yyvsp[0].String);}
#line 1466 "iope.tab.c"
    break;

  case 12: /* decl_pack: PACK ID $@1 BGIN declarations END list_param_packs  */
#line 76 "iope.y"
                                                                          {
               pack_vars.clear();
               pack_vecs.clear();
}
#line 1475 "iope.tab.c"
    break;

  case 15: /* decl: TYPE ID  */
#line 84 "iope.y"
                     {
               VarInfo var((yyvsp[-1].String), (yyvsp[0].String), "null", pack_name, false);
               pack_vars.push_back(var);
               }
#line 1484 "iope.tab.c"
    break;

  case 16: /* decl: TYPE ID size  */
#line 88 "iope.y"
                         {
               VecInfo vec((yyvsp[-2].String), (yyvsp[-1].String), pack_name, current_dims, false);
               pack_vecs.push_back(vec);
               current_dims.clear();
           }
#line 1494 "iope.tab.c"
    break;

  case 17: /* decl: TYPE ID size ASSIGN init_for_vec  */
#line 93 "iope.y"
                                             {
               VecInfo vec((yyvsp[-4].String), (yyvsp[-3].String), pack_name, current_dims, init_values_vec, false, yylineno);
               pack_vecs.push_back(vec);
               current_dims.clear();
               init_values_vec.clear();
           }
#line 1505 "iope.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 99 "iope.y"
                                            {scope = (yyvsp[-4].String);current_type = (yyvsp[-5].String);}
#line 1511 "iope.tab.c"
    break;

  case 19: /* decl: TYPE ID '(' list_param ')' BGIN $@2 list END  */
#line 99 "iope.y"
                                                                                    {
               FuncInfo func((yyvsp[-8].String), (yyvsp[-7].String), pack_name, current_params, false);

               current_params.clear();
               st.add_func(func, yylineno);
          }
#line 1522 "iope.tab.c"
    break;

  case 20: /* $@3: %empty  */
#line 105 "iope.y"
                                 {scope = (yyvsp[-3].String);current_type = (yyvsp[-4].String);}
#line 1528 "iope.tab.c"
    break;

  case 21: /* decl: TYPE ID '(' ')' BGIN $@3 list END  */
#line 105 "iope.y"
                                                                         {
               FuncInfo func((yyvsp[-7].String), (yyvsp[-6].String), pack_name, false);

               current_params.clear();
               st.add_func(func, yylineno);

           }
#line 1540 "iope.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 112 "iope.y"
                                                  {scope = (yyvsp[-4].String); current_type = (yyvsp[-5].String);}
#line 1546 "iope.tab.c"
    break;

  case 23: /* decl: CONST TYPE ID '(' list_param ')' BGIN $@4 list END  */
#line 112 "iope.y"
                                                                                           {
               FuncInfo func((yyvsp[-8].String), (yyvsp[-7].String), pack_name, current_params, true);

               current_params.clear();
               st.add_func(func, yylineno);
           }
#line 1557 "iope.tab.c"
    break;

  case 24: /* $@5: %empty  */
#line 118 "iope.y"
                                       {scope = (yyvsp[-3].String);current_type = (yyvsp[-4].String);}
#line 1563 "iope.tab.c"
    break;

  case 25: /* decl: CONST TYPE ID '(' ')' BGIN $@5 list END  */
#line 118 "iope.y"
                                                                               {
               FuncInfo func((yyvsp[-7].String), (yyvsp[-6].String), pack_name, true);

               current_params.clear();
               st.add_func(func, yylineno);
           }
#line 1574 "iope.tab.c"
    break;

  case 26: /* decl: TYPE ID ASSIGN expr  */
#line 124 "iope.y"
                               {
               (yyvsp[0].ast)->compute();
               VarInfo var((yyvsp[-3].String), (yyvsp[-2].String), (yyvsp[0].ast), pack_name, false);
               pack_vars.push_back(var);
          }
#line 1584 "iope.tab.c"
    break;

  case 27: /* decl: CONST TYPE ID ASSIGN expr  */
#line 129 "iope.y"
                                     {
               (yyvsp[0].ast)->compute();
               VarInfo var((yyvsp[-3].String), (yyvsp[-2].String), (yyvsp[0].ast), pack_name, true);
               pack_vars.push_back(var);
          }
#line 1594 "iope.tab.c"
    break;

  case 30: /* param_pack: ID  */
#line 139 "iope.y"
              {
          PackInfo pack((yyvsp[0].String),pack_name, pack_vars, pack_vecs);
          st.add_pack(pack, yylineno);
}
#line 1603 "iope.tab.c"
    break;

  case 31: /* param_pack: ID size  */
#line 143 "iope.y"
                   {
          }
#line 1610 "iope.tab.c"
    break;

  case 34: /* decl_v: TYPE ID  */
#line 151 "iope.y"
                {
          VarInfo var((yyvsp[-1].String), (yyvsp[0].String), "null", "global", false);
          st.add_var(var, yylineno);
     }
#line 1619 "iope.tab.c"
    break;

  case 35: /* decl_v: TYPE ID size  */
#line 155 "iope.y"
                     {
          VecInfo vec((yyvsp[-2].String), (yyvsp[-1].String), "global", current_dims, false);
          st.add_vec(vec, yylineno);
      }
#line 1628 "iope.tab.c"
    break;

  case 36: /* decl_v: TYPE ID size ASSIGN init_for_vec  */
#line 159 "iope.y"
                                       {
               VecInfo vec((yyvsp[-4].String), (yyvsp[-3].String), "global", current_dims, init_values_vec, false, yylineno);
               st.add_vec(vec, yylineno);
               current_dims.clear();
               init_values_vec.clear();
     }
#line 1639 "iope.tab.c"
    break;

  case 37: /* decl_v: TYPE ID ASSIGN expr  */
#line 165 "iope.y"
                          {
          (yyvsp[0].ast)->compute();
          if((yyvsp[0].ast)->type != (yyvsp[-3].String)){
               printf("line: %d Error: %s is not a %s!\n", yylineno, (yyvsp[-2].String), (yyvsp[0].ast)->type.c_str());
               exit(1);
          }
          VarInfo var((yyvsp[-3].String), (yyvsp[-2].String), (yyvsp[0].ast), "global", false);
          st.add_var(var, yylineno);
     }
#line 1653 "iope.tab.c"
    break;

  case 38: /* decl_v: CONST TYPE ID ASSIGN expr  */
#line 174 "iope.y"
                                {
          (yyvsp[0].ast)->compute();
          if((yyvsp[0].ast)->type != (yyvsp[-3].String)){
               printf("line: %d Error: %s is not a %s!\n", yylineno, (yyvsp[-2].String), (yyvsp[0].ast)->type.c_str());
               exit(1);
          }
          (yyvsp[0].ast)->compute();
          VarInfo var((yyvsp[-3].String), (yyvsp[-2].String), (yyvsp[0].ast), "global", true);
          st.add_var(var, yylineno);
     }
#line 1668 "iope.tab.c"
    break;

  case 41: /* $@6: %empty  */
#line 191 "iope.y"
                                       {scope = (yyvsp[-4].String); current_type = (yyvsp[-5].String);}
#line 1674 "iope.tab.c"
    break;

  case 42: /* decl_f: TYPE ID '(' list_param ')' BGIN $@6 list END  */
#line 191 "iope.y"
                                                                                {
          FuncInfo func((yyvsp[-8].String), (yyvsp[-7].String), "global", current_params, false);

          current_params.clear();
          st.add_func(func, yylineno);
}
#line 1685 "iope.tab.c"
    break;

  case 43: /* $@7: %empty  */
#line 197 "iope.y"
                            {scope = (yyvsp[-3].String); current_type = (yyvsp[-4].String);}
#line 1691 "iope.tab.c"
    break;

  case 44: /* decl_f: TYPE ID '(' ')' BGIN $@7 list END  */
#line 197 "iope.y"
                                                                     {
          FuncInfo func((yyvsp[-7].String), (yyvsp[-6].String), "global", false);

          st.add_func(func, yylineno);
      }
#line 1701 "iope.tab.c"
    break;

  case 45: /* $@8: %empty  */
#line 203 "iope.y"
                                             {scope = (yyvsp[-4].String); current_type = (yyvsp[-5].String);}
#line 1707 "iope.tab.c"
    break;

  case 46: /* decl_f: CONST TYPE ID '(' list_param ')' BGIN $@8 list END  */
#line 203 "iope.y"
                                                                                      {
          FuncInfo func((yyvsp[-8].String), (yyvsp[-7].String), "global", current_params, true);

          current_params.clear();
          st.add_func(func, yylineno);
      }
#line 1718 "iope.tab.c"
    break;

  case 47: /* $@9: %empty  */
#line 209 "iope.y"
                                  {scope = (yyvsp[-3].String); current_type = (yyvsp[-4].String);}
#line 1724 "iope.tab.c"
    break;

  case 48: /* decl_f: CONST TYPE ID '(' ')' BGIN $@9 list END  */
#line 209 "iope.y"
                                                                           {
          FuncInfo func((yyvsp[-7].String), (yyvsp[-6].String), "global", true);
          st.add_func(func, yylineno);
      }
#line 1733 "iope.tab.c"
    break;

  case 51: /* param: TYPE ID  */
#line 218 "iope.y"
               {
     VarInfo* var = new VarInfo((yyvsp[-1].String), (yyvsp[0].String), "null", false);
     current_params.push_back({var, nullptr});
}
#line 1742 "iope.tab.c"
    break;

  case 52: /* param: TYPE ID size  */
#line 222 "iope.y"
                    {
          VecInfo* vec = new VecInfo((yyvsp[-2].String), (yyvsp[-1].String), current_dims, false);
          current_dims.clear();    
          current_params.push_back({nullptr, vec});
      }
#line 1752 "iope.tab.c"
    break;

  case 53: /* param: CONST TYPE ID  */
#line 227 "iope.y"
                     {
          VarInfo* var = new VarInfo((yyvsp[-1].String), (yyvsp[0].String), "null", true);
          current_params.push_back({var, nullptr});
      }
#line 1761 "iope.tab.c"
    break;

  case 54: /* param: CONST TYPE ID size  */
#line 231 "iope.y"
                          {
          VecInfo* vec = new VecInfo((yyvsp[-2].String), (yyvsp[-1].String), current_dims, true);
          current_dims.clear();    
          current_params.push_back({nullptr, vec});
      }
#line 1771 "iope.tab.c"
    break;

  case 55: /* size: '[' NR ']'  */
#line 238 "iope.y"
                 {
          int size = stoi((yyvsp[-1].String));
          current_dims.push_back(size);
     }
#line 1780 "iope.tab.c"
    break;

  case 56: /* size: '[' NR ']' size  */
#line 242 "iope.y"
                      {
          int size = stoi((yyvsp[-2].String));
          current_dims.push_back(size);
     }
#line 1789 "iope.tab.c"
    break;

  case 57: /* $@10: %empty  */
#line 248 "iope.y"
            {scope = "main"; current_type = "any";}
#line 1795 "iope.tab.c"
    break;

  case 58: /* block: EXEC $@10 list DIE  */
#line 248 "iope.y"
                                                            {
     scope = "main";

     printf("The programme is correct!\n"); 
     st.print();
}
#line 1806 "iope.tab.c"
    break;

  case 61: /* statement: TYPE ID  */
#line 260 "iope.y"
                   {
               VarInfo var((yyvsp[-1].String), (yyvsp[0].String), "null", scope, false);
               st.add_var(var, yylineno);
          }
#line 1815 "iope.tab.c"
    break;

  case 62: /* statement: TYPE ID size  */
#line 264 "iope.y"
                         {
               VecInfo vec((yyvsp[-2].String), (yyvsp[-1].String), scope, current_dims, false);
               st.add_vec(vec, yylineno);
               current_dims.clear();
           }
#line 1825 "iope.tab.c"
    break;

  case 63: /* statement: TYPE ID size ASSIGN init_for_vec  */
#line 269 "iope.y"
                                             {
               VecInfo vec((yyvsp[-4].String), (yyvsp[-3].String), scope, current_dims, init_values_vec, false, yylineno);
               st.add_vec(vec, yylineno);
               current_dims.clear();
               init_values_vec.clear();
           }
#line 1836 "iope.tab.c"
    break;

  case 64: /* statement: TYPE ID ASSIGN expr  */
#line 275 "iope.y"
                                {
               CheckErr((yyvsp[0].ast)->compute(), yylineno);
               if((yyvsp[0].ast)->type != (yyvsp[-3].String)){
                    printf("line: %d Error: %s is not a %s!\n", yylineno, (yyvsp[-2].String), (yyvsp[0].ast)->type.c_str());
                    exit(1);
               }
               VarInfo var((yyvsp[-3].String), (yyvsp[-2].String), (yyvsp[0].ast), scope, false);
               st.add_var(var, yylineno);
           }
#line 1850 "iope.tab.c"
    break;

  case 65: /* statement: CONST TYPE ID ASSIGN expr  */
#line 284 "iope.y"
                                      {
               CheckErr((yyvsp[0].ast)->compute(), yylineno);
               if((yyvsp[0].ast)->type != (yyvsp[-3].String)){
                    printf("line: %d Error: %s is not a %s!\n", yylineno, (yyvsp[-2].String), (yyvsp[0].ast)->type.c_str());
                    exit(1);
               }
               VarInfo var((yyvsp[-3].String), (yyvsp[-2].String), (yyvsp[0].ast), scope, true);
               st.add_var(var, yylineno);
           }
#line 1864 "iope.tab.c"
    break;

  case 66: /* statement: ID ASSIGN expr  */
#line 293 "iope.y"
                           {
               CheckErr((yyvsp[0].ast)->compute(), yylineno);
               st.change_val((yyvsp[-2].String), (yyvsp[0].ast)->value, (yyvsp[0].ast)->type, yylineno);
           }
#line 1873 "iope.tab.c"
    break;

  case 67: /* statement: ID '[' NR ']' ASSIGN expr  */
#line 297 "iope.y"
                                      {
               CheckErr((yyvsp[0].ast)->compute(), yylineno);
               st.change_vec((yyvsp[-5].String), (yyvsp[0].ast)->value, (yyvsp[0].ast)->type, stoi((yyvsp[-3].String)), yylineno);
           }
#line 1882 "iope.tab.c"
    break;

  case 68: /* statement: IF '(' expr ')' BGIN list END  */
#line 301 "iope.y"
                                          {
               CheckErr((yyvsp[-4].ast)->compute(), yylineno);
               if((yyvsp[-4].ast)->type != "bool"){
                    printf("line: %d Error: condition inside if should be boolean!\n", yylineno);
                    exit(1);
               }
           }
#line 1894 "iope.tab.c"
    break;

  case 69: /* statement: IF '(' expr ')' BGIN list END ELSE BGIN list END  */
#line 308 "iope.y"
                                                             {
               CheckErr((yyvsp[-8].ast)->compute(), yylineno);
               if((yyvsp[-8].ast)->type != "bool"){
                    printf("line: %d Error: condition inside if should be boolean!\n", yylineno);
                    exit(1);
               }
           }
#line 1906 "iope.tab.c"
    break;

  case 70: /* statement: WHILE '(' expr ')' BGIN list END  */
#line 315 "iope.y"
                                             {
               CheckErr((yyvsp[-4].ast)->compute(), yylineno);
               if((yyvsp[-4].ast)->type != "bool"){
                    printf("line: %d Error: condition inside while should be boolean!\n", yylineno);
                    exit(1);
               }
           }
#line 1918 "iope.tab.c"
    break;

  case 71: /* $@11: %empty  */
#line 322 "iope.y"
                                   {
               CheckErr((yyvsp[0].ast)->compute(), yylineno);
               st.change_val((yyvsp[-2].String), (yyvsp[0].ast)->value, (yyvsp[0].ast)->type, yylineno); 
           }
#line 1927 "iope.tab.c"
    break;

  case 72: /* statement: FOR '(' ID ASSIGN expr $@11 ';' expr ';' ID ASSIGN expr ')' BGIN list END  */
#line 325 "iope.y"
                                                          {

               CheckErr((yyvsp[-8].ast)->compute(), yylineno);
               if((yyvsp[-8].ast)->type != "bool"){
                    printf("line: %d Error: condition inside for should be boolean!\n", yylineno);
                    exit(1);
               }

               CheckErr((yyvsp[-4].ast)->compute(), yylineno);
               st.change_val((yyvsp[-6].String), (yyvsp[-4].ast)->value, (yyvsp[-4].ast)->type, yylineno);
           }
#line 1943 "iope.tab.c"
    break;

  case 73: /* $@12: %empty  */
#line 336 "iope.y"
                   {size_stack.push(current_exprs.size());}
#line 1949 "iope.tab.c"
    break;

  case 74: /* statement: ID '(' $@12 call_param ')'  */
#line 336 "iope.y"
                                                                          {
               int delim = size_stack.top();
               vector<AST*> parameters;
               for(int i = delim;i < current_exprs.size(); i++){
                    parameters.push_back(current_exprs[i]);
               }
               string funcType = st.checkValidParams((yyvsp[-4].String), scope, parameters, yylineno);

               int size = current_exprs.size();
               for(int i = delim;i < size; i++){
                    current_exprs.pop_back();
               }
               size_stack.pop();
           }
#line 1968 "iope.tab.c"
    break;

  case 75: /* $@13: %empty  */
#line 350 "iope.y"
                   {size_stack.push(current_exprs.size());}
#line 1974 "iope.tab.c"
    break;

  case 76: /* statement: ID '(' $@13 ')'  */
#line 350 "iope.y"
                                                               {
               int delim = size_stack.top();
               vector<AST*> parameters;
               for(int i = delim;i < current_exprs.size(); i++){
                    parameters.push_back(current_exprs[i]);
               }
               string funcType = st.checkValidParams((yyvsp[-3].String), scope, parameters, yylineno);

               int size = current_exprs.size();
               for(int i = delim;i < size; i++){
                    current_exprs.pop_back();
               }
               size_stack.pop();
           }
#line 1993 "iope.tab.c"
    break;

  case 77: /* $@14: %empty  */
#line 364 "iope.y"
                                  {size_stack.push(current_exprs.size());}
#line 1999 "iope.tab.c"
    break;

  case 78: /* statement: ID PACK_ACCESS ID '(' $@14 call_param ')'  */
#line 364 "iope.y"
                                                                                         {
               string name = (yyvsp[-6].String);
               bool ok = st.checkIfDeclared(name, "pack", yylineno);
               if(!ok){
                    printf("line: %d Error: %s not declared or is not a pack!\n", yylineno, (yyvsp[-6].String));
                    exit(1);
               }
               PackInfo temp = st.get_pack(name);

               int delim = size_stack.top();
               vector<AST*> parameters;
               for(int i = delim;i < current_exprs.size(); i++){
                    parameters.push_back(current_exprs[i]);
               }

               string funcType = st.checkValidParams((yyvsp[-4].String), temp.type, current_exprs, yylineno);

               int size = current_exprs.size();
               for(int i = delim;i < size; i++){
                    current_exprs.pop_back();
               }
               size_stack.pop();
             }
#line 2027 "iope.tab.c"
    break;

  case 79: /* $@15: %empty  */
#line 387 "iope.y"
                                    {size_stack.push(current_exprs.size());}
#line 2033 "iope.tab.c"
    break;

  case 80: /* statement: ID PACK_ACCESS ID '(' $@15 ')'  */
#line 387 "iope.y"
                                                                                {
               string name = (yyvsp[-5].String);
               bool ok = st.checkIfDeclared(name, "pack", yylineno);
               if(!ok){
                    printf("line: %d Error: %s not declared or is not a pack!\n", yylineno, (yyvsp[-5].String));
                    exit(1);
               }
               PackInfo temp = st.get_pack(name);

               int delim = size_stack.top();
               vector<AST*> parameters;
               for(int i = delim;i < current_exprs.size(); i++){
                    parameters.push_back(current_exprs[i]);
               }

               string funcType = st.checkValidParams((yyvsp[-3].String), temp.type, current_exprs, yylineno);

               int size = current_exprs.size();
               for(int i = delim;i < size; i++){
                    current_exprs.pop_back();
               }
               size_stack.pop();
             }
#line 2061 "iope.tab.c"
    break;

  case 81: /* statement: EVAL '(' expr ')'  */
#line 410 "iope.y"
                              {
               CheckErr((yyvsp[-1].ast)->compute(), yylineno);
               cout<<(yyvsp[-1].ast)->value<<endl;
           }
#line 2070 "iope.tab.c"
    break;

  case 82: /* statement: TYPEOF '(' expr ')'  */
#line 414 "iope.y"
                               {
               CheckErr((yyvsp[-1].ast)->compute(), yylineno);
               cout<<(yyvsp[-1].ast)->type<<endl;
           }
#line 2079 "iope.tab.c"
    break;

  case 83: /* statement: RET expr  */
#line 418 "iope.y"
                     {
               CheckErr((yyvsp[0].ast)->compute(), yylineno);
               if((yyvsp[0].ast)->type != current_type && current_type != "any"){
                    printf("line: %d Error: return type should be %s!\n", yylineno, current_type.c_str());
                    exit(1);
               }
           }
#line 2091 "iope.tab.c"
    break;

  case 85: /* init_vec: expr  */
#line 430 "iope.y"
              {
          CheckErr((yyvsp[0].ast)->compute(), yylineno);
          init_values_vec.push_back((yyvsp[0].ast));
     }
#line 2100 "iope.tab.c"
    break;

  case 86: /* init_vec: init_vec ',' expr  */
#line 434 "iope.y"
                             {
               CheckErr((yyvsp[0].ast)->compute(), yylineno);
               init_values_vec.push_back((yyvsp[0].ast));
          }
#line 2109 "iope.tab.c"
    break;

  case 87: /* call_param: expr  */
#line 440 "iope.y"
                {
          current_exprs.push_back((yyvsp[0].ast));
     }
#line 2117 "iope.tab.c"
    break;

  case 88: /* call_param: call_param ',' expr  */
#line 443 "iope.y"
                               {
               current_exprs.push_back((yyvsp[0].ast));
          }
#line 2125 "iope.tab.c"
    break;

  case 89: /* expr: expr AND expr  */
#line 448 "iope.y"
                   {
          (yyval.ast) = new AST("and", (yyvsp[-2].ast), (yyvsp[0].ast), true);
     }
#line 2133 "iope.tab.c"
    break;

  case 90: /* expr: expr OR expr  */
#line 451 "iope.y"
                  {
          (yyval.ast) = new AST("or", (yyvsp[-2].ast), (yyvsp[0].ast), true);
     }
#line 2141 "iope.tab.c"
    break;

  case 91: /* expr: NOT expr  */
#line 454 "iope.y"
              {
          (yyval.ast) = new AST("not", (yyvsp[0].ast), nullptr, true);
     }
#line 2149 "iope.tab.c"
    break;

  case 92: /* expr: '(' expr ')'  */
#line 457 "iope.y"
                  {
          (yyval.ast) = (yyvsp[-1].ast);
     }
#line 2157 "iope.tab.c"
    break;

  case 93: /* expr: '-' expr  */
#line 460 "iope.y"
                           {
          (yyval.ast) = new AST("-", (yyvsp[0].ast), nullptr, true);
     }
#line 2165 "iope.tab.c"
    break;

  case 94: /* expr: expr '<' expr  */
#line 463 "iope.y"
                   {
          (yyval.ast) = new AST("<", (yyvsp[-2].ast), (yyvsp[0].ast), true);
     }
#line 2173 "iope.tab.c"
    break;

  case 95: /* expr: expr '>' expr  */
#line 466 "iope.y"
                    {
            (yyval.ast) = new AST(">", (yyvsp[-2].ast), (yyvsp[0].ast), true);
      }
#line 2181 "iope.tab.c"
    break;

  case 96: /* expr: expr EQ expr  */
#line 469 "iope.y"
                    {
            (yyval.ast) = new AST("==", (yyvsp[-2].ast), (yyvsp[0].ast), true);
      }
#line 2189 "iope.tab.c"
    break;

  case 97: /* expr: expr EQG expr  */
#line 472 "iope.y"
                     {
            (yyval.ast) = new AST(">=", (yyvsp[-2].ast), (yyvsp[0].ast), true);
      }
#line 2197 "iope.tab.c"
    break;

  case 98: /* expr: expr EQL expr  */
#line 475 "iope.y"
                     {
            (yyval.ast) = new AST("<=", (yyvsp[-2].ast), (yyvsp[0].ast), true);
      }
#line 2205 "iope.tab.c"
    break;

  case 99: /* expr: expr NEQ expr  */
#line 478 "iope.y"
                     {
            (yyval.ast) = new AST("!=", (yyvsp[-2].ast), (yyvsp[0].ast), true);
      }
#line 2213 "iope.tab.c"
    break;

  case 100: /* expr: TRU  */
#line 481 "iope.y"
           {
            (yyval.ast) = new AST("true", "bool", nullptr, nullptr, false);
      }
#line 2221 "iope.tab.c"
    break;

  case 101: /* expr: FOLS  */
#line 484 "iope.y"
            {
            (yyval.ast) = new AST("false", "bool", nullptr, nullptr, false);
      }
#line 2229 "iope.tab.c"
    break;

  case 102: /* expr: ID  */
#line 487 "iope.y"
          {
               int ok = st.checkIfDeclaredScoped((yyvsp[0].String), "var", scope, yylineno);
               if(ok){
                    VarInfo temp = st.get_var((yyvsp[0].String), scope);
                    if(temp.value == "null"){
                         printf("line: %d Error: use of unitialized variable: %s!\n", yylineno, temp.name.c_str());
                         exit(0);
                    }
                    (yyval.ast) = new AST(temp.value, temp.type, nullptr, nullptr, false);    
               }
               else{
                    ok = st.checkIfDeclaredScoped((yyvsp[0].String), "vec", scope, yylineno);
                    if(ok){
                         VecInfo temp = st.get_vec((yyvsp[0].String), scope);
                         (yyval.ast) = new AST(getUndefValue(temp.type), temp.type, nullptr, nullptr, false, temp.rows, temp.cols);
                    } else{
                         for(auto param: current_params){
                              if(param.first != nullptr){
                                   if(param.first->name == (yyvsp[0].String)){
                                        (yyval.ast) = new AST(getUndefValue(param.first->type), param.first->type, nullptr, nullptr, false);
                                        ok = 1;
                                   }
                              }
                              else{
                                   if(param.second->name == (yyvsp[0].String)){
                                        (yyval.ast) = new AST(getUndefValue(param.second->type), param.second->type, nullptr, nullptr, false,  param.second->rows, param.second->cols);        
                                        ok = 1;             
                                   }
                              }
                         }
                    }
               }

               if(!ok){
                    printf("line: %d Error: %s not declared in this scope!\n", yylineno, (yyvsp[0].String));
                    exit(1);
               }
      }
#line 2272 "iope.tab.c"
    break;

  case 103: /* expr: NR  */
#line 525 "iope.y"
          {
               (yyval.ast) = new AST((yyvsp[0].String), "int", nullptr, nullptr, false);
      }
#line 2280 "iope.tab.c"
    break;

  case 104: /* expr: FLOAT  */
#line 528 "iope.y"
             {
               (yyval.ast) = new AST((yyvsp[0].String), "float",nullptr, nullptr, false);
      }
#line 2288 "iope.tab.c"
    break;

  case 105: /* expr: STRING  */
#line 531 "iope.y"
              {
               (yyval.ast) = new AST((yyvsp[0].String), "string", nullptr, nullptr, false);
      }
#line 2296 "iope.tab.c"
    break;

  case 106: /* expr: CHAR  */
#line 534 "iope.y"
            {
               (yyval.ast) = new AST((yyvsp[0].String), "char", nullptr, nullptr, false);
      }
#line 2304 "iope.tab.c"
    break;

  case 107: /* expr: expr '+' expr  */
#line 537 "iope.y"
                     {
            (yyval.ast) = new AST("+", (yyvsp[-2].ast), (yyvsp[0].ast), true);
      }
#line 2312 "iope.tab.c"
    break;

  case 108: /* expr: expr '-' expr  */
#line 540 "iope.y"
                    {
               (yyval.ast) = new AST("-", (yyvsp[-2].ast), (yyvsp[0].ast), true);
          }
#line 2320 "iope.tab.c"
    break;

  case 109: /* expr: expr '*' expr  */
#line 543 "iope.y"
                    {
               (yyval.ast) = new AST("*", (yyvsp[-2].ast), (yyvsp[0].ast), true);
          }
#line 2328 "iope.tab.c"
    break;

  case 110: /* expr: expr '/' expr  */
#line 546 "iope.y"
                    {
               (yyval.ast) = new AST("/", (yyvsp[-2].ast), (yyvsp[0].ast), true);
          }
#line 2336 "iope.tab.c"
    break;

  case 111: /* expr: EVAL '(' expr ')'  */
#line 549 "iope.y"
                        {
               (yyval.ast) = (yyvsp[-1].ast);
          }
#line 2344 "iope.tab.c"
    break;

  case 112: /* expr: ID '[' NR ']'  */
#line 552 "iope.y"
                     {
               bool ok = st.checkIfDeclaredScoped((yyvsp[-3].String), "vec", scope, yylineno);
               if(!ok){
                    printf("line: %d Error: %s not declared in this scope!\n", yylineno, (yyvsp[-3].String));
                    exit(1);
               }
               VecInfo temp = st.get_vec((yyvsp[-3].String), scope);
               int index = stoi((yyvsp[-1].String));
               if(index >= temp.vars.size()){
                    printf("line: %d Error: index out of bounds!\n", yylineno);
                    exit(1);
               }
               string value = temp.vars[index];
               if(value == "null"){
                    printf("line: %d Error:  use of unitialized variable: %s[%d]!\n", yylineno, (yyvsp[-3].String), index);
                    exit(1);
               }
               (yyval.ast) = new AST(value, temp.type, nullptr, nullptr, false);
          }
#line 2368 "iope.tab.c"
    break;

  case 113: /* $@16: %empty  */
#line 572 "iope.y"
             {size_stack.push(current_exprs.size());}
#line 2374 "iope.tab.c"
    break;

  case 114: /* expr: ID '(' $@16 call_param ')'  */
#line 572 "iope.y"
                                                                    {
          int delim = size_stack.top();
          vector<AST*> parameters;
          for(int i = delim;i < current_exprs.size(); i++){
               parameters.push_back(current_exprs[i]);
          }
          string funcType = st.checkValidParams((yyvsp[-4].String), scope, parameters, yylineno);

          (yyval.ast) = new AST(getUndefValue(funcType), funcType, nullptr, nullptr, false);
          int size = current_exprs.size();
          for(int i = delim;i < size; i++){
               current_exprs.pop_back();
          }
          size_stack.pop();
     }
#line 2394 "iope.tab.c"
    break;

  case 115: /* $@17: %empty  */
#line 587 "iope.y"
            {size_stack.push(current_exprs.size());}
#line 2400 "iope.tab.c"
    break;

  case 116: /* expr: ID '(' $@17 ')'  */
#line 587 "iope.y"
                                                        {
          int delim = size_stack.top();
          vector<AST*> parameters;
          for(int i = delim;i < current_exprs.size(); i++){
               parameters.push_back(current_exprs[i]);
          }
          string funcType = st.checkValidParams((yyvsp[-3].String), scope, parameters, yylineno);

          (yyval.ast) = new AST(getUndefValue(funcType), funcType, nullptr, nullptr, false);
          int size = current_exprs.size();
          for(int i = delim;i < size; i++){
               current_exprs.pop_back();
          }
          size_stack.pop();
     }
#line 2420 "iope.tab.c"
    break;

  case 117: /* expr: ID PACK_ACCESS ID  */
#line 602 "iope.y"
                        { 
           string name = (yyvsp[-2].String);
            bool ok = st.checkIfDeclared(name, "pack", yylineno);
            if(!ok){
               printf("line: %d Error: %s not declared!\n", yylineno, (yyvsp[-2].String));
               exit(1);
            }
            PackInfo temp = st.get_pack(name);
            string field = (yyvsp[0].String);
            int found = false;
            for(auto var: temp.vars){
               if(var.name == field){
                    if(var.value == "null"){
                         printf("line: %d Error: use of unitialized field: %s!\n", yylineno, var.name.c_str());
                         exit(0);
                    }
                    (yyval.ast) = new AST(var.value, var.type, nullptr, nullptr, false);
                    found = true;
               }
            }
            if(!found){
               printf("line: %d Error: %s is not a field in %s!\n", yylineno, field.c_str(), name.c_str());
               exit(1);
            }
     }
#line 2450 "iope.tab.c"
    break;

  case 118: /* $@18: %empty  */
#line 627 "iope.y"
                                 {size_stack.push(current_exprs.size());}
#line 2456 "iope.tab.c"
    break;

  case 119: /* expr: ID PACK_ACCESS ID '(' $@18 call_param ')'  */
#line 627 "iope.y"
                                                                                        {
               string name = (yyvsp[-6].String);
               bool ok = st.checkIfDeclared(name, "pack", yylineno);
               if(!ok){
                    printf("line: %d Error: %s not declared or is not a pack!\n", yylineno, (yyvsp[-6].String));
                    exit(1);
               }
               PackInfo temp = st.get_pack(name);

               int delim = size_stack.top();
               vector<AST*> parameters;
               for(int i = delim;i < current_exprs.size(); i++){
                    parameters.push_back(current_exprs[i]);
               }

               string funcType = st.checkValidParams((yyvsp[-4].String), temp.type, current_exprs, yylineno);

               (yyval.ast) = new AST(getUndefValue(funcType), funcType, nullptr, nullptr, false);
               int size = current_exprs.size();
               for(int i = delim;i < size; i++){
                    current_exprs.pop_back();
               }
               size_stack.pop();
             }
#line 2485 "iope.tab.c"
    break;

  case 120: /* $@19: %empty  */
#line 651 "iope.y"
                                    {size_stack.push(current_exprs.size());}
#line 2491 "iope.tab.c"
    break;

  case 121: /* expr: ID PACK_ACCESS ID '(' $@19 ')'  */
#line 651 "iope.y"
                                                                                {
               string name = (yyvsp[-5].String);
               bool ok = st.checkIfDeclared(name, "pack", yylineno);
               if(!ok){
                    printf("line: %d Error: %s not declared or is not a pack!\n", yylineno, (yyvsp[-5].String));
                    exit(1);
               }
               PackInfo temp = st.get_pack(name);

               int delim = size_stack.top();
               vector<AST*> parameters;
               for(int i = delim;i < current_exprs.size(); i++){
                    parameters.push_back(current_exprs[i]);
               }

               string funcType = st.checkValidParams((yyvsp[-3].String), temp.type, current_exprs, yylineno);

               (yyval.ast) = new AST(getUndefValue(funcType), funcType, nullptr, nullptr, false);
               int size = current_exprs.size();
               for(int i = delim;i < size; i++){
                    current_exprs.pop_back();
               }
               size_stack.pop();
             }
#line 2520 "iope.tab.c"
    break;

  case 122: /* expr: ID PACK_ACCESS ID '[' NR ']'  */
#line 675 "iope.y"
                                            {
               int index = stoi((yyvsp[-1].String));
               string name = (yyvsp[-5].String);
               bool ok = st.checkIfDeclared(name, "pack", yylineno);
               if(!ok){
                    printf("line: %d Error: %s not declared!\n", yylineno, (yyvsp[-5].String));
                    exit(1);
               }
               PackInfo temp = st.get_pack(name);
               string field = (yyvsp[-3].String);
               int found = false;
               for(auto var: temp.vecs){
                    if(var.name == field){
                         if(var.vars[index] == "null"){
                              printf("line: %d Error: use of unitialized field: %s[%d]!\n", yylineno, var.name.c_str(), index);
                              exit(0);
                         }
                         (yyval.ast) = new AST(var.vars[index], var.type, nullptr, nullptr, false);
                         found = true;
                    }
               }
            if(!found){
               printf("line: %d Error: %s is not a field in %s!\n", yylineno, field.c_str(), name.c_str());
               exit(1);
            }
             }
#line 2551 "iope.tab.c"
    break;


#line 2555 "iope.tab.c"

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

#line 702 "iope.y"

void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}
int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
} 
