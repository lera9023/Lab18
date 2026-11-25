#include "array_utils.h"
#include "fibonacci.h"
#include "factorial.h"

#include <limits>

bool processArray(long long a[], int n, unsigned long long& sum)
{
    sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (isFibonacci(a[i]))
        {
            // 20! помещается в unsigned long long, а 21! уже нет.
            if (a[i] > 20)
            {
                return false;
            }

            unsigned long long f;

            if (!factorial(static_cast<unsigned int>(a[i]), f))
            {
                return false;
            }

            // Проверяем переполнение суммы до сложения.
            if (sum > std::numeric_limits<unsigned long long>::max() - f)
            {
                return false;
            }

            a[i] = static_cast<long long>(f);
            sum += f;
        }
    }

    return true;
}