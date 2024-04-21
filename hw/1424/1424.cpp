#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    setlocale(LC_ALL, "");
    cout << "Пары чисел-близнецов: " << endl;
    
    for (int i = 2; i <= 200; i++) {
        if (isPrime(i) and isPrime(i+2)) {
            cout << i << " и " << i+2 << endl;
        }
    }
    
    return 0;
}
