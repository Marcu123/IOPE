%{
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <string>
#include <utility>
#include "SymbolTable.h"

using namespace std;

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);

SymbolTable st;
string scope = "global";
string current_type;
string current_scope;
string pack_name;

vector<VarInfo> current_vars;
vector<pair<VarInfo*, VecInfo*>> current_params;

vector<VecInfo> current_vecs;

vector<FuncInfo> current_funcs;
vector<AST*> current_exprs;

vector<int> current_dims;
vector<AST*> init_values_vec;

vector<VarInfo> pack_vars;
vector<VecInfo> pack_vecs;
stack<int> size_stack;  
%}
%union {
  int Int;
  class AST* ast;
  char* String;
}
%token BGIN END EXEC DIE PACK ASSIGN CONST IF FOR WHILE AND OR NOT EQ EQG EQL NEQ PACKS END_PACKS GLOBAL_V END_GLOBAL_V GLOBAL_F END_GLOBAL_F PACK_ACCESS RET ELSE
%token<String> TYPE EVAL TYPEOF FLOAT STRING CHAR TRU FOLS
%token<String> ID NR
%type<ast> expr
%start progr

%left OR
%left AND
%left NOT
%left '<' '>' EQ EQG EQL NEQ
%left '+' '-' 
%left '*' '/' '%'
%right MINUS


%%
progr: gen_packs
     ;
gen_packs: PACKS declarations_pack END_PACKS gen_global_vals
          | gen_global_vals
         ;
gen_global_vals: GLOBAL_V declarations_v END_GLOBAL_V gen_global_funcs
               | gen_global_funcs
               ;
gen_global_funcs: GLOBAL_F declarations_f END_GLOBAL_F block
               | block
                ;

declarations_pack: decl_pack ';'
                 | declarations_pack decl_pack ';'
                 ;

decl_pack: PACK ID{pack_name = $2;} BGIN declarations END list_param_packs{
               pack_vars.clear();
               pack_vecs.clear();
}
         ;
declarations:  decl ';'          
	       |  declarations decl ';'
	       ;
decl       : TYPE ID {
               VarInfo var($1, $2, "null", pack_name, false);
               pack_vars.push_back(var);
               }
           | TYPE ID size{
               VecInfo vec($1, $2, pack_name, current_dims, false);
               pack_vecs.push_back(vec);
               current_dims.clear();
           }
           | TYPE ID size ASSIGN init_for_vec{
               VecInfo vec($1, $2, pack_name, current_dims, init_values_vec, false, yylineno);
               pack_vecs.push_back(vec);
               current_dims.clear();
               init_values_vec.clear();
           }
           | TYPE ID '(' list_param ')' BGIN{scope = $2;current_type = $1;} list END{
               FuncInfo func($1, $2, pack_name, current_params, false);

               current_params.clear();
               st.add_func(func, yylineno);
          }
           | TYPE ID '(' ')' BGIN{scope = $2;current_type = $1;} list END{
               FuncInfo func($1, $2, pack_name, false);

               current_params.clear();
               st.add_func(func, yylineno);

           }
           | CONST TYPE ID '(' list_param ')' BGIN{scope = $3; current_type = $2;} list END{
               FuncInfo func($2, $3, pack_name, current_params, true);

               current_params.clear();
               st.add_func(func, yylineno);
           }
           | CONST TYPE ID '(' ')' BGIN{scope = $3;current_type = $2;} list END{
               FuncInfo func($2, $3, pack_name, true);

               current_params.clear();
               st.add_func(func, yylineno);
           }
          | TYPE ID ASSIGN expr{
               $4->compute();
               VarInfo var($1, $2, $4, pack_name, false);
               pack_vars.push_back(var);
          }
          | CONST TYPE ID ASSIGN expr{
               $5->compute();
               VarInfo var($2, $3, $5, pack_name, true);
               pack_vars.push_back(var);
          }
           ;
list_param_packs: param_pack 
                | list_param_packs ',' param_pack
                ;

param_pack: ID{
          PackInfo pack($1,pack_name, pack_vars, pack_vecs);
          st.add_pack(pack, yylineno);
} 
          | ID size{
          }
          ;

declarations_v: decl_v ';'
              | declarations_v decl_v ';'
              ;

