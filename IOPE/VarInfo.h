#pragma once
#include "AST.h"
struct VarInfo
{
    string type;
    string name;
    string value;
    string scope;
    bool change = false;
    VarInfo(){};
    VarInfo(string type, string name, AST *value, bool forever);
    VarInfo(string type, string name, AST *value, string scope, bool forever);
    VarInfo(string name, AST *value, bool change);
    VarInfo(string type, string name, string value, bool forever);
    VarInfo(string type, string name, string value, string scope, bool forever);
    VarInfo(string name, string value, bool change);
};