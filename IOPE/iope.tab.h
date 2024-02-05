/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_IOPE_TAB_H_INCLUDED
# define YY_YY_IOPE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BGIN = 258,                    /* BGIN  */
    END = 259,                     /* END  */
    EXEC = 260,                    /* EXEC  */
    DIE = 261,                     /* DIE  */
    PACK = 262,                    /* PACK  */
    ASSIGN = 263,                  /* ASSIGN  */
    CONST = 264,                   /* CONST  */
    IF = 265,                      /* IF  */
    FOR = 266,                     /* FOR  */
    WHILE = 267,                   /* WHILE  */
    AND = 268,                     /* AND  */
    OR = 269,                      /* OR  */
    NOT = 270,                     /* NOT  */
    EQ = 271,                      /* EQ  */
    EQG = 272,                     /* EQG  */
    EQL = 273,                     /* EQL  */
    NEQ = 274,                     /* NEQ  */
    PACKS = 275,                   /* PACKS  */
    END_PACKS = 276,               /* END_PACKS  */
    GLOBAL_V = 277,                /* GLOBAL_V  */
    END_GLOBAL_V = 278,            /* END_GLOBAL_V  */
    GLOBAL_F = 279,                /* GLOBAL_F  */
    END_GLOBAL_F = 280,            /* END_GLOBAL_F  */
    PACK_ACCESS = 281,             /* PACK_ACCESS  */
    RET = 282,                     /* RET  */
    ELSE = 283,                    /* ELSE  */
    TYPE = 284,                    /* TYPE  */
    EVAL = 285,                    /* EVAL  */
    TYPEOF = 286,                  /* TYPEOF  */
    FLOAT = 287,                   /* FLOAT  */
    STRING = 288,                  /* STRING  */
    CHAR = 289,                    /* CHAR  */
    TRU = 290,                     /* TRU  */
    FOLS = 291,                    /* FOLS  */
    ID = 292,                      /* ID  */
    NR = 293,                      /* NR  */
    MINUS = 294                    /* MINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "iope.y"

  int Int;
  class AST* ast;
  char* String;

#line 109 "iope.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_IOPE_TAB_H_INCLUDED  */
