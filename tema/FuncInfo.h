#pragma once
#include "VarInfo.h"
#include "VecInfo.h"
struct FuncInfo
{
    string type;
    string name;
    string scope;
    vector<pair<VarInfo *, VecInfo *>> params;

    FuncInfo(){};
    FuncInfo(string type, string name, string scope, vector<pair<VarInfo *, VecInfo *>> current_params, bool forever);
    FuncInfo(string type, string name, string scope, bool forever);
    FuncInfo(string type, string name, vector<pair<VarInfo *, VecInfo *>> current_params, bool forever);
};