#!/bin/bash

echo "compiling $1"
rm -f lex.yy.c
rm -f $1.tab.c
rm -f $1
bison -d $1.y -Wcounterexamples -Wother
lex $1.l
g++ AST.cpp VarInfo.cpp VecInfo.cpp FuncInfo.cpp PackInfo.cpp SymbolTable.cpp Utils.cpp lex.yy.c  $1.tab.c  -o $1
