// VTableHook.cpp — 虚表函数替换工具

#include "VTableHook/VTableHook.hpp"

static int Unprotect(void* Region)
{
    MEMORY_BASIC_INFORMATION Mbi;
    VirtualQuery((LPCVOID)Region, &Mbi, sizeof(Mbi));
    VirtualProtect(Mbi.BaseAddress, Mbi.RegionSize, PAGE_READWRITE, &Mbi.Protect);
    return Mbi.Protect;
}

static void Protect(void* Region, int Protection)
{
    MEMORY_BASIC_INFORMATION Mbi;
    VirtualQuery((LPCVOID)Region, &Mbi, sizeof(Mbi));
    VirtualProtect(Mbi.BaseAddress, Mbi.RegionSize, Protection, &Mbi.Protect);
}

void* RorinnnTools::VTable::Hook(void* Instance, void* HookFn, int Offset)
{
    intptr_t Table    = *((intptr_t*)Instance);
    intptr_t Entry    = Table + sizeof(intptr_t) * Offset;
    intptr_t Original = *((intptr_t*)Entry);

    int OriginalProtection = Unprotect((void*)Entry);
    *((intptr_t*)Entry)    = (intptr_t)HookFn;
    Protect((void*)Entry, OriginalProtection);

    return (void*)Original;
}
