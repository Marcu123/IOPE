#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <algorithm>
#include <utility>
using namespace std;

struct AST
{
    string type;    // int,float etc
    string value;   //+, -, *, /, =, constant;
    bool operation; //+, -, *, /, =, constant;
    bool isvec;
    int rows;
    vector<int> cols;

    AST *left = nullptr;
    AST *right = nullptr;

    AST(string value, string type, AST *left, AST *right, bool operation);
    AST(string value, AST *left, AST *right, bool operation);
    AST(string value, string type, AST *left, AST *right, bool operation, int rows, vector<int> cols);

    string compute();
};