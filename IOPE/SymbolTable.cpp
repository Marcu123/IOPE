#include "SymbolTable.h"
ofstream fout("symboltable.txt");

void SymbolTable::print()
{

    fout << "Symbol Table" << endl
         << endl;
    fout << "VARS: " << endl;
    for (auto var : vars)
    {
        fout << "type: " << var.type << "\t name: " << var.name << "\t value: " << var.value << "\t scope: " << var.scope << "; " << endl;
    }
    fout << endl;
    fout << "FUNCS: " << endl;
    for (auto func : funcs)
    {
        fout << "type: " << func.type << "\t name: " << func.name << "\t scope: " << func.scope << "; " << endl;
        if (!func.params.empty())
            fout << "params: ";
        else
            fout << "no params";
        for (auto param : func.params)
        {
            if (param.first != nullptr)
                fout << "\ttype: " << param.first->type << "\tname: " << param.first->name << "; ";
            else
            {
                fout << "\ttype: " << param.second->type << "\tname: " << param.second->name << "; ";
                fout << "\tsize: ";
                for (auto col : param.second->cols)
                {
                    fout << "[" << col << "]";
                }
            }
        }
        fout << endl;
        fout << endl;
    }
    fout << endl;
    fout << "VECS: " << endl;
    for (auto vec : vecs)
    {
        fout << "type: " << vec.type << " \t name: " << vec.name;

        fout << "\tsize: ";
        for (auto col : vec.cols)
        {
            fout << "[" << col << "]";
        }
        fout << " \t scope: " << vec.scope << endl
             << "values: ";

        for (auto var : vec.vars)
        {
            fout << var << " ";
        }
        fout << endl;
    }
    fout<<endl<<"PACKS: "<<endl;
    for(auto pack:packs)
    {
        fout<<"name: "<<pack.name<<" type: "<<pack.type<<endl;
        fout<<"vars: ";
        for(auto var:pack.vars)
        {
            fout<<"name: "<<var.name<<" type: "<<var.type<<" value: "<<var.value<<endl;
        }
        fout<<endl<<"vecs: "<<endl;
        for(auto vec:pack.vecs)
        {
            fout << "type: " << vec.type << " \t name: " << vec.name;

            fout << "\tsize: ";
            for (auto col : vec.cols)
            {
                fout << "[" << col << "]";
            }
            fout<<"\tvalues: ";
            for (auto var : vec.vars)
            {
                fout << var << " ";
            }
        }
        fout<<endl<<endl;
    }
}
bool SymbolTable::checkIfDeclared(string name, string type, int yylineno)
{
    if (type == "var")
    {
        for (auto var : vars)
        {
            if (var.name == name)
                return true;
        }
    }
    else if (type == "func")
    {
        for (auto var : funcs)
            if (var.name == name)
                return true;
    }
    else if (type == "vec")
    {
        for (auto var : vecs)
            if (var.name == name)
                return true;
    }
    else if (type == "pack")
    {
        for (auto var : packs)
            if (var.name == name)
                return true;
    }
    return false;
}
bool SymbolTable::checkIfDeclaredScoped(string name, string type, string scope, int yylineno)
{
    if (type == "var")
    {
        for (auto var : vars)
        {
            if (var.name == name && (var.scope == scope || var.scope == "global"))
                return true;
        }
    }
    else if (type == "func")
    {
        for (auto var : funcs)
            if (var.name == name && (var.scope == scope || var.scope == "global"))
                return true;
    }
    else if (type == "vec")
    {
        for (auto var : vecs)
            if (var.name == name && (var.scope == scope || var.scope == "global"))
                return true;
    } 
    else if(type == "pack")
    {
        for(auto var:packs)
            if(var.name == name)
                return true;
    }
    return false;
}
void SymbolTable::add_var(VarInfo var, int yylineno)
{
    bool test = this->checkIfDeclared(var.name, "var", yylineno) || this->checkIfDeclared(var.name, "vec", yylineno) || this->checkIfDeclared(var.name, "pack", yylineno);
    if (test)
    {
        cout << "line :" << yylineno << "Error: " << var.name << " was already declareded" << endl;
        exit(0);
    }
    vars.push_back(var);
}
void SymbolTable::add_func(FuncInfo func, int yylineno)
{
    bool test = this->checkIfDeclared(func.name, "func", yylineno);
    if (test)
    {
        cout << "line :" << yylineno << "Error: " << func.name << " was already declareded" << endl;
        exit(0);
    }
    funcs.push_back(func);
}
void SymbolTable::add_vec(VecInfo vec, int yylineno)
{
    bool test = this->checkIfDeclared(vec.name, "var", yylineno) || this->checkIfDeclared(vec.name, "vec", yylineno) || this->checkIfDeclared(vec.name, "pack", yylineno);
    if (test)
    {
        cout << "line :" << yylineno << "Error: " << vec.name << " was already declareded" << endl;
        exit(0);
    }
    vecs.push_back(vec);
}
void SymbolTable::add_pack(PackInfo pack, int yylineno)
{
    this->packs.push_back(pack);
}
int SymbolTable::change_val(string name, string val, string type, int yylineno)
{
    for (auto &var : vars)
    {
        if (var.name == name)
        {
            if (var.type != "float" && var.type[0] == 'f' && var.type[1] == 'o')
            {
                cout << "line: " << yylineno << " Error: " << name << " is a constant variable " << endl;
                exit(0);
            }
            if (type != var.type)
            {
                cout << "line :" << yylineno << "Error: " << name << " is not a " << type << endl;
                exit(0);
            }
            var.value = val;
            return 0;
        }
    }

    cout << "line :" << yylineno << "Error: " << name << " wasn't declareded" << endl;
    exit(0);
}
void SymbolTable::change_vec(string name, string val, string type, int pos, int yylineno)
{
    for (auto &vec : vecs)
    {
        if (vec.name == name)
        {
            if (pos >= vec.vars.size())
            {
                cout << "line: " << yylineno << " Error: " << name << "[" << pos << "] out of range" << endl;
                exit(0);
            }
            if (vec.type != "float" && vec.type[0] == 'f' && vec.type[1] == 'o')
            {
                cout << "line: " << yylineno << " Error: " << name << " is a constant variable " << endl;
                exit(0);
            }
            if (type != vec.type)
            {
                cout << "line: " << yylineno << " Error: " << name << " is not a " << type << endl;
                exit(0);
            }
            vec.vars[pos] = val;
            return;
        }
    }
    cout << "line :" << yylineno << "Error: " << name << " wasn't declareded" << endl;
    exit(0);
}
VarInfo SymbolTable::get_var(string name, string scope)
{
    VarInfo global;
    for (auto var : vars)
    {
        if (var.name == name)
        {
            return var;
        }
    }

    return global;
}
FuncInfo SymbolTable::get_func(string name)
{
    FuncInfo global;
    for (auto func : funcs)
    {
        if (func.name == name)
        {
            return func;
        }
    }
    return global;
}
VecInfo SymbolTable::get_vec(string name, string scope)
{
    VecInfo global;
    for (auto vec : vecs)
    {
        if (vec.name == name)
            return vec;
    }
    return global;
}
PackInfo SymbolTable::get_pack(string name)
{
    PackInfo global;
    for (auto pack : packs)
    {
        if (pack.name == name)
            return pack;
    }
    return global;
}
string SymbolTable::checkValidParams(string id, string scope, vector<AST *> current_exprs, int yylineno)
{
    bool ok = this->checkIfDeclaredScoped(id, "func", scope, yylineno);
    if (!ok)
    {
        cout << "line: " << yylineno << " Error: " << id << " not declared in this scope!\n";
        exit(1);
    }

    FuncInfo temp = this->get_func(id);
    if (temp.params.size() != current_exprs.size())
    {
        cout << "line: " << yylineno << " Error: wrong number of parameters, used: " << current_exprs.size() << ", needed:" << temp.params.size() << "!\n";
        exit(1);
    }
    for (int i = 0; i < temp.params.size(); i++)
    {
        if (temp.params[i].first != nullptr)
        {
            CheckErr(current_exprs[i]->compute(), yylineno);
            if (current_exprs[i]->type != temp.params[i].first->type)
            {
                cout << "line: " << yylineno << " Error: wrong type of parameter, number " << i + 1 << " is " << current_exprs[i]->type << " but should be " << temp.params[i].first->type << "!\n";
                exit(1);
            }
        }
        else
        {
            CheckErr(current_exprs[i]->compute(), yylineno);
            if (!current_exprs[i]->isvec)
            {
                cout << "line: " << yylineno << " Error: wrong type of parameter, should be an array!\n";
                exit(1);
            }
            if (current_exprs[i]->type != temp.params[i].second->type)
            {
                cout << "line: " << yylineno << " Error: wrong type of parameter, number " << i + 1 << " is " << current_exprs[i]->type << " but should be " << temp.params[i].second->type << "!\n";
                exit(1);
            }
            if (current_exprs[i]->rows != temp.params[i].second->rows)
            {
                cout << "line: " << yylineno << " Error: wrong vector size on parameter " << i + 1 << " should have " << temp.params[i].second->rows << " row(s) but has " << current_exprs[i]->rows << endl;
                exit(1);
            }
            for (int j = 0; j < current_exprs[i]->cols.size(); j++)
            {
                if (current_exprs[i]->cols[j] != temp.params[i].second->cols[j])
                {
                    cout << "line: " << yylineno << " Error: wrong vector size on parameter " << i + 1 << endl;
                    exit(1);
                }
            }
        }
    }
    return temp.type;
}