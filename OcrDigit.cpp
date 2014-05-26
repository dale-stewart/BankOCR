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

OcrDigit::operator std::string() const
{
    auto iter = digits_.find(digit_);

    if (iter != digits_.end())
        return iter->second;

    return "?";
}

vector<char> OcrDigit::related()
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
            if (allSegmentsOn[i][j] != ' ')
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
    }

    std::sort(value.begin(), value.end());

    return value;
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
