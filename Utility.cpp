#include <iostream>
#include "Utility.h"

vector<string> enumToString{"FUNC", "STRING", "VOID", "BYTE", "BOOL", "INT", "NONE"};

vector<string> Symbol::typeStringList() {
    vector<string> res;
    for (EType arg: argTypes) {
        res.push_back(enumToString[arg]);
    }
    return res;
}

bool Symbol::checkArgTypes(TypeList typeList) {
    list<pair<EType, string>>::iterator it;
    int i = 0;
    if (argTypes.size() != typeList.typesAndRegs.size()) {
        return false;
    }
    for (it = typeList.typesAndRegs.begin(); it != typeList.typesAndRegs.end(); i++, it++) {
        if (argTypes[i] != it->first && !(it->first == EBYTE && argTypes[i] == EINT)) {
            return false;
        }
    }
    return true;
}


void Scope::addSymbol(Symbol symbol) {
    this->symTable.push_back(symbol);
}


void Scope::printScope() {
    output::endScope();
    string typeString;
    for (Symbol sym: symTable) {
        if (sym.type != EFUNC) {
            typeString = enumToString[sym.type];
            output::printID(sym.name, sym.offset, typeString);
        } else {
            vector<string> typeStringList = sym.typeStringList();
            typeString = output::makeFunctionType(enumToString[sym.retType], typeStringList);
            output::printID(sym.name, 0, typeString);
        }
    }
}


bool TablesStack::findId(string name, Symbol &s) {
    for (int i = scopes.size() - 1; i >= 0; i--) {
        for (int j = 0; j < (scopes[i].symTable).size(); j++) {
            if (name == scopes[i].symTable[j].name) {
                s = scopes[i].symTable[j];
                return true;
            }
        }
    }
    return false;
}


TablesStack::TablesStack() {
    Scope scope;
    vector<EType> printArgTypes = {ESTRING};
    vector<EType> printiArgTypes = {EINT};

    scope.addSymbol(Symbol("print", printArgTypes, {}, EVOID));
    scope.addSymbol(Symbol("printi", printiArgTypes, {}, EVOID));
    this->scopes.push_back(scope);
}


void TablesStack::addSymbol(Symbol sym) {
    this->scopes.back().addSymbol(sym);
}

void TablesStack::openScope(bool isWhile) {
    scopes.push_back(Scope(isWhile));
}


void TablesStack::closeScope() {
    /* this->scopes.back().printScope(); */
    scopes.pop_back();
}


EType TablesStack::lastFuncRetType() {
    for (int i = scopes.size() - 1; i >= 0; i--) {
        for (int j = (scopes[i].symTable).size() - 1; j >= 0; j--) {
            if (scopes[i].symTable[j].type == EFUNC) {
                return scopes[i].symTable[j].retType;
            }
        }
    }
    return ENONE;
}

OffsetsStack::OffsetsStack() {
    offsets.push_back(0);
}

void OffsetsStack::openScope() {
    int lastOffset = offsets.back();
    offsets.push_back(lastOffset);
}


int OffsetsStack::getOffset() {
    return offsets.back();
}

void OffsetsStack::closeScope() {
    this->offsets.pop_back();
}
