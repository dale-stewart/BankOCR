#include <gmock/gmock.h>
#include <sstream>
#include <iostream>

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

TEST_P(TestOcrDigit, CanComputeRelatedDigits)
{
    int index = GetParam();
    OcrDigit digit(digits[index]);
    vector<char> related = digit.related();
    vector<char> expected;

    for(auto a: allRelated[index])
        expected.push_back('0' + a);

    EXPECT_EQ(expected, related);
}
