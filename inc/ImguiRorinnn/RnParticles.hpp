#pragma once

// RnParticles.hpp — ImguiRorinnn 粒子效果

#include <imgui.h>

namespace RorinnnTools::ImguiRorinnn
{

struct SnowflakeOptions
{
    int    Count     = 72;
    float  MinRadius = 1.0f;
    float  MaxRadius = 3.4f;
    float  MinSpeed  = 18.0f;
    float  MaxSpeed  = 62.0f;
    float  Wind      = 12.0f;
    float  Drift     = 18.0f;
    ImVec4 Color     = ImVec4(1.0f, 1.0f, 1.0f, 0.72f);
};

void DrawSnowflakes(const char* Id, const ImVec2& Min, const ImVec2& Max, const SnowflakeOptions& Options = {});

} // namespace RorinnnTools::ImguiRorinnn
