#include <iostream>
#include "gauss.h"
#include <cmath>

int main() {
    setlocale(LC_ALL, "rus");

    int n;
    std::cout << "Ведите количество уравнений ";
    std::cin >> n;

    double** A = new double* [n];
    for (int i = 0; i < n + 1; ++i) {
        A[i] = new double[n + 1];
    }
    double* x;

    A = gen(A, n);
    x = gauss(A, n);

    if (check(A, n, x) == 1) {
        std::cout << "Ответ:" << std::endl;
        for (int i = 0; i < n; i++)
            std::cout << "x[" << i + 1 << "]=" << x[i] << std::endl;
    }
    else {
        std::cout << "Ошибка в рассчетах" << std::endl;
    }

    system("pause");
    return 0;
}
