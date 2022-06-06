#pragma once
//сформировать систему
double** gen(double** A, int n);

//решить систему
double* gauss(double** A, int n);

//проверить корректность решения и найтти погрешность
double check(double** A, int n, double* x);

