%{
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include "iope.h"
using namespace std;
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
SymbolTable st;
string scope = "global";
string current_scope;
string pack_name;

vector<VarInfo> current_vars;
//vector<VarInfo> current_pack;
vector<VarInfo> current_params;

vector<VecInfo> current_vecs;

vector<FuncInfo> current_funcs;

vector<int> current_dims;
int delim;
%}
%union {
  int Int;
  char* String;
}
%token BGIN END EXEC DIE PACK ASSIGN CONST IF FOR WHILE AND OR NOT EQ EQG EQL NEQ PACKS END_PACKS GLOBAL_V END_GLOBAL_V GLOBAL_F END_GLOBAL_F PACK_ACCESS 
%token<String> ID TYPE NR EVAL TYPEOF FLOAT STRING CHAR TRU FOLS
%type<String> arit_expr acces_field conditions condition
%start progr

%left '+' '-' 
%left '*' '/' '%'

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

acces_field: ID PACK_ACCESS ID
             | ID size PACK_ACCESS ID
             | ID PACK_ACCESS ID '(' call_param ')'
             | ID size PACK_ACCESS ID '(' call_param ')'
             | ID PACK_ACCESS ID '(' ')'
             | ID size PACK_ACCESS ID '(' ')'
             | ID PACK_ACCESS ID size
             ;

declarations_pack: decl_pack ';'
                 | declarations_pack decl_pack ';'
                 ;

decl_pack: PACK ID{pack_name = $2;} BGIN declarations END list_param_packs{
               scope = $2;
               for(auto var : current_vars){
                    var.scope = scope;
                    int rc = st.add_var(var);
                    if(rc == -1){
                         printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
                         exit(1);
                    }
               }
               current_vars.clear();

               for(auto func: current_funcs){
                    func.scope = scope;
                    int rc = st.add_func(func);
                    if(rc == -1){
                         printf("line: %d Error: %s already declared!\n", yylineno, func.name.c_str());
                         exit(1);
                    }
               }
               current_funcs.clear();
}
         ;

list_param_packs: param_pack 
                | list_param_packs ',' param_pack
                ;

param_pack: ID{
          VarInfo var(pack_name, $1, "null", "global", false);
          st.add_var(var);
} 
          | ID size{
               VecInfo var(pack_name, $1, "global", current_dims, false);
               st.add_vec(var);
          }
          ;

declarations_v: decl_v ';'
              | declarations_v decl_v ';'
              ;

decl_v: TYPE ID {
          VarInfo var($1, $2, "null", "global", false);
          st.add_var(var);
     }
      | TYPE ID size {
          VecInfo vec($1, $2, "global", current_dims, false);
          st.add_vec(vec);
      }
      | TYPE ID ASSIGN arit_expr {
          VarInfo var($1, $2, $4, "global", false);
          int rc = st.add_var(var);
     }
      | CONST TYPE ID ASSIGN arit_expr{
          VarInfo var($2, $3, $5, "global", true);
          int rc = st.add_var(var);
          if(rc == -1){
               printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
               exit(1);
          }
     }
     | TYPE ID ASSIGN STRING{
          if(strcmp($1, "string") != 0){
               printf("line: %d Error: %s is not a string!\n", yylineno, $2);
               exit(1);
          }
          VarInfo var($1, $2, $4, "global", false);
          int rc = st.add_var(var);
          if(rc == -1){
               printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
               exit(1);
          }
     }
     | CONST TYPE ID ASSIGN STRING{
          if(strcmp($2, "string") != 0){
               printf("line: %d Error: %s is not a string!\n", yylineno, $3);
               exit(1);
          }
          VarInfo var($2, $3, $5, "global", true);
          int rc = st.add_var(var);
          if(rc == -1){
               printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
               exit(1);
          }
     }
     | TYPE ID ASSIGN CHAR{
          if(strcmp($1, "char") != 0){
               printf("line: %d Error: %s is not a char!\n", yylineno, $2);
               exit(1);
          }
          VarInfo var($1, $2, $4, "global", false);
          int rc = st.add_var(var);
          if(rc == -1){
               printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
               exit(1);
          }
     }
     | CONST TYPE ID ASSIGN CHAR{
          if(strcmp($2, "char") != 0){
               printf("line: %d Error: %s is not a char!\n", yylineno, $3);
               exit(1);
          }
          VarInfo var($2, $3, $5, "global", true);
          int rc = st.add_var(var);
          if(rc == -1){
               printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
               exit(1);
          }
     }
     | TYPE ID ASSIGN conditions{
          if(strcmp($1, "bool") != 0){
               printf("line: %d Error: %s is not a bool!\n", yylineno, $2);
               exit(1);
          }
          VarInfo var($1, $2, $4, "global", false);
          int rc = st.add_var(var);
          if(rc == -1){
               printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
               exit(1);
          }
     }
     | CONST TYPE ID ASSIGN conditions{
          if(strcmp($2, "bool") != 0){
               printf("line: %d Error: %s is not a bool!\n", yylineno, $3);
               exit(1);
          }
          VarInfo var($2, $3, $5, "global", true);
          int rc = st.add_var(var);
          if(rc == -1){
               printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
               exit(1);
          }
     }
      ;

