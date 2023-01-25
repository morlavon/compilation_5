#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <list>
#include <string>
#include "Node.h"
#include "hw3_output.hpp"


class Symbol {
public:
    Symbol() {}

    Symbol(std::string name, EType type, int offset, string reg) : name(name), type(type), offset(offset), reg(reg) {}

    Symbol(std::string name, std::vector<EType> argTypes, std::vector<std::string> argNames, EType retType) : name(
            name), type(EFUNC),
                                                                                                              offset(0),
                                                                                                              argTypes(
                                                                                                                      argTypes),
                                                                                                              argNames(
                                                                                                                      argNames),
                                                                                                              retType(retType),
                                                                                                              reg("") {}

    std::string name;
    EType type;
    int offset;
    string reg;
    std::vector<EType> argTypes;
    std::vector<std::string> argNames;
    EType retType;

    std::vector<std::string> typeStringList();

    bool checkArgTypes(TypeList typeList);
};


class Scope {
public:
    Scope(bool isWhile = false) : isWhile(isWhile) {}

    std::vector<Symbol> symTable;
    bool isWhile;

    void addSymbol(Symbol symbol);

    void printScope();
};


class TablesStack {
public:
    TablesStack();

    std::vector<Scope> scopes;

    void addSymbol(Symbol symbol);

    void openScope(bool isWhile = false);

    void closeScope();

    bool findId(std::string name, Symbol &s);

    EType lastFuncRetType();
};


class OffsetsStack {
public:
    OffsetsStack();

    std::vector<int> offsets;

    void openScope();

    void closeScope();

    int getOffset();
};

#endif //UTILITY_H