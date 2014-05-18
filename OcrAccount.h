#ifndef __OcrAccount_h__
#define __OcrAccount_h__

#include <vector>
#include <string>

class OcrAccount
{
public:
    OcrAccount(const std::vector<std::string>& rhs);
    operator std::string();
    bool isValid();

private:
    std::vector<std::string> value_;
};

#endif // __OcrAccount_h__
