#include "Utils.h"

void CheckErr(string ErrCode, int yylineno)
{
    if (ErrCode != "correct")
    {
        cout << "line: " << yylineno << " Error: " << ErrCode << endl;
        exit(0);
    }
}

string getUndefValue(string type)
{
    if (type == "int")
        return "0";
    else if (type == "float")
        return "0.0";
    else if (type == "bool")
        return "false";
    else if (type == "char")
        return "\'\'";
    else if (type == "string")
        return "\"\"";
    else
        return "null";
}