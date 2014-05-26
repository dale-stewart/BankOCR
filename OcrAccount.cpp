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

OcrAccount::operator string() const
{
    string value;
    
    for(int i = 0; i < 9; ++i)
        value += OcrDigit(slice(i));

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
        return hasValidChecksum(account);
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

vector<string> OcrAccount::correctError() const
{
    vector<string> value;
    for(int i = 0; i < 10; ++i)
    {
        string account = *this;
        OcrDigit ocrDigit = OcrDigit(slice(i));
        vector<OcrDigit> related = ocrDigit.related();
        for(auto iter = related.begin(); iter!= related.end(); ++iter)
        {
            account[i] = string(*iter)[0];
            if (account.find("?") == string::npos && hasValidChecksum(account))
                value.push_back(account);
        }
    }
    return value;
}

vector<string> OcrAccount::slice(int index) const
{
    vector<string> digit;
    for(int j = 0; j < 3; ++j)
    {
        digit.push_back(value_[j].substr(index*3, 3));
    }
    return digit;
}

bool OcrAccount::hasValidChecksum(const std::string& account)
{
    int checksum   = 0;
    int multiplier = 10;

    while(--multiplier)
        checksum += (account[9 - multiplier] - '0') * multiplier;

    checksum %= 11;

    return checksum == 0;
}
