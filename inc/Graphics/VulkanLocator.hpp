#pragma once

// VulkanLocator — Vulkan 方法地址定位接口

#include "Graphics/GraphicsLocator.hpp"

#include <string>
#include <unordered_map>

namespace RorinnnTools::Graphics
{
struct VulkanMethods
{
    std::unordered_map<std::string, void*> Methods;
};

LocateStatus LocateVulkan(VulkanMethods& Out);

} // namespace RorinnnTools::Graphics
