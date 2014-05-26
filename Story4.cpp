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
        if (!account.isValid())
        {
            vector<string> corrected = account.correctError();

            if (corrected.size() == 1)
                cout << corrected[0];
            else if (corrected.size() > 1)
            {
                cout << string(account);
                cout << " AMB [";
                for(auto acct: corrected)
                {
                    cout << "'" << acct << "'";
                    if (acct != *(corrected.end() - 1))
                        cout << ", ";
                }
                cout << "]";
            }
            else if (!account.isLegible())
            {
                cout << string(account);
                cout << " ILL";
            }
            else
            {
                cout << string(account);
                cout << " ERR";
            }
        }
        else
        {
            cout << string(account);
        }
 
        cout << endl;
    }

    return 0;
}
