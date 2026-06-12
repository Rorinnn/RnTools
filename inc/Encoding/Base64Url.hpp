#pragma once

// Base64Url.hpp — Base64Url 编解码工具

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace RorinnnTools::Encoding
{

std::string Base64UrlEncode(const std::vector<uint8_t>& Bytes);
std::string Base64UrlEncode(std::string_view Text);
bool        Base64UrlDecode(std::string_view Text, std::vector<uint8_t>& Bytes);

} // namespace RorinnnTools::Encoding
