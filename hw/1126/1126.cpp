#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int arr[] = {3, -5, 8, 0, -2, 7, -4};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Выводим неотрицательные элементы
    cout << "Неотрицательные элементы:";
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            cout << " " << arr[i];
        }
    }
    cout << endl;

    // Выводим отрицательные элементы
    cout << "Отрицательные элементы:";
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            cout << " " << arr[i];
        }
    }
    cout << endl;

    return 0;
}
