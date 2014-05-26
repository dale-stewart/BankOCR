#include <gmock/gmock.h>
#include <iostream>

#include "OcrDigit.h"

using std::string;
using std::vector;
using std::to_string;

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

vector<vector<int>> allRelated =
{
    { 8 },
    { 7 },
    { },
    { 9 },
    { },
    { 6, 9 },
    { 5, 8 },
    { 1 },
    { 0, 6, 9 },
    { 3, 5, 8 }
};

class TestOcrDigit : public TestWithParam<int>
{
public:
    void SetUp()
    {
        digit = OcrDigit(digits[GetParam()]);
    }

    OcrDigit digit;
};

TEST_P(TestOcrDigit, CanDecodeDigit)
{
    string expected = to_string(GetParam());
    EXPECT_EQ(expected, string(digit));
}

TEST_P(TestOcrDigit, CanComputeRelatedDigits)
{
    vector<char> related = digit.related();

    vector<char> expected;
    for(auto a: allRelated[GetParam()])
        expected.push_back('0' + a);

    EXPECT_EQ(expected, related);
}

INSTANTIATE_TEST_CASE_P(AllDigits, TestOcrDigit, Range(0, 10));
