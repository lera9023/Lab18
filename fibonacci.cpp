#include "fibonacci.h"
#include <limits>

bool isFibonacci(long long n)
{
    if (n < 0)
    {
        return false;
    }

    long long a = 0;
    long long b = 1;

    while (a < n)
    {
        if (b > std::numeric_limits<long long>::max() - a)
        {
            return false;
        }

        long long c = a + b;
        a = b;
        b = c;
    }

    return a == n;
}