
#ifndef HEXDATA_H
#define HEXDATA_H

#include <openpal/container/RSlice.h>
#include <openpal/container/Buffer.h>

#include <string>
#include <cstdint>

class HexData {

public:
    HexData(const std::string& hex, bool allowBadChars);

    openpal::RSlice GetSlice() const;

private:

    HexData(const std::string& validHex);

    static char ToHexChar(char c);

    static std::string RemoveBadCharacters(const std::string& hex, bool allowBadChars);

    static bool IsHexChar(char i);
    static bool IsDigit(char i);
    static bool IsUpperHexAlpha(char i);
    static bool IsLowerHexAlpha(char i);

    openpal::Buffer m_buffer;
};

#endif
