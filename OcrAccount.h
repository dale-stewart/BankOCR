#ifndef __OcrAccount_h__
#define __OcrAccount_h__

#include <vector>
#include <string>

class OcrAccount
{
public:
    OcrAccount(const std::vector<std::string>& rhs);
    operator std::string() const;
    bool isValid();
    bool isLegible();
    bool operator==(const OcrAccount& rhs) const;
    std::vector<std::string> correctError() const;

private:
    std::vector<std::string> value_;
    std::vector<std::string> slice(int index) const;
    static bool hasValidChecksum(const std::string& account);
};

#endif // __OcrAccount_h__
