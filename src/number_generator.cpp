#include "number_generator.h"
#include <random>

int GenerateRandomNumber(int range)
{
    srand(static_cast<unsigned int>(time(NULL)));
    int output(rand() % range + 1);
    return output;
}