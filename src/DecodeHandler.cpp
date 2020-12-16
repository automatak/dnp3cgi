
#include "DecodeHandler.h"

#include <opendnp3/logging/LogLevels.h>
#include <iostream>

using namespace std;
using namespace opendnp3;

DecodeHandler::DecodeHandler() : indent(0)
{

}

void DecodeHandler::log(ModuleId module, const char* id, LogLevel level, char const* location, char const* message)
{
    auto clazz = GetClass(level);
    cout << "<pre class=\"" << GetClass(level) << " indent" << indent << "\">" << std::endl;
    cout << message << std::endl;
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

std::string DecodeHandler::GetClass(const LogLevel& level)
{
    using namespace opendnp3::flags;

    if (level == EVENT)
        return "event";
    else if (level == ERR || level == WARN)
        return "error";
    else if (level == APP_HEADER_RX || level == APP_HEADER_TX)
        return "app-header";
    else if (level == APP_OBJECT_RX || level == APP_OBJECT_TX)
        return "app-object-header";
    else if (level == APP_HEX_RX || level == APP_HEX_TX)
        return "app-hex";
    else if (level == LINK_RX || level == LINK_TX || level == LINK_RX_HEX || level == LINK_TX_HEX)
        return "link";
    else if (level == TRANSPORT_RX || level == TRANSPORT_TX)
        return "transport";
    else
        return "unknown";
}

