#ifndef COMPI_HW5_ATTRIBUTES_H
#define COMPI_HW5_ATTRIBUTES_H


#include <vector>
#include <string>
#include <stack>
#include <map>
#include "bp.hpp"

using namespace std;

typedef struct {
    int i;
    char b;
    string s;
    string type;
    vector<string> params_types;
    vector<string> params_names;
    string place;
    vector<string> place_vec;
    vector<pair<int,BranchLabelIndex>> true_list;
    vector<pair<int,BranchLabelIndex>> false_list;
    vector<pair<int,BranchLabelIndex>> next_list;
    string label;
    stack<string> case_label_list;
    vector<pair<int,string>> switch_values;
    int value;
} ushkud;

#define YYSTYPE ushkud

typedef struct{
    string _name;
    string _type;
    int _offset;
    bool _is_func;
    vector<string> _types;
    vector<string> _params;
    string place;
} var;

typedef struct{
    vector<var> _vars;
    bool _im_while;
    bool _is_while;
    bool _im_switch;
    bool _is_switch;
    bool _is_return;
} symbol_table;

typedef struct whileAndSwitchData{
    string entry_label;
    vector<pair<int,BranchLabelIndex>> next_list;
}whileAndSwitchData;

extern map<string,var> global_symbol_table;
extern stack<symbol_table> scope_stack;
extern stack<int> offsets;
extern stack<string> func_types;
extern bool main_exists;
extern map<string, size_t> string_lengths;
extern vector<whileAndSwitchData> whileAndSwitchStack;

var newFunc(string& name, string& type, int offset, bool is_func, vector<string>& types, vector<string>& params, string place="");
var newVar(string& name, string& type, int offset, bool is_func, string place="");
void initFunctionAndUpdateStack(string& name, string& type, vector<string>& types, vector<string>& params, bool is_push_params = true);
void initVariableAndUpdateStack(string& name, string& type);
void initAndPushSymbolTableAndOffset(bool is_while = false, bool is_switch = false);
void closeScope(bool is_func = false);
void initGlobalScope();
void checkByte(int i);
void checkBool(const string& type);
void checkNumeric(const string& type);
string returnNumericType(const string& type1, const string& type2);
string IdCheck(const string& name);
string funcCheck(const string& name, const vector<string>& args_types = vector<string>());
void checkAssignByType(const string& l_type, const string& r_type);
void checkAssignByName(const string& name,const string& r_type);
void checkDec(const string& name);
void checkReturnType(const string& type, bool is_return_exp = false);
void checkBreak();
void checkContinue();
void endGlobalScope();

#endif //COMPI_HW5_ATTRIBUTES_H
