#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    const int size = 15;
    float arr1[size], arr2[size], arr3[size];
    int arr4[size];

    srand(time(0));

    // Заполняем массивы вещественными значениями (22 <= x < 23), (0 <= x < 10), (-50 <= x < 50)
    for (int i = 0; i < size; i++) {
        arr1[i] = 22 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(23-22)));
        arr2[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(10)));
        arr3[i] = -50 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(50+50)));
    }

    // Заполняем массив целыми значениями от 0 до 10 включительно
    for (int i = 0; i < size; i++) {
        arr4[i] = rand() % 11;
    }

    // Выводим массивы
    cout << "Массив 1: ";
    for (int i = 0; i < size; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Массив 2: ";
    for (int i = 0; i < size; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << "Массив 3: ";
    for (int i = 0; i < size; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    cout << "Массив 4: ";
    for (int i = 0; i < size; i++) {
        cout << arr4[i] << " ";
    }
    cout << endl;

    return 0;
}
