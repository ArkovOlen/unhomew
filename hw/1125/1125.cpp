#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int arr[] = {12, 45, 100, 78, 952, 6, 333, 777, 222, 1010, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Печатаем второй, четвертый и т.д. элементы
    cout << "Второй, четвертый и т.д. элементы: ";
    for (int i = 1; i < n; i += 2) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Печатаем третий, шестой и т.д. элементы
    cout << "Третий, шестой и т.д. элементы: ";
    for (int i = 2; i < n; i += 3) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
