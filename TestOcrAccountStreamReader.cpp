#include <gmock/gmock.h>
#include <sstream>
#include <vector>
#include <string>
#include "OcrAccount.h"

using namespace testing;

using std::stringstream;
using std::vector;
using std::string;
using std::istream;
using std::getline;

namespace
{
    vector<string> accountList = 
    {
        "123456789",
    };

    string fileContents = 
        "    _  _     _  _  _  _  _ \n"
        "  | _| _||_||_ |_   ||_||_|\n"
        "  ||_  _|  | _||_|  ||_| _|\n"
        "\n"
        ;
}

class OcrAccountStreamReader
{
public:
    OcrAccountStreamReader(istream& rhs)
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

    operator vector<string>()
    {
        return accountList_;
    }

private:
    vector<string> accountList_;
};

class TestOcrAccountStreamReader: public Test
{
};

// Create a class that reads from a stream and decodes all the account numbers into a list.
// Use an istream& to read from - test with a stringstream.

TEST_F(TestOcrAccountStreamReader, CanReadStream)
{
    stringstream stream(fileContents);
    OcrAccountStreamReader reader(stream);
    EXPECT_EQ(accountList, vector<string>(reader));
}
