#pragma once

// RnFonts.hpp — ImguiRorinnn 字体加载

#include <imgui.h>

namespace RorinnnTools::ImguiRorinnn
{

struct FontSet
{
    ImFont* Default             = nullptr;
    ImFont* Icon                = nullptr;
    ImFont* IconFixedWidth      = nullptr;
    bool    UsedDefaultTextFont = false;
};

bool           LoadFonts(float TextSize = 16.0f, float IconSize = 15.0f);
const FontSet& Fonts();

} // namespace RorinnnTools::ImguiRorinnn
