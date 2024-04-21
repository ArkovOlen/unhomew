#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int arr[] = {0, -5, 30, 80, -2, 120, 50, 0, 90, 145, -9};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Все неотрицательные элементы:" << endl;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            cout << arr[i] << " ";
        }
    }

    cout << "\n Все элементы, не превышающие 100:" << endl;
    for (int i = 0; i < size; i++) {
        if (arr[i] <= 100) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}
