//
// Created by tamir on 11/01/2022.
//

#ifndef HW5_IR_TRANSLATION_H
#define HW5_IR_TRANSLATION_H

#include "bp.hpp"
#include "utilities.hpp"
#include <iostream>
#include <cassert>




void assignNewReg(STYPE &item, bool is_assign);

void storeValInReg(STYPE &dst, const STYPE &src, bool is_const);

void loadID(STYPE &dst, const STYPE &src);

void nextListUpdate(STYPE &statement, const STYPE &statements);

void bpatchNextList(const STYPE &statements, const STYPE &marker);

void markerN(STYPE &src);

void markerM(STYPE &src);

void returnEmptyFunc();

void returnFunc(const STYPE &src);

void
bpatchDoubleCond(STYPE &src, const STYPE &marker_n, const STYPE &marker_m1, const STYPE &exp, const STYPE &marker_m2,
             const STYPE &statements1,
             const STYPE &marker_m3,
             const STYPE &statements2);
void bpatchSingleCond(STYPE &src, const STYPE &marker_n, const STYPE &marker_m1, const STYPE &exp, const STYPE &marker_m2);
void initWhile(const string &label);
void bpatchWhile(STYPE &src, const STYPE &marker_m, const STYPE &statement);
void getNextBreak();
void getNextContinue();
void getBoolResult(STYPE &expr);
void make_add_sub(STYPE &res, const STYPE &val1, const STYPE &op, const STYPE &val2);
void byte_operation(STYPE &res, const STYPE &var1, const STYPE &var2, const string &op);
void make_mul_div(STYPE &res, const STYPE &var1, const STYPE &op, const STYPE &var2);
void funcAsBoolExp(STYPE &src, const STYPE &call);
void getNumber(STYPE &src, const STYPE &num);
void getString(STYPE &src, const STYPE  &str);
void assignBool(STYPE &src, bool val);
void invBool(STYPE &src, const STYPE &val);
void andBool(STYPE &res, const STYPE &val1, const STYPE &marker, const STYPE &val2);
void orBool(STYPE &res, const STYPE &val1, const STYPE &marker, const STYPE &val2);
void expCompare(STYPE &src, const STYPE &val1, const STYPE &val2, const string &op);
void callFunc(STYPE &parent, int hasParams, STYPE &func, STYPE &paramsList);
void declFunc(STYPE &returnType, STYPE &func, STYPE &paramsList);
void endFunc(const STYPE &ret, const STYPE &sta);
#endif //HW5_IR_TRANSLATION_H
