#include <iostream>
#include <cmath>

using namespace std;

// Функция для вычисления функции f(x)
double func(double x1, double x2, double x3) {
    double term1 = exp(x1*x1 + x2*x2);
    double term2 = log(4 + x2*x2 + 2*x3*x3);
    return term1 + term2;
}

// Метод покоординатного спуска для минимизации функции
void coordinateDescent(double x1, double x2, double x3, double epsilon, int maxIterations) {
    int iter = 0;
    double prevX1, prevX2, prevX3;
    
    do {
        prevX1 = x1;
        prevX2 = x2;
        prevX3 = x3;
        
        // Обновление x1
        double fx1_min = func(x1 - epsilon, x2, x3);
        double fx1_plus = func(x1 + epsilon, x2, x3);
        if (fx1_min < fx1_plus) {
            x1 -= epsilon;
        } else {
            x1 += epsilon;
        }
        
        // Обновление x2
        double fx2_min = func(x1, x2 - epsilon, x3);
        double fx2_plus = func(x1, x2 + epsilon, x3);
        if (fx2_min < fx2_plus) {
            x2 -= epsilon;
        } else {
            x2 += epsilon;
        }
        
        // Обновление x3
        double fx3_min = func(x1, x2, x3 - epsilon);
        double fx3_plus = func(x1, x2, x3 + epsilon);
        if (fx3_min < fx3_plus) {
            x3 -= epsilon;
        } else {
            x3 += epsilon;
        }
        
        iter++;
        
    } while (iter < maxIterations && (fabs(prevX1 - x1) > epsilon || fabs(prevX2 - x2) > epsilon || fabs(prevX3 - x3) > epsilon));
    
    // Вывод результатов
    cout << "Минимум функции f(x) достигается в точке: (" << x1 << ", " << x2 << ", " << x3 << ")" << endl;
    cout << "Значение f(x) в этой точке: " << func(x1, x2, x3) << endl;
}

int main() {
    double x1 = 0.0, x2 = 0.0, x3 = 0.0;
    double epsilon = 1e-6;
    int maxIterations = 1000;
    
    coordinateDescent(x1, x2, x3, epsilon, maxIterations);
    
    return 0;
}

