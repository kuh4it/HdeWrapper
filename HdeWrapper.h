// HdeWrapper.h
#pragma once
#include <string>
#include "hde64.h"

class HdeWrapper {
public:
    HdeWrapper(unsigned char* base);
    std::pair<bool, uintptr_t> FindString(const std::string& str);
    std::pair<bool, uintptr_t> FindNearestInstruction(const std::string& instructionType, uintptr_t startAddress, int maxDistance, bool searchForward);

private:
    unsigned char* base_address;
    hde64s disassemble(unsigned char* code);
};
