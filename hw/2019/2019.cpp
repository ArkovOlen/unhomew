#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    // Объявление переменных
    double a, b, x, y;

    // Приглашение пользователю ввести значения a и b
    cout << "Введите значение a: ";
    cin >> a;
    cout << "Введите значение b: ";
    cin >> b;

    // Расчет значения x
    if (b - std::sqrt(b) - (a + b) / 2 != 0) {  // Проверка знаменателя на ноль
        x = (2 / (a * a + 25) + b) / (std::sqrt(b) + (a + b) / 2);
    } else {
        std::cerr << "Ошибка: деление на ноль в выражении для x." << std::endl;
        return 1;  // Завершение программы с ошибкой
    }

    // Расчет значения y
    y = (fabs(a) + 2 * sin(b)) / (5.5 * a);
    if (a == 0) {
        std::cerr << "Ошибка: деление на ноль в выражении для y." << std::endl;
        return 1;  // Завершение программы с ошибкой
    }

    // Вывод результатов
    cout << "x = " << x << std::endl;
    cout << "y = " << y << std::endl;

    return 0;
}
