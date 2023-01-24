#ifndef SCOPESTACKS_H
#define SCOPESTACKS_H

#include "Utility.h"
#include <stack>

class ScopeStacks {
public:
    TablesStack tablesStack;
    OffsetsStack offsetsStack;
    stack<vector<jumpPair>> conts;
    stack<vector<jumpPair>> brks;


    vector<jumpPair> contsTopAndPop() {
        vector<jumpPair> toReturn = conts.top();
        conts.pop();
        return toReturn;
    }

    vector<jumpPair> brksTopAndPop() {
        vector<jumpPair> toReturn = brks.top();
        brks.pop();
        return toReturn;
    }

    void openScope(bool isWhile = false) {
        tablesStack.openScope(isWhile);
        offsetsStack.openScope();
    }

    void closeScope() {
        tablesStack.closeScope();
        offsetsStack.closeScope();
    }

    bool isWhileScope() {
        return tablesStack.scopes.back().isWhile;
    }

    void addSymbol(Symbol sym) {
        tablesStack.addSymbol(sym);
        if (sym.type != EFUNC) {
            (offsetsStack.offsets.back())++;
        }
    }
};

#endif //SCOPESTACKS_H