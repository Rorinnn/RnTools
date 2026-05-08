#pragma once

// ManualMapper.hpp — 手动映射注入接口

#include <Windows.h>

namespace RorinnnTools
{

bool ManualMapDll(HANDLE Process,
                  BYTE*  SourceData,
                  SIZE_T FileSize,
                  bool   ClearHeader            = true,
                  bool   ClearNonNeededSections = true,
                  bool   AdjustProtections      = true,
                  bool   SEHExceptionSupport    = true,
                  DWORD  Reason                 = DLL_PROCESS_ATTACH,
                  LPVOID Reserved               = nullptr);

} // namespace RorinnnTools
