#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    string word;
    int k;

    cout << "Введите слово: ";
    cin >> word;

    cout << "Введите позицию символа: ";
    cin >> k;

    if(k > 0 && k <= word.length()) {
        cout << "Символ на позиции " << k << ": " << word[k-1] << endl;
    } else {
        cout << "Некорректный номер позиции!" << endl;
    }

    return 0;
}
