#include "ir.hpp"
#include <sstream>

using std::stringstream;

void emitPrintGlobal() {
    CodeBuffer &cb = CodeBuffer::instance();
    cb.emitGlobal("declare i32 @printf(i8*, ...)");
    cb.emitGlobal("declare void @exit(i32)");

    cb.emitGlobal(R"(@.int_specifier = constant [4 x i8] c"%d\0A\00")");
    cb.emitGlobal(R"(@.str_specifier = constant [4 x i8] c"%s\0A\00")");
    cb.emitGlobal(R"(@.error_div_by_zero = constant [23 x i8] c"Error division by zero\00")");

    cb.emitGlobal("define void @printi(i32) {");
    cb.emitGlobal("%spec_ptr = getelementptr [4 x i8], [4 x i8]* @.int_specifier, i32 0, i32 0");
    cb.emitGlobal("call i32 (i8*, ...) @printf(i8* %spec_ptr, i32 %0)");
    cb.emitGlobal("ret void");
    cb.emitGlobal("}");

    cb.emitGlobal("define void @print(i8*) {");
    cb.emitGlobal("%spec_ptr = getelementptr [4 x i8], [4 x i8]* @.str_specifier, i32 0, i32 0");
    cb.emitGlobal("call i32 (i8*, ...) @printf(i8* %spec_ptr, i8* %0)");
    cb.emitGlobal("ret void");
    cb.emitGlobal("}");
}

void printBuffers() {
    CodeBuffer &cb = CodeBuffer::instance();
    cb.printCodeBuffer();
    cb.printGlobalBuffer();
}

void byteBINOP(ushkud &ush, const ushkud &u1, const ushkud &u2, const string &op) {
    CodeBuffer &cb = CodeBuffer::instance();
//    string v1 = cb.freshVar();
//    cb.emit(v1 + " = trunc i32 " + u1.place + " to i8");
//    string v2 = cb.freshVar();
//    cb.emit(v2 + " = trunc i32 " + u2.place + " to i8");
    string v3 = cb.freshVar();
//    cb.emit(v3 + " = " + op + " i8 " + v1 + ", " + v2);
    cb.emit(v3 + " = " + op + " i8 " + u1.place + ", " + u2.place);
//    string v4 = cb.freshVar();
//    cb.emit(v4 + " = zext i8 " + v3 + " to i32");
//    ush.place = v4;
    ush.place = v3;
}

void add(ushkud &ush, const ushkud &u1, const ushkud &op_expr, const ushkud &u2) {
    CodeBuffer& cb = CodeBuffer::instance();

    string op = op_expr.s == "+" ? "add" : "sub";

    if (u1.type == "BYTE" and u2.type == "BYTE")
        byteBINOP(ush, u1, u2, op);
    else {
        string var = cb.freshVar();
        string v1 = u1.place;
        string v2 = u2.place;
        if (u1.type == "BYTE"){
            v1 = cb.freshVar();
            cb.emit(v1 + " = zext i8 " + u1.place + " to i32");
        } else if (u2.type == "BYTE"){
            v2 = cb.freshVar();
            cb.emit(v2 + " = zext i8 " + u2.place + " to i32");
        }
        cb.emit(var + " = " + op + " i32 " + v1 + ", " + v2);
        ush.place = var;
    }
}

