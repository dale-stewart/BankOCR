#include <gmock/gmock.h>
#include <sstream>

#include "OcrDigit.h"

using std::string;
using std::vector;
using std::stringstream;

using namespace testing;

namespace
{
    vector< vector< string > > digits = 
    {
        {
            " _ ",
            "| |",
            "|_|"
        },
        {
            "   ",
            "  |",
            "  |"
        },
        {
            " _ ",
            " _|",
            "|_ "
        },
        {
            " _ ",
            " _|",
            " _|"
        },
        {
            "   ",
            "|_|",
            "  |"
        },
        {
            " _ ",
            "|_ ",
            " _|"
        },
        {
            " _ ",
            "|_ ",
            "|_|"
        },
        {
            " _ ",
            "  |",
            "  |"
        },
        {
            " _ ",
            "|_|",
            "|_|"
        },
        {
            " _ ",
            "|_|",
            " _|"
        },
    };
}

class TestOcrDigit : public TestWithParam<int>
{
};

TEST_P(TestOcrDigit, CanDecodeDigit)
{
    vector<string> input = digits[GetParam()];
    OcrDigit digit(input);

    stringstream ss;
    ss << GetParam();
    string expected = ss.str();

    EXPECT_EQ(expected, string(digit));
}

INSTANTIATE_TEST_CASE_P(AllDigits, TestOcrDigit, Range(0, 10));
