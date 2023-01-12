//
// Created by tamir on 11/01/2022.
//

#include "ir_translation.h"


void assignNewReg(STYPE &item, bool is_assign) {
    CodeBuffer &buffer = CodeBuffer::instance();
    string type = global_sym_table[item.name].type;
    string reg = buffer.newTemp();
//    if(!is_assign || (type != "BOOL" && !item.isConst)){
    if (!is_assign || (type != "BOOL")) {
        if (type == "BOOL") { // we init bool to false with bit extension to 32bit
            string temp_reg = buffer.newTemp();
            buffer.emit(temp_reg + " = zext i1 false to i32");
            buffer.emit(reg + " = alloca i32");
            buffer.emit("store i32 " + temp_reg + ", i32* " + reg);
        } else { //we init int to 0
            buffer.emit(reg + " = alloca i32");
            buffer.emit("store i32 0, i32* " + reg);
        }
    }
    global_sym_table[item.name].reg_add = reg;
}

string globalBoolCalc(const STYPE &src) {
    CodeBuffer &buffer = CodeBuffer::instance();
    string reg1 = buffer.newTemp();
    string true_lbl = buffer.genLabel();
    buffer.emit(reg1 + " = add i1 0, true");
    int location1 = buffer.emit("br label @");

    string reg2 = buffer.newTemp();
    string false_lbl = buffer.genLabel();
    buffer.emit(reg2 + " = add i1 0, false");
    int location2 = buffer.emit("br label @");

    string phi = buffer.newTemp();
    string result = buffer.genLabel();
    buffer.emit(phi + " = phi i1 [" + reg1 + ", %" + true_lbl + "], [" + reg2 + ", %" + false_lbl + "]");

    buffer.bpatch(CodeBuffer::makelist(make_pair(location1, FIRST)),
                  result); //update jump after first eval - if true - to result
    buffer.bpatch(CodeBuffer::makelist(make_pair(location2, FIRST)),
                  result); //update jump after second eval - if false - to result
    buffer.bpatch(src.true_list, true_lbl);
    buffer.bpatch(src.false_list, false_lbl);
    return phi;
}

void storeValInReg(STYPE &dst, const STYPE &src, bool is_const) {
    CodeBuffer &buffer = CodeBuffer::instance();
    if (src.type == "BOOL") {
        int lbl_location = buffer.emit("br label @");

        string true_lbl = buffer.genLabel();
        buffer.bpatch(CodeBuffer::makelist(make_pair(lbl_location, FIRST)), true_lbl);
        string true_val = buffer.newTemp();
        buffer.emit(true_val + " = add i1 0, true");
        int return_true = buffer.emit("br label @");

        string false_lbl = buffer.genLabel();
        string false_val = buffer.newTemp();
        buffer.emit(false_val + " = add i1 0, false");
        int return_false = buffer.emit("br label @");

        string result = buffer.genLabel();
        string phi = buffer.newTemp();
        buffer.emit(phi + " = phi i1 [" + true_val + ", %" + true_lbl + "], [" + false_val + ", %" + false_lbl + "]");

        string temp = buffer.newTemp();
        buffer.emit(temp + " = zext i1 " + phi + " to i32");
        string reg = buffer.newTemp();
        buffer.emit(reg + " = alloca i32");
        buffer.emit("store i32 " + temp + ", i32* " + reg);
        global_sym_table[dst.name].reg_add = reg;

        buffer.bpatch(CodeBuffer::makelist(make_pair(return_true, FIRST)), result);
        buffer.bpatch(CodeBuffer::makelist(make_pair(return_false, FIRST)), result);
        buffer.bpatch(src.true_list, true_lbl);
        buffer.bpatch(src.false_list, false_lbl);
    } else {
//        if(is_const && src.is_raw_num){
//            global_sym_table[dst.name].reg_add = "RAW_NUM";
//            dst.value = src.value;
//        } else {
        string reg = buffer.newTemp();
//            string org_add = src.reg_add == "RAW_NUM"? to_string(src.value) : src.reg_add;
        if (src.type == "BYTE") {
            buffer.emit(reg + " = zext i8 " + src.reg_add + " to i32");
        } else {
            reg = src.reg_add;
        }
        buffer.emit("store i32 " + reg + ", i32* " + global_sym_table[dst.name].reg_add);
//        }
    }
}

