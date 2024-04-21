#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int choice = 0;
    int a, b;

    while (true) {
        cout << "1) Найти среднее арифметическое всех целых чисел от 1 до 750" << endl;
        cout << "2) Найти среднее арифметическое всех целых чисел от 150 до b (b >= 150)" << endl;
        cout << "3) Найти среднее арифметическое всех целых чисел от a до 200 (a <= 200)" << endl;
        cout << "4) Найти среднее ариметическое всех целых чисел от a до b (b >= a)" << endl;
        cout << "5) Выход" << endl;
        cout << "Что вы хотите выполнить?: ";
        cin >> choice;

        if (choice == 1) {
            int sum = 0;
            for (int i = 1; i <= 750; i++) {
                sum += i;
            }
            float average = sum / 750.0;
            cout << "Среднее значение: " << average << endl;
        } else if (choice == 2) {
            cout << "Введите значение b (b >= 150): ";
            cin >> b;
            if (b < 150) {
                cout << "Неправильный ввод" << endl;
            } else {
                int sum = 0;
                for (int i = 150; i <= b; i++) {
                    sum += i;
                }
                float average = sum / (b - 150 + 1.0);
                cout << "Среднее значение: " << average << endl;
            }
        } else if (choice == 3) {
            cout << "Введите значение a (a <= 200): ";
            cin >> a;
            if (a > 200) {
                cout << "Неправильный ввод" << endl;
            } else {
                int sum = 0;
                for (int i = a; i <= 200; i++) {
                    sum += i;
                }
                float average = sum / (200 - a + 1.0);
                cout << "Среднее значение: " << average << endl;
            }
        } else if (choice == 4) {
            cout << " Введите значение a (b >= a):";
            cin >> a;
            cout << "Введите значение a (b >= a): ";
            cin >> b;
            if (b < a) {
                cout << "Неправильный ввод" << endl;
            } else {
                int sum = 0;
                for (int i = a; i <= b; i++) {
                    sum += i;
                }
                float average = sum / (b - a + 1.0);
                cout << "Среднее значение: " << average << endl;
            }
        } else if (choice == 5) {
            break;
        } else {
            cout << "Неправильный ввод" << endl;
        }
    }

    return 0;
}
