#include "VecInfo.h"

VecInfo::VecInfo(string type, string name, vector<int> current_dims, bool forever)
{
    this->type = type;
    this->name = name;

    int rows = 0;
    reverse(current_dims.begin(), current_dims.end());
    for (auto cols : current_dims)
    {
        this->cols.push_back(cols);
        rows++;
    }
    this->rows = rows;

    for (int i = 0; i < this->cols[0]; i++)
    {
        this->vars.push_back("null");
    }
}
VecInfo::VecInfo(string type, string name, string scope, vector<int> current_dims, bool forever)
{
    this->type = type;
    this->name = name;
    this->scope = scope;

    int rows = 0;
    reverse(current_dims.begin(), current_dims.end());
    for (auto cols : current_dims)
    {
        this->cols.push_back(cols);
        rows++;
    }
    this->rows = rows;

    for (int i = 0; i < this->cols[0]; i++)
    {
        this->vars.push_back("null");
    }
}
VecInfo::VecInfo(string type, string name, string scope, vector<int> current_dims, vector<AST *> init, bool forever, int yylineno)
{
    this->type = type;
    this->name = name;
    this->scope = scope;

    int rows = 0;
    reverse(current_dims.begin(), current_dims.end());
    for (auto cols : current_dims)
    {
        this->cols.push_back(cols);
        rows++;
    }
    this->rows = rows;

    for (int i = 0; i < this->cols[0]; i++)
    {
        this->vars.push_back("null");
    }

    if (forever)
    {
        if (init.size() != this->cols[0])
        {
            cout << "line: " << yylineno << " Error: " << this->name << " has " << this->cols[0] << " columns but " << init.size() << " values were given" << endl;
            exit(0);
        }
    }
    else
    {
        if (init.size() > this->cols[0])
        {
            cout << "line: " << yylineno << " Error: " << this->name << " has " << this->cols[0] << " columns but " << init.size() << " values were given" << endl;
            exit(0);
        }
    }

    int index = 0;
    for (auto Tree : init)
    {
        if (Tree->type != this->type)
        {
            cout << "line: " << yylineno << " Error: " << this->name << " is not a " << Tree->type << endl;
            exit(0);
        }
        this->vars[index++] = Tree->value;
        free(Tree);
    }
}