//void loadID(STYPE &dst, const STYPE &src) {
//    CodeBuffer &buffer = CodeBuffer::instance();
//    string type = global_sym_table[src.name].type;
//    string reg = buffer.newTemp();
//    if (type == "BOOL") {
//        string bool_ret = buffer.newTemp();
//        if (global_sym_table[src.name].offset >= 0) { //local var
//            string temp_reg = buffer.newTemp();
//            buffer.emit(temp_reg + " = load i32, i32* " + global_sym_table[src.name].reg_add);
//            buffer.emit(reg + " = trunc i32 " + temp_reg + " to i1");
//        } else {
//            buffer.emit(reg + " = add i1 0, " + global_sym_table[src.name].reg_add);
//        }
//        buffer.emit(bool_ret + " = " + "icmp eq i1 " + reg + ", true");
//        int address = buffer.emit("br i1 " + bool_ret + ", label @, label @");
//        dst.true_list.emplace_back(address, FIRST);
//        dst.false_list.emplace_back(address, SECOND);
//    } else {
//        if (global_sym_table[src.name].offset >= 0) {
//            if (type == "INT") {
//                if(global_sym_table[src.name].reg_add != "RAW_NUM"){
//                    buffer.emit(reg + " = load i32, i32* " + global_sym_table[src.name].reg_add);
//                } else {
//                    reg = to_string(src.value);
//                }
//            } else {
//                if(global_sym_table[src.name].reg_add != "RAW_NUM"){
//                    string temp_var = buffer.newTemp();
//                    buffer.emit(temp_var + " = load i32, i32* " + global_sym_table[src.name].reg_add);
//                    buffer.emit(reg + " = trunc i32 " + temp_var + " to i8");
//                } else {
//                    reg = to_string(src.value);
//                }
//            }
//            dst.reg_add = reg;
//        } else {
//            if(global_sym_table[src.name].reg_add != "RAW_NUM"){
//                dst.reg_add = global_sym_table[src.name].reg_add;
//            } else {
//                dst.reg_add = to_string(src.value);
//            }
//        }
//    }
//}

void loadID(STYPE &dst, const STYPE &src) {
    CodeBuffer &buffer = CodeBuffer::instance();
    string type = global_sym_table[src.name].type;
    string var = buffer.newTemp();
    if (type == "BOOL") {
        string bool_ret = buffer.newTemp();
        if (global_sym_table[src.name].offset >= 0) {
            string temp_var = buffer.newTemp();
            buffer.emit(temp_var + " = load i32, i32* " + global_sym_table[src.name].reg_add);
            buffer.emit(var + " = trunc i32 " + temp_var + " to i1");
        } else {
            buffer.emit(var + " = add i1 0, " + global_sym_table[src.name].reg_add);
        }
        buffer.emit(bool_ret + " = " + "icmp eq i1 " + var + ", true");
        int address = buffer.emit("br i1 " + bool_ret + ", label @, label @");
        dst.true_list.emplace_back(address, FIRST);
        dst.false_list.emplace_back(address, SECOND);
    } else {
        if (global_sym_table[src.name].offset >= 0) {
            if (type == "INT") {
                buffer.emit(var + " = load i32, i32* " + global_sym_table[src.name].reg_add);
            } else {
                string temp_var = buffer.newTemp();
                buffer.emit(temp_var + " = load i32, i32* " + global_sym_table[src.name].reg_add);
                buffer.emit(var + " = trunc i32 " + temp_var + " to i8");
            }
            dst.reg_add = var;
        } else {
            dst.reg_add = global_sym_table[src.name].reg_add;
        }
    }
}

