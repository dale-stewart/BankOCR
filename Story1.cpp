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
    vector<string> numbers = reader;

    for(auto number: numbers)
        cout << number << endl;

    return 0;
}
