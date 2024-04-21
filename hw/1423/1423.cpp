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
    cout << "Трехзначные простые числа:\n";
    
    for (int i = 100; i <= 999; i++) {
        if (isPrime(i)) {
            cout << i << endl;
        }
    }
    
    return 0;
}

