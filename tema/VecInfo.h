#pragma once
#include "AST.h"

struct VecInfo
{
    string type;
    string name;
    string scope;
    vector<string> vars;
    int rows;
    vector<int> cols;
    
    VecInfo(){};
    VecInfo(string type, string name, vector<int> current_dims, bool forever);
    VecInfo(string type, string name, string scope, vector<int> current_dims, bool forever);
    VecInfo(string type, string name, string scope, vector<int> current_dims, vector<AST *> init, bool forever, int yylineno);
};