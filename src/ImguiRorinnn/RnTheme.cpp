// RnTheme.cpp — ImguiRorinnn 主题令牌

#include "ImguiRorinnn/RnTheme.hpp"

#include <algorithm>

namespace RorinnnTools::ImguiRorinnn
{
namespace
{
static float Clamp01(float Value)
{
    return std::clamp(Value, 0.0f, 1.0f);
}

static ImVec4 Col(float R, float G, float B, float A = 1.0f)
{
    return ImVec4(R, G, B, A);
}

struct AccentToken
{
    AccentColor Accent;
    ImVec4      Color;
};

static ImVec4 ResolveAccent(AccentColor Accent, const ImVec4& CustomAccent)
{
    if (Accent == AccentColor::Custom)
    {
        return CustomAccent;
    }

    static const AccentToken AccentTokens[] = {
        {AccentColor::Blue, Color::Blue},
        {AccentColor::Green, Color::Green},
        {AccentColor::Orange, Color::Orange},
        {AccentColor::Purple, Color::Purple},
        {AccentColor::Rose, Color::Rose},
        {AccentColor::White, Color::SoftWhite},
    };

    for (const AccentToken& Token : AccentTokens)
    {
        if (Token.Accent == Accent)
        {
            return Token.Color;
        }
    }

    return Color::Blue;
}

static void ApplyStyleFromTheme(const Theme& ThemeValue)
{
    if (!ImGui::GetCurrentContext())
    {
        return;
    }

    ImGuiStyle&        Style = ImGui::GetStyle();
    const ColorTokens& C     = ThemeValue.Colors;
    const SizeTokens&  S     = ThemeValue.Sizes;

    Style.WindowPadding       = S.WindowPadding;
    Style.WindowRounding      = S.WindowRounding;
    Style.WindowBorderSize    = 0.0f;
    Style.ChildRounding       = S.PanelRounding;
    Style.ChildBorderSize     = 0.0f;
    Style.PopupRounding       = S.PanelRounding;
    Style.PopupBorderSize     = S.BorderWidth;
    Style.FramePadding        = S.FramePadding;
    Style.FrameRounding       = S.ControlRounding;
    Style.FrameBorderSize     = 0.0f;
    Style.ItemSpacing         = ImVec2(S.ItemGap, S.ItemGap * 0.75f);
    Style.ItemInnerSpacing    = ImVec2(S.ItemGap, S.ItemGap * 0.70f);
    Style.CellPadding         = ImVec2(S.ItemGap, S.ItemGap * 0.65f);
    Style.IndentSpacing       = 18.0f;
    Style.ScrollbarSize       = 13.0f;
    Style.ScrollbarRounding   = S.ControlRounding;
    Style.GrabMinSize         = 9.0f;
    Style.GrabRounding        = S.ControlRounding;
    Style.TabRounding         = S.ControlRounding;
    Style.ButtonTextAlign     = ImVec2(0.5f, 0.5f);
    Style.SelectableTextAlign = ImVec2(0.0f, 0.5f);

    ImVec4* Colors                        = Style.Colors;
    Colors[ImGuiCol_Text]                 = C.Text;
    Colors[ImGuiCol_TextDisabled]         = C.TextDisabled;
    Colors[ImGuiCol_WindowBg]             = C.Background;
    Colors[ImGuiCol_ChildBg]              = WithAlpha(C.Surface, 0.62f);
    Colors[ImGuiCol_PopupBg]              = C.Overlay;
    Colors[ImGuiCol_Border]               = C.Border;
    Colors[ImGuiCol_BorderShadow]         = WithAlpha(C.Background, 0.0f);
    Colors[ImGuiCol_FrameBg]              = C.Surface;
    Colors[ImGuiCol_FrameBgHovered]       = C.SurfaceHover;
    Colors[ImGuiCol_FrameBgActive]        = C.SurfaceActive;
    Colors[ImGuiCol_TitleBg]              = C.Background;
    Colors[ImGuiCol_TitleBgActive]        = C.Background;
    Colors[ImGuiCol_TitleBgCollapsed]     = C.Background;
    Colors[ImGuiCol_MenuBarBg]            = C.Surface;
    Colors[ImGuiCol_ScrollbarBg]          = WithAlpha(C.Background, 0.55f);
    Colors[ImGuiCol_ScrollbarGrab]        = WithAlpha(C.BorderStrong, 0.55f);
    Colors[ImGuiCol_ScrollbarGrabHovered] = WithAlpha(C.Accent, 0.58f);
    Colors[ImGuiCol_ScrollbarGrabActive]  = WithAlpha(C.Accent, 0.78f);
    Colors[ImGuiCol_CheckMark]            = C.AccentText;
    Colors[ImGuiCol_SliderGrab]           = C.Accent;
    Colors[ImGuiCol_SliderGrabActive]     = C.AccentHover;
    Colors[ImGuiCol_Button]               = C.Surface;
    Colors[ImGuiCol_ButtonHovered]        = C.SurfaceHover;
    Colors[ImGuiCol_ButtonActive]         = C.SurfaceActive;
    Colors[ImGuiCol_Header]               = WithAlpha(C.SurfaceHover, 0.72f);
    Colors[ImGuiCol_HeaderHovered]        = WithAlpha(C.Accent, 0.32f);
    Colors[ImGuiCol_HeaderActive]         = WithAlpha(C.Accent, 0.42f);
    Colors[ImGuiCol_Separator]            = WithAlpha(C.Border, 0.0f);
    Colors[ImGuiCol_SeparatorHovered]     = WithAlpha(C.Border, 0.0f);
    Colors[ImGuiCol_SeparatorActive]      = WithAlpha(C.Border, 0.0f);
    Colors[ImGuiCol_ResizeGrip]           = WithAlpha(C.BorderStrong, 0.20f);
    Colors[ImGuiCol_ResizeGripHovered]    = WithAlpha(C.Accent, 0.34f);
    Colors[ImGuiCol_ResizeGripActive]     = WithAlpha(C.Accent, 0.52f);
    Colors[ImGuiCol_Tab]                  = C.Surface;
    Colors[ImGuiCol_TabHovered]           = WithAlpha(C.Accent, 0.34f);
    Colors[ImGuiCol_TabActive]            = C.SurfaceActive;
    Colors[ImGuiCol_TabUnfocused]         = C.Surface;
    Colors[ImGuiCol_TabUnfocusedActive]   = C.SurfaceHover;
    Colors[ImGuiCol_TextSelectedBg]       = WithAlpha(C.Accent, 0.34f);
    Colors[ImGuiCol_NavHighlight]         = WithAlpha(C.Accent, 0.42f);
    Colors[ImGuiCol_ModalWindowDimBg]     = WithAlpha(Color::Black, 0.46f);
}

static Theme g_BaseTheme = MakeTheme();
static Theme g_Theme     = g_BaseTheme;
} // namespace

Theme MakeTheme(ThemeMode Mode, AccentColor Accent, ImVec4 CustomAccent)
{
    Theme Result{};
    Result.Mode         = Mode;
    Result.Accent       = Accent;
    Result.CustomAccent = CustomAccent;

    const bool   Dark        = Mode == ThemeMode::Dark;
    const ImVec4 AccentValue = ResolveAccent(Accent, CustomAccent);

    Result.Colors.Accent = AccentValue;
    Result.Colors.AccentHover =
        Dark ? Blend(AccentValue, Col(1.0f, 1.0f, 1.0f), 0.12f) : Blend(AccentValue, Col(1.0f, 1.0f, 1.0f), 0.20f);
    Result.Colors.AccentActive =
        Dark ? Blend(AccentValue, Col(0.0f, 0.0f, 0.0f), 0.20f) : Blend(AccentValue, Col(0.0f, 0.0f, 0.0f), 0.16f);
    Result.Colors.AccentText = Col(0.98f, 0.99f, 1.0f);
    Result.Colors.Success    = Color::Green;
    Result.Colors.Warning    = Color::Orange;
    Result.Colors.Danger     = Color::Red;

    if (Dark)
    {
        Result.Colors.Background    = Col(0.055f, 0.065f, 0.080f);
        Result.Colors.Surface       = Col(0.105f, 0.120f, 0.145f);
        Result.Colors.SurfaceHover  = Col(0.140f, 0.160f, 0.190f);
        Result.Colors.SurfaceActive = Col(0.180f, 0.205f, 0.240f);
        Result.Colors.Overlay       = Col(0.070f, 0.082f, 0.100f, 0.96f);
        Result.Colors.Border        = Col(0.260f, 0.300f, 0.350f, 0.55f);
        Result.Colors.BorderStrong  = Col(0.360f, 0.410f, 0.480f, 0.72f);
        Result.Colors.Text          = Col(0.920f, 0.950f, 0.980f);
        Result.Colors.TextMuted     = Col(0.650f, 0.700f, 0.760f);
        Result.Colors.TextDisabled  = Col(0.420f, 0.460f, 0.510f);
    }
    else
    {
        Result.Colors.Background    = Col(0.955f, 0.960f, 0.970f);
        Result.Colors.Surface       = Col(1.000f, 1.000f, 1.000f);
        Result.Colors.SurfaceHover  = Col(0.925f, 0.935f, 0.950f);
        Result.Colors.SurfaceActive = Col(0.885f, 0.900f, 0.925f);
        Result.Colors.Overlay       = Col(0.985f, 0.988f, 0.994f, 0.96f);
        Result.Colors.Border        = Col(0.680f, 0.710f, 0.760f, 0.60f);
        Result.Colors.BorderStrong  = Col(0.500f, 0.540f, 0.610f, 0.74f);
        Result.Colors.Text          = Col(0.090f, 0.110f, 0.140f);
        Result.Colors.TextMuted     = Col(0.380f, 0.420f, 0.480f);
        Result.Colors.TextDisabled  = Col(0.620f, 0.650f, 0.700f);
    }

    return Result;
}

void SetTheme(const Theme& NewTheme)
{
    g_BaseTheme = NewTheme;
    g_Theme     = g_BaseTheme;
}

void ApplyTheme(const Theme& NewTheme)
{
    SetTheme(NewTheme);
    ApplyStyleFromTheme(g_Theme);
}

void ApplyTheme(ThemeMode Mode, AccentColor Accent)
{
    ApplyTheme(MakeTheme(Mode, Accent));
}

const Theme& GetTheme()
{
    return g_BaseTheme;
}

const ColorTokens& Colors()
{
    return g_Theme.Colors;
}

const SizeTokens& Sizes()
{
    return g_Theme.Sizes;
}

ImVec4 WithAlpha(ImVec4 Color, float Alpha)
{
    Color.w = Clamp01(Alpha);
    return Color;
}

ImVec4 WithMultipliedAlpha(ImVec4 Color, float AlphaScale)
{
    Color.w = Clamp01(Color.w * AlphaScale);
    return Color;
}

ImVec4 Blend(ImVec4 A, ImVec4 B, float Amount)
{
    const float T = Clamp01(Amount);
    return ImVec4(A.x + (B.x - A.x) * T, A.y + (B.y - A.y) * T, A.z + (B.z - A.z) * T, A.w + (B.w - A.w) * T);
}

ImU32 ToU32(const ImVec4& Color)
{
    return ImGui::ColorConvertFloat4ToU32(Color);
}

} // namespace RorinnnTools::ImguiRorinnn
