#ifndef __OcrDigit_h__
#define __OcrDigit_h__

#include <string>
#include <vector>

class OcrDigit
{
public:
    OcrDigit();
    OcrDigit(const std::vector<std::string>& rhs);
    operator std::string() const;
    std::vector<char> related();
    bool operator==(const OcrDigit& rhs) const;
    bool operator!=(const OcrDigit& rhs) const;
    bool operator<(const OcrDigit& rhs) const;

private:
    std::vector<std::string> digit_;
    static std::vector<std::vector<std::string>> digits_;
};

#endif // __OcrDigit_h__
