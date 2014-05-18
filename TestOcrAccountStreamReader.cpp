#include <gmock/gmock.h>
#include "OcrAccountStreamReader.h"

using namespace testing;

using std::stringstream;
using std::vector;
using std::string;

namespace
{
    vector<string> accountList = 
    {
        "123456789",
    };

    string fileContents = 
        "    _  _     _  _  _  _  _ \n"
        "  | _| _||_||_ |_   ||_||_|\n"
        "  ||_  _|  | _||_|  ||_| _|\n"
        "\n"
        ;

    vector<string> accountVector =
    {
        "    _  _     _  _  _  _  _ ",
        "  | _| _||_||_ |_   ||_||_|",
        "  ||_  _|  | _||_|  ||_| _|"
    };

    vector<OcrAccount> ocrAccountList =
    {
        OcrAccount(accountVector),
    };
}

class TestOcrAccountStreamReader: public Test
{
};

TEST_F(TestOcrAccountStreamReader, CanReadStreamAsStringVector)
{
    stringstream stream(fileContents);
    OcrAccountStreamReader reader(stream);
    EXPECT_EQ(accountList, vector<string>(reader));
}

TEST_F(TestOcrAccountStreamReader, CanReadStreamAsAccountVector)
{
    stringstream stream(fileContents);
    OcrAccountStreamReader reader(stream);
    EXPECT_EQ(ocrAccountList, vector<OcrAccount>(reader));
}
