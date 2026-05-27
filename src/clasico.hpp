#ifndef CLASICO_HPP
#define CLASICO_HPP

#include "matriz.hpp"
using namespace std;

Matrix multiply(const Matrix& A, const Matrix& B, const int n) {
    Matrix C = create(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i * n + j] += A[i * n + k] * B[k * n + j];
    return C;
}

#endif