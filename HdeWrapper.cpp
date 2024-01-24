// HdeWrapper.cpp
#include "HdeWrapper.h"
#include <cstring>

int p_dist = 0;

// GLOBAL with limits
int GetPageFrameDistance()
{
    if(p_dist < 1) return 5;
    return p_dist;
}

HdeWrapper::HdeWrapper(unsigned char* base) : base_address(base) {}

std::pair<bool, uintptr_t> HdeWrapper::FindString(const std::string& str) {
    size_t str_len = str.length();
    for (unsigned char* addr = base_address; ; ++addr) {
        if (!std::memcmp(addr, str.c_str(), str_len)) {
            return {true, reinterpret_cast<uintptr_t>(addr)};
        }
    }
    return {false, 0};
}

std::pair<bool, uintptr_t> HdeWrapper::FindNearestInstruction(const std::string& instructionType, uintptr_t startAddress, int maxDistance, bool searchForward) {
    int distance = GetPageFrameDistance();
    unsigned char* addr = reinterpret_cast<unsigned char*>(startAddress);
    while (distance < maxDistance) {
        hde64s hs;
        unsigned int len = hde64_disasm(addr, &hs);
        if (len == 0) break;
        if ((instructionType == "mov" && hs.opcode == 0x89) || (instructionType == "push" && hs.opcode == 0x50)) {
            return {true, reinterpret_cast<uintptr_t>(addr)};
        }
        addr += (searchForward ? len : -len);
        distance += len;
    }
    return {false, 0};
}

hde64s HdeWrapper::disassemble(unsigned char* code) {
    hde64s hs;
    hde64_disasm(code, &hs);
    return hs;
}
