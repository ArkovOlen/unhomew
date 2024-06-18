#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // для функции swap

using namespace std;

class CubicSpline {
public:
    CubicSpline(const vector<double>& x, const vector<double>& y) : x(x), y(y) {
        int n = static_cast<int>(x.size()) - 1;
        vector<double> h(n);
        for (int i = 0; i < n; ++i) {
            h[i] = x[i + 1] - x[i];
        }

        vector<vector<double>> A(n + 1, vector<double>(n + 1, 0.0));
        vector<double> b(n + 1, 0.0);

        for (int i = 1; i < n; ++i) {
            A[i][i - 1] = h[i - 1];
            A[i][i] = 2 * (h[i - 1] + h[i]);
            A[i][i + 1] = h[i];
            b[i] = 3 * ((y[i + 1] - y[i]) / h[i] - (y[i] - y[i - 1]) / h[i - 1]);
        }

        A[0][0] = 1.0;
        A[n][n] = 1.0;

        vector<double> c = solveLinearSystem(A, b);

        a.resize(n);
        b_coeff.resize(n);
        c_coeff.resize(n);
        d.resize(n);

        for (int i = 0; i < n; ++i) {
            a[i] = y[i];
            b_coeff[i] = (y[i + 1] - y[i]) / h[i] - h[i] * (2 * c[i] + c[i + 1]) / 3;
            c_coeff[i] = c[i];
            d[i] = (c[i + 1] - c[i]) / (3 * h[i]);
        }
    }

    double operator()(double xi) const {
        int n = static_cast<int>(x.size()) - 1;
        int idx = 0;
        while (idx < n && xi > x[idx + 1]) {
            ++idx;
        }
        double dx = xi - x[idx];
        return a[idx] + b_coeff[idx] * dx + c_coeff[idx] * dx * dx + d[idx] * dx * dx * dx;
    }

private:
    vector<double> x, y;
    vector<double> a, b_coeff, c_coeff, d;

    vector<double> solveLinearSystem(const vector<vector<double>>& A, const vector<double>& b) {
        int n = static_cast<int>(b.size());
        vector<vector<double>> augmentedMatrix(n, vector<double>(n + 1));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                augmentedMatrix[i][j] = A[i][j];
            }
            augmentedMatrix[i][n] = b[i];
        }

        // Gaussian elimination
        for (int i = 0; i < n; ++i) {
            // Search for maximum in this column
            double maxEl = abs(augmentedMatrix[i][i]);
            int maxRow = i;
            for (int k = i + 1; k < n; ++k) {
                if (abs(augmentedMatrix[k][i]) > maxEl) {
                    maxEl = abs(augmentedMatrix[k][i]);
                    maxRow = k;
                }
            }

            // Swap maximum row with current row (column by column)
            for (int k = i; k < n + 1; ++k) {
                swap(augmentedMatrix[maxRow][k], augmentedMatrix[i][k]);
            }

            // Make all rows below this one 0 in current column
            for (int k = i + 1; k < n; ++k) {
                double c = -augmentedMatrix[k][i] / augmentedMatrix[i][i];
                for (int j = i; j < n + 1; ++j) {
                    if (i == j) {
                        augmentedMatrix[k][j] = 0;
                    } else {
                        augmentedMatrix[k][j] += c * augmentedMatrix[i][j];
                    }
                }
            }
        }

        // Solve equation Ax=b for an upper triangular matrix A
        vector<double> x(n);
        for (int i = n - 1; i >= 0; i--) {
            x[i] = augmentedMatrix[i][n] / augmentedMatrix[i][i];
            for (int k = i - 1; k >= 0; k--) {
                augmentedMatrix[k][n] -= augmentedMatrix[k][i] * x[i];
            }
        }

        return x;
    }
};

int main() {
    vector<double> x_j = {0.0, 1.0, 2.0, 3.0, 4.0};
    vector<double> y_j = {0.0, 0.5, 0.86603, 1.0, 0.86603};

    CubicSpline spline(x_j, y_j);

    double x_star = 1.5;
    double y_star = spline(x_star);

    cout << "Значение функции в точке x* = " << x_star << ": y* = " << y_star << endl;

    return 0;
}

