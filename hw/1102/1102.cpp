#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int arr[10];

    cout << "Введите " << "10" << " значений: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    cout << "Итоговый массив: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
