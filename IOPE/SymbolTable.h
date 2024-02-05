#pragma once
#include "VarInfo.h"
#include "VecInfo.h"
#include "FuncInfo.h"
#include "PackInfo.h"   
#include "Utils.h"
struct SymbolTable
{
    vector<VarInfo> vars;
    vector<FuncInfo> funcs;
    vector<VecInfo> vecs;
    vector<PackInfo> packs;

    void print();
    bool checkIfDeclared(string name, string type, int yylineno);
    bool checkIfDeclaredScoped(string name, string type, string scope, int yylineno);
    void add_var(VarInfo var, int yylineno);
    void add_func(FuncInfo func, int yylineno);
    void add_vec(VecInfo vec, int yylineno);
    void add_pack(PackInfo pack, int yylineno);
    int change_val(string name, string val, string type, int yylineno);
    void change_vec(string name, string val, string type, int pos, int yylineno);
    VarInfo get_var(string name, string scope);
    FuncInfo get_func(string name);
    VecInfo get_vec(string name, string scope);
    PackInfo get_pack(string name);
    string checkValidParams(string id, string scope, vector<AST *> current_exprs, int yylineno);
};