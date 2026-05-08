#pragma once

// AesCrypto.hpp — Windows CryptoAPI AES-CBC 加密解密工具

#include <cstddef>
#include <cstdint>
#include <vector>

namespace RorinnnTools::Crypto
{
bool EncryptAes256Cbc(
    const uint8_t* PData, size_t DataSize, const uint8_t* PKey, size_t KeySize, std::vector<uint8_t>& Output);

bool DecryptAes256Cbc(const uint8_t*        PData,
                      size_t                DataSize,
                      const uint8_t*        PKey,
                      size_t                KeySize,
                      std::vector<uint8_t>& Output,
                      size_t                OriginalSize);
} // namespace RorinnnTools::Crypto