decl_v: TYPE ID {
          VarInfo var($1, $2, "null", "global", false);
          st.add_var(var, yylineno);
     }
      | TYPE ID size {
          VecInfo vec($1, $2, "global", current_dims, false);
          st.add_vec(vec, yylineno);
      }
     | TYPE ID size ASSIGN init_for_vec{
               VecInfo vec($1, $2, "global", current_dims, init_values_vec, false, yylineno);
               st.add_vec(vec, yylineno);
               current_dims.clear();
               init_values_vec.clear();
     }
     | TYPE ID ASSIGN expr{
          $4->compute();
          if($4->type != $1){
               printf("line: %d Error: %s is not a %s!\n", yylineno, $2, $4->type.c_str());
               exit(1);
          }
          VarInfo var($1, $2, $4, "global", false);
          st.add_var(var, yylineno);
     }
     | CONST TYPE ID ASSIGN expr{
          $5->compute();
          if($5->type != $2){
               printf("line: %d Error: %s is not a %s!\n", yylineno, $3, $5->type.c_str());
               exit(1);
          }
          $5->compute();
          VarInfo var($2, $3, $5, "global", true);
          st.add_var(var, yylineno);
     }
      ;


declarations_f: decl_f ';'
              | declarations_f decl_f ';'
              ;

decl_f: TYPE ID '(' list_param ')' BGIN{scope = $2; current_type = $1;} list END{
          FuncInfo func($1, $2, "global", current_params, false);

          current_params.clear();
          st.add_func(func, yylineno);
}
      | TYPE ID '(' ')' BGIN{scope = $2; current_type = $1;} list END{
          FuncInfo func($1, $2, "global", false);

          st.add_func(func, yylineno);
      }

      | CONST TYPE ID '(' list_param ')' BGIN{scope = $3; current_type = $2;} list END{
          FuncInfo func($2, $3, "global", current_params, true);

          current_params.clear();
          st.add_func(func, yylineno);
      }
      | CONST TYPE ID '(' ')' BGIN{scope = $3; current_type = $2;} list END{
          FuncInfo func($2, $3, "global", true);
          st.add_func(func, yylineno);
      }
      ;
list_param  : param
            | list_param ','  param 
            ;
            
param : TYPE ID{
     VarInfo* var = new VarInfo($1, $2, "null", false);
     current_params.push_back({var, nullptr});
} 
      | TYPE ID size{
          VecInfo* vec = new VecInfo($1, $2, current_dims, false);
          current_dims.clear();    
          current_params.push_back({nullptr, vec});
      }
      | CONST TYPE ID{
          VarInfo* var = new VarInfo($2, $3, "null", true);
          current_params.push_back({var, nullptr});
      }
      | CONST TYPE ID size{
          VecInfo* vec = new VecInfo($2, $3, current_dims, true);
          current_dims.clear();    
          current_params.push_back({nullptr, vec});
      }
      ;  

size : '[' NR ']'{
          int size = stoi($2);
          current_dims.push_back(size);
     }
     | '[' NR ']' size{
          int size = stoi($2);
          current_dims.push_back(size);
     }
     ;

block : EXEC{scope = "main"; current_type = "any";} list DIE{
     scope = "main";

     printf("The programme is correct!\n"); 
     st.print();
}
     ;

list :  statement ';' 
     | list statement ';'
     ;

