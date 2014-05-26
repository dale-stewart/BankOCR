#include <sstream>
#include <algorithm>
#include "OcrDigit.h"

using std::string;
using std::vector;
using std::stringstream;
using std::equal;
using std::unique;
using std::sort;

OcrDigit::OcrDigit()
{
}

OcrDigit::OcrDigit(const vector<string>& rhs)
{
    digit_ = rhs;
}

OcrDigit::operator std::string() const
{
    for(int i = 0; i < 10; ++i)
    {
        if( digit_ == digits_[i] )
        {
            stringstream ss;
            ss << i;
            return ss.str();
        }
    }
    return "?";
}

vector<char> OcrDigit::related()
{
    vector<char> value;
    vector<string> allSegmentsOn = digits_[8];

    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++ j)
        {
            vector<string> testDigit = digit_;

            if (testDigit[i][j] == ' ')
                testDigit[i][j] = allSegmentsOn[i][j];
            else
                testDigit[i][j] = ' ';

            OcrDigit test(testDigit);
            if (string(test) != "?")
                value.push_back(string(test)[0]);
        }
    }

    std::sort(value.begin(), value.end());
    auto it = std::unique(value.begin(), value.end());
    value.resize( std::distance(value.begin(), it));

    return value;
}

bool OcrDigit::operator==(const OcrDigit& rhs) const
{
    return equal(digit_.begin(), digit_.end(), rhs.digit_.begin());
}

bool OcrDigit::operator!=(const OcrDigit& rhs) const
{
    return equal(digit_.begin(), digit_.end(), rhs.digit_.begin());
}

bool OcrDigit::operator<(const OcrDigit& rhs) const
{
    return string(*this) < string(rhs);
}

vector< vector< string > > OcrDigit::digits_ = 
{
    {
        " _ ",
        "| |",
        "|_|"
    },
    {
        "   ",
        "  |",
        "  |"
    },
    {
        " _ ",
        " _|",
        "|_ "
    },
    {
        " _ ",
        " _|",
        " _|"
    },
    {
        "   ",
        "|_|",
        "  |"
    },
    {
        " _ ",
        "|_ ",
        " _|"
    },
    {
        " _ ",
        "|_ ",
        "|_|"
    },
    {
        " _ ",
        "  |",
        "  |"
    },
    {
        " _ ",
        "|_|",
        "|_|"
    },
    {
        " _ ",
        "|_|",
        " _|"
    },
};
