#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    
    for(int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    setlocale(LC_ALL, "");
    int n;
    cout << "Введите количество чисел: ";
    cin >> n;
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cout << "Введите число " << i+1 << ": ";
        cin >> num;
        
        if (num > 0 and log(num) / log(5) == trunc(log(num) / log(5))) {
            count++;
        }
    }
    
    cout << "Количество чисел, являющихся степенями пятерки: " << count << endl;
    return 0;
}
