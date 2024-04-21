#include <iostream>
#include <cmath> // Для функций sin и pow
using namespace std;
int main() {
    setlocale(LC_ALL, "");
    double x, y;

    cout << "Введите значение переменной x: ";
    cin >> x;

    if (x > 0) {
        y = sin(pow(x, 2)); // y = sin(x^2)
    } else if (x < 0) {
        y = 1 + 2 * pow(sin(x), 2); // y = 1 + 2*sin^2(x)
    } else {
        // Для x = 0 в условиях задачи не определено, по умолчанию возвратить 0
        y = 0;
    }

    cout << "Значение функции y при x = " << x << " равно " << y << endl;

    return 0;
}
