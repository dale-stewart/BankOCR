#include <gmock/gmock.h>
#include "OcrAccount.h"

using namespace testing;

using std::string;
using std::vector;

class TestOcrAccount: public Test
{
};

namespace
{
    vector<string> account = 
    {
        "    _  _     _  _  _  _  _ ",
        "  | _| _||_||_ |_   ||_||_|",
        "  ||_  _|  | _||_|  ||_| _|"
    };

    vector<string> validAccount = 
    {
        " _  _  _  _  _  _  _  _    ",
        "| || || || || || || ||_   |",
        "|_||_||_||_||_||_||_| _|  |"
    };

    vector<string> invalidAccount = 
    {
        "                           ",
        "  |  |  |  |  |  |  |  |  |",
        "  |  |  |  |  |  |  |  |  |",
    };

    vector<string> illegibleAccount = 
    {
        "    _  _     _  _  _     _ ",
        "  | _| _||_||  |_   ||_||_|",
        "  ||_  _|  | _||_|  ||_| _|"
    };
}

TEST_F(TestOcrAccount, CanDecodeAccountNumber)
{
    OcrAccount ocrAccount(account);
    EXPECT_EQ(string("123456789"), string(ocrAccount));
}

TEST_F(TestOcrAccount, CanDetectAccountNumberIsValid)
{
    OcrAccount ocrAccount(validAccount);
    EXPECT_TRUE(ocrAccount.isValid());
}

TEST_F(TestOcrAccount, CanDetectAccountNumberIsInvalid)
{
    OcrAccount ocrAccount(invalidAccount);
    EXPECT_FALSE(ocrAccount.isValid());
}

TEST_F(TestOcrAccount, CanDetectAccountNumberIsLegible)
{
    OcrAccount ocrAccount(account);
    EXPECT_TRUE(ocrAccount.isLegible());
}

TEST_F(TestOcrAccount, CanDetectAccountNumberIsIllegible)
{
    OcrAccount ocrAccount(illegibleAccount);
    EXPECT_FALSE(ocrAccount.isLegible());
}

TEST_F(TestOcrAccount, IllegibleAccountIsInvalid)
{
    OcrAccount ocrAccount(illegibleAccount);
    EXPECT_FALSE(ocrAccount.isValid());
}

TEST_F(TestOcrAccount, CanCorrectError)
{
    OcrAccount ocrAccount(invalidAccount);
    vector<string> corrections;
    corrections = ocrAccount.correctError();
    vector<string> expected = { "711111111" };
    EXPECT_EQ(corrections, expected);
}
