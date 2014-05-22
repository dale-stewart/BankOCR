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
    { 0, 8 },
    { 1, 7 },
    { 2 },
    { 3, 9 },
    { 4 },
    { 5, 6, 9 },
    { 5, 6, 8 },
    { 1, 7 },
    { 0, 6, 8, 9 },
    { 3, 5, 8, 9 }
};

TEST_P(TestOcrDigit, CanComputeRelatedDigits)
{
    int index = GetParam();
    OcrDigit digit(digits[index]);
    vector<OcrDigit> related = digit.related();
    vector<OcrDigit> expected;

    for(auto a: allRelated[index])
        expected.push_back(OcrDigit(digits[a]));

    for(auto r: related)
        cout << index << ": " << string(r) << endl;

    EXPECT_EQ(expected, related);
}
