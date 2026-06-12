#pragma once

// Hash.hpp — 哈希工具

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace RorinnnTools::Crypto
{

bool Sha256Bytes(std::string_view Text, std::vector<uint8_t>& Hash);
bool Sha256Hex(std::string_view Text, std::string& HashHex);

} // namespace RorinnnTools::Crypto
