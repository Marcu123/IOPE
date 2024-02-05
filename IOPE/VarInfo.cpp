#include "VarInfo.h"

VarInfo::VarInfo(string type, string name, AST *value, bool forever)
{
    if (forever)
    {
        this->type = "forever ";
        this->type += type;
    }
    else
        this->type = type;
    this->name = name;
    this->value = value->value;
}
VarInfo::VarInfo(string type, string name, AST *value, string scope, bool forever)
{
    if (forever)
    {
        this->type = "forever ";
        this->type += type;
    }
    else
        this->type = type;
    this->name = name;
    this->value = value->value;
    this->scope = scope;
}
VarInfo::VarInfo(string name, AST *value, bool change)
{
    this->name = name;
    this->value = value->value;
    this->change = change;
}
VarInfo::VarInfo(string type, string name, string value, bool forever)
{
    if (forever)
    {
        this->type = "forever ";
        this->type += type;
    }
    else
        this->type = type;
    this->name = name;
    this->value = value;
}
VarInfo::VarInfo(string type, string name, string value, string scope, bool forever)
{
    if (forever)
    {
        this->type = "forever ";
        this->type += type;
    }
    else
        this->type = type;
    this->name = name;
    this->value = value;
    this->scope = scope;
}
VarInfo::VarInfo(string name, string value, bool change)
{
    this->name = name;
    this->value = value;
    this->change = change;
}