void nextListUpdate(STYPE &statement, const STYPE &statements) {
    statement.next_list = statements.next_list;
}

void bpatchNextList(const STYPE &statements, const STYPE &marker) {
    CodeBuffer &buffer = CodeBuffer::instance();
    buffer.bpatch(statements.next_list, marker.label);
}

void markerN(STYPE &src) {
    CodeBuffer &buffer = CodeBuffer::instance();
    int location = buffer.emit("br label @");
    src.next_list.emplace_back(location, FIRST);
}

void markerM(STYPE &src) {
    CodeBuffer &buffer = CodeBuffer::instance();
    string lbl = buffer.genLabel();
    src.label = lbl;
}

void returnEmptyFunc() {
    CodeBuffer &buffer = CodeBuffer::instance();
    buffer.emit("ret void");
    scopes.top().is_return = true;
}

void returnFunc(const STYPE &src) {
    CodeBuffer &buffer = CodeBuffer::instance();

    if (src.type == "BOOL") {

        string res = globalBoolCalc(src);
        buffer.emit("ret i1 " + res);
    } else {
        if (src.type == "BYTE") {
            string reg = src.reg_add;
            if (funcs_decl.top() == "INT") {
                reg = buffer.newTemp();
                buffer.emit(reg + " = zext i8 " + src.reg_add + " to i32");
                buffer.emit("ret i32 " + reg);
            } else {
                buffer.emit("ret i8 " + reg);
            }
        } else {
            buffer.emit("ret i32 " + src.reg_add);
        }
    }
    scopes.top().is_return = true;
}

void bpatchSingleCond(STYPE &src, const STYPE &marker_n, const STYPE &marker_m1, const STYPE &exp, const STYPE &marker_m2) {
    CodeBuffer &buffer = CodeBuffer::instance();
    buffer.bpatch(marker_n.next_list, marker_m1.label);
    buffer.bpatch(exp.true_list, marker_m2.label);
    src.next_list = CodeBuffer::merge(src.next_list, exp.false_list);
}

void
bpatchDoubleCond(STYPE &src, const STYPE &marker_n, const STYPE &marker_m1, const STYPE &exp, const STYPE &marker_m2,
                 const STYPE &statements1,
                 const STYPE &marker_m3,
                 const STYPE &statements2) {
    CodeBuffer &buffer = CodeBuffer::instance();
    buffer.bpatch(marker_n.next_list, marker_m1.label);
    buffer.bpatch(exp.true_list, marker_m2.label);
    buffer.bpatch(exp.false_list, marker_m3.label);
    src.next_list = CodeBuffer::merge(statements1.next_list, statements2.next_list);
}

void initWhile(const string &label) {
    while_data data = {label, {}};
    while_stack.push_back(data);
}

void bpatchWhile(STYPE &src, const STYPE &marker_m, const STYPE &statement) {
    CodeBuffer &buffer = CodeBuffer::instance();
    buffer.bpatch(statement.next_list, marker_m.label);
    src.next_list = CodeBuffer::merge(src.next_list, while_stack.back().next_list);
}

void getNextBreak() {
    CodeBuffer &buffer = CodeBuffer::instance();
    int location = buffer.emit("br label @");
    while_stack.back().next_list.emplace_back(location, FIRST);
}

void getNextContinue() {
    CodeBuffer &buffer = CodeBuffer::instance();
    auto it = while_stack.rbegin();
    while (it != while_stack.rend()) {
        if (!it->entry_label.empty()) {
            buffer.emit("br label %" + it->entry_label);
            break;
        }
        ++it;
    }
}

void getBoolResult(STYPE &expr) {
    if (expr.type != "BOOL") return;
    CodeBuffer &buffer = CodeBuffer::instance();

    string res = globalBoolCalc(expr);
    expr.reg_add = res;
}