void mul(ushkud &ush, const ushkud &u1, const ushkud &op_expr, const ushkud &u2) {
    CodeBuffer &cb = CodeBuffer::instance();
    if (op_expr.s == "/") {
        string cond = cb.freshVar();
        string type = u2.type == "INT" ? " i32 " : " i8 ";
        cb.emit(cond + " = icmp eq" + type + u2.place + ", 0");
        int location = cb.emit("br i1 " + cond + ", label @, label @");
        string true_list = cb.genLabel();
        cb.emit("call void (i8*) @print(i8* getelementptr ([23 x i8], [23 x i8]* @.error_div_by_zero, i32 0, i32 0))");
        cb.emit("call void (i32) @exit(i32 0)");

        string ret = func_types.top();
        if (ret == "INT") {
            cb.emit("ret i32 0");
        } else if (ret == "BYTE") {
            cb.emit("ret i8 0");
        } else if (ret == "BOOL") {
            cb.emit("ret i1 false");
        } else {
            cb.emit("ret void");
        }

        string false_list = cb.genLabel();
        cb.bpatch(CodeBuffer::makelist({location, FIRST}), true_list);
        cb.bpatch(CodeBuffer::makelist({location, SECOND}), false_list);
    }
    string op = op_expr.s == "*" ? "mul" : "sdiv";

    if (u1.type == "BYTE" and u2.type == "BYTE") {
        op = op == "sdiv" ? "udiv" : "mul";
        byteBINOP(ush, u1, u2, op);
    } else {
        string var = cb.freshVar();
        string v1 = u1.place;
        string v2 = u2.place;
        if (u1.type == "BYTE"){
            v1 = cb.freshVar();
            cb.emit(v1 + " = zext i8 " + u1.place + " to i32");
        } else if (u2.type == "BYTE"){
            v2 = cb.freshVar();
            cb.emit(v2 + " = zext i8 " + u2.place + " to i32");
        }
        cb.emit(var + " = " + op + " i32 " + v1 + ", " + v2);
        ush.place = var;
    }
}

void assignBool(ushkud &ush, bool val) {
    CodeBuffer &cb = CodeBuffer::instance();
    int location = cb.emit("br label @");
    if (val) {
        ush.true_list.emplace_back(location, FIRST);
    } else {
        ush.false_list.emplace_back(location, FIRST);
    }
}

void inverseBool(ushkud &ush, const ushkud &u1) {
    ush.true_list = u1.false_list;
    ush.false_list = u1.true_list;
}

void andBool(ushkud &ush, const ushkud &u1, const ushkud &marker, const ushkud &u2) {
    CodeBuffer &cb = CodeBuffer::instance();
    cb.bpatch(u1.true_list, marker.label);
    ush.true_list = u2.true_list;
    ush.false_list = CodeBuffer::merge(u1.false_list, u2.false_list);
}

void orBool(ushkud &ush, const ushkud &u1, const ushkud &marker, const ushkud &u2) {
    CodeBuffer &cb = CodeBuffer::instance();
    cb.bpatch(u1.false_list, marker.label);
    ush.false_list = u2.false_list;
    ush.true_list = CodeBuffer::merge(u1.true_list, u2.true_list);
}

void genN(ushkud &ush) {
    CodeBuffer &cb = CodeBuffer::instance();
    int location = cb.emit("br label @");
    ush.next_list.emplace_back(location, FIRST);
}

void genM(ushkud &ush) {
    CodeBuffer &cb = CodeBuffer::instance();
    string l = cb.genLabel();
    ush.label = l;
}

void loadNum(ushkud &ush, const ushkud &num) {
    CodeBuffer &cb = CodeBuffer::instance();
    string var = cb.freshVar();
    string type = ush.type;
    if (type == "BYTE") {
        cb.emit(var + " = add i8 " + to_string(num.i) + ", 0");
    } else {
        cb.emit(var + " = add i32 " + to_string(num.i) + ", 0");
    }
    ush.place = var;
}

void loadString(ushkud &ush, const ushkud &str) {
    CodeBuffer &cb = CodeBuffer::instance();
    string var = cb.freshGlobalVar();
    size_t len = str.s.size();
    string clean_str = str.s.substr(1, len - 2);
    cb.emitGlobal(
            var + " = private unnamed_addr constant [" + to_string(len - 1) + " x i8] c\"" + clean_str + "\\00\"");
    ush.place = var;
    string_lengths[var] = len - 1;
}

void assignNewID(ushkud &id, bool assign) {
    CodeBuffer &cb = CodeBuffer::instance();
    string var = cb.freshVar();
    string type = global_symbol_table[id.s]._type;
    if (not assign || type != "BOOL") {
        if (type == "BOOL") {
            string temp_var = cb.freshVar();
            cb.emit(temp_var + " = zext i1 false to i32");
            cb.emit(var + " = alloca i32");
            cb.emit("store i32 " + temp_var + ", i32* " + var);
        } else {
            cb.emit(var + " = alloca i32");
            cb.emit("store i32 0, i32* " + var);
        }
    }
    global_symbol_table[id.s].place = var;
}

void storeID(ushkud &ush, const ushkud &exp) {
    CodeBuffer &cb = CodeBuffer::instance();
    if (exp.type == "BOOL") {
        int loc0 = cb.emit("br label @");

        string true_label = cb.genLabel();
        cb.bpatch(CodeBuffer::makelist(make_pair(loc0, FIRST)), true_label);
        string bool_true = cb.freshVar();
        cb.emit(bool_true + " = add i1 0, true");
        int ret_true = cb.emit("br label @");

        string false_label = cb.genLabel();
        string bool_false = cb.freshVar();
        cb.emit(bool_false + " = add i1 0, false");
        int ret_false = cb.emit("br label @");

        string result = cb.genLabel();
        string phi = cb.freshVar();
        cb.emit(phi + " = phi i1 [" + bool_true + ", %" + true_label + "], [" + bool_false + ", %" + false_label +
                "]");

        string temp_var = cb.freshVar();
        cb.emit(temp_var + " = zext i1 " + phi + " to i32");
        string var = cb.freshVar();
        cb.emit(var + " = alloca i32");
        cb.emit("store i32 " + temp_var + ", i32* " + var);
        global_symbol_table[ush.s].place = var;

        cb.bpatch(CodeBuffer::makelist(make_pair(ret_true, FIRST)), result);
        cb.bpatch(CodeBuffer::makelist(make_pair(ret_false, FIRST)), result);
        cb.bpatch(exp.true_list, true_label);
        cb.bpatch(exp.false_list, false_label);
    } else {
        string var = cb.freshVar();
        if (exp.type == "BYTE") {
            cb.emit(var + " = zext i8 " + exp.place + " to i32");
        } else {
            var = exp.place;
        }
        cb.emit("store i32 " + var + ", i32* " + global_symbol_table[ush.s].place);
    }
}

void loadID(ushkud &ush, const ushkud &id) {
    CodeBuffer &cb = CodeBuffer::instance();
    string type = global_symbol_table[id.s]._type;
    string var = cb.freshVar();
    if (type == "BOOL") {
        string bool_ret = cb.freshVar();
        if (global_symbol_table[id.s]._offset >= 0) {
            string temp_var = cb.freshVar();
            cb.emit(temp_var + " = load i32, i32* " + global_symbol_table[id.s].place);
            cb.emit(var + " = trunc i32 " + temp_var + " to i1");
        } else {
            cb.emit(var + " = add i1 0, " + global_symbol_table[id.s].place);
        }
        cb.emit(bool_ret + " = " + "icmp eq i1 " + var + ", true");
        int address = cb.emit("br i1 " + bool_ret + ", label @, label @");
        ush.true_list.emplace_back(address, FIRST);
        ush.false_list.emplace_back(address, SECOND);
    } else {
        if (global_symbol_table[id.s]._offset >= 0) {
            if (type == "INT") {
                cb.emit(var + " = load i32, i32* " + global_symbol_table[id.s].place);
            } else {
                string temp_var = cb.freshVar();
                cb.emit(temp_var + " = load i32, i32* " + global_symbol_table[id.s].place);
                cb.emit(var + " = trunc i32 " + temp_var + " to i8");
            }
            ush.place = var;
        } else {
            ush.place = global_symbol_table[id.s].place;
        }
    }
}

void relComp(ushkud &ush, const ushkud &u1, const ushkud &u2, const string &opExpr) {
    CodeBuffer &cb = CodeBuffer::instance();
    string op;
    if (opExpr == "<") {
        op = "slt";
    } else if (opExpr == "<=") {
        op = "sle";
    } else if (opExpr == ">") {
        op = "sgt";
    } else if (opExpr == ">=") {
        op = "sge";
    } else if (opExpr == "==") {
        op = "eq";
    } else {
        op = "ne";
    }
    string temp_var1 = u1.place;
    string temp_var2 = u2.place;
    if (u1.type == "BYTE") {
        temp_var1 = cb.freshVar();
        cb.emit(temp_var1 + " = zext i8 " + u1.place + " to i32");
    }
    if (u2.type == "BYTE") {
        temp_var2 = cb.freshVar();
        cb.emit(temp_var2 + " = zext i8 " + u2.place + " to i32");
    }
    string compar = cb.freshVar();
    cb.emit(compar + " = icmp " + op + " i32 " + temp_var1 + ", " + temp_var2);
    int location = cb.emit("br i1 " + compar + ", label @, label @");

    ush.true_list.emplace_back(location, FIRST);
    ush.false_list.emplace_back(location, SECOND);
}

void boolResult(ushkud &expr) {
    if (expr.type != "BOOL") return;
    CodeBuffer &cb = CodeBuffer::instance();

    string v1 = cb.freshVar();
    string true_label = cb.genLabel();
    cb.emit(v1 + " = add i1 0, true");
    int location1 = cb.emit("br label @");

    string v2 = cb.freshVar();
    string false_label = cb.genLabel();
    cb.emit(v2 + " = add i1 0, false");
    int location2 = cb.emit("br label @");

    string phi = cb.freshVar();
    string result = cb.genLabel();
    cb.emit(phi + " = phi i1 [" + v1 + ", %" + true_label + "], [" + v2 + ", %" + false_label + "]");

    cb.bpatch(CodeBuffer::makelist(make_pair(location1, FIRST)), result);
    cb.bpatch(CodeBuffer::makelist(make_pair(location2, FIRST)), result);
    cb.bpatch(expr.true_list, true_label);
    cb.bpatch(expr.false_list, false_label);
    expr.place = phi;
}

void updateNext(ushkud &statement, const ushkud &statements) {
    statement.next_list = statements.next_list;
}

void patchStatements(const ushkud &statements, const ushkud &marker) {
    CodeBuffer &cb = CodeBuffer::instance();
    cb.bpatch(statements.next_list, marker.label);
}

void retFunction(const ushkud &expr) {
    CodeBuffer &cb = CodeBuffer::instance();

    if (expr.type == "BOOL") {

        string v1 = cb.freshVar();
        string true_label = cb.genLabel();
        cb.emit(v1 + " = add i1 0, true");
        int location1 = cb.emit("br label @");

        string v2 = cb.freshVar();
        string false_label = cb.genLabel();
        cb.emit(v2 + " = add i1 0, false");
        int location2 = cb.emit("br label @");

        string phi = cb.freshVar();
        string result = cb.genLabel();
        cb.emit(phi + " = phi i1 [" + v1 + ", %" + true_label + "], [" + v2 + ", %" + false_label + "]");

        cb.emit("ret i1 " + phi);

        cb.bpatch(CodeBuffer::makelist(make_pair(location1, FIRST)), result);
        cb.bpatch(CodeBuffer::makelist(make_pair(location2, FIRST)), result);
        cb.bpatch(expr.true_list, true_label);
        cb.bpatch(expr.false_list, false_label);
    } else {
        if (expr.type == "BYTE") {
            string var = expr.place; // TODO edited from  here
            if (func_types.top() == "INT"){
                var = cb.freshVar();
                cb.emit(var + " = zext i8 " + expr.place + " to i32");
                cb.emit("ret i32 " + var);
            } else{ // TODO edited until  here
                cb.emit("ret i8 " + var);
            }
        } else {
            cb.emit("ret i32 " + expr.place);
        }
    }
    scope_stack.top()._is_return = true;
}

void retEmptyFunction() {
    CodeBuffer &cb = CodeBuffer::instance();
    cb.emit("ret void");
    scope_stack.top()._is_return = true;
}

void patchIf(ushkud &u, const ushkud &n, const ushkud &m1, const ushkud &open_if, const ushkud &m2) {
    CodeBuffer &cb = CodeBuffer::instance();
    cb.bpatch(n.next_list, m1.label);
    cb.bpatch(open_if.true_list, m2.label);
    u.next_list = CodeBuffer::merge(u.next_list, open_if.false_list);
}

void
patchIfElse(ushkud &u, const ushkud &n, const ushkud &m1, const ushkud &open_if, const ushkud &m2, const ushkud &s1,
            const ushkud &m3,
            const ushkud &s2) {
    CodeBuffer &cb = CodeBuffer::instance();
    cb.bpatch(n.next_list, m1.label);
    cb.bpatch(open_if.true_list, m2.label);
    cb.bpatch(open_if.false_list, m3.label);
    u.next_list = CodeBuffer::merge(s1.next_list, s2.next_list);
}

void nextBreak() {
    CodeBuffer &cb = CodeBuffer::instance();
    int location = cb.emit("br label @");
    whileAndSwitchStack.back().next_list.emplace_back(location, FIRST);
}

void nextContinue() {
    CodeBuffer &cb = CodeBuffer::instance();
    auto it = whileAndSwitchStack.rbegin();
    while (it != whileAndSwitchStack.rend()){
        if (!it->entry_label.empty()){
            cb.emit("br label %" + it->entry_label);
            break;
        }
        ++it;
    }
}

void patchWhile(ushkud &u, const ushkud &marker, const ushkud &statement) {
    CodeBuffer &cb = CodeBuffer::instance();
    cb.bpatch(statement.next_list, marker.label);
    u.next_list = CodeBuffer::merge(u.next_list, whileAndSwitchStack.back().next_list);
}

void patchNextSwitch(ushkud &u) {
    u.next_list = CodeBuffer::merge(u.next_list, whileAndSwitchStack.back().next_list);
}

void patchSwitch(ushkud &u, const ushkud &N1, const ushkud &M, const ushkud &exp, const ushkud &N2, ushkud &cl) {
    CodeBuffer &cb = CodeBuffer::instance();
    cb.bpatch(N1.next_list, M.label);
    string label = cb.genLabel();
    cb.bpatch(N2.next_list, label);
    bool first = true;
    int location = -1;
    pair<int, string> p;
    while (not cl.switch_values.empty()) {
        if (!first) {
            string false_label = cb.genLabel();
            cb.bpatch(CodeBuffer::makelist(make_pair(location, SECOND)), false_label);
        }
        first = false;
        p = cl.switch_values.back();
        cl.switch_values.pop_back();
        string var = cb.freshVar();
        string true_label = cl.case_label_list.top();
        cl.case_label_list.pop();
        if (p.second == "default") {
            cb.emit("br label %" + true_label);
        } else {
            cb.emit(var + " = icmp eq i32 " + to_string(p.first) + ", " + exp.place);
            location = cb.emit("br i1 " + var + ", label %" + true_label + ", label @");
        }
    }
    if (p.second != "default"){
        u.next_list = CodeBuffer::merge(cl.next_list, CodeBuffer::makelist(make_pair(location, SECOND)));
    }
    else{
        u.next_list = cl.next_list;
    }
}

void pushLastCase(ushkud &u, const ushkud &case_decl) {
    u.case_label_list.push(case_decl.label);
    u.switch_values.emplace_back(case_decl.value, "");
    u.next_list = case_decl.next_list;
}

void pushCase(ushkud &u, const ushkud &case_decl, const ushkud &case_list) {
    CodeBuffer &cb = CodeBuffer::instance();
    cb.bpatch(case_decl.next_list, case_list.case_label_list.top());
    u.next_list = case_list.next_list;
    u.case_label_list = case_list.case_label_list;
    u.case_label_list.push(case_decl.label);
    u.switch_values = case_list.switch_values;
    u.switch_values.emplace_back(case_decl.value, "");
}

void initWhileAndSwitchData(const string &label) {
    whileAndSwitchData d = {label, {}};
    whileAndSwitchStack.push_back(d);
}

void openFunction(const ushkud &ret_type, const ushkud &id, const ushkud &formals) {
    CodeBuffer &cb = CodeBuffer::instance();
    string return_type = "i32";
    if (ret_type.type == "VOID") {
        return_type = "void";
    } else if (ret_type.type == "BYTE") {
        return_type = "i8";
    } else if (ret_type.type == "BOOL") {
        return_type = "i1";
    }
    stringstream params;
    params << "";
    string arg_type = "i32 ";
    for (size_t i = 0; i < formals.params_types.size(); ++i) {
        if (formals.params_types[i] == "STRING") {
            arg_type = "i8* ";
        } else if (formals.params_types[i] == "BYTE") {
            arg_type = "i8 ";
        } else if (formals.params_types[i] == "BOOL") {
            arg_type = "i1 ";
        } else {
            arg_type = "i32 ";
        }
        string var = cb.freshVar();
        params << arg_type << var;
        global_symbol_table[formals.params_names[i]].place = var;
        if (formals.params_types.size() - 1 != i) {
            params << ", ";
        }
    }
    cb.emit("define " + return_type + " @" + id.s + "(" + params.str() + ") {");
}

void closeFunction(const ushkud &ret_type, const ushkud &statements) {
    CodeBuffer &cb = CodeBuffer::instance();
    if (not scope_stack.top()._is_return) {
        string label = cb.genLabel();
        if (ret_type.type == "VOID") {
            cb.emit("ret void");
        } else if (ret_type.type == "BOOL") {
            cb.emit("ret i1 false");
        } else if (ret_type.type == "BYTE") {
            cb.emit("ret i8 0");
        } else {
            cb.emit("ret i32 0");
        }
        cb.bpatch(statements.next_list, label);
    }
    cb.emit("}");
}

void callFunction(ushkud &u, const ushkud &id, const ushkud &exp_list, bool no_params) {
    CodeBuffer &cb = CodeBuffer::instance();

    stringstream params;
    vector<string> func_types = global_symbol_table[id.s]._types;
    if (not no_params) {
        params << "(";
        for (size_t i = 0; i < func_types.size(); ++i) {
            if (func_types[i] == "STRING") {
                params << "i8*";
            } else if (func_types[i] == "BOOL") {
                params << "i1";
            } else if (func_types[i] == "BYTE") {
                params << "i8";
            } else {
                params << "i32";
            }
            if (func_types.size() - 1 != i) {
                params << ", ";
            }
        }
        params << ") @" << id.s << "(";
        for (size_t i = 0; i < func_types.size(); ++i) {
            if (func_types[i] == "STRING") {
                string length = to_string(string_lengths[exp_list.place_vec[i]]);
                params << "i8* getelementptr ([" << length << " x i8], [" << length << " x i8]* "
                       << exp_list.place_vec[i] << ", i32 0, i32 0)";
            } else if (func_types[i] == "BOOL") {
                params << "i1 " << exp_list.place_vec[i];
            } else if (func_types[i] == "BYTE") {
                params << "i8 " << exp_list.place_vec[i];
            } else {
                string v = exp_list.place_vec[i];
                if (exp_list.params_types[i] == "BYTE"){
                    v = cb.freshVar();
                    cb.emit(v + " = zext i8 " + exp_list.place_vec[i] + " to i32");
                }
                params << "i32 " << v;
            }
            if (exp_list.params_types.size() - 1 != i) {
                params << ", ";
            }
        }
        params << ")";
    } else {
        params << "@" << id.s << "()";
    }



    if (global_symbol_table[id.s]._type == "VOID") {
        cb.emit("call void " + params.str());
    } else if (global_symbol_table[id.s]._type == "BOOL") {
        string var = cb.freshVar();
        cb.emit(var + " = call i1 " + params.str());
        u.place = var;
    } else if (global_symbol_table[id.s]._type == "BYTE") {
        string var = cb.freshVar();
        cb.emit(var + " = call i8 " + params.str());
        u.place = var;
    } else {
        string var = cb.freshVar();
        cb.emit(var + " = call i32 " + params.str());
        u.place = var;
    }
}

void funcAsBoolExp(ushkud &u, const ushkud &call) {
    if (call.type != "BOOL") return;
    CodeBuffer &cb = CodeBuffer::instance();
    string compar = cb.freshVar();
    cb.emit(compar + " = icmp eq i1 " + call.place + ", true");
    int location = cb.emit("br i1 " + compar + ", label @, label @");
    u.true_list.emplace_back(location, FIRST);
    u.false_list.emplace_back(location, SECOND);
}