#ifndef __OcrDigit_h__
#define __OcrDigit_h__

#include <string>
#include <vector>

class OcrDigit
{
public:
    OcrDigit(const std::vector<std::string>& rhs);
    operator std::string();

private:
    std::vector<std::string> digit_;
    static std::vector<std::vector<std::string>> digits_;
};

#endif // __OcrDigit_h__
