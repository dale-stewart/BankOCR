#include <gmock/gmock.h>
#include <sstream>
#include <iostream>

#include "OcrDigit.h"

using std::string;
using std::vector;
using std::stringstream;
using std::cout;
using std::endl;

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

class TestOcrDigitWithParam : public TestWithParam<int>
{
};

TEST_P(TestOcrDigitWithParam, CanDecodeDigit)
{
    vector<string> input = digits[GetParam()];
    OcrDigit digit(input);

    stringstream ss;
    ss << GetParam();
    string expected = ss.str();

    EXPECT_EQ(expected, string(digit));
}

INSTANTIATE_TEST_CASE_P(AllDigits, TestOcrDigitWithParam, Range(0, 10));

TEST(TestOcrDigit, CanComputeDigitsRelatedToZero)
{
    OcrDigit digit(digits[0]);
    vector<OcrDigit> related = digit.related();
    vector<OcrDigit> expected = { OcrDigit(digits[0]), OcrDigit(digits[8]) };

    for(auto r: related)
        cout << "0: " << string(r) << endl;

    EXPECT_EQ(expected, related);
}

TEST(TestOcrDigit, CanComputeDigitsRelatedToOne)
{
    OcrDigit digit(digits[1]);
    vector<OcrDigit> related = digit.related();
    vector<OcrDigit> expected = { OcrDigit(digits[1]), OcrDigit(digits[7]) };

    for(auto r: related)
        cout << "1: " << string(r) << endl;

    EXPECT_EQ(expected, related);
}
