#pragma once

// OpenGLLocator — OpenGL 方法地址定位接口

#include "Graphics/GraphicsLocator.hpp"

#include <string>
#include <unordered_map>

namespace RorinnnTools::Graphics
{
struct OpenGLMethods
{
    std::unordered_map<std::string, void*> Methods;
};

LocateStatus LocateOpenGL(OpenGLMethods& Out);

} // namespace RorinnnTools::Graphics
