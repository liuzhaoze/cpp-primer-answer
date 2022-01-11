#include "quiz_6.8.h"

unsigned int fact(unsigned int n)
{
    unsigned int result = 1;

    while (n > 1)
    {
        result *= n--;
    }

    return result;
}
