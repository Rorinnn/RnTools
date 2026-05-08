#pragma once

// RnAnimation.hpp — ImguiRorinnn 即时模式动画工具

#include <imgui.h>

namespace RorinnnTools::ImguiRorinnn
{

enum class Ease
{
    Linear,
    OutQuad,
    OutCubic,
    InOutCubic,
    OutBack,
};

float EaseValue(Ease Mode, float T);
float GetFrameDeltaSeconds();
float SmoothValue(ImGuiID Id, float Target, float Speed = 18.0f, float InitialValue = 0.0f);
float SmoothValue(const char* Id, float Target, float Speed = 18.0f, float InitialValue = 0.0f);
float AnimateBool(ImGuiID Id, bool Active, float Speed = 18.0f);
float AnimateBool(const char* Id, bool Active, float Speed = 18.0f);
void  ClearAnimationState(ImGuiID Id);
void  ClearAllAnimationStates();

} // namespace RorinnnTools::ImguiRorinnn
