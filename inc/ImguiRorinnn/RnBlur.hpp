#pragma once

// RnBlur.hpp — ImguiRorinnn DX11 高斯模糊工具

#include <d3d11.h>
#include <imgui.h>

namespace RorinnnTools::ImguiRorinnn
{

struct Dx11BlurTarget
{
    ID3D11Texture2D*          Texture            = nullptr;
    ID3D11ShaderResourceView* ShaderResourceView = nullptr;
    ID3D11RenderTargetView*   RenderTargetView   = nullptr;
    int                       Width              = 0;
    int                       Height             = 0;
};

class Dx11GaussianBlur
{
  public:
    Dx11GaussianBlur() = default;
    ~Dx11GaussianBlur();

    bool Initialize(ID3D11Device* Device, ID3D11DeviceContext* Context);
    void Shutdown();
    bool Resize(int Width, int Height);
    bool Blur(ID3D11ShaderResourceView* SourceView, float Radius = 10.0f, int PassCount = 2);
    void DrawBlurredImage(const ImVec2& Size, const ImVec4& Tint = ImVec4(1.0f, 1.0f, 1.0f, 1.0f));

    ID3D11ShaderResourceView* GetOutputView() const;
    int                       GetWidth() const;
    int                       GetHeight() const;

  private:
    bool CreateShaders();
    bool CreateSampler();
    bool CreateTarget(Dx11BlurTarget& Target, int Width, int Height);
    void DestroyTarget(Dx11BlurTarget& Target);
    void DrawPass(ID3D11ShaderResourceView* SourceView,
                  ID3D11RenderTargetView*   TargetView,
                  float                     DirectionX,
                  float                     DirectionY,
                  float                     Radius);

    ID3D11Device*        D3dDevice      = nullptr;
    ID3D11DeviceContext* D3dContext     = nullptr;
    ID3D11VertexShader*  VertexShader   = nullptr;
    ID3D11PixelShader*   PixelShader    = nullptr;
    ID3D11Buffer*        ConstantBuffer = nullptr;
    ID3D11SamplerState*  SamplerState   = nullptr;
    ID3D11BlendState*    BlendState     = nullptr;
    Dx11BlurTarget       PingTarget{};
    Dx11BlurTarget       PongTarget{};
};

} // namespace RorinnnTools::ImguiRorinnn
