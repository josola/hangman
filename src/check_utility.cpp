#include "check_utility.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cin;

bool CheckAttemptInput(const unsigned int input)
{
    int min = 1;
    int max = 25;

    if (input < min || input > max)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool CheckWordLengthInput(const unsigned int input)
{
    int min = 2;
    int max = 14;

    if (input < min || input > max)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool CheckGuessInput(const char input)
{
    vector<char> bad_guesses = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=',
    ',', '.', '/', '<', '>', '?', ';', ':', '[', ']',
    '{', '}', '|', '`', '~'
    };

    bool output = false;
    for (size_t i = 0; i < bad_guesses.size(); i++)
    {
        if (input == bad_guesses[i])
        {
            return false;
        }
        else
        {
            output = true;
        }
    }
    return output;
}