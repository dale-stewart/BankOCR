#ifndef __OcrAccountStreamReader_h__
#define __OcrAccountStreamReader_h__

#include "OcrAccount.h"

#include <istream>
#include <vector>
#include <string>

class OcrAccountStreamReader
{
public:
    OcrAccountStreamReader(std::istream& rhs);
    operator std::vector<std::string>();
    operator std::vector<OcrAccount>();

private:
    std::vector<OcrAccount> accountList_;
};

#endif // __OcrAccountStreamReader_h__
