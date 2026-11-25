#include "factorial.h"
#include <limits>

bool factorial(unsigned int n, unsigned long long& result)
{
    if (n == 0 || n == 1)
    {
        result = 1;
        return true;
    }

    unsigned long long f;

    if (!factorial(n - 1, f))
    {
        return false;
    }

    if (f > std::numeric_limits<unsigned long long>::max() / n)
    {
        return false;
    }

    result = n * f;
    return true;
}