
#include <opendnp3/decoder/Decoder.h>
#include <opendnp3/LogLevels.h>

#include <openpal/logging/LogRoot.h>
#include <openpal/container/Buffer.h>

#include <cstdio>

using namespace std;
using namespace openpal;
using namespace opendnp3;

int main(int argc, char* argv[])
{
    openpal::LogRoot log(nullptr, "decoder", LogFilters(~0));
    IDecoderCallbacks callback;
    Decoder decoder(callback, log.GetLogger());

    Buffer buffer(4096);

    while (true)
    {
        const size_t NUM_READ = fread(buffer(), 1, buffer.Size(), stdin);

        if (NUM_READ == 0)
        {
            return 0;
        }

        decoder.DecodeLPDU(buffer.ToRSlice().Take(NUM_READ));
    }

    return 0;
}