#pragma once

// ProcessTools.hpp — 进程查询与权限工具

#include <Windows.h>

namespace RorinnnTools
{

DWORD GetProcessIdByName(const wchar_t* Name);
bool  IsCorrectTargetArchitecture(HANDLE Process);
bool  EnableDebugPrivilege();

} // namespace RorinnnTools
