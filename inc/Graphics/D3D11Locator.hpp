#pragma once

// D3D11Locator — D3D11 方法地址定位接口

#include "Graphics/GraphicsLocator.hpp"

#include <vector>

namespace RorinnnTools::Graphics
{
struct D3D11Methods
{
    std::vector<void*> SwapChainMethods;
    std::vector<void*> DeviceMethods;
    std::vector<void*> ContextMethods;
};

LocateStatus LocateD3D11(D3D11Methods& Out);

} // namespace RorinnnTools::Graphics
