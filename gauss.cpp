#include <iostream>
#include <cmath>

double** gen(double** A, int n) {

    if (n <= 4) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
                std::cin >> A[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            std::cout << "b[" << i + 1 << "] = ";
            std::cin >> A[i][n + 1];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << A[i][j] << "*x" << j + 1;
                if (j < n - 1) std::cout << " + ";
            }
            std::cout << " = " << A[i][n + 1];
            std::cout << "" << std::endl;
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = rand() % 100 + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            A[i][n + 1] = rand() % 100 + 1;
        }
        std::cout << "ћатрица " << n << "x" << n << " заполненна€ случайными значени€ми от 1 до 100" << std::endl;
    }
    return A;
}

double* gauss(double** A, int n) {
    double* x, max;
    int k, ind;
    const double zero{ 0.00001 };

    x = new double[n];
    k = 0;

    while (k < n) {
        max = abs(A[k][k]);
        ind = k;

        for (int i = k + 1; i < n; i++) {
            if (abs(A[i][k]) > max) {
                max = abs(A[i][k]);
                ind = i;
            }
        }

        for (int j = 0; j < n; j++) {
            double a = A[k][j];
            A[k][j] = A[ind][j];
            A[ind][j] = a;
        }
        double a = A[k][n + 1];
        A[k][n + 1] = A[ind][n + 1];
        A[ind][n + 1] = a;

        for (int i = k; i < n; i++) {
            double a = A[i][k];
            if (abs(a) < zero) continue;
            for (int j = 0; j < n; j++) {
                A[i][j] = A[i][j] / a;
            }
            A[i][n + 1] = A[i][n + 1] / a;
            if (i == k)  continue;
            for (int j = 0; j < n; j++) {
                A[i][j] = A[i][j] - A[k][j];
            }
            A[i][n + 1] = A[i][n + 1] - A[k][n + 1];
        }
        k++;
    }

    double* c = new double[n];
    for (int i = 0; i < n; i++) {
        c[i] = A[i][n + 1];
    }

    for (k = n - 1; k >= 0; k--) {
        x[k] = A[k][n + 1];
        for (int i = 0; i < k; i++) {
            A[i][n + 1] = A[i][n + 1] - A[i][k] * x[k];
        }
    }

    for (int i = 0; i < n; i++) {
        A[i][n + 1] = c[i];
    }

    return x;
}

double check(double** A, int n, double* x) {
    double max{ 0.0 };

    for (int i = 0; i < n; i++) {
        double a{};

        for (int j = 0; j < n; j++) {
            a = a + (A[i][j] * x[j]);
        }
        double c = abs(A[i][n + 1] - a);
        if (c > max) {
            max = c;
        }
    }
    return max;
}
