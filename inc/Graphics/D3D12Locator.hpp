#pragma once

// D3D12Locator — D3D12 方法地址定位接口

#include "Graphics/GraphicsLocator.hpp"

#include <vector>

namespace RorinnnTools::Graphics
{
struct D3D12Methods
{
    std::vector<void*> DeviceMethods;
    std::vector<void*> CommandQueueMethods;
    std::vector<void*> CommandAllocatorMethods;
    std::vector<void*> CommandListMethods;
    std::vector<void*> SwapChainMethods;
};

LocateStatus LocateD3D12(D3D12Methods& Out);

} // namespace RorinnnTools::Graphics