declarations_f: decl_f ';'
              | declarations_f decl_f ';'
              ;

decl_f: TYPE ID '(' list_param ')' BGIN list END{
          FuncInfo func($1, $2, "global", current_params, false);

          current_params.clear();
          int rc = st.add_func(func);
          if(rc == -1){
               printf("line: %d Error: %s already declared!\n", yylineno, func.name.c_str());
               exit(1);
          }

          for(auto var : current_vars){
               var.scope = func.name;
               int rc = st.add_var(var);
               if(rc == -1){
                    printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
                    exit(1);
               }
          }

          current_vars.clear();
}
      | TYPE ID '(' ')' BGIN list END{
          FuncInfo func($1, $2, "global", current_params, false);

          int rc = st.add_func(func);
          if(rc == -1){
               printf("line: %d Error: %s already declared!\n", yylineno, func.name.c_str());
               exit(1);
          }

          for(auto var : current_vars){
               var.scope = func.name;
               int rc = st.add_var(var);
               if(rc == -1){
                    printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
                    exit(1);
               }
          }
      }

      | CONST TYPE ID '(' list_param ')' BGIN list END{
          FuncInfo func($2, $3, "global", current_params, true);
          current_params.clear();
          int rc = st.add_func(func);
          if(rc == -1){
               printf("line: %d Error: %s already declared!\n", yylineno, func.name.c_str());
               exit(1);
          }

          for(auto var : current_vars){
               var.scope = func.name;
               int rc = st.add_var(var);
               if(rc == -1){
                    printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
                    exit(1);
               }
          }

          current_vars.clear();
      }
      | CONST TYPE ID '(' ')' BGIN list END{
          FuncInfo func($2, $3, "global", current_params, true);
          int rc = st.add_func(func);
          if(rc == -1){
               printf("line: %d Error: %s already declared!\n", yylineno, func.name.c_str());
               exit(1);
          }

          for(auto var : current_vars){
               var.scope = func.name;
               int rc = st.add_var(var);
               if(rc == -1){
                    printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
                    exit(1);
               }
          }

          current_vars.clear();
      }
      ;

declarations:  decl ';'          
	       |  declarations decl ';'
	       ;

decl       : TYPE ID {
               VarInfo var($1, $2, "null", false);
               current_vars.push_back(var);
               }
           | TYPE ID size{
               VecInfo vec($1, $2, current_dims, false);
               current_vecs.push_back(vec); 
           }
           
           | TYPE ID '(' list_param ')' BGIN{delim = current_vars.size() - 1;} list END{
               FuncInfo func($1, $2, current_params, false);
               current_funcs.push_back(func);

               current_params.clear();

               int index = 0;
               for(auto var : current_vars){
                    if(index <= delim){
                         index++;
                         continue;
                    }
                    var.scope = func.name;
                    int rc = st.add_var(var);
                    if(rc == -1){
                         printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
                         exit(1);
                    }
                    current_vars.erase(current_vars.begin() + index);
                    index++;
               }
          }
           | TYPE ID '(' ')' BGIN{delim = current_vars.size() - 1;} list END{
               FuncInfo func($1, $2, current_params, false);
               current_funcs.push_back(func);

               int index = 0;
               for(auto var : current_vars){
                    if(index <= delim){
                         index++;
                         continue;
                    }
                    var.scope = func.name;
                    int rc = st.add_var(var);
                    if(rc == -1){
                         printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
                         exit(1);
                    }
                    current_vars.erase(current_vars.begin() + index);
                    index++;
               }
           }
           | TYPE ID ASSIGN arit_expr{
               VarInfo var($1, $2, $4, false);
               current_vars.push_back(var);
           }
           | CONST TYPE ID '(' list_param ')' BGIN{delim = current_vars.size() - 1;} list END{
               FuncInfo func($2, $3, current_params, true);
               current_funcs.push_back(func);

               current_params.clear();

               int index = 0;
               for(auto var : current_vars){
                    if(index <= delim){
                         index++;
                         continue;
                    }
                    var.scope = func.name;
                    int rc = st.add_var(var);
                    if(rc == -1){
                         printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
                         exit(1);
                    }
                    current_vars.erase(current_vars.begin() + index);
                    index++;
               }
           }
           | CONST TYPE ID '(' ')' BGIN{delim = current_vars.size() - 1;} list END{
               FuncInfo func($2, $3, current_params, true);
               current_funcs.push_back(func);

               int index = 0;
               for(auto var : current_vars){
                    if(index <= delim){
                         index++;
                         continue;
                    }
                    var.scope = func.name;
                    int rc = st.add_var(var);
                    if(rc == -1){
                         printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
                         exit(1);
                    }
                    current_vars.erase(current_vars.begin() + index);
                    index++;
               }
           }
           | CONST TYPE ID ASSIGN arit_expr{
               VarInfo var($2, $3, $5, true);
               current_vars.push_back(var);
           }
          | TYPE ID ASSIGN STRING{
               if(strcmp($1, "string") != 0){
                    printf("line: %d Error: %s is not a string!\n", yylineno, $2);
                    exit(1);
               }
               VarInfo var($1, $2, $4, false);
               current_vars.push_back(var); 
          }
          | CONST TYPE ID ASSIGN STRING{
               if(strcmp($2, "string") != 0){
                    printf("line: %d Error: %s is not a string!\n", yylineno, $3);
                    exit(1);
               }
               VarInfo var($2, $3, $5, true);
               current_vars.push_back(var);
          }
          | TYPE ID ASSIGN CHAR{
               if(strcmp($1, "char") != 0){
                    printf("line: %d Error: %s is not a char!\n", yylineno, $2);
                    exit(1);
               }
               VarInfo var($1, $2, $4, false);
               current_vars.push_back(var);
          }
          | CONST TYPE ID ASSIGN CHAR{
               if(strcmp($2, "char") != 0){
                    printf("line: %d Error: %s is not a char!\n", yylineno, $3);
                    exit(1);
               }
               VarInfo var($2, $3, $5, true);
               current_vars.push_back(var);
          }
          | TYPE ID ASSIGN conditions{
               if(strcmp($1, "bool") != 0){
                    printf("line: %d Error: %s is not a bool!\n", yylineno, $2);
                    exit(1);
               }
               VarInfo var($1, $2, $4, false);
               current_vars.push_back(var);
          }
          | CONST TYPE ID ASSIGN conditions{
               if(strcmp($2, "bool") != 0){
                    printf("line: %d Error: %s is not a bool!\n", yylineno, $3);
                    exit(1);
               }
               VarInfo var($2, $3, $5, true);
               current_vars.push_back(var);
          }
          | 
           ;

list_param  : param
            | list_param ','  param 
            ;
            
param : TYPE ID{
     VarInfo var($1, $2, "null", false);
     current_params.push_back(var);
} 
      | TYPE ID size
      | CONST TYPE ID{
          VarInfo var($2, $3, "null", true);
          current_params.push_back(var);
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

block : EXEC{scope = "main";} list DIE{
     scope = "main";
     for(auto var : current_vars){
          var.scope = scope;
          if(var.change){
               int rc = st.change_val(var.name,var.value, var.scope);
               if(rc == -1){
                    cout<<"line: "<<yylineno<<" Error: "<<var.name<<" not declared ";
                    exit(1);
               }
          }
          else{
               int rc = st.add_var(var);
               if(rc == -1){
                    printf("line: %d Error: %s already declared!\n", yylineno, var.name.c_str());
                    exit(1);
               }
          }
     }
     current_vars.clear();

     for(auto vec: current_vecs){
          vec.scope = scope;
          int rc = st.add_vec(vec);
          if(rc == -1){
               printf("line: %d Error: %s already declared!\n", yylineno, vec.name.c_str());
               exit(1);
          }
     }
     current_vecs.clear();

     printf("The programme is correct!\n"); 
     st.print();
}
     ;

list :  statement ';' 
     | list statement ';'
     ;

statement: TYPE ID {
          VarInfo var($1, $2, "null", current_scope, false);
          current_vars.push_back(var);
          }
           | TYPE ID size{
               VecInfo vec($1, $2, current_dims, false);

               current_vecs.push_back(vec);
           }
           | TYPE ID ASSIGN arit_expr{
               VarInfo var($1, $2, $4, false);
               current_vars.push_back(var);
           }
           | TYPE ID ASSIGN STRING{
               if(strcmp($1, "string") != 0){
                    printf("line: %d Error: %s is not a string!\n", yylineno, $2);
                    exit(1);
               }
               VarInfo var($1, $2, $4, false);
               current_vars.push_back(var);
           }
           | TYPE ID ASSIGN CHAR{
               if(strcmp($1, "char") != 0){
                    printf("line: %d Error: %s is not a char!\n", yylineno, $2);
                    exit(1);
               }
               VarInfo var($1, $2, $4, false);
               current_vars.push_back(var);
           }
           | TYPE ID ASSIGN conditions{
               if(strcmp($1, "bool") != 0){
                    printf("line: %d Error: %s is not a bool!\n", yylineno, $2);
                    exit(1);
               }
               VarInfo var($1, $2, $4, false);
               current_vars.push_back(var);
           }
           | CONST TYPE ID ASSIGN arit_expr{
               VarInfo var($2, $3, $5, true);
               current_vars.push_back(var);
           }
           | CONST TYPE ID ASSIGN STRING{
               if(strcmp($2, "string") != 0){
                    printf("line: %d Error: %s is not a string!\n", yylineno, $3);
                    exit(1);
               }
               VarInfo var($2, $3, $5, true);
               current_vars.push_back(var);
           }
           | CONST TYPE ID ASSIGN CHAR{
               if(strcmp($2, "char") != 0){
                    printf("line: %d Error: %s is not a char!\n", yylineno, $3);
                    exit(1);
               }
               VarInfo var($2, $3, $5, true);
               current_vars.push_back(var);
           }
           | CONST TYPE ID ASSIGN conditions{
               if(strcmp($2, "bool") != 0){
                    printf("line: %d Error: %s is not a bool!\n", yylineno, $3);
                    exit(1);
               }
               VarInfo var($2, $3, $5, true);
               current_vars.push_back(var);
           }
           | ID ASSIGN arit_expr{
               VarInfo var($1, $3, true);
               current_vars.push_back(var);
           }
           | ID ASSIGN STRING{
               VarInfo var($1, $3, true);
               current_vars.push_back(var);
           }
           | ID ASSIGN CHAR{
               VarInfo var($1, $3, true);
               current_vars.push_back(var);
           }
           | ID ASSIGN conditions{
               VarInfo var($1, $3, true);
               current_vars.push_back(var);
           }
           | IF '(' conditions ')' BGIN list END
           | WHILE '(' conditions ')' BGIN list END
           | FOR '(' ID ASSIGN arit_expr ';' conditions ';' ID ASSIGN arit_expr ')' BGIN list END
           | ID '(' call_param ')'{
               bool notOk = st.checkIfDeclared($1, scope, "func");
               if(notOk){
                    printf("line: %d Error: %s not declared!\n", yylineno, $1);
                    exit(1);
               }
               else {
                    vector<VarInfo> temp = st.get_params($1, scope);
                    if(temp.size() != current_params.size()){
                         printf("line: %d Error: %s wrong number of parameters!\n", yylineno, $1);
                         exit(1);
                    }
                    else{
                         for(int i = 0; i < temp.size(); i++){
                              if(temp[i].type != current_params[i].type){
                                   printf("line: %d Error: %s wrong type of parameters!\n", yylineno, $1);
                                   exit(1);
                              }
                         }
                    }
               }
           }
           | EVAL '(' arit_expr ')'
           | EVAL '(' conditions')'
           | TYPEOF'(' arit_expr ')'
           | TYPEOF '(' conditions')'
           ;

call_param: arit_expr
          | call_param ',' arit_expr
          ;

conditions: condition{
               $$ = $1;
}
          | NOT condition{
               $$ = $2;
          }
          |'(' conditions ')'{
               $$ = $2;
          }
          | NOT '(' conditions AND condition ')'{
               $$ = $3;
          }
          | NOT '(' conditions OR condition ')'{
               $$ = $3;
          }
          | conditions AND condition{
               $$ = $1;
          }
          | conditions OR condition{
               $$ = $1;
          }
          ;
condition: arit_expr '<' arit_expr
          | arit_expr '>' arit_expr
          | arit_expr EQ arit_expr
          | arit_expr EQG arit_expr
          | arit_expr EQL arit_expr
          | arit_expr NEQ arit_expr
          | TRU{
               $$ = $1;
          }
          | FOLS{
               $$ = $1;
          }
          ;

arit_expr: arit_expr '+' arit_expr
         | arit_expr '-' arit_expr
         | arit_expr '*' arit_expr
         | arit_expr '/' arit_expr
         | arit_expr '%' arit_expr
         | '(' arit_expr ')'{
               $$ = $2;
         }
         | NR{
               $$ = $1;
         }
         | FLOAT{
               $$ = $1;
         }
         | ID 
         | ID size
         | ID '(' call_param ')'
         | EVAL '(' arit_expr ')'
         | EVAL '(' conditions')'
         | TYPEOF '(' arit_expr ')'
         | TYPEOF'(' conditions')'
         | acces_field
         ;
%%
void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}
int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
} 