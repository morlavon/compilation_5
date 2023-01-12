#ifndef HW5_IR_HPP
#define HW5_IR_HPP

#include "bp.hpp"
//#include "hw3_output.hpp"
#include "attributes.hpp"

void emitPrintGlobal();
void printBuffers();
void byteBINOP(ushkud& ush, const ushkud& u1, const ushkud& u2, const string& op);
void add(ushkud &ush, const ushkud &u1, const ushkud &op_expr, const ushkud &u2);
void mul(ushkud &ush, const ushkud &u1, const ushkud &op_expr, const ushkud &u2);
void assignBool(ushkud& ush, bool val);
void inverseBool(ushkud& ush, const ushkud& u1);
void andBool(ushkud& ush, const ushkud& u1, const ushkud& marker, const ushkud& u2);
void orBool(ushkud& ush, const ushkud& u1, const ushkud& marker, const ushkud& u2);
void genN(ushkud& ush);
void genM(ushkud& ush);
void loadNum(ushkud& ush, const ushkud& num);
void loadString(ushkud& ush, const ushkud& num);
void assignNewID(ushkud& id, bool assign);
void storeID(ushkud& ush, const ushkud& exp);
void loadID(ushkud& ush, const ushkud& id);
void relComp(ushkud& ush, const ushkud& u1, const ushkud& u2, const string& op);
void boolResult(ushkud& expr);
void updateNext(ushkud& statements, const ushkud& statement);
void patchStatements(const ushkud& statements, const ushkud& marker);
void retFunction(const ushkud& expr);
void retEmptyFunction();
void patchIf(ushkud &u, const ushkud& n, const ushkud& m1, const ushkud &open_if, const ushkud &m2);
void patchIfElse(ushkud &u, const ushkud& n, const ushkud& m1, const ushkud &open_if, const ushkud &m2, const ushkud &s1, const ushkud &m3, const ushkud &s2);
void nextBreak();
void nextContinue();
void patchWhile(ushkud& u, const ushkud& marker, const ushkud& statement);
void patchNextSwitch(ushkud& u);
void patchSwitch(ushkud &u, const ushkud &N1, const ushkud &M, const ushkud &exp, const ushkud &N2, ushkud &cl);
void pushLastCase(ushkud& u, const ushkud& case_decl);
void pushCase(ushkud& u, const ushkud& case_decl, const ushkud& case_list);
void initWhileAndSwitchData(const string& label="");
void openFunction(const ushkud& ret_type, const ushkud& id, const ushkud& formals);
void closeFunction(const ushkud& ret_type, const ushkud& statements);
void callFunction(ushkud& u, const ushkud& id, const ushkud& exp_list, bool no_params=false);
void funcAsBoolExp(ushkud& u, const ushkud& call);
void func(ushkud &u);
#endif //HW5_IR_HPP
