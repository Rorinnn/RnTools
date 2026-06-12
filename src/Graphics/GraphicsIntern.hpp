#pragma once

// GraphicsIntern — 图形方法定位内部工具

#include <Windows.h>

#include <utility>

namespace RorinnnTools::Graphics::detail
{
struct DummyWin32Window
{
    WNDCLASSEXA WindowClass{};
    HWND        WindowHandle = nullptr;
};

void CreateDummyWin32Window(DummyWin32Window& Window);
void DestroyDummyWin32Window(DummyWin32Window& Window);

template <typename F> class ScopeExit
{
  public:
    explicit ScopeExit(F Callback) : Callback(std::move(Callback)) {}
    ScopeExit(const ScopeExit&)            = delete;
    ScopeExit& operator=(const ScopeExit&) = delete;

    ~ScopeExit()
    {
        Callback();
    }

  private:
    F Callback;
};

template <typename F> ScopeExit<F> MakeScopeExit(F Callback)
{
    return ScopeExit<F>(std::move(Callback));
}

} // namespace RorinnnTools::Graphics::detail
