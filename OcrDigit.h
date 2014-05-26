#ifndef __OcrDigit_h__
#define __OcrDigit_h__

#include <string>
#include <vector>
#include <map>

class OcrDigit
{
public:
    OcrDigit();
    OcrDigit(const std::vector<std::string>& rhs);
    operator std::string() const;
    std::vector<char> related();

private:
    std::vector<std::string> digit_;
    static std::map<std::vector<std::string>, std::string> digits_;
};

#endif // __OcrDigit_h__
