//
// Created by tamir on 10/12/2021.
//

#include "utilities.hpp"
#include "hw3_output.hpp"


#define MAX_BYTE 255
using namespace std;
using namespace output;
extern int yylineno;

bool main_found = false;

var createFunction(const string &name, const string &ret_type, const vector <param> &func_params) {
    var func = var{name, ret_type, 0, true, false, func_params, ""};
    return func;
}

var newVariable(const string &name, const string &type, int offset, bool is_const) {
    var variable = var{name, type, offset, false, is_const, {},""};
    return variable;
}

void initScope(bool is_while) {
    scope sc = scope{vector<var>(), is_while, is_while};
    if (offsets.empty()) {
        offsets.push(0);
    } else {
        offsets.push(offsets.top());
    }
    if (!scopes.empty()) {
        if (scopes.top().is_while) {
            sc.is_while = true;
        }
    }
    scopes.push(sc);
}

void initFunction(const string &name, const string &ret_type, const vector <param> &func_params, bool is_push_params) {
    if (global_sym_table.count(name) != 0) {
        errorDef(yylineno, name);
        exit(1);
    }
    if (name == "main" && ret_type == "VOID" && func_params.empty()) {
        main_found = true;
    }
    var func = createFunction(name, ret_type, func_params);
    global_sym_table.insert({name, func});
    scopes.top().vars.push_back(func);
    if (is_push_params) {
        initScope(false);
        for (size_t i = 0; i < func_params.size(); ++i) {
            if (ret_type == "STRING" || (func_params[i].type == "STRING" && name != "print")) {
                errorMismatch(yylineno);
                exit(1);
            }
            if (global_sym_table.count(func_params[i].name) != 0) {
                errorDef(yylineno, func_params[i].name);
                exit(1);
            }
            var param = newVariable(func_params[i].name, func_params[i].type, -i - 1, func_params[i].isConst);
            global_sym_table.insert({func_params[i].name, param});
            scopes.top().vars.push_back(param);
        }
    }
    funcs_decl.push(ret_type);
}

void initVariable(const string &name, const string &type, bool isConst) {
    if (global_sym_table.count(name) != 0) {
        errorDef(yylineno, name);
        exit(1);
    }
    var v = newVariable(name, type, offsets.top()++, isConst);
    global_sym_table.insert({name, v});
    scopes.top().vars.push_back(v);
}

void initGlobalScope() {
    initScope(false);
    string name("print");
    string ret_type("VOID");
    vector <param> func_params = {{"input", "STRING", false}};
    initFunction(name, ret_type, func_params, false);
    name = "printi";
    func_params[0].type = "INT";
    initFunction(name, ret_type, func_params, false);
}

std::vector <string> getFuncArg(const vector <param> &func_params) {
    std::vector <string> retVec;
    for (const param &p : func_params) {
        retVec.push_back(p.type);
    }
    return retVec;
}

void closeScope(bool is_func) {
//    endScope();
    offsets.pop();
    scope current_scope = scopes.top();
    if(current_scope.is_in_while){
        while_stack.pop_back();
    }
    for (const auto &var: current_scope.vars) {
        string type = var.type;
        if (var.is_func) {
            vector <string> types = getFuncArg(var.func_params);
            type = makeFunctionType(var.type, types);
        }
//        printID(var.name, var.offset, type);
        global_sym_table.erase(var.name);
    }
    scopes.pop();
    if (is_func) {
        funcs_decl.pop();
    }
}

string validID(const string &name) {
    if (global_sym_table.count(name) == 0 || global_sym_table[name].is_func) {
        errorUndef(yylineno, name);
        exit(1);
    }
    return global_sym_table[name].type;
}

void checkValidByte(int num) {
    if (num > MAX_BYTE) {
        errorByteTooLarge(yylineno, to_string(num));
        exit(1);
    }
}

void checkValidCast(const string &left, const string &right) {
    if (!((left == "INT" || left == "BYTE") && (right == "INT" || right == "BYTE"))) {
        errorMismatch(yylineno);
        exit(1);
    }
}

void checkNumeric(const string &type) {
    if (type != "BYTE" && type != "INT") {
        errorMismatch(yylineno);
        exit(1);
    }
}

void checkBool(const string &type) {
    if (type != "BOOL") {
        errorMismatch(yylineno);
        exit(1);
    }
}


void checkIfFuncDeclared(const string &funcName) {
    if (global_sym_table.count(funcName) == 0) {
        errorUndefFunc(yylineno, funcName);
        exit(1);
    }
}

void checkIsFunc(const var &func, const string &funcName) {
    if (!func.is_func) {
        errorUndefFunc(yylineno, funcName);
        exit(1);
    }
}

void checkIfFuncParamsSizeMatch(const var &func, const string &funcName, const vector <string> &args_types) {
    if (func.func_params.size() != args_types.size()) {
        std::vector <string> expectedParams = getFuncArg(func.func_params);
        errorPrototypeMismatch(yylineno, funcName, expectedParams);
        exit(1);
    }
}

void checkIfFuncParamsTypeMatch(const var &func, const string &funcName, const vector <string> &args_types) {
    for (size_t i = 0; i < func.func_params.size(); i++) {
        if ((func.func_params[i].type != args_types[i]) &&
            !(func.func_params[i].type == "INT" && args_types[i] == "BYTE")) {
            std::vector <string> expectedParams = getFuncArg(func.func_params);
            errorPrototypeMismatch(yylineno, funcName, expectedParams);
            exit(1);
        }
    }
}

string checkFuncType(const string &funcName, const vector <param> &args_types) {
    checkIfFuncDeclared(funcName);
    var &func = global_sym_table[funcName];
    checkIsFunc(func, funcName);
    vector <string> types = getFuncArg(args_types);
    checkIfFuncParamsSizeMatch(func, funcName, types);
    checkIfFuncParamsTypeMatch(func, funcName, types);
    return func.type;
}

string getNumericType(const string &left, const string &right) {
    return left == "INT" || right == "INT" ? "INT" : "BYTE";
}

void checkAssignTypes(const string &left, const string &right) {
    if ((left != right) && !(left == "INT" && right == "BYTE")) {
        errorMismatch(yylineno);
        exit(1);
    }
}

void checkNotConst(bool isConst) {
    if (isConst) {
        errorConstDef(yylineno);
        exit(1);
    }
}

void checkAssignName(const string &name, const string &right) {
    if (global_sym_table.count(name) == 0 || global_sym_table[name].is_func) {
        errorUndef(yylineno, name);
        exit(1);
    }
    if (global_sym_table[name].is_const) {
        errorConstMismatch(yylineno);
        exit(1);
    }
    checkAssignTypes(global_sym_table[name].type, right);
}

void checkReturnType(const string &type, bool is_return_exp) {
    if (is_return_exp && funcs_decl.top() == "VOID") {
        errorMismatch(yylineno);
        exit(1);
    }
    checkAssignTypes(funcs_decl.top(), type);
}

void checkBreak() {
    if (!scopes.top().is_while) {
        errorUnexpectedBreak(yylineno);
        exit(1);
    }
}

void checkContinue() {
    if (!scopes.top().is_while) {
        errorUnexpectedContinue(yylineno);
        exit(1);
    }
}

void endGlobalScope() {
    if (!main_found) {
        errorMainMissing();
        exit(1);
    }
    closeScope(false);
}
