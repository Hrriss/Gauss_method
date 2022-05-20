#include <iostream>

double** gen(double** A, int n) {

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
    std::cout << "\n";

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

    std::cout << "\n";


    for (k = n - 1; k >= 0; k--) {
        x[k] = A[k][n + 1];
        for (int i = 0; i < k; i++)
            A[i][n + 1] = A[i][n + 1] - A[i][k] * x[k];
    }


    return x;
}

bool check(double** A, int n, double* x) {
    const double zero{ 0.00001 };

    for (int i = 0; i < n; i++) {
        double a{};
        for (int j = 0; j < n; j++) {
            a = A[i][j] * x[j];
        }
        double b = a - A[i][n + 1];
        if (b > zero) {
            return false;
        }
    }
    return true;
}