statement: TYPE ID {
               VarInfo var($1, $2, "null", scope, false);
               st.add_var(var, yylineno);
          }
           | TYPE ID size{
               VecInfo vec($1, $2, scope, current_dims, false);
               st.add_vec(vec, yylineno);
               current_dims.clear();
           }
           | TYPE ID size ASSIGN init_for_vec{
               VecInfo vec($1, $2, scope, current_dims, init_values_vec, false, yylineno);
               st.add_vec(vec, yylineno);
               current_dims.clear();
               init_values_vec.clear();
           }
           | TYPE ID ASSIGN expr{
               CheckErr($4->compute(), yylineno);
               if($4->type != $1){
                    printf("line: %d Error: %s is not a %s!\n", yylineno, $2, $4->type.c_str());
                    exit(1);
               }
               VarInfo var($1, $2, $4, scope, false);
               st.add_var(var, yylineno);
           }
           | CONST TYPE ID ASSIGN expr{
               CheckErr($5->compute(), yylineno);
               if($5->type != $2){
                    printf("line: %d Error: %s is not a %s!\n", yylineno, $3, $5->type.c_str());
                    exit(1);
               }
               VarInfo var($2, $3, $5, scope, true);
               st.add_var(var, yylineno);
           }
           | ID ASSIGN expr{
               CheckErr($3->compute(), yylineno);
               st.change_val($1, $3->value, $3->type, yylineno);
           }
           | ID '[' NR ']' ASSIGN expr{
               CheckErr($6->compute(), yylineno);
               st.change_vec($1, $6->value, $6->type, stoi($3), yylineno);
           }
           | IF '(' expr ')' BGIN list END{
               CheckErr($3->compute(), yylineno);
               if($3->type != "bool"){
                    printf("line: %d Error: condition inside if should be boolean!\n", yylineno);
                    exit(1);
               }
           }
           | IF '(' expr ')' BGIN list END ELSE BGIN list END{
               CheckErr($3->compute(), yylineno);
               if($3->type != "bool"){
                    printf("line: %d Error: condition inside if should be boolean!\n", yylineno);
                    exit(1);
               }
           }
           | WHILE '(' expr ')' BGIN list END{
               CheckErr($3->compute(), yylineno);
               if($3->type != "bool"){
                    printf("line: %d Error: condition inside while should be boolean!\n", yylineno);
                    exit(1);
               }
           }
           | FOR '(' ID ASSIGN expr{
               CheckErr($5->compute(), yylineno);
               st.change_val($3, $5->value, $5->type, yylineno); 
           } ';' expr ';' ID ASSIGN expr ')' BGIN list END{

               CheckErr($8->compute(), yylineno);
               if($8->type != "bool"){
                    printf("line: %d Error: condition inside for should be boolean!\n", yylineno);
                    exit(1);
               }

               CheckErr($12->compute(), yylineno);
               st.change_val($10, $12->value, $12->type, yylineno);
           }
           | ID '('{size_stack.push(current_exprs.size());} call_param ')'{
               int delim = size_stack.top();
               vector<AST*> parameters;
               for(int i = delim;i < current_exprs.size(); i++){
                    parameters.push_back(current_exprs[i]);
               }
               string funcType = st.checkValidParams($1, scope, parameters, yylineno);

               int size = current_exprs.size();
               for(int i = delim;i < size; i++){
                    current_exprs.pop_back();
               }
               size_stack.pop();
           }
           | ID '('{size_stack.push(current_exprs.size());} ')'{
               int delim = size_stack.top();
               vector<AST*> parameters;
               for(int i = delim;i < current_exprs.size(); i++){
                    parameters.push_back(current_exprs[i]);
               }
               string funcType = st.checkValidParams($1, scope, parameters, yylineno);

               int size = current_exprs.size();
               for(int i = delim;i < size; i++){
                    current_exprs.pop_back();
               }
               size_stack.pop();
           }
           | ID PACK_ACCESS ID '('{size_stack.push(current_exprs.size());} call_param ')'{
               string name = $1;
               bool ok = st.checkIfDeclared(name, "pack", yylineno);
               if(!ok){
                    printf("line: %d Error: %s not declared or is not a pack!\n", yylineno, $1);
                    exit(1);
               }
               PackInfo temp = st.get_pack(name);

               int delim = size_stack.top();
               vector<AST*> parameters;
               for(int i = delim;i < current_exprs.size(); i++){
                    parameters.push_back(current_exprs[i]);
               }

               string funcType = st.checkValidParams($3, temp.type, current_exprs, yylineno);

               int size = current_exprs.size();
               for(int i = delim;i < size; i++){
                    current_exprs.pop_back();
               }
               size_stack.pop();
             }
             | ID PACK_ACCESS ID '('{size_stack.push(current_exprs.size());} ')'{
               string name = $1;
               bool ok = st.checkIfDeclared(name, "pack", yylineno);
               if(!ok){
                    printf("line: %d Error: %s not declared or is not a pack!\n", yylineno, $1);
                    exit(1);
               }
               PackInfo temp = st.get_pack(name);

               int delim = size_stack.top();
               vector<AST*> parameters;
               for(int i = delim;i < current_exprs.size(); i++){
                    parameters.push_back(current_exprs[i]);
               }

               string funcType = st.checkValidParams($3, temp.type, current_exprs, yylineno);

               int size = current_exprs.size();
               for(int i = delim;i < size; i++){
                    current_exprs.pop_back();
               }
               size_stack.pop();
             }
           | EVAL '(' expr ')'{
               CheckErr($3->compute(), yylineno);
               cout<<$3->value<<endl;
           }
           | TYPEOF'(' expr ')'{
               CheckErr($3->compute(), yylineno);
               cout<<$3->type<<endl;
           }
           | RET expr{
               CheckErr($2->compute(), yylineno);
               if($2->type != current_type && current_type != "any"){
                    printf("line: %d Error: return type should be %s!\n", yylineno, current_type.c_str());
                    exit(1);
               }
           }
           ;

init_for_vec: '{' init_vec '}'
            ;

