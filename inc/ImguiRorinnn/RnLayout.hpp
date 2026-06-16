#pragma once

// RnLayout.hpp — ImguiRorinnn 布局组件

#include <imgui.h>

namespace RorinnnTools::ImguiRorinnn
{

struct PanelOptions
{
    ImVec2 Size      = ImVec2(0.0f, 0.0f);
    bool   Border    = false;
    bool   FitHeight = false;
};

struct ModuleHeaderOptions
{
    const char* Description                 = nullptr;
    bool        DefaultOpen                 = false;
    bool        Enabled                     = true;
    bool*       Checked                     = nullptr;
    bool        DescriptionAtBottomWhenOpen = false;
    float       AnimationSpeed              = 18.0f;
};

struct VerticalSplitterOptions
{
    float Height    = 0.0f;
    float HitWidth  = 8.0f;
    float LineWidth = 2.0f;
};

void   AddVerticalSpace(float Height);
void   SameLineRight(float ItemWidth);
ImVec2 CalcButtonSize(const char* Label, float MinWidth = 0.0f);
ImVec2 CalcWindowContentSize(float PreferredWidth, float PreferredHeight);
float  GetVerticalSplitterHitWidth();
bool   DrawVerticalSplitter(const char* Id, float Height);
bool   DrawVerticalSplitter(const char* Id, const VerticalSplitterOptions& Options = {});

bool BeginPanel(const char* Id, const PanelOptions& Options = {});
void EndPanel();

bool IsPanelContentVisible();
bool BeginModule(const char* Id, const char* Name, const ModuleHeaderOptions& Options = {});
void EndModule();

void BeginIndented(float Width = 12.0f);
void EndIndented(float Width = 12.0f);

} // namespace RorinnnTools::ImguiRorinnn
