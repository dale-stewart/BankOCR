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
        accountList_.push_back(string(account));
        int removeCount = 4;
        while(file.size() && --removeCount)
            file.erase(file.begin(), file.begin()+1);            
    }
}

OcrAccountStreamReader::operator vector<string>()
{
    return accountList_;
}
