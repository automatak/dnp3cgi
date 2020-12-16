#ifndef DNP3DECODE_DECODEHANDLER_H
#define DNP3DECODE_DECODEHANDLER_H

#include <opendnp3/logging/ILogHandler.h>
#include <opendnp3/decoder/IDecoderCallbacks.h>

#include <string>

class DecodeHandler final : public opendnp3::ILogHandler, public opendnp3::IDecoderCallbacks
{

public:
    DecodeHandler();

protected:

    static std::string GetClass(const opendnp3::LogLevel& level);


    virtual void log(opendnp3::ModuleId module, const char* id, opendnp3::LogLevel level, char const* location, char const* message) override;
    virtual void PushIndent() override;
    virtual void PopIndent() override;

    uint32_t indent;
};

#endif //DNP3DECODE_DECODEHANDLER_H
