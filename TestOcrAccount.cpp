#include <gmock/gmock.h>
#include "OcrAccount.h"

using namespace testing;

using std::string;
using std::vector;

class TestOcrAccount: public Test
{
};

namespace
{
    vector<string> account = 
    {
        "    _  _     _  _  _  _  _ ",
        "  | _| _||_||_ |_   ||_||_|",
        "  ||_  _|  | _||_|  ||_| _|"
    };
}

TEST_F(TestOcrAccount, CanDecodeAccountNumber)
{
    OcrAccount ocrAccount(account);
    EXPECT_EQ(string("123456789"), string(ocrAccount));
}
