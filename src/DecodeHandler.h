#ifndef DNP3DECODE_DECODEHANDLER_H
#define DNP3DECODE_DECODEHANDLER_H

#include <openpal/logging/ILogHandler.h>
#include <dnp3decode/IDecoderCallbacks.h>

#include <string>

class DecodeHandler final : public openpal::ILogHandler, public opendnp3::IDecoderCallbacks
{

public:
    DecodeHandler();

protected:

    static std::string GetClass(const openpal::LogFilters& filters);


    virtual void Log( const openpal::LogEntry& entry ) override;
    virtual void PushIndent() override;
    virtual void PopIndent() override;

    uint32_t indent;
};

#endif //DNP3DECODE_DECODEHANDLER_H
