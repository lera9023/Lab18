#include <iostream>

#include "tests.h"
#include "fibonacci.h"
#include "factorial.h"
#include "array_utils.h"

void runTests()
{
    int errors = 0;
    unsigned long long f;
    unsigned long long sum;

    // Тесты isFibonacci
    if (!isFibonacci(0)) errors++;
    if (!isFibonacci(1)) errors++;
    if (!isFibonacci(8)) errors++;
    if (isFibonacci(10)) errors++;
    if (isFibonacci(-5)) errors++;

    // Тесты factorial
    if (!factorial(0, f) || f != 1) errors++;
    if (!factorial(1, f) || f != 1) errors++;
    if (!factorial(5, f) || f != 120) errors++;
    if (!factorial(20, f) || f != 2432902008176640000ULL) errors++;
    if (factorial(21, f)) errors++;

    // Тесты processArray
    long long a[] = { 1, 4, 5, 7, 8 };

    if (!processArray(a, 5, sum)) errors++;
    if (a[0] != 1 || a[1] != 4 || a[2] != 120 ||
        a[3] != 7 || a[4] != 40320) errors++;
    if (sum != 40441) errors++;

    // Массив без чисел Фибоначчи
    long long b[] = { 4, 6, 10, 11 };

    if (!processArray(b, 4, sum)) errors++;
    if (sum != 0) errors++;

    // Пустой массив
    long long c[1] = { 0 };

    if (!processArray(c, 0, sum)) errors++;
    if (sum != 0) errors++;

    // Переполнение факториала
    long long d[] = { 34 };

    if (processArray(d, 1, sum)) errors++;

    // Переполнение суммы
    long long e[] = { 20, 20, 20, 20, 20, 20, 20, 20 };

    if (processArray(e, 8, sum)) errors++;

    if (errors == 0)
    {
        std::cout << "Все тесты пройдены!" << std::endl;
    }
    else
    {
        std::cout << "Количество ошибок: " << errors << std::endl;
    }
}