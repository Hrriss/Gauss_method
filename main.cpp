#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "gauss.h" 

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));

    int n;
    std::cout << "Ведите количество уравнений ";
    std::cin >> n;
    std::cout << "\n";

    double** A = new double* [n];
    for (int i = 0; i < n + 1; ++i) {
        A[i] = new double[n + 1];
    }
    double* x;

    A = gen(A, n);
    std::cout << "\n";

    double stime = clock();
    x = gauss(A, n);
    double ftime = clock();

    std::cout << "Размер решаемой задачи: " << n << "x" << n << std::endl;
    std::cout << "Погрешность вычислений: " << check(A, n, x) << std::endl;
    std::cout << "Время работы программы: " << (double)(ftime - stime) / CLOCKS_PER_SEC << "c" << "\n" << std::endl;
    std::cout << "Ответ:" << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << "x[" << i + 1 << "]=" << x[i] << std::endl;

    return 0;
}
