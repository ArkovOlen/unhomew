#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double sum = 0.0;
    double term1, term2;
    double epsilon = 1e-6; // Точность до 10^{-6}
    int k = 1;
    
    do {
        term1 = 4.0 / pow(2, k - 1);
        term2 = pow(-1, k - 1) / (2.0 * pow(3, k - 1));
        double current_term = term1 + term2;
        sum += current_term;
        k++;
    } while (fabs(term1 + term2) > epsilon);
    
    cout << "Сумма ряда: " << sum << endl;
    
    return 0;
}

