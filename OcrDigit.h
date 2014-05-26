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
    bool operator==(const OcrDigit& rhs) const;
    std::vector<char> related() const;

private:
    mutable std::vector<std::string> digit_;
    static std::map<std::vector<std::string>, std::string> digits_;
    static void toggle(char& segment, char reference);
};

#endif // __OcrDigit_h__
