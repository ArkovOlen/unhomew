#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

int main() {
    // Определяем комплексные числа
    complex<double> z1(-1, 1);
    complex<double> z2(-4, -2);
    complex<double> z3(-1, -1);
    
    // Сумма z1 и z2
    complex<double> sum = z1 + z2;
    cout << "Сумма: " << sum << endl;
    
    // Разность z1 и z2
    complex<double> diff = z1 - z2;
    cout << "Разность: " << diff << endl;
    
    // Произведение z1 и z2
    complex<double> prod = z1 * z2;
    cout << "Произведение: " << prod << endl;
    
    // Частное z1 и z2
    complex<double> quot = z1 / z2;
    cout << "Частное: " << quot << endl;
    
    // Четвертая степень z3
    complex<double> z3_pow4 = pow(z3, 4);
    cout << "Четвертая степень z3: " << z3_pow4 << endl;
    
    // Корень третьей степени z3
    complex<double> z3_root3 = pow(z3, 1.0/3);
    cout << "Корень третьей степени z3: " << z3_root3 << endl;
    
    return 0;
}

