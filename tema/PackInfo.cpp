#include "PackInfo.h"

PackInfo::PackInfo(){}

PackInfo::PackInfo(string name, string type, vector<VarInfo> vars, vector<VecInfo> vecs)
{
    this->name = name;
    this->type = type;
    for(auto var:vars)
        this->vars.push_back(var);
    for(auto vec:vecs)
        this->vecs.push_back(vec);
}
//verif nume comun
void PackInfo::add_var(VarInfo var)
{
    this->vars.push_back(var);
}
void PackInfo::add_vec(VecInfo vec)
{
    this->vecs.push_back(vec);
}
void PackInfo::print()
{
    cout << "Package: " << this->name << endl;
    cout << "Vars: " << endl;
    for (auto var : this->vars)
    {
        cout<<var.name<<" "<<var.type<<" "<<endl;
    }
    cout << "Vecs: " << endl;
    for (auto vec : this->vecs)
    {
        cout<<vec.name<<" "<<vec.type<<" "<<endl;
    }
}

void PackInfo::operator=(const PackInfo &pack)
{
    for(auto var:pack.vars)
        this->vars.push_back(var);
    for(auto vec:pack.vecs)
        this->vecs.push_back(vec);
}
