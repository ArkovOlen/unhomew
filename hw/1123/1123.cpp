#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int arr[] = {13, 20, 6, 8, 15, 40, 7, 50, 62, 70};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Все четные элементы: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
        }
    }

    cout << "\n Все элементы, оканчивающиеся на 0: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] % 10 == 0) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}
