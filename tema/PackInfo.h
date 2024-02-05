#include "VarInfo.h"
#include "VecInfo.h"

struct PackInfo{
    string name;
    string type;
    vector<VarInfo> vars;
    vector<VecInfo> vecs;

    PackInfo();
    PackInfo(string name, string type, vector<VarInfo> vars, vector<VecInfo> vecs);
    void add_var(VarInfo var);
    void add_vec(VecInfo vec);
    void print();
    void operator=(const PackInfo& pack);
};