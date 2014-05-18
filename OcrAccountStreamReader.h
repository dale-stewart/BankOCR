#ifndef __OcrAccountStreamReader_h__
#define __OcrAccountStreamReader_h__

#include <istream>
#include <vector>
#include <string>

class OcrAccountStreamReader
{
public:
    OcrAccountStreamReader(std::istream& rhs);
    operator std::vector<std::string>();

private:
    std::vector<std::string> accountList_;
};

#endif // __OcrAccountStreamReader_h__
