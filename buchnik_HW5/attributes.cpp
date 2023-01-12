#include "attributes.hpp"
#include "hw3_output.hpp"
using namespace output;
using namespace std;

extern int yylineno;

#define MAX_BYTE 255

map<string,var> global_symbol_table = map<string,var>();
stack<symbol_table> scope_stack = stack<symbol_table>();
stack<int> offsets = stack<int>();
stack<string> func_types = stack<string>();
bool main_exists = false;
map<string, size_t> string_lengths = map<string, size_t>();

vector<whileAndSwitchData> whileAndSwitchStack = vector<whileAndSwitchData>();

var newFunc(string& name, string& type, int offset, bool is_func, vector<string>& types, vector<string>& params, string place){
    var f = var{name, type, offset, is_func, types, params, place};
    return f;
}

var newVar(string& name, string& type, int offset, bool is_func, string place){
    var v = var{name, type, offset, is_func, {}, {}, place};
    return v;
}

void initFunctionAndUpdateStack(string& name, string& type, vector<string>& types, vector<string>& params, bool is_push_params){
    if (global_symbol_table.count(name) != 0){
        errorDef(yylineno, name);
        exit(1);
    }
    if (name=="main" and type == "VOID" and types.empty())
        main_exists = true;
    var func = newFunc(name, type, 0, true, types, params);
    global_symbol_table.insert({name, func});
    scope_stack.top()._vars.push_back(func);
    if (is_push_params) {
        initAndPushSymbolTableAndOffset();
        for (int i = 0; i < static_cast<int>(params.size()); ++i) {
            if (type == "STRING" or (types[i] == "STRING" and name != "print")) {
                errorMismatch(yylineno);
                exit(1);
            }
            if (global_symbol_table.count(params[i]) != 0){//and global_symbol_table[params[i]]._is_func){
                errorDef(yylineno, params[i]);
                exit(1);
            }
            var param = newVar(params[i], types[i], -i - 1, false);
            global_symbol_table.insert({params[i], param});
            scope_stack.top()._vars.push_back(param);
        }
    }
    func_types.push(type);
}

void initVariableAndUpdateStack(string& name, string& type){
    if (global_symbol_table.count(name) != 0){
        errorDef(yylineno, name);
        exit(1);
    }
    var v = newVar(name, type, offsets.top()++, false);
    global_symbol_table.insert({name, v});
    scope_stack.top()._vars.push_back(v);
}

void initAndPushSymbolTableAndOffset(bool is_while, bool is_switch){
    symbol_table sym = symbol_table{vector<var>(), is_while, is_while, is_switch, is_switch};
    if(offsets.empty()){
        offsets.push(0);
    }
    else{
        int top_val = offsets.top();
        offsets.push(top_val);
    }
    if(!scope_stack.empty()){
        if(scope_stack.top()._is_while){
            sym._is_while = true;
        }
        if(scope_stack.top()._is_switch){
            sym._is_switch = true;
        }
    }
    scope_stack.push(sym);
}

void closeScope(bool is_func){
    endScope();
    offsets.pop();
    symbol_table sym = scope_stack.top();
    if (sym._im_while or sym._im_switch){
        whileAndSwitchStack.pop_back();
    }
    for (auto _var: sym._vars) {
        string type = _var._type;
        if (_var._is_func){
            type = makeFunctionType(_var._type, _var._types);
        }
        printID(_var._name, _var._offset, type);
        global_symbol_table.erase(_var._name);
    }
    scope_stack.pop();
    if (is_func){
        func_types.pop();
    }
}

void initGlobalScope(){
    initAndPushSymbolTableAndOffset();
    string name = "print";
    string type = "VOID";
    vector<string> types = {"STRING"};
    vector<string> params = {"input"};
    initFunctionAndUpdateStack(name, type, types, params, false);
    name = "printi";
    types = {"INT"};
    initFunctionAndUpdateStack(name, type, types, params, false);
}

void checkByte(int i){
    if (i > MAX_BYTE){
        errorByteTooLarge(yylineno, to_string(i));
        exit(1);
    }
}

void checkBool(const string &type) {
    if (type != "BOOL"){
        errorMismatch(yylineno);
        exit(1);
    }
}

void checkNumeric(const string &type) {
    if (type != "INT" and type != "BYTE"){
        errorMismatch(yylineno);
        exit(1);
    }
}

string returnNumericType(const string &type1, const string &type2) {
    string res = type1=="INT" or type2=="INT" ? "INT" : "BYTE";
    return res;
}

string IdCheck(const string &name) {
   if(global_symbol_table.count(name) == 0){
       errorUndef(yylineno, name);
       exit(1);
   }

   var& v = global_symbol_table[name];
   if (v._is_func){
       errorUndef(yylineno, name);
       exit(1);
   }

   return v._type;
}

string funcCheck(const string &name, const vector<string>& args_types) {
    if(global_symbol_table.count(name) == 0){
        errorUndefFunc(yylineno, name);
        exit(1);
    }

    var& f = global_symbol_table[name];
    if (!f._is_func){
        errorUndefFunc(yylineno, name);
        exit(1);
    }

    if (f._types.size() != args_types.size()){
        errorPrototypeMismatch(yylineno, name, f._types);
        exit(1);
    }

    for (int i = 0; i < static_cast<int>(f._types.size()) ; ++i) {
        if (f._types[i] != args_types[i] and !(f._types[i] == "INT" and args_types[i] == "BYTE")) {
            errorPrototypeMismatch(yylineno, name, f._types);
            exit(1);
        }
    }

    return f._type;
}

void checkAssignByType(const string& l_type,const string& r_type){
    if((l_type != r_type) and !(l_type == "INT" and r_type == "BYTE")){
        errorMismatch(yylineno);
        exit(1);
    }
}

void checkAssignByName(const string& name,const string& r_type){
    string l_type = global_symbol_table[name]._type;
    checkAssignByType(l_type, r_type);
}

void checkDec(const string& name){
    if(global_symbol_table.count(name) == 0 or global_symbol_table[name]._is_func){
        errorUndef(yylineno, name);
        exit(1);
    }
}

void checkReturnType(const string& type, bool is_return_exp){
    if(is_return_exp and func_types.top() == "VOID"){
        errorMismatch(yylineno);
        exit(1);
    }
    checkAssignByType(func_types.top(), type);
}

void checkBreak(){
    if (!scope_stack.top()._is_while and !scope_stack.top()._is_switch){
        errorUnexpectedBreak(yylineno);
        exit(1);
    }
}

void checkContinue(){
    if (!scope_stack.top()._is_while){
        errorUnexpectedContinue(yylineno);
        exit(1);
    }
}

void endGlobalScope(){
    if (!main_exists){
        errorMainMissing();
        exit(1);
    }
    closeScope();
}