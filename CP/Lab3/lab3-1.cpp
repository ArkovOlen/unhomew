#include <iostream>
#include <cmath>

using namespace std;

// Функция, которая вычисляет значение подынтегральной функции
double f(double x) {
    return pow(x, 4) / (4 + pow(x, 2));
}

// Метод прямоугольников
double rectangle_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        double x = a + (i + 0.5) * h;  // середина интервала
        sum += f(x);
    }
    return h * sum;
}

// Метод трапеций
double trapezoid_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }
    return h * sum;
}

// Метод Симпсона (парабол)
double simpson_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i += 2) {
        double x = a + i * h;
        sum += 4 * f(x);
    }
    for (int i = 2; i < n; i += 2) {
        double x = a + i * h;
        sum += 2 * f(x);
    }
    return h * sum / 3.0;
}

int main() {
    double a = 1.0; // Нижний предел интегрирования
    double b = 2.0; // Верхний предел интегрирования
    double epsilon = 1e-6; // Точность до 10^{-6}
    
    // Вычисление интеграла методом прямоугольников
    int n_rect = 1;
    double prev_rect = rectangle_method(a, b, n_rect);
    double curr_rect = rectangle_method(a, b, 2 * n_rect);
    while (fabs(curr_rect - prev_rect) > epsilon) {
        prev_rect = curr_rect;
        n_rect *= 2;
        curr_rect = rectangle_method(a, b, 2 * n_rect);
    }
    
    // Вычисление интеграла методом трапеций
    int n_trap = 1;
    double prev_trap = trapezoid_method(a, b, n_trap);
    double curr_trap = trapezoid_method(a, b, 2 * n_trap);
    while (fabs(curr_trap - prev_trap) > epsilon) {
        prev_trap = curr_trap;
        n_trap *= 2;
        curr_trap = trapezoid_method(a, b, 2 * n_trap);
    }
    
    // Вычисление интеграла методом Симпсона
    int n_simpson = 1;
    double prev_simpson = simpson_method(a, b, n_simpson);
    double curr_simpson = simpson_method(a, b, 2 * n_simpson);
    while (fabs(curr_simpson - prev_simpson) > epsilon) {
        prev_simpson = curr_simpson;
        n_simpson *= 2;
        curr_simpson = simpson_method(a, b, 2 * n_simpson);
    }
    
    // Вывод результатов
    cout << "Метод прямоугольников: " << curr_rect << endl;
    cout << "Метод трапеций: " << curr_trap << endl;
    cout << "Метод Симпсона: " << curr_simpson << endl;
    
    return 0;
}

