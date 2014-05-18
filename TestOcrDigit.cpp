#include <gmock/gmock.h>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using std::string;
using std::vector;
using std::cout;
using std::stringstream;
using std::map;
using std::make_pair;

using namespace testing;

namespace
{
    vector<string> digits = {
        " _     _  _     _  _  _  _  _ ",
        "| |  | _| _||_||_ |_   ||_||_|",
        "|_|  ||_  _|  | _||_|  ||_| _|"
    };
}

class OcrDigit
{
public:
    OcrDigit(const vector<string>& rhs)
    {
        digit_ = rhs;
    }

    operator string()
    {
        for(int i = 0; i < 10; ++i)
        {
            if( digit_ == compute_digit(i) )
            {
                stringstream ss;
                ss << i;
                return ss.str();
            }
        }
        return "?";
    }

    vector<string> compute_digit(int value)
    {
        vector<string> digit;

        for(int i = 0; i < 3; ++i)
        {
            digit.push_back(digits[i].substr(value*3, 3));
        }

        return digit;
    }

private:
    vector<string> digit_;
};

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
