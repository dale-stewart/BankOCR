#ifndef __OcrAccount_h__
#define __OcrAccount_h__

#include <vector>
#include <string>
#include "OcrDigit.h"

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
    std::vector<OcrDigit> value_;
    static std::vector<std::string> slice(int index, const std::vector<std::string>& v);
    static bool hasValidChecksum(const std::string& account);
    void computeCorrection(int i, std::string account, std::vector<std::string>& value) const;
};

#endif // __OcrAccount_h__
