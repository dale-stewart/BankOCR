#include <algorithm>
#include "OcrAccount.h"

using std::vector;
using std::string;
using std::equal;

OcrAccount::OcrAccount(const vector<string>& rhs)
{
    for(int i = 0; i < 9; ++i)
        value_.push_back(OcrDigit(slice(i, rhs)));
}

OcrAccount::operator string() const
{
    string value;
    
    for(int i = 0; i < 9; ++i)
        value += value_[i];

    return value;
}

bool OcrAccount::isValid()
{
    string account = *this;
    return hasValidChecksum(account);
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
    string account = *this;

    size_t index = account.find("?");
    if (index == string::npos)
    {
        for(int i = 0; i < 9; ++i)
            computeCorrection(i, account, value);
    }
    else
        computeCorrection(index, account, value);

    return value;
}

vector<string> OcrAccount::slice(int index, const vector<string>& v)
{
    vector<string> digit;

    for(int i = 0; i < 3; ++i)
        digit.push_back(v[i].substr(index*3, 3));

    return digit;
}

bool OcrAccount::hasValidChecksum(const std::string& account)
{
    if (account.find("?") != string::npos)
        return false;

    int checksum   = 0;
    int multiplier = 10;

    while(--multiplier)
        checksum += (account[9 - multiplier] - '0') * multiplier;

    checksum %= 11;

    return checksum == 0;
}

void OcrAccount::computeCorrection(int i, string account, vector<string>& value) const
{
    vector<char> related = value_[i].related();

    for(auto c: related)
    {
        account[i] = c;
        if (hasValidChecksum(account))
            value.push_back(account);
    }
}
