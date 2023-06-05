#include <iostream>
#include <iomanip> // Для использования setprecision()
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUSSIAN"); // Установка локали для вывода сообщений на русском языке

    float alpha, z1, z2;
    cout << " Введите значение 'alpha' в градусах: ";
    cin >> alpha;

    while (cin.fail() || cin.get() != '\n') // Проверка, что введенное значение является числом
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << " Введено некорректное значение!\n Повторите ввод: ";
        cin >> alpha;
    }

    const double PI = 3.14; // Задание константы PI
    alpha = PI / 180 * alpha; // Перевод градусов в радианы

    cout << " 'alpha' в радианах: " << alpha << endl;

    // Вычисление z1
    const float numerator1 = alpha + 2; // Числитель первого слагаемого
    const float denominator1 = sqrt(2 * alpha); // Знаменатель первого слагаемого
    const float term1 = numerator1 / denominator1; // Первое слагаемое выражения для z1

    const float numerator2 = alpha; // Числитель второго слагаемого
    const float denominator2 = sqrt(2 * alpha) + 2; // Знаменатель второго слагаемого
    const float term2 = numerator2 / denominator2; // Второе слагаемое выражения для z1

    const float numerator3 = 2; // Числитель третьего слагаемого
    const float denominator3 = alpha - sqrt(2 * alpha); // Знаменатель третьего слагаемого
    const float term3 = numerator3 / denominator3; // Третье слагаемое выражения для z1

    const float factor = (sqrt(alpha) - sqrt(2)) / (alpha + 2); // Множитель выражения для z1

    if (denominator1 == 0 || denominator2 == 0 || denominator3 == 0) {  // Проверка на деление на ноль
        cout << " Деление на ноль!\n";
        return 1; // Возврат кода ошибки
    }

    z1 = (term1 - term2 + term3) * factor; // Значение z1

    // Вычисление z2
    z2 = 1 / (sqrt(alpha) + sqrt(2)); // Значение z2
    if (z1 - z2 < 0.00001)
        cout << " Они равны!" << '\n';
    else
        cout << " Они не равны!" << '\n';

    cout << setprecision(6) << " z1 = " << z1 << "\n" << " z2 = " << z2 << "\n";
    return 0;
}
