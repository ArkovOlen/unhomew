#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "");
    string word;

    cout << "Введите слово: ";
    cin >> word;

    if (word.length() >= 3) {
        cout << "Третий символ слова: " << word[2] << endl;
    } else {
        cout << "Слово слишком короткое, третьего символа нет." << endl;
    }

    return 0; 
}
