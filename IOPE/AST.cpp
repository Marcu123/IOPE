#include "AST.h"

AST::AST(string value, string type, AST *left, AST *right, bool operation)
{
    this->value = value;
    this->type = type;
    this->left = left;
    this->right = right;
    this->operation = operation;
    this->isvec = false;
}
AST::AST(string value, AST *left, AST *right, bool operation)
{
    this->value = value;
    this->left = left;
    this->right = right;
    this->operation = operation;
    this->isvec = false;
}
AST::AST(string value, string type, AST *left, AST *right, bool operation, int rows, vector<int> cols)
{
    this->value = value;
    this->type = type;
    this->left = left;
    this->right = right;
    this->operation = operation;
    this->isvec = true;
    this->rows = rows;
    for (int i = 0; i < cols.size(); i++)
        this->cols.push_back(cols[i]);
}

string AST::compute()
{
    if (this->left != nullptr)
        this->left->compute();
    if (this->right != nullptr)
        this->right->compute();
    if (this->operation)
    {
        // checking if operand is a vector
        if (this->left->isvec)
        {
            string error = "operator ";
            error += this->value;
            error += " is not suited for arrays";
            return error;
        }
        if (this->right != nullptr)
        {
            if (this->right->isvec)
            {
                string error = "operator ";
                error += this->value;
                error += " is not suited for arrays";
                return error;
            }
        }

        if (this->value == "+")
        {
            if (this->left->type == "int" && this->right->type == "int")
            {
                this->type = "int";
                this->value = to_string(stoi(this->left->value) + stoi(this->right->value));
            }
            else if (this->left->type == "float" && this->right->type == "float")
            {
                this->type = "float";
                this->value = to_string(stof(this->left->value) + stof(this->right->value));
            }
            else if (this->left->type == "string" || this->right->type == "string")
                return "operator + is not suited for string values";
            else if (this->left->type == "char" || this->right->type == "char")
                return "operator + is not suited for char values";
            else if (this->left->type == "bool" || this->right->type == "bool")
                return "operator + is not suited for bool values";
            else
                "can't cast";
        }
        else if (this->value == "-")
        {
            if (this->right == nullptr)
            {
                if (this->left->type == "int")
                {
                    this->type = "int";
                    this->value = to_string(0 - stoi(this->left->value));
                }
                else if (this->left->type == "float")
                {
                    this->type = "float";
                    this->value = to_string(0 - stoi(this->left->value));
                }
                else if (this->left->type == "string")
                    return "operator - is not suited for string values";
                else if (this->left->type == "char")
                    return "operator - is not suited for char values";
                else if (this->left->type == "bool")
                    return "operator - is not suited for bool values";
                else
                    "can't cast";
            }
            else
            {
                if (this->left->type == "int" && this->right->type == "int")
                {
                    this->type = "int";
                    this->value = to_string(stoi(this->left->value) - stoi(this->right->value));
                }
                else if (this->left->type == "float" && this->right->type == "float")
                {
                    this->type = "float";
                    this->value = to_string(stof(this->left->value) - stof(this->right->value));
                }
                else if (this->left->type == "string" || this->right->type == "string")
                    return "operator - is not suited for string values";
                else if (this->left->type == "char" || this->right->type == "char")
                    return "operator - is not suited for char values";
                else if (this->left->type == "bool" || this->right->type == "bool")
                    return "operator - is not suited for bool values";
                else
                    return "can't cast";
            }
        }
        else if (this->value == "*")
        {
            if (this->left->type == "int" && this->right->type == "int")
            {
                this->type = "int";
                this->value = to_string(stoi(this->left->value) * stoi(this->right->value));
            }
            else if (this->left->type == "float" && this->right->type == "float")
            {
                this->type = "float";
                this->value = to_string(stof(this->left->value) * stof(this->right->value));
            }
            else if (this->left->type == "string" || this->right->type == "string")
                return "operator * is not suited for string values";
            else if (this->left->type == "char" || this->right->type == "char")
                return "operator * is not suited for char values";
            else if (this->left->type == "bool" || this->right->type == "bool")
                return "operator * is not suited for bool values";
            else
                return "can't cast";
        }
        else if (this->value == "/")
        {
            if (this->left->type == "int" && this->right->type == "int")
            {
                if (this->right->value == "0")
                    return "can't divide by 0";
                this->type = "int";
                this->value = to_string(stoi(this->left->value) / stoi(this->right->value));
            }
            else if (this->left->type == "float" && this->right->type == "float")
            {
                if (this->right->value == "0")
                    return "can't divide by 0";
                this->type = "float";
                this->value = to_string(stof(this->left->value) / stof(this->right->value));
            }
            else if (this->left->type == "string" || this->right->type == "string")
                return "operator / is not suited for string values";
            else if (this->left->type == "char" || this->right->type == "char")
                return "operator / is not suited for char values";
            else if (this->left->type == "bool" || this->right->type == "bool")
                return "operator / is not suited for bool values";
            else
                return "can't cast";
        }
        else if (this->value == "==")
        {
            this->type = "bool";
            if (this->left->type != this->right->type)
            {
                string error = "can't cast ";
                error += this->left->type;
                error += " to ";
                error += this->right->type;
                return error;
            }
            this->value = (this->left->value == this->right->value) ? "true" : "false";
        }
        else if (this->value == "!=")
        {
            this->type = "bool";
            if (this->left->type != this->right->type)
            {
                string error = "can't cast ";
                error += this->left->type;
                error += " to ";
                error += this->right->type;
                return error;
            }
            this->value = (this->left->value != this->right->value) ? "true" : "false";
        }
        else if (this->value == "<")
        {
            this->type = "bool";
            if (this->left->type == "int" && this->right->type == "int")
                this->value = (stoi(this->left->value) < stoi(this->right->value)) ? "true" : "false";
            else if (this->left->type == "float" && this->right->type == "float")
                this->value = (stof(this->left->value) < stof(this->right->value)) ? "true" : "false";
            else if (this->left->type == "string" || this->right->type == "string")
                return "operator < is not suited for string values";
            else if (this->left->type == "char" || this->right->type == "char")
                return "operator < is not suited for char values";
            else if (this->left->type == "bool" || this->right->type == "bool")
                return "operator < is not suited for bool values";
            else
                "can't cast";
        }
        else if (this->value == ">")
        {
            this->type = "bool";
            if (this->left->type == "int" && this->right->type == "int")
            {
                this->value = (stoi(this->left->value) > stoi(this->right->value)) ? "true" : "false";
            }
            else if (this->left->type == "float" && this->right->type == "float")
            {
                this->value = (stof(this->left->value) > stof(this->right->value)) ? "true" : "false";
            }
            else if (this->left->type == "string" || this->right->type == "string")
                return "operator > is not suited for string values";
            else if (this->left->type == "char" || this->right->type == "char")
                return "operator > is not suited for char values";
            else if (this->left->type == "bool" || this->right->type == "bool")
                return "operator > is not suited for bool values";
            else
                return "can't cast";
        }
        else if (this->value == "<=")
        {
            this->type = "bool";
            if (this->left->type == "int" && this->right->type == "int")
            {
                this->value = (stoi(this->left->value) <= stoi(this->right->value)) ? "true" : "false";
            }
            else if (this->left->type == "float" && this->right->type == "float")
            {
                this->value = (stof(this->left->value) <= stof(this->right->value)) ? "true" : "false";
            }
            else if (this->left->type == "string" || this->right->type == "string")
                return "operator <= is not suited for string values";
            else if (this->left->type == "char" || this->right->type == "char")
                return "operator <= is not suited for char values";
            else if (this->left->type == "bool" || this->right->type == "bool")
                return "operator <= is not suited for bool values";
            else
                return "can't cast";
        }
        else if (this->value == ">=")
        {
            this->type = "bool";
            if (this->left->type == "int" && this->right->type == "int")
            {
                this->value = (stoi(this->left->value) >= stoi(this->right->value)) ? "true" : "false";
            }
            else if (this->left->type == "float" && this->right->type == "float")
            {
                this->value = (stof(this->left->value) >= stof(this->right->value)) ? "true" : "false";
            }
            else if (this->left->type == "string" || this->right->type == "string")
                return "operator >= is not suited for string values";
            else if (this->left->type == "char" || this->right->type == "char")
                return "operator >= is not suited for char values";
            else if (this->left->type == "bool" || this->right->type == "bool")
                return "operator >= is not suited for bool values";
            else
                return "can't cast";
        }
        else if (this->value == "and")
        {
            this->type = "bool";
            if (this->left->type == "bool" && this->right->type == "bool")
                this->value = (this->left->value == "true" && this->right->value == "true") ? "true" : "false";
            else if (this->left->type != "bool" && this->right->type != "bool")
            {
                string error = "operator and is not suited for ";
                error += this->left->type;
                return error;
            }
            else
                return "can't cast";
        }
        else if (this->value == "or")
        {
            this->type = "bool";
            if (this->left->type == "bool" && this->right->type == "bool")
                this->value = (this->left->value == "true" || this->right->value == "true") ? "true" : "false";
            else if (this->left->type != "bool" && this->right->type != "bool")
            {
                string error = "operator or is not suited for ";
                error += this->left->type;
                return error;
            }
            else
                return "can't cast";
        }
        else if (this->value == "not")
        {
            this->type = "bool";
            if (this->left->type == "bool")
                this->value = (this->left->value == "true") ? "false" : "true";
            else
            {
                string error = "operator not is not suited for ";
                error += this->left->type;
                return error;
            }
        }
    }
    else
        return "correct";

    return "correct";
}