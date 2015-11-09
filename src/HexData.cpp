#include "HexData.h"

#include <sstream>
#include <stdexcept>

using namespace std;
using namespace openpal;

HexData::HexData(const std::string& hex, bool allowBadChars)
    : HexData(RemoveBadCharacters(hex, allowBadChars))
{

}

HexData::HexData(const std::string& valid) : m_buffer(valid.size()/2)
{
    auto NUM_BYTES = valid.size()/2;

    for(size_t pos = 0; pos < NUM_BYTES; ++pos)
    {
        uint32_t val;
        std::stringstream ss;
        ss << std::hex << valid.substr(2*pos, 2);
        if((ss >> val).fail())
        {
            throw std::invalid_argument("failed to convert hex");
        }
        m_buffer[pos] = static_cast<uint8_t>(val);
    }
}

openpal::RSlice HexData::GetSlice() const
{
    return m_buffer.ToRSlice();
}

std::string HexData::RemoveBadCharacters(const std::string& hex, bool allowBadChars)
{
    ostringstream oss;

    for(const char& c : hex)
    {
        if(IsHexChar(c))
        {
            oss << c;
        }
        else if(c != ' ')
        {
            throw std::invalid_argument("Bad character");
        }
    }

    return oss.str();
}

bool HexData::IsHexChar(char i)
{
    return IsDigit(i) || IsUpperHexAlpha(i) || IsLowerHexAlpha(i);
}

bool HexData::IsDigit(char i)
{
    return (i >= '0') && (i <= '9');
}

bool HexData::IsUpperHexAlpha(char i)
{
    return (i >= 'A') && (i <= 'F');
}

bool HexData::IsLowerHexAlpha(char i)
{
    return (i >= 'a') && (i <= 'f');
}
