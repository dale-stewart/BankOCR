#include <gmock/gmock.h>
#include <string>
#include <vector>

#include "OcrDigit.h"

using namespace testing;

using std::string;
using std::vector;

class OcrAccount
{
public:
    OcrAccount(const vector<string>& rhs)
    {
        value_ = rhs;
    }

    operator string()
    {
        string value;
        
        for(int i = 0; i < 9; ++i)
        {
            vector<string> digit;
            for(int j = 0; j < 3; ++j)
            {
                digit.push_back(value_[j].substr(i*3, 3));
            }
            value += OcrDigit(digit);
        }

        return value;
    }

private:
    vector<string> value_;
};

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
