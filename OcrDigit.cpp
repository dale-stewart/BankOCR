#include <sstream>
#include "OcrDigit.h"

using std::string;
using std::vector;
using std::stringstream;

OcrDigit::OcrDigit(const vector<string>& rhs)
{
    digit_ = rhs;
}

OcrDigit::operator std::string()
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
