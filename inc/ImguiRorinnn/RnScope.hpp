#pragma once

// RnScope.hpp — ImGui 样式作用域

#include <imgui.h>

namespace RorinnnTools::ImguiRorinnn
{

class StyleColorScope
{
  public:
    StyleColorScope() = default;
    StyleColorScope(ImGuiCol Index, const ImVec4& Color);
    ~StyleColorScope();

    StyleColorScope(const StyleColorScope&)            = delete;
    StyleColorScope& operator=(const StyleColorScope&) = delete;

    StyleColorScope(StyleColorScope&& Other) noexcept;
    StyleColorScope& operator=(StyleColorScope&& Other) noexcept;

    void Push(ImGuiCol Index, const ImVec4& Color);
    void Pop();

  private:
    int Count = 0;
};

class StyleVarScope
{
  public:
    StyleVarScope() = default;
    StyleVarScope(ImGuiStyleVar Index, float Value);
    StyleVarScope(ImGuiStyleVar Index, const ImVec2& Value);
    ~StyleVarScope();

    StyleVarScope(const StyleVarScope&)            = delete;
    StyleVarScope& operator=(const StyleVarScope&) = delete;

    StyleVarScope(StyleVarScope&& Other) noexcept;
    StyleVarScope& operator=(StyleVarScope&& Other) noexcept;

    void Push(ImGuiStyleVar Index, float Value);
    void Push(ImGuiStyleVar Index, const ImVec2& Value);
    void Pop();

  private:
    int Count = 0;
};

class DisabledScope
{
  public:
    explicit DisabledScope(bool Disabled);
    ~DisabledScope();

    DisabledScope(const DisabledScope&)            = delete;
    DisabledScope& operator=(const DisabledScope&) = delete;

  private:
    bool Active = false;
};

} // namespace RorinnnTools::ImguiRorinnn
