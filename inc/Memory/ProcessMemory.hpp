#pragma once

// ProcessMemory.hpp — 当前进程内存安全读取工具

#include <cstddef>
#include <cstdint>

namespace RorinnnTools::Memory
{
bool ReadBytes(uintptr_t Ptr, void* PBuffer, size_t Size);
bool IsReadablePtr(uintptr_t Ptr);
bool IsReadableRange(uintptr_t Ptr, size_t Size);
bool ReadPtr(uintptr_t Ptr, uintptr_t& Value);

template <typename T> bool ReadValue(uintptr_t Ptr, T& Value)
{
    if (!ReadBytes(Ptr, &Value, sizeof(T)))
    {
        return false;
    }
    return true;
}
} // namespace RorinnnTools::Memory
