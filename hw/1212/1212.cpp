#include <iostream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "");
    string word;
    
    cout << "Введите слово: ";
    cin >> word; // Ввод слова с клавиатуры

    if (!word.empty()) { // Проверка, что строка не пустая
        cout << "Последний символ слова: " << word[word.length() - 1] << endl; // Вывод последнего символа
    } else {
        cout << "Введена пустая строка." << endl; // Сообщение о пустом вводе
    }

    return 0;
}
