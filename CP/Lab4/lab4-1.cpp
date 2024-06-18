#include <iostream>
#include <vector>
#include <iomanip> // Для форматированного вывода

using namespace std;

// Функция для печати матрицы
void printMatrix(vector<vector<double>>& A, int n) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            cout << setw(8) << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Функция для печати вектора
void printVector(vector<double>& B, int n) {
    for (size_t i = 0; i < n; ++i) {
        cout << setw(8) << B[i] << endl;
    }
    cout << endl;
}

// Матричный метод для решения системы линейных уравнений
vector<double> matrixMethod(vector<vector<double>>& A, vector<double>& B, int n) {
    vector<double> X(n); // Вектор решений
    
    // Вычисление обратной матрицы
    for (size_t i = 0; i < n; ++i) {
        double pivot = A[i][i];
        
        // Преобразование строки i
        for (size_t j = 0; j < n; ++j) {
            A[i][j] /= pivot;
        }
        B[i] /= pivot;
        
        // Вычитание строки i из остальных строк
        for (size_t k = 0; k < n; ++k) {
            if (k != i) {
                double multiplier = A[k][i];
                for (size_t j = 0; j < n; ++j) {
                    A[k][j] -= multiplier * A[i][j];
                }
                B[k] -= multiplier * B[i];
            }
        }
    }
    
    // Запись решения в вектор X
    for (size_t i = 0; i < n; ++i) {
        X[i] = B[i];
    }
    
    return X;
}

int main() {
    // Исходные данные (коэффициенты системы)
    vector<vector<double>> A = {
        {  2, -8,  0,  5 },
        { -9,  9, -7,  6 },
        { -6,  7,  3,  8 },
        { -1,  8,  5,  1 }
    };
    
    // Правая часть системы уравнений
    vector<double> B = { -40, -58, -75, 1 };
    
    size_t n = A.size(); // Размерность системы
    
    // Вывод исходной системы уравнений
    cout << "Исходная система уравнений:" << endl;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            cout << setw(8) << A[i][j] << "x_" << j+1;
            if (j < n - 1) {
                cout << " + ";
            }
        }
        cout << " = " << setw(8) << B[i] << endl;
    }
    cout << endl;
    
    // Решение с использованием матричного метода
    vector<double> solution = matrixMethod(A, B, n);
    
    // Вывод решения
    cout << "Решение системы уравнений:" << endl;
    for (size_t i = 0; i < n; ++i) {
        cout << "x_" << i+1 << " = " << setw(8) << solution[i] << endl;
    }
    
    return 0;
}
Реализовать на языке python вычислительные алгоритмы поиска решений линейных алгебраических уравнений и методом Крамера и Якоби. система имеет следующий вид:
2x_1 - 8x_2 + 5x_4 = -40,
-9x_1 + 9x_2 - 7x_3 + 6x_4 = -58,
-6x_1 + 7x_2 +3x_3 + 8x_4 = -75,
-x_1 + 8x_2 + 5 x_3 + x_4 = 1

