#include <algorithm>
#include "OcrDigit.h"

using std::string;
using std::vector;
using std::equal;
using std::sort;
using std::map;

OcrDigit::OcrDigit()
{
}

OcrDigit::OcrDigit(const vector<string>& rhs)
{
    digit_ = rhs;
}

bool OcrDigit::operator==(const OcrDigit& rhs) const
{
    return equal(digit_.begin(), digit_.end(), rhs.digit_.begin());
}

OcrDigit::operator std::string() const
{
    auto iter = digits_.find(digit_);

    if (iter != digits_.end())
        return iter->second;

    return "?";
}

vector<char> OcrDigit::related() const
{
    vector<char> value;

    vector<string> allSegmentsOn = 
        {
            " _ ",
            "|_|",
            "|_|"
        };

    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++ j)
        {
            char segment = allSegmentsOn[i][j];

            if (segment != ' ')
            {
                toggle(digit_[i][j], segment);

                string test = *this;
                if (test != "?")
                    value.push_back(test[0]);

                toggle(digit_[i][j], segment);
            }
        }
    }

    std::sort(value.begin(), value.end());

    return value;
}

void OcrDigit::toggle(char& segment, char reference)
{
    if (segment == ' ')
        segment = reference;
    else
        segment = ' ';
}

map< vector< string >, string > OcrDigit::digits_ = 
{
    {
        {
            " _ ",
            "| |",
            "|_|"
        },
        "0"
    },
    {
        {
            "   ",
            "  |",
            "  |"
        },
        "1"
    },
    {
        {
            " _ ",
            " _|",
            "|_ "
        },
        "2"
    },
    {
        {
            " _ ",
            " _|",
            " _|"
        },
        "3"
    },
    {
        {
            "   ",
            "|_|",
            "  |"
        },
        "4"
    },
    {
        {
            " _ ",
            "|_ ",
            " _|"
        },
        "5"
    },
    {
        {
            " _ ",
            "|_ ",
            "|_|"
        },
        "6"
    },
    {
        {
            " _ ",
            "  |",
            "  |"
        },
        "7"
    },
    {
        {
            " _ ",
            "|_|",
            "|_|"
        },
        "8"
    },
    {
        {
            " _ ",
            "|_|",
            " _|"
        },
        "9"
    }
};
