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
}

class TestOcrAccountStreamReader: public Test
{
};

TEST_F(TestOcrAccountStreamReader, CanReadStream)
{
    stringstream stream(fileContents);
    OcrAccountStreamReader reader(stream);
    EXPECT_EQ(accountList, vector<string>(reader));
}
