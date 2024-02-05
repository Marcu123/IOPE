#include "FuncInfo.h"

FuncInfo::FuncInfo(string type, string name, string scope, vector<pair<VarInfo *, VecInfo *>> current_params, bool forever)
{
    if (forever)
    {
        this->type = "forever ";
        this->type += type;
    }
    else
        this->type = type;
    this->name = name;
    this->scope = scope;
    for (auto param : current_params)
    {
        this->params.push_back(param);
    }
}
FuncInfo::FuncInfo(string type, string name, string scope, bool forever)
{
    if (forever)
    {
        this->type = "forever ";
        this->type += type;
    }
    else
        this->type = type;
    this->name = name;
    this->scope = scope;
}
FuncInfo::FuncInfo(string type, string name, vector<pair<VarInfo *, VecInfo *>> current_params, bool forever)
{
    if (forever)
    {
        this->type = "forever ";
        this->type += type;
    }
    else
        this->type = type;
    this->name = name;
    for (auto param : current_params)
    {
        this->params.push_back(param);
    }
}
