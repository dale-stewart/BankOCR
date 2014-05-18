#include "OcrAccount.h"
#include "OcrDigit.h"

using std::vector;
using std::string;

OcrAccount::OcrAccount(const vector<string>& rhs)
{
    value_ = rhs;
}

OcrAccount::operator string()
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
