#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    string word1, word2;
    cin >> word1 >> word2;
    if (word1[0] == word2[word2.length() - 1]) {
        cout << "Символы одинаковы." << endl;
    } else {
        cout << "Символы различны." << endl;
    }
    return 0;
}
