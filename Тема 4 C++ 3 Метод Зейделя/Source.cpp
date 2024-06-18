#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> seidel(vector<vector<double>> a, vector<double> b, double tol = 0.01, int max_iterations = 100) {
    int n = b.size();
    vector<double> x(n, 0.0);
    vector<double> x_new(n, 0.0);

    for (int k = 0; k < max_iterations; ++k) {
        for (int i = 0; i < n; ++i) {
            double s1 = 0.0;
            for (int j = 0; j < i; ++j) {
                s1 += a[i][j] * x_new[j];
            }
            double s2 = 0.0;
            for (int j = i + 1; j < n; ++j) {
                s2 += a[i][j] * x[j];
            }
            x_new[i] = (b[i] - s1 - s2) / a[i][i];
        }

        bool convergence = true;
        for (int i = 0; i < n; ++i) {
            if (fabs(x_new[i] - x[i]) > tol) {
                convergence = false;
                break;
            }
        }

        if (convergence) {
            break;
        }

        x = x_new;
    }

    return x;
}

int main() {
    vector<vector<double>> a = { {18, 8, -3, 4},
                                {-7, 11, -5, 2},
                                {4, 1, 3, 4},
                                {-8, -8, -6, 31} };

    vector<double> b = { -84, -5, -38, 263 };

    vector<double> solution = seidel(a, b);

    cout << "Решение методом Зейделя: ";
    for (double x : solution) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
