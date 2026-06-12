#pragma once

// VTableHook.hpp — 虚表函数替换接口

#include <Windows.h>

namespace RorinnnTools::VTable
{
void* HookSlot(void** Slot, void* HookFn);
void* Hook(void* Instance, void* HookFn, int Offset);
} // namespace RorinnnTools::VTable
