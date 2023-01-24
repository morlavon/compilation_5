//
// Created by lioco on 21/05/2022.
//

#ifndef NODE_H
#define NODE_H
#define YYSTYPE Node*

#include "bp.hpp"
#include <vector>
#include <string>
#include <list>

typedef pair<int, BranchLabelIndex> jumpPair;

enum EType {
    EFUNC,
    ESTRING,
    EVOID,
    EBYTE,
    EBOOL,
    EINT,
    ENONE,
};


class Node {
public:
    string reg;
    string hookLabel;
    vector<pair<int,BranchLabelIndex>> hookQuad;
    bool isTernary;
    Node() : reg("none"),hookLabel("none"),hookQuad(),isTernary(false) {};
};


class Type : public Node {
public:
    EType type;
    vector<jumpPair> trueList;
    vector<jumpPair> falseList;

    Type(EType type) : Node(), type(type) {}

    Type(EType type, vector<jumpPair> trueList, vector<jumpPair> falseList)
            : Node(), type(type), trueList(trueList), falseList(falseList) {};

    bool isNum() {
        if (type == EBYTE || type == EINT) {
            return true;
        }
        return false;
    }
};


class Id : public Node {
public:
    std::string name;

    Id(char *name) : Node(), name(std::string(name)) {};
};

class Num : public Node {
public:
    int value;

    Num(char *num) : Node(), value(atoi(num)) {};
};

class Argument : public Node {
public:
    EType type;
    std::string name;

    Argument(EType type, std::string name) : Node(), type(type), name(name) {}
};

class ArgumentList : public Node {
public:
    std::list<Argument> arguments;

    void addArgument(Argument arg) {
        arguments.push_front(arg);
    }

    void createLists(std::vector<EType> &types, std::vector<std::string> &names) {
        for (std::list<Argument>::iterator it = arguments.begin(); it != arguments.end(); it++) {
            types.push_back(it->type);
            names.push_back(it->name);
        }
    }

};

class TypeList : public Node {
public:
    list<pair<EType, string>> typesAndRegs;

    void addTypeAndReg(EType type, string reg) {
        pair<EType, string> typeAndReg = make_pair(type, reg);
        typesAndRegs.push_front(typeAndReg);
    }
};

class Statement : public Node {
public:
    vector<jumpPair> nextList;

    Statement() : Node(), nextList() {}

    Statement(vector<jumpPair> nextList) : Node(), nextList(nextList) {}
};


class String : public Node {
public:
    string val;

    String(char *val) : Node(), val(val) {};
};

class Oper : public Node {
public:
    std::string oper;

    Oper(char *oper) : Node(), oper(std::string(oper)) {};
};


class M : public Node {
public:
    string quad;

    M(string quad) : Node(), quad(quad) {}
};

class N : public Node {
public:
    std::vector<jumpPair> nextList;
    std::string quad;

    N(string quad, vector<jumpPair> nextList) : Node(), quad(quad), nextList(nextList) {}
};

#endif //NODE_H
