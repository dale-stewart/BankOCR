#include <gmock/gmock.h>
#include "OcrDigit.h"

using std::string;
using std::vector;

using namespace testing;

class TestOcrDigit : public Test
{
};

TEST_F(TestOcrDigit, CanDecodeDigitOne)
{
    vector<string> one = { "   ",
                           "  |",
                           "  |" };

    OcrDigit digit(one);

    EXPECT_EQ(string("1"), string(digit));
}

TEST_F(TestOcrDigit, CanDecodeDigitTwo)
{
    vector<string> two = { " _ ",
                           " _|",
                           "|_ " };

    OcrDigit digit(two);

    EXPECT_EQ(string("2"), string(digit));
}
