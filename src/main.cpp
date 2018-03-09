

#include <opendnp3/LogLevels.h>

#include <dnp3decode/Decoder.h>

#include <openpal/logging/Logger.h>
#include <openpal/container/Buffer.h>
#include <openpal/logging/LogMacros.h>

#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include <stdexcept>

#include "HexData.h"
#include "DecodeHandler.h"

using namespace std;
using namespace cgicc;
using namespace openpal;
using namespace opendnp3;

enum class Mode : uint8_t
{
    Link,
    Transport,
    App
};

Mode GetMode(Cgicc& cgi);
std::string GetHex(Cgicc& cgi);

int main(int argc, char* argv[])
{
    // Set up the HTML document
    cout << HTTPHTMLHeader() << endl;
    cout << html() << endl;
    cout << head() << endl;
    cout << title("decoded output") << endl;
    cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"https://www.automatak.com/opendnp3/decoder/decoder.css\"/>" << std::endl;
    cout << head() << endl;
    cout << body() << endl;

    try
    {
        Cgicc cgi;
        const auto MODE = GetMode(cgi);
        const auto HEX = GetHex(cgi);

        const auto FILTERS = ~0 & (~(flags::LINK_RX_HEX | flags::LINK_TX_HEX));

        auto handler = std::make_shared<DecodeHandler>();
        openpal::Logger logger(handler, "decoder", LogFilters(FILTERS));

        Decoder decoder(*handler, logger);

        HexData hex(HEX, true);

        FORMAT_HEX_BLOCK(logger, flags::EVENT, hex.GetSlice(), 18, 18);

        switch(MODE)
        {
            case(Mode::Link):
                decoder.DecodeLPDU(hex.GetSlice());
                break;
            case(Mode::Transport):
                decoder.DecodeTPDU(hex.GetSlice());
                break;
            default:
                decoder.DecodeAPDU(hex.GetSlice());
                break;
        }
    }
    catch(const std::exception& e)
    {
        cout << "<pre class=\"error\">" << "An exception occured: " << "</pre>" << endl;
        cout << "<pre class=\"error\">" << e.what() << "</pre>" << endl;
    }

    // Close the HTML document
    cout << body() << std::endl;
    cout << html() << std::endl;

    return 0;
}

Mode GetMode(Cgicc& cgi)
{
    auto inputMode = cgi.getElement("mode");
    if(inputMode == cgi.getElements().end())
    {
        throw std::invalid_argument("The decoder mode was not specified");
    }

    const auto VALUE = **inputMode;

    if(VALUE == "app") return Mode::App;
    if(VALUE == "transport") return Mode::Transport;
    return Mode::Link;
}

std::string GetHex(Cgicc& cgi)
{
    auto hex = cgi.getElement("hex");
    if(hex == cgi.getElements().end())
    {
        throw std::invalid_argument("The input hex was not specified");
    }

    return **hex;
}
