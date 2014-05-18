#include <fstream>
#include <iostream>
#include "OcrAccountStreamReader.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;

int main(void)
{
    ifstream stream("numbers.txt");
    OcrAccountStreamReader reader(stream);
    vector<OcrAccount> accounts = reader;

    for(auto account: accounts)
    {
        cout << string(account);

        if (!account.isLegible())
            cout << " ILL";
        else if(!account.isValid())
            cout << " ERR";
        
        cout << endl;
    }

    return 0;
}