void byte_operation(STYPE &res, const STYPE &var1, const STYPE &var2, const string &op) {
    CodeBuffer &buffer = CodeBuffer::instance();
    string reg_res = buffer.newTemp();
    buffer.emit(reg_res + " = " + op + " i8 " + var1.reg_add + ", " + var2.reg_add);
    res.reg_add = reg_res;
}

void make_add_sub(STYPE &res, const STYPE &val1, const STYPE &op, const STYPE &val2) {
    CodeBuffer &buffer = CodeBuffer::instance();

    string operation = op.name == "+" ? "add" : "sub";

    if (val1.type == "BYTE" and val2.type == "BYTE") {
        byte_operation(res, val1, val2, operation);
    } else {
        string reg_res = buffer.newTemp();
        string reg1 = val1.reg_add;
        string reg2 = val2.reg_add;
        if (val1.type == "BYTE") {
            reg1 = buffer.newTemp();
            buffer.emit(reg1 + " = zext i8 " + val1.reg_add + " to i32");
        } else if (val2.type == "BYTE") {
            reg2 = buffer.newTemp();
            buffer.emit(reg2 + " = zext i8 " + val2.reg_add + " to i32");
        }
        buffer.emit(reg_res + " = " + operation + " i32 " + reg1 + ", " + reg2);
        res.reg_add = reg_res;
    }
}

void make_mul_div(STYPE &res, const STYPE &var1, const STYPE &op, const STYPE &var2) {
    CodeBuffer &buffer = CodeBuffer::instance();
    if (op.name == "/") {
        string cond = buffer.newTemp();
        string type = var2.type == "INT" ? " i32 " : " i8 ";
        buffer.emit(cond + " = icmp eq" + type + var2.reg_add + ", 0");
        int location = buffer.emit("br i1 " + cond + ", label @, label @");
        string true_list = buffer.genLabel();
        buffer.emit(
                "call void (i8*) @print(i8* getelementptr ([23 x i8], [23 x i8]* @.error_division_by_zero, i32 0, i32 0))");
        buffer.emit("call void (i32) @exit(i32 0)");

        string ret = funcs_decl.top();
        if (ret == "INT") {
            buffer.emit("ret i32 0");
        } else if (ret == "BYTE") {
            buffer.emit("ret i8 0");
        } else if (ret == "BOOL") {
            buffer.emit("ret i1 false");
        } else {
            buffer.emit("ret void");
        }

        string false_list = buffer.genLabel();
        buffer.bpatch(CodeBuffer::makelist({location, FIRST}), true_list);
        buffer.bpatch(CodeBuffer::makelist({location, SECOND}), false_list);
    }
    string operation = op.name == "*" ? "mul" : "sdiv";

    if (var1.type == "BYTE" and var2.type == "BYTE") {
        operation = operation == "sdiv" ? "udiv" : "mul";
        byte_operation(res, var1, var2, operation);
    } else {
        string reg_res = buffer.newTemp();
        string reg1 = var1.reg_add;
        string reg2 = var2.reg_add;
        if (var1.type == "BYTE") {
            reg1 = buffer.newTemp();
            buffer.emit(reg1 + " = zext i8 " + var1.reg_add + " to i32");
        } else if (var2.type == "BYTE") {
            reg2 = buffer.newTemp();
            buffer.emit(reg2 + " = zext i8 " + var2.reg_add + " to i32");
        }
        buffer.emit(reg_res + " = " + operation + " i32 " + reg1 + ", " + reg2);
        res.reg_add = reg_res;
    }
}

void funcAsBoolExp(STYPE &src, const STYPE &call) {
    if (call.type != "BOOL") return;
    CodeBuffer &buffer = CodeBuffer::instance();
    string compare = buffer.newTemp();
    buffer.emit(compare + " = icmp eq i1 " + call.reg_add + ", true");
    int location = buffer.emit("br i1 " + compare + ", label @, label @");
    src.true_list.emplace_back(location, FIRST);
    src.false_list.emplace_back(location, SECOND);
}

