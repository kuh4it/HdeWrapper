// DllMain.cpp
#include "HdeWrapper.h"
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        {
            HdeWrapper wrapper(reinterpret_cast<unsigned char*>(GetModuleHandle(NULL))); // Base address of the process

            //Search for a unique string pattern from your pseudocode
            auto stringSearchResult = wrapper.FindString("SeamlessTravel FlushLevelStreaming"); 
            if (stringSearchResult.first) {
                uintptr_t stringAddress = stringSearchResult.second;

                //Assuming mov instruction related to GWorld is within 100 instructions after the found string
                auto instructionSearchResult = wrapper.FindNearestInstruction("mov", stringAddress, 100, true); 
                if (instructionSearchResult.first) {
                    uintptr_t gWorldPtrAddress = instructionSearchResult.second;
                    //wow
                }
            }
        }
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
