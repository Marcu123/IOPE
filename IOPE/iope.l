%{
#include <iostream>
#include <string>
#include "iope.tab.h"
using namespace std;
%}
type "int"|"float"|"char"|"string"|"bool" 
var [a-zA-Z][a-zA-Z0-9]* 
nr [0-9]+
float [0-9]+\.[0-9]+
string \"[^\"]*\"
char \'[^\']\'
%option noyywrap
%%
"pack" {return PACK;}
"execute" {return EXEC;}
"die" {return DIE;}
"begin" {return BGIN;}
"end" {return END;}
"packs" {return PACKS;}
"end_packs" {return END_PACKS;}
"global_v" {return GLOBAL_V;}
"end_global_v" {return END_GLOBAL_V;}
"global_f" {return GLOBAL_F;}
"end_global_f" {return END_GLOBAL_F;}
"forever" {return CONST;}
"if" {return IF;}
"else" {return ELSE;}
"for" {return FOR;}
"while" {return WHILE;}
"and" {return AND;}
"or" {return OR;}
"not" {return NOT;}
"true" {return TRU;}
"false" {return FOLS;}
"Eval" {return EVAL;}
"Typeof" {return TYPEOF;}
"->" {return PACK_ACCESS;}
"return" {yylval.String = strdup(yytext); return RET;}
{char} {yylval.String = strdup(yytext); return CHAR;}
{string} {yylval.String = strdup(yytext); return STRING;}
{type} {yylval.String = strdup(yytext);return TYPE;}
{var} {yylval.String = strdup(yytext); return ID;}
"==" {return EQ;}
"!=" {return NEQ;}
"<=" {return EQL;}
">=" {return EQG;}
"=" {return ASSIGN;}
{float} {yylval.String = strdup(yytext); return FLOAT;}
{nr} {yylval.String = strdup(yytext); return NR;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}

 