void getNumber(STYPE &src, const STYPE &num) {
    CodeBuffer &buffer = CodeBuffer::instance();
    string var = buffer.newTemp();
    string type = src.type;
    if (type == "BYTE") {
        buffer.emit(var + " = add i8 " + to_string(num.value) + ", 0");
    } else {
        buffer.emit(var + " = add i32 " + to_string(num.value) + ", 0");
    }
    src.reg_add = var;
}

void getString(STYPE &src, const STYPE  &str) {
    CodeBuffer &buffer = CodeBuffer::instance();
    string var = buffer.newGlobalTemp();
    size_t len = str.name.size();
    string clean_str = str.name.substr(1, len - 2);
    buffer.emitGlobal(
            var + " = private unnamed_addr constant [" + to_string(len - 1) + " x i8] c\"" + clean_str + "\\00\"");
    src.reg_add = var;
    string_lengths[var] = len - 1;
}

void assignBool(STYPE &src, bool val) {
    CodeBuffer &buffer = CodeBuffer::instance();
    int location = buffer.emit("br label @");
    if (val) {
        src.true_list.emplace_back(location, FIRST);
    } else {
        src.false_list.emplace_back(location, FIRST);
    }
}

void invBool(STYPE &src, const STYPE &val) {
    src.true_list = val.false_list;
    src.false_list = val.true_list;
}

void andBool(STYPE &res, const STYPE &val1, const STYPE &marker, const STYPE &val2) {
    CodeBuffer &buffer = CodeBuffer::instance();
    buffer.bpatch(val1.true_list, marker.label);
    res.true_list = val2.true_list;
    res.false_list = CodeBuffer::merge(val1.false_list, val2.false_list);
}

void orBool(STYPE &res, const STYPE &val1, const STYPE &marker, const STYPE &val2) {
    CodeBuffer &buffer = CodeBuffer::instance();
    buffer.bpatch(val1.false_list, marker.label);
    res.false_list = val2.false_list;
    res.true_list = CodeBuffer::merge(val1.true_list, val2.true_list);
}

void expCompare(STYPE &src, const STYPE &val1, const STYPE &val2, const string &op) {
    CodeBuffer &buffer = CodeBuffer::instance();
    string operation;
    if (op == "<") {
        operation = "slt";
    } else if (op == "<=") {
        operation = "sle";
    } else if (op == ">") {
        operation = "sgt";
    } else if (op == ">=") {
        operation = "sge";
    } else if (op == "==") {
        operation = "eq";
    } else {
        operation = "ne";
    }
    string temp_var1 = val1.reg_add;
    string temp_var2 = val2.reg_add;
    if (val1.type == "BYTE") {
        temp_var1 = buffer.newTemp();
        buffer.emit(temp_var1 + " = zext i8 " + val1.reg_add + " to i32");
    }
    if (val2.type == "BYTE") {
        temp_var2 = buffer.newTemp();
        buffer.emit(temp_var2 + " = zext i8 " + val2.reg_add + " to i32");
    }
    string compare = buffer.newTemp();
    buffer.emit(compare + " = icmp " + operation + " i32 " + temp_var1 + ", " + temp_var2);
    int location = buffer.emit("br i1 " + compare + ", label @, label @");

    src.true_list.emplace_back(location, FIRST);
    src.false_list.emplace_back(location, SECOND);
}
//___________________________________________________________________________________________________________________________________

void emitPrintGlobal() {
    CodeBuffer &buffer = CodeBuffer::instance();

    //declare the relevant functions the segel ordered:
    buffer.emitGlobal("declare i32 @printf(i8*, ...)");
    buffer.emitGlobal("declare void @exit(i32)");

    //not sure what this do

    buffer.emitGlobal(R"(@.int_specifier = constant [4 x i8] c"%d\0A\00")");
    buffer.emitGlobal(R"(@.str_specifier = constant [4 x i8] c"%s\0A\00")");
    buffer.emitGlobal(R"(@.error_division_by_zero = constant [23 x i8] c"Error division by zero\00")");

    //
    buffer.emitGlobal("define void @printi(i32) {");
    buffer.emitGlobal("%spec_ptr = getelementptr [4 x i8], [4 x i8]* @.int_specifier, i32 0, i32 0");
    buffer.emitGlobal("call i32 (i8*, ...) @printf(i8* %spec_ptr, i32 %0)");
    buffer.emitGlobal("ret void");
    buffer.emitGlobal("}");

    //
    buffer.emitGlobal("define void @print(i8*) {");
    buffer.emitGlobal("%spec_ptr = getelementptr [4 x i8], [4 x i8]* @.str_specifier, i32 0, i32 0");
    buffer.emitGlobal("call i32 (i8*, ...) @printf(i8* %spec_ptr, i8* %0)");
    buffer.emitGlobal("ret void");
    buffer.emitGlobal("}");
}


string getReturnType(STYPE &returnType) {
    if (returnType.type == "BOOL") {
        return "i1";
    }

    if (returnType.type == "VOID") {
        return "void";
    }

    if (returnType.type == "BYTE") {
        return "i8";
    } else {
        std::cout << "Error - not suppose to get here" << std::endl;
        assert(true); //#TODO make sure it wont break anything
        return "ERROR";
    }
}

string makeParamsStr(CodeBuffer &buffer, STYPE &paramsList) {
    string argT;
    string crntVar = buffer.newTemp();
    string retValue;
    int numOfParams = paramsList.params.size();
    for (int i = 0; i < numOfParams; ++i) {
        string crntType = paramsList.params[i].type;
        bool flagChanged = false;
        if (crntType == "BOOL") {
            argT = "i1";
            flagChanged = true;
        } else if (crntType == "BYTE") {
            argT = "i8";
            flagChanged = true;
        } else if (crntType == "BOOL") {
            argT = "i1";
            flagChanged = true;
        }
        if (!flagChanged) {
            argT = "i32";
        }
        argT += " "; //anyway add the space

        retValue += argT + crntVar;
        global_sym_table[paramsList.params[i].name].reg_add = crntVar;//add the var to the globalsymbltable

        bool isLastParam = (numOfParams - 1 == i);
        if (!isLastParam) {
            retValue += ", ";
        }
    }
    return retValue;
}

string fillWithParams(string &toFill, STYPE &paramsList, string funcName) {
    vector<param> func_types = global_sym_table[funcName].func_params;
    toFill += "(";
    for (int i = 0; i < func_types.size(); ++i) {
        string crnt_type = func_types[i].type;
        bool flag = false;
        if (crnt_type == "BOOL") {
            toFill += "i1";
            flag = true;
        }
        if (crnt_type == "STRING") {
            toFill += "i8*";
            flag = true;

        }
        if (crnt_type == "BYTE") {
            toFill += "i8";
            flag = true;

        }
        if (!flag) {
            toFill += "i32";
            flag = true;
        }
        bool isLast = (func_types.size() - 1 == i);
        if (!isLast) {
            toFill += ", ";
        }


        toFill += ") @" + funcName + "(";
        for (size_t i = 0; i < func_types.size(); ++i) {
            if (func_types[i].type == "STRING") {
                string length = to_string(string_lengths[paramsList.reg_add[i]]);
                toFill += "i8* getelementptr ([" + length + " x i8], [" + length + " x i8]* "
                          + paramsList.reg_add[i] + ", i32 0, i32 0)";
            } else if (func_types[i].type == "BOOL") {
                toFill += "i1 " + paramsList.reg_add[i];
            } else if (func_types[i].type == "BYTE") {
                toFill += "i8 " + paramsList.reg_add[i];
            } else {
                string v = to_string(paramsList.reg_add[i]);
                if (func_types[i].type == "BYTE") {
                    v = CodeBuffer::instance().newTemp();
                    CodeBuffer::instance().emit(v + " = zext i8 " + paramsList.reg_add[i] + " to i32");
                }
                toFill += "i32 " + v;
            }
            bool isLast = (func_types.size() - 1 == i);
            if (!isLast) {
                toFill += ", ";
            }
        }
        toFill += ")";

    }


    toFill += ") @";
    toFill += funcName;
    toFill += "(";
    int i = 0;
    for (auto &func_type : func_types) {
        if (func_type.type == "STRING") {
            toFill += "i8* getelementptr ([" + to_string(string_lengths[paramsList.reg_add_list[i]]) + " x i8], [" +
                      to_string(string_lengths[paramsList.reg_add_list[i]]) + " x i8]* "
                      + paramsList.reg_add_list[i] + ", i32 0, i32 0)";
        } else if (func_type.type == "BOOL") {
            toFill += "i1 " + paramsList.reg_add_list[i];
        } else if (func_type.type == "BYTE") {
            toFill += "i8 " + paramsList.reg_add_list[i];
        } else {
            string b = paramsList.reg_add_list[i];
            if (paramsList.params[i].type == "BYTE") {
                b = CodeBuffer::instance().newTemp();
                CodeBuffer::instance().emit(b + " = zext i8 " + paramsList.reg_add_list[i] + " to i32");
            }
            toFill += "i32 " + b;
        }
        bool isLast = paramsList.params.size() - 1 == i;
        i++;
        if (!isLast) {
            toFill += ", ";
        }
    }
    string endSymbol = ")";
    toFill += endSymbol;
}

void callFunc(STYPE &parent, int hasParams, STYPE &func, STYPE &paramsList) {
    CodeBuffer &buffer = CodeBuffer::instance();
    string params_input;
    if (hasParams == 0) {
        params_input += "@" + func.name + "()";
    } else { //have params
        assert(hasParams == 10);
        fillWithParams(params_input, paramsList, func.name);
    }
    string funcType = global_sym_table[func.name].type;
    if (funcType == "VOID") {
        buffer.emit("call void " + params_input);
    } else if (funcType == "BYTE") {
        string newTmp = buffer.newTemp();
        buffer.emit(newTmp + " = call i8 " + params_input);
        parent.reg_add = newTmp;
    } else if (funcType == "BOOL") {
        string newTmp = buffer.newTemp();
        buffer.emit(newTmp + " = call i1 " + params_input);
        parent.reg_add = newTmp;

    } else {
        string newTmp = buffer.newTemp();
        buffer.emit(newTmp + " = call i32 " + params_input);
        parent.reg_add = newTmp;
    }
}

void declFunc(STYPE &returnType, STYPE &func, STYPE &paramsList) {
    CodeBuffer &buffer = CodeBuffer::instance();
    string retType = getReturnType(returnType);
    string strToEmmit = "define "; //defines a function str
    strToEmmit = strToEmmit + retType;
    strToEmmit += " @" + func.name + "(" + makeParamsStr(buffer, paramsList) + ")" + " {";
    buffer.emit(strToEmmit);
}

void endFunc(const STYPE &ret, const STYPE &sta) {
    CodeBuffer &buffer = CodeBuffer::instance();
    if (scopes.top().is_return) {
        buffer.emit("}");
        return;
    } else {
        //take care of the return values:
        if (ret.type == "BYTE") {
            buffer.emit("ret i8 0");
        } else if (ret.type == "BOOL") {
            buffer.emit("ret i1 false");
        } else if (ret.type == "VOID") {
            buffer.emit("ret void");
        } else {
            //defualt - just return int
            buffer.emit("ret i32 0");
        }
        buffer.bpatch(sta.next_list, buffer.genLabel());
    }

    buffer.emit("}");
}