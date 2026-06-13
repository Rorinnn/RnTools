#pragma once

// SystemKeyboard.hpp — Windows 系统键盘输入封装

#include <Windows.h>

#include <cstddef>

namespace RorinnnTools::Input
{
bool TapVirtualKey(WORD VirtualKey, DWORD PressMs = 20);
bool TapVirtualKeyChord(const WORD* PVirtualKeys, size_t Count, DWORD PressMs = 20);
} // namespace RorinnnTools::Input
