#include <iostream>
#include <cmath>
usung namespace std;
int main() {
    setlocale(LC_ALL, "");
    double x, y;

    cout << "Введите значение переменной x: ";
    cin >> x;

    if (x > 0) {
        y = pow(sin(x), 2);
    } else {
        y = 1 - 2 * sin(pow(x, 2));
    }
    
    cout << "Значение функции y при x = " << x << " равно " << y << endl;

    return 0;
}
