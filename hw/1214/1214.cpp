#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    string word;
    cout << "Введите слово: ";
    cin >> word;
    
    if (word.length() < 4) {
        cout << "Слово слишком короткое." << endl;
    } else {
        if (word[1] == word[3]) {
            cout << "Второй и четвертый символы одинаковы." << endl;
        } else {
            cout << "Второй и четвертый символы различны." << endl;
        }
    }
    return 0;
}

