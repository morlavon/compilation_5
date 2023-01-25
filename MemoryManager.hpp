#ifndef MEM_H
#define MEM_H

#include <string>


class MemoryManager {
    int stringCount;
    int registerCount;
    int activationRecordCount;

public:
    MemoryManager() : stringCount(0), registerCount(0), activationRecordCount(0) {}


    std::string createString() {
        return "@str" + std::to_string(stringCount++);
    }

    std::string createReg() {
        return "%reg" + std::to_string(registerCount++);
    }

    std::string createActivationRecord() {
        activationRecordCount += 1;
        return "%ar" + std::to_string(activationRecordCount);
    }

    std::string getActivationRecord() {
        return "%ar" + std::to_string(activationRecordCount);
    }
};

#endif