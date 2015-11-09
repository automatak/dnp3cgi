
#include "DecodeHandler.h"

#include <opendnp3/LogLevels.h>
#include <iostream>

using namespace std;
using namespace openpal;
using namespace opendnp3;

DecodeHandler::DecodeHandler() : indent(0)
{

}

void DecodeHandler::Log( const LogEntry& entry )
{
    auto clazz = GetClass(entry.GetFilters());
    cout << "<pre class=" << GetClass(entry.GetFilters()) << " indent" << indent << ">" << std::endl;
    cout << entry.GetMessage() << std::endl;
    cout << "</pre>" << std::endl;
}

void DecodeHandler::PushIndent()
{
    ++indent;
}

void DecodeHandler::PopIndent()
{
    --indent;
}

std::string DecodeHandler::GetClass(const LogFilters& filters)
{
    switch(filters.GetBitfield())
    {
        case(flags::EVENT):
            return "event";
        case(flags::ERR):
        case(flags::WARN):
            return "error";
        case(flags::APP_HEADER_RX):
        case(flags::APP_HEADER_TX):
            return "object-header";
        case(flags::APP_HEX_RX):
        case(flags::APP_HEX_TX):
            return "app-hex";
        case(flags::LINK_RX):
        case(flags::LINK_TX):
        case(flags::LINK_RX_HEX):
        case(flags::LINK_TX_HEX):
            return "link";
        case(flags::TRANSPORT_RX):
        case(flags::TRANSPORT_TX):
            return "transport";
        default:
            return "unknown";
    }
}

