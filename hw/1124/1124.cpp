#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int arr[] = {12, 45, 100, 78, 952, 6, 333, 777, 222, 1010, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Двузначные числа
    cout << "Двузначные числа: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 10 && arr[i] < 100) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    // Трехзначные числа
    cout << "Трехзначные числа: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 100 && arr[i] < 1000) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
