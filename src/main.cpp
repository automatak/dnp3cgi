
#include <opendnp3/decoder/Decoder.h>
#include <opendnp3/LogLevels.h>

#include <openpal/logging/LogRoot.h>
#include <openpal/container/Buffer.h>

#include <cgicc/Cgicc.h>

using namespace std;
using namespace cgicc;
using namespace openpal;
using namespace opendnp3;

int main(int argc, char* argv[])
{
    try
    {
        Cgicc cgi;

        // Send HTTP header
        //cout << HTTPHTMLHeader() << endl;
        //HandleCGI(cgi);
    }
    catch(exception& e)
    {
        //cout << p(e.what()) << endl;
    }

    openpal::LogRoot log(nullptr, "decoder", LogFilters(~0));
    IDecoderCallbacks callback;
    Decoder decoder(callback, log.GetLogger());


    return 0;
}