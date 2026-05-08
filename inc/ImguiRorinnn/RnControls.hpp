#pragma once

// RnControls.hpp — ImguiRorinnn 常用控件

#include <cstddef>

#include <imgui.h>

#include "ImguiRorinnn/RnIcons.hpp"

namespace RorinnnTools::ImguiRorinnn
{

enum class ButtonVariant
{
    Secondary,
    Primary,
    Ghost,
    Danger,
};

enum class StatusKind
{
    Neutral,
    Success,
    Warning,
    Danger,
};

enum class BadgeVariant
{
    Neutral,
    Accent,
    Success,
    Warning,
    Danger,
};

enum class InfoSeverity
{
    Info,
    Success,
    Warning,
    Danger,
};

struct IconButtonOptions
{
    Icon          IconValue  = Icon::None;
    const char*   Tooltip    = nullptr;
    ImVec2        Size       = ImVec2(0.0f, 0.0f);
    ButtonVariant Variant    = ButtonVariant::Ghost;
    bool          Active     = false;
    bool          Enabled    = true;
    bool          FixedWidth = true;
};

struct WindowOptions
{
    bool*            Open                       = nullptr;
    bool             UseRightSideCollapseButton = true;
    const char*      CollapseTooltip            = "折叠";
    const char*      RestoreTooltip             = "还原";
    ImGuiWindowFlags Flags                      = 0;
    bool             CountAsManagedWindow       = true;
};

struct PanelChildOptions
{
    ImVec2           Size   = ImVec2(0.0f, 0.0f);
    bool             Border = true;
    ImGuiWindowFlags Flags  = 0;
};

void Text(const char* Value);
void TextMuted(const char* Value);
void TextDisabled(const char* Value);
void Heading(const char* Value);
bool Hyperlink(const char* Label, const char* Url = nullptr);
void StatusText(const char* Value, StatusKind Kind = StatusKind::Neutral);
void Badge(const char* Label, BadgeVariant Variant = BadgeVariant::Neutral);
void BadgeDot(BadgeVariant Variant = BadgeVariant::Danger, float Radius = 0.0f);
void BadgeNumber(int Value, BadgeVariant Variant = BadgeVariant::Danger);
bool InfoBar(const char*  Message,
             InfoSeverity Severity    = InfoSeverity::Info,
             bool*        Open        = nullptr,
             const char*  ActionLabel = nullptr);
void HelpMarker(const char* Text);

bool Button(const char*   Label,
            const ImVec2& Size    = ImVec2(0.0f, 0.0f),
            ButtonVariant Variant = ButtonVariant::Secondary);
bool PrimaryButton(const char* Label, const ImVec2& Size = ImVec2(0.0f, 0.0f));
bool GhostButton(const char* Label, const ImVec2& Size = ImVec2(0.0f, 0.0f));
bool DangerButton(const char* Label, const ImVec2& Size = ImVec2(0.0f, 0.0f));
bool IconButton(const char*   Id,
                const char*   Icon,
                const char*   Tooltip = nullptr,
                const ImVec2& Size    = ImVec2(0.0f, 0.0f));
bool IconButton(const char* Id, Icon IconValue, const char* Tooltip = nullptr, const ImVec2& Size = ImVec2(0.0f, 0.0f));
bool IconActionButton(const char* Id, const IconButtonOptions& Options);
bool SettingsButton(const char* Id = "Settings", bool Active = false);
bool HelpButton(const char* Id, const char* Tooltip);
bool DiscordButton(const char* Id = "Discord");
bool IconButtonWithText(const char*   Id,
                        Icon          IconValue,
                        const char*   Label,
                        const ImVec2& Size    = ImVec2(0.0f, 0.0f),
                        ButtonVariant Variant = ButtonVariant::Secondary);

bool Checkbox(const char* Label, bool* Value);
bool Toggle(const char* Label, bool* Value);
bool SliderFloat(const char* Label, float* Value, float Min, float Max, const char* Format = "%.2f");
bool SliderInt(const char* Label, int* Value, int Min, int Max);
bool SliderIntMapped(
    const char* Label, int* Value, int Min, int Max, int DisplayMultiplier, const char* DisplayFormat = "%d");
bool Combo(const char* Label, int* CurrentItem, const char* const Items[], int ItemCount);
bool SegmentedControl(const char*       Id,
                      int*              CurrentItem,
                      const char* const Items[],
                      int               ItemCount,
                      const ImVec2&     Size = ImVec2(0.0f, 0.0f));
bool InputText(
    const char* Label, char* Buffer, size_t BufferSize, const char* Hint = nullptr, ImGuiInputTextFlags Flags = 0);
bool InputInt(const char* Label, int* Value);
bool InputFloat(const char* Label, float* Value, const char* Format = "%.3f");
void ProgressBar(const char*   Id,
                 float         Fraction,
                 const ImVec2& Size    = ImVec2(0.0f, 0.0f),
                 const char*   Overlay = nullptr);
void IndeterminateProgressBar(const char* Id, const ImVec2& Size = ImVec2(0.0f, 0.0f));
void ProgressRing(const char* Id, float Fraction, float Radius = 0.0f, float Thickness = 0.0f);
void Spinner(const char* Id, float Radius = 0.0f, float Thickness = 0.0f);
bool BeginTable(const char* Id, int ColumnCount, ImGuiTableFlags Flags = 0, const ImVec2& OuterSize = ImVec2(0.0f, 0.0f));
void TableHeadersRow(const char* const Headers[], int HeaderCount);
void EndTable();

void LabelValue(const char* Label, const char* Value);
void LabelValue(const char* Label, int Value);
void LabelValue(const char* Label, float Value, const char* Format = "%.2f");

bool BeginWindow(const char* Name, const WindowOptions& Options = {});
void EndWindow();
void BeginManagedWindowFrame();
bool HasVisibleManagedWindows();
void DrawTitleBarCollapseButton(const char* Id              = "RnTitleBarCollapseButton",
                                const char* CollapseTooltip = "折叠",
                                const char* RestoreTooltip  = "还原");
bool BeginPanelChild(const char* Id, const PanelChildOptions& Options = {});
void EndPanelChild();
bool IsPanelChildContentVisible();

} // namespace RorinnnTools::ImguiRorinnn
