#pragma once

// ManualMapTypes.hpp — 手动映射内部类型

#include <Windows.h>

namespace RorinnnTools
{

using LoadLibraryA_t   = HINSTANCE(WINAPI*)(const char* FileName);
using GetProcAddress_t = FARPROC(WINAPI*)(HMODULE Module, LPCSTR ProcName);
using DllEntryPoint_t  = BOOL(WINAPI*)(void* Dll, DWORD Reason, void* Reserved);

#ifdef _WIN64
using RtlAddFunctionTable_t = BOOL(WINAPIV*)(PRUNTIME_FUNCTION FunctionTable, DWORD EntryCount, DWORD64 BaseAddress);
#endif

struct ManualMappingData
{
    LoadLibraryA_t   LoadLibraryA;
    GetProcAddress_t GetProcAddress;
#ifdef _WIN64
    RtlAddFunctionTable_t RtlAddFunctionTable;
#endif
    BYTE*     Base;
    HINSTANCE Module;
    DWORD     Reason;
    LPVOID    Reserved;
    BOOL      SEHSupport;
};

void __stdcall ManualMapShellcode(ManualMappingData* Data);

} // namespace RorinnnTools
