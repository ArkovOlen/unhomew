#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    double x, y, z, q;

    // Просим пользователя ввести значения x и y
    cout << "Введите значение x: ";
    cin >> x;
    cout << "Введите значение y: ";
    cin >> y;

    // Вычисляем z, проверяя возможное деление на ноль
    if (x == 0 or (x * x + 10) == 0) {
        cout << "Ошибка: деление на ноль." << endl;
    } else {
        double denominatorZ = y + (1 / sqrt(x * x + 10));
        if (denominatorZ == 0) {
            cout << "Ошибка: деление на ноль при вычислении z." << endl;
        } else {
            z = (x + (2 + y) / (x * x)) / denominatorZ;
            cout << "z = " << z << endl;
        }
    }

    // Вычисляем q
    q = 7.25 * sin(x) - fabs(y);
    cout << "q = " << q << endl;

    return 0;
}
