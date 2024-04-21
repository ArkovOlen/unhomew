#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int arr[8] = {37, 0, 50, 46, 34, 46, 0, 13};

    cout << "Массив из восьми элементов: ";
    for (int i = 0; i < 8; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
