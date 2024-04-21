#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    double e, f, g, h;
    double a, b, c;

    // Запроси и считайте значения переменных
    cout << "Введите значение e: ";
    cin >> e;
    cout << "Введите значение f: ";
    cin >> f;
    cout << "Введите значение g: ";
    cin >> g;
    cout << "Введите значение h: ";
    cin >> h;

    // Расчет a
    if (f == 0) {
        cout << "Ошибка: Деление на ноль при расчете a." << endl;
    } else {
        a = sqrt(pow(abs(e - (3 / f)), 3) + g);
        cout << "a = " << a << endl;
    }

    // Расчет b
    b = sin(e) + pow(cos(h), 2);
    cout << "b = " << b << endl;

    // Расчет c
    if (e * f - 3 == 0) {
        cout << "Ошибка: Деление на ноль при расчете c." << endl;
    } else {
        c = 33 * g / (e * f - 3);
        cout << "c = " << c << endl;
    }

    return 0;
}
