#pragma once

// RnImage.hpp — ImguiRorinnn DX11 图片资源工具

#include <cstddef>
#include <cstdint>

#include <d3d11.h>
#include <imgui.h>

namespace RorinnnTools::ImguiRorinnn
{

struct ImageTexture
{
    ID3D11ShaderResourceView* View   = nullptr;
    int                       Width  = 0;
    int                       Height = 0;
};

bool CreateDx11TextureFromMemory(ID3D11Device* Device, const void* Data, size_t Size, ImageTexture& Texture);
bool CreateDx11TextureFromFile(ID3D11Device* Device, const wchar_t* Path, ImageTexture& Texture);
void DestroyDx11Texture(ImageTexture& Texture);
void Image(const ImageTexture& Texture,
           const ImVec2&       Size,
           const ImVec4&       Tint   = ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
           const ImVec4&       Border = ImVec4(0.0f, 0.0f, 0.0f, 0.0f));

} // namespace RorinnnTools::ImguiRorinnn
