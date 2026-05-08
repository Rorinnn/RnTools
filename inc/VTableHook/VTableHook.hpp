#pragma once

// VTableHook.hpp — 虚表函数替换接口

#include <Windows.h>

namespace RorinnnTools::VTable
{
void* Hook(void* Instance, void* HookFn, int Offset);
} // namespace RorinnnTools::VTable
