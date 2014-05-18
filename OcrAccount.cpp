#include <algorithm>
#include "OcrAccount.h"
#include "OcrDigit.h"

using std::vector;
using std::string;
using std::equal;

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

// account number:  3  4  5  8  8  2  8  6  5
// position names:  d9 d8 d7 d6 d5 d4 d3 d2 d1
// checksum calculation: (d1+2*d2+3*d3 +..+9*d9) mod 11 = 0

bool OcrAccount::isValid()
{
    if (isLegible())
    {
        string account = *this;

        int checksum   = 0;
        int multiplier = 10;

        while(--multiplier)
            checksum += (account[9 - multiplier] - '0') * multiplier;

        checksum %= 11;

        return checksum == 0;
    }

    return false;
}

bool OcrAccount::isLegible()
{
    string account = *this;
    return account.find('?') == string::npos;
}

bool OcrAccount::operator==(const OcrAccount& rhs) const
{
    return equal(value_.begin(), value_.end(), rhs.value_.begin());
}
