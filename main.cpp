#include <iostream>

#include "array_utils.h"
#include "tests.h"

using namespace std;

int main()
{
    int choice;

    cout << "Выберите действие:" << endl;
    cout << "1 - Обработать массив" << endl;
    cout << "2 - Запустить тесты" << endl;
    cout << "Ваш выбор: ";

    cin >> choice;

    if (cin.fail())
    {
        cout << "Ошибка: нужно ввести число." << endl;
        return 1;
    }

    if (choice == 1)
    {
        int n;
        long long a[10];
        unsigned long long sum;

        cout << "Введите размер массива от 1 до 10: ";
        cin >> n;

        if (cin.fail() || n < 1 || n > 10)
        {
            cout << "Ошибка: размер массива должен быть от 1 до 10." << endl;
            return 1;
        }

        cout << "Введите элементы массива:" << endl;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (cin.fail())
            {
                cout << "Ошибка: элемент массива должен быть целым числом." << endl;
                return 1;
            }
        }

        if (processArray(a, n, sum))
        {
            cout << "Изменённый массив: ";

            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }

            cout << endl;
            cout << "Сумма изменённых элементов: " << sum << endl;
        }
        else
        {
            cout << "Ошибка: переполнение при вычислении факториала или суммы." << endl;
        }
    }
    else if (choice == 2)
    {
        runTests();
    }
    else
    {
        cout << "Ошибка: выберите 1 или 2." << endl;
        return 1;
    }

    return 0;
}