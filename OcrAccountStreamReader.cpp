#include "OcrAccountStreamReader.h"
#include "OcrAccount.h"

using std::vector;
using std::string;
using std::istream;
using std::getline;

OcrAccountStreamReader::OcrAccountStreamReader(istream& rhs)
{
    vector<string> file;
    string accountNumber;
    while(!rhs.eof())
    {
        getline(rhs, accountNumber);
        file.push_back(accountNumber);
    }

    while(file.size()/4 > 0)
    {
        OcrAccount account(file);
        accountList_.push_back(account);
        if (file.size() >= 4)
            file.erase(file.begin(), file.begin()+4);            
    }
}

OcrAccountStreamReader::operator vector<OcrAccount>()
{
    return accountList_;
}

OcrAccountStreamReader::operator vector<string>()
{
    vector<string> value;

    for(auto account: accountList_)
        value.push_back(account);

    return value;
}
