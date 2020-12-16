
#ifndef HEXDATA_H
#define HEXDATA_H

#include <opendnp3/util/Buffer.h>

#include <string>
#include <cstdint>
#include <array>

class HexData {

public:
    HexData(const std::string& hex, bool allowBadChars);

    opendnp3::Buffer GetSlice() const;

private:

    HexData(const std::string& validHex);

    static char ToHexChar(char c);

    static std::string RemoveBadCharacters(const std::string& hex, bool allowBadChars);

    static bool IsHexChar(char i);
    static bool IsDigit(char i);
    static bool IsUpperHexAlpha(char i);
    static bool IsLowerHexAlpha(char i);

    std::array<uint8_t, 4096> m_buffer;
};

#endif
