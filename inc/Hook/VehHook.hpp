#pragma once

// VehHook.hpp — VEH 异常 Hook 接口

#include <Windows.h>

#include <cstddef>
#include <cstdint>
#include <functional>

namespace RorinnnTools::Hook
{
enum class VehHookType
{
    Int3,
    Int3Trace,
    Int3Jump,
    HardwareBreakpoint,
    HardwareTrace,
    HardwareJump,
};

enum class VehHookStatus
{
    Ok,
    AlreadyInstalled,
    NotInstalled,
    HandlerInstallFailed,
    InvalidArgument,
    DuplicateToken,
    DuplicateTarget,
    TokenNotFound,
    TypeInvalid,
    ReadFailed,
    WriteFailed,
    AllocateFailed,
    ThreadSnapshotFailed,
    ThreadOpenFailed,
    ThreadContextFailed,
    HardwareBreakpointLimit,
};

using VehHookCallback = std::function<void(VehHookType Type, PEXCEPTION_POINTERS PExceptionInfo)>;

struct VehHookOptions
{
    int             Token           = 0;
    void*           TargetAddress   = nullptr;
    void*           RedirectAddress = nullptr;
    VehHookType     Type            = VehHookType::Int3;
    VehHookCallback Callback        = {};
    const uint8_t*  TrampolineBytes = nullptr;
    size_t          TrampolineSize  = 0;
};

VehHookStatus InstallVehHookHandler();
VehHookStatus UninstallVehHookHandler();
bool          IsVehHookHandlerInstalled();

VehHookStatus AddVehHook(const VehHookOptions& Options);
VehHookStatus RemoveVehHook(int Token);
VehHookStatus RemoveAllVehHooks();
VehHookStatus RefreshHardwareVehHooks();
size_t        GetVehHookCount();

const char* GetVehHookStatusName(VehHookStatus Status);
} // namespace RorinnnTools::Hook
