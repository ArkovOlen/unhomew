#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    string word;
    cin >> word;
    
    if (word.front() == word.back()) {
        cout << "Первый и последний символы одинаковы." << endl;
    } else {
        cout << "Первый и последний символы различны." << endl;
    }
    
    return 0;
}