init_vec: expr{
          CheckErr($1->compute(), yylineno);
          init_values_vec.push_back($1);
     }        
          | init_vec ',' expr{
               CheckErr($3->compute(), yylineno);
               init_values_vec.push_back($3);
          }
          ;

call_param: expr{
          current_exprs.push_back($1);
     }
          | call_param ',' expr{
               current_exprs.push_back($3);
          }
          ;

expr: expr AND expr{
          $$ = new AST("and", $1, $3, true);
     }
    | expr OR expr{
          $$ = new AST("or", $1, $3, true);
     }
    | NOT expr{
          $$ = new AST("not", $2, nullptr, true);
     }
    | '(' expr ')'{
          $$ = $2;
     }
     | '-' expr %prec MINUS{
          $$ = new AST("-", $2, nullptr, true);
     }
    | expr '<' expr{
          $$ = new AST("<", $1, $3, true);
     }
     | expr '>' expr{
            $$ = new AST(">", $1, $3, true);
      }
      | expr EQ expr{
            $$ = new AST("==", $1, $3, true);
      }
      | expr EQG expr{
            $$ = new AST(">=", $1, $3, true);
      }
      | expr EQL expr{
            $$ = new AST("<=", $1, $3, true);
      }
      | expr NEQ expr{
            $$ = new AST("!=", $1, $3, true);
      }
      | TRU{
            $$ = new AST("true", "bool", nullptr, nullptr, false);
      }
      | FOLS{
            $$ = new AST("false", "bool", nullptr, nullptr, false);
      }
      | ID{
               int ok = st.checkIfDeclaredScoped($1, "var", scope, yylineno);
               if(ok){
                    VarInfo temp = st.get_var($1, scope);
                    if(temp.value == "null"){
                         printf("line: %d Error: use of unitialized variable: %s!\n", yylineno, temp.name.c_str());
                         exit(0);
                    }
                    $$ = new AST(temp.value, temp.type, nullptr, nullptr, false);    
               }
               else{
                    ok = st.checkIfDeclaredScoped($1, "vec", scope, yylineno);
                    if(ok){
                         VecInfo temp = st.get_vec($1, scope);
                         $$ = new AST(getUndefValue(temp.type), temp.type, nullptr, nullptr, false, temp.rows, temp.cols);
                    } else{
                         for(auto param: current_params){
                              if(param.first != nullptr){
                                   if(param.first->name == $1){
                                        $$ = new AST(getUndefValue(param.first->type), param.first->type, nullptr, nullptr, false);
                                        ok = 1;
                                   }
                              }
                              else{
                                   if(param.second->name == $1){
                                        $$ = new AST(getUndefValue(param.second->type), param.second->type, nullptr, nullptr, false,  param.second->rows, param.second->cols);        
                                        ok = 1;             
                                   }
                              }
                         }
                    }
               }

               if(!ok){
                    printf("line: %d Error: %s not declared in this scope!\n", yylineno, $1);
                    exit(1);
               }
      }
      | NR{
               $$ = new AST($1, "int", nullptr, nullptr, false);
      }
      | FLOAT{
               $$ = new AST($1, "float",nullptr, nullptr, false);
      }
      | STRING{
               $$ = new AST($1, "string", nullptr, nullptr, false);
      }
      | CHAR{
               $$ = new AST($1, "char", nullptr, nullptr, false);
      }
      | expr '+' expr{
            $$ = new AST("+", $1, $3, true);
      }
     | expr '-' expr{
               $$ = new AST("-", $1, $3, true);
          }
     | expr '*' expr{
               $$ = new AST("*", $1, $3, true);
          }
     | expr '/' expr{
               $$ = new AST("/", $1, $3, true);
          }
     | EVAL '(' expr ')'{
               $$ = $3;
          }
     | ID '[' NR ']' {
               bool ok = st.checkIfDeclaredScoped($1, "vec", scope, yylineno);
               if(!ok){
                    printf("line: %d Error: %s not declared in this scope!\n", yylineno, $1);
                    exit(1);
               }
               VecInfo temp = st.get_vec($1, scope);
               int index = stoi($3);
               if(index >= temp.vars.size()){
                    printf("line: %d Error: index out of bounds!\n", yylineno);
                    exit(1);
               }
               string value = temp.vars[index];
               if(value == "null"){
                    printf("line: %d Error:  use of unitialized variable: %s[%d]!\n", yylineno, $1, index);
                    exit(1);
               }
               $$ = new AST(value, temp.type, nullptr, nullptr, false);
          }
     ;
     | ID '('{size_stack.push(current_exprs.size());} call_param ')'{
          int delim = size_stack.top();
          vector<AST*> parameters;
          for(int i = delim;i < current_exprs.size(); i++){
               parameters.push_back(current_exprs[i]);
          }
          string funcType = st.checkValidParams($1, scope, parameters, yylineno);

          $$ = new AST(getUndefValue(funcType), funcType, nullptr, nullptr, false);
          int size = current_exprs.size();
          for(int i = delim;i < size; i++){
               current_exprs.pop_back();
          }
          size_stack.pop();
     }
     | ID'('{size_stack.push(current_exprs.size());} ')'{
          int delim = size_stack.top();
          vector<AST*> parameters;
          for(int i = delim;i < current_exprs.size(); i++){
               parameters.push_back(current_exprs[i]);
          }
          string funcType = st.checkValidParams($1, scope, parameters, yylineno);

          $$ = new AST(getUndefValue(funcType), funcType, nullptr, nullptr, false);
          int size = current_exprs.size();
          for(int i = delim;i < size; i++){
               current_exprs.pop_back();
          }
          size_stack.pop();
     }
     | ID PACK_ACCESS ID{ 
           string name = $1;
            bool ok = st.checkIfDeclared(name, "pack", yylineno);
            if(!ok){
               printf("line: %d Error: %s not declared!\n", yylineno, $1);
               exit(1);
            }
            PackInfo temp = st.get_pack(name);
            string field = $3;
            int found = false;
            for(auto var: temp.vars){
               if(var.name == field){
                    if(var.value == "null"){
                         printf("line: %d Error: use of unitialized field: %s!\n", yylineno, var.name.c_str());
                         exit(0);
                    }
                    $$ = new AST(var.value, var.type, nullptr, nullptr, false);
                    found = true;
               }
            }
            if(!found){
               printf("line: %d Error: %s is not a field in %s!\n", yylineno, field.c_str(), name.c_str());
               exit(1);
            }
     }
          | ID PACK_ACCESS ID '('{size_stack.push(current_exprs.size());} call_param ')'{
               string name = $1;
               bool ok = st.checkIfDeclared(name, "pack", yylineno);
               if(!ok){
                    printf("line: %d Error: %s not declared or is not a pack!\n", yylineno, $1);
                    exit(1);
               }
               PackInfo temp = st.get_pack(name);

               int delim = size_stack.top();
               vector<AST*> parameters;
               for(int i = delim;i < current_exprs.size(); i++){
                    parameters.push_back(current_exprs[i]);
               }

               string funcType = st.checkValidParams($3, temp.type, current_exprs, yylineno);

               $$ = new AST(getUndefValue(funcType), funcType, nullptr, nullptr, false);
               int size = current_exprs.size();
               for(int i = delim;i < size; i++){
                    current_exprs.pop_back();
               }
               size_stack.pop();
             }
             | ID PACK_ACCESS ID '('{size_stack.push(current_exprs.size());} ')'{
               string name = $1;
               bool ok = st.checkIfDeclared(name, "pack", yylineno);
               if(!ok){
                    printf("line: %d Error: %s not declared or is not a pack!\n", yylineno, $1);
                    exit(1);
               }
               PackInfo temp = st.get_pack(name);

               int delim = size_stack.top();
               vector<AST*> parameters;
               for(int i = delim;i < current_exprs.size(); i++){
                    parameters.push_back(current_exprs[i]);
               }

               string funcType = st.checkValidParams($3, temp.type, current_exprs, yylineno);

               $$ = new AST(getUndefValue(funcType), funcType, nullptr, nullptr, false);
               int size = current_exprs.size();
               for(int i = delim;i < size; i++){
                    current_exprs.pop_back();
               }
               size_stack.pop();
             }
             | ID PACK_ACCESS ID '[' NR ']' {
               int index = stoi($5);
               string name = $1;
               bool ok = st.checkIfDeclared(name, "pack", yylineno);
               if(!ok){
                    printf("line: %d Error: %s not declared!\n", yylineno, $1);
                    exit(1);
               }
               PackInfo temp = st.get_pack(name);
               string field = $3;
               int found = false;
               for(auto var: temp.vecs){
                    if(var.name == field){
                         if(var.vars[index] == "null"){
                              printf("line: %d Error: use of unitialized field: %s[%d]!\n", yylineno, var.name.c_str(), index);
                              exit(0);
                         }
                         $$ = new AST(var.vars[index], var.type, nullptr, nullptr, false);
                         found = true;
                    }
               }
            if(!found){
               printf("line: %d Error: %s is not a field in %s!\n", yylineno, field.c_str(), name.c_str());
               exit(1);
            }
             }
             ;
%%
void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}
int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
} 