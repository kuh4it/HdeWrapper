// DllMain.cpp
#include "HdeWrapper.h"
#include <windows.h>

uintptr_t gWorldPtr;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        {
            //
            // We don't spoofcall or use lazy importer cause we ghetto
            //
            HdeWrapper wrapper(reinterpret_cast<unsigned char*>(GetModuleHandle(NULL))); // Base address of the process

            //Search for a unique string pattern from your pseudocode
            auto stringSearchResult = wrapper.FindString("SeamlessTravel FlushLevelStreaming"); 
            if (stringSearchResult.first) {
                uintptr_t stringAddress = stringSearchResult.second;

                //
                // mov rcx, GWorld
                //
                auto instructionSearchResult = wrapper.FindNearestInstruction("mov", stringAddress, 100, true); 
                if (instructionSearchResult.first) {
                    gWorldPtr = instructionSearchResult.second;
                    //
                    // Proceed with p2c
                    //
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
