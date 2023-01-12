//
// Created by tamir on 10/12/2021.
//

#ifndef HW3_UTILITIES_H
#define HW3_UTILITIES_H
#include <vector>
#include <string>
#include <map>
#include <stack>
#include "ir_translation.h"

using std::vector;
using std::string;
using std::pair;
using std::map;
using std::stack;

typedef struct {
    string name;
    string type;
    bool isConst;
} param;

typedef struct {
    int value;
    string name;
    string type;
    bool isConst;
    vector<param> params;
    string reg_add;
    vector<string> reg_add_list;
    vector<pair<int,BranchLabelIndex>> next_list;
    vector<pair<int,BranchLabelIndex>> false_list;
    vector<pair<int,BranchLabelIndex>> true_list;
    string label;
    bool is_raw_num;
} STYPE;

#define YYSTYPE STYPE

typedef struct{
    string name;
    string type;
    int offset;
    bool is_func;
    bool is_const;
    vector<param> func_params;
    string reg_add;
} var;

typedef struct{
    vector<var> vars;
    bool is_while;
    bool is_in_while;
    bool is_return;
} scope;

typedef struct {
    string entry_label;
    vector<pair<int,BranchLabelIndex>> next_list;
} while_data;

map <string, var> global_sym_table;
stack <scope> scopes;
stack<int> offsets;
stack <string> funcs_decl;
map<string, size_t> string_lengths;
vector<while_data> while_stack;


void initScope(bool is_while);
void initFunction(const string& name, const string& ret_type, const vector<param>& func_params, bool is_push_params);
void initVariable(const string& name, const string& type, bool isConst);
void initGlobalScope();
void closeScope(bool is_func);
string validID(const string &name);
void checkValidByte(int num);
void checkValidCast(const string& left, const string& right);
void checkNumeric(const string& type);
void checkBool(const string &type);
string checkFuncType(const string &funcName,const vector<param>& args_types=vector<param>());
string getNumericType(const string& left, const string& right);
void checkAssignTypes(const string& left, const string& right);
void checkNotConst(bool isConst);
void checkAssignName(const string& name,const string& right);
void checkReturnType(const string& type, bool is_return_exp);
void checkBreak();
void checkContinue();
void endGlobalScope();

#endif //HW3_UTILITIES_H
