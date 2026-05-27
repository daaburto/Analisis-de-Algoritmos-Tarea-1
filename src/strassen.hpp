#ifndef STRASSEN_HPP
#define STRASSEN_HPP

#include "matriz.hpp"
using namespace std;

Matrix strassen(const Matrix& A, const Matrix& B, int n) {
    // Caso base
    if (n == 1) {
        Matrix C = create(1);
        C[0] = A[0] * B[0];
        return C;
    }

    // Particionar A y B en submatrices
    int half = n / 2;
    Matrix A11, A12, A21, A22;
    Matrix B11, B12, B21, B22;
    splitMatrix(A, A11, A12, A21, A22, n);
    splitMatrix(B, B11, B12, B21, B22, n);

    Matrix temp1 = create(half);
    Matrix temp2 = create(half);

    add(A11,A22, temp1);
    add(B11, B22, temp2);
    auto M1 = strassen(temp1, temp2, half);

    add(A21, A22, temp1);
    auto M2 = strassen(temp1, B11, half);

    subtract(B12, B22, temp2);
    auto M3 = strassen(A11, temp2, half);

    subtract(B21, B11, temp2);
    auto M4 = strassen(A22, temp2, half);

    add(A11, A12, temp1);
    auto M5 = strassen(temp1, B22, half);

    subtract(A21, A11, temp1);
    add(B11, B12, temp2);
    auto M6 = strassen(temp1, temp2, half);

    subtract(A12, A22, temp1);
    add(B21, B22, temp2);
    auto M7 = strassen(temp1, temp2, half);

    // Calcular submatrices de C
    Matrix C11 = create(half);
    Matrix C12 = create(half);
    Matrix C21 = create(half);
    Matrix C22 = create(half);
    Matrix tmp = create(half);

    add(M1, M4, tmp); subtract(tmp, M5, C11); add(C11, M7, tmp);
    C11 = tmp;
    add(M3, M5, C12);
    add(M2, M4, C21);
    subtract(M1, M2, tmp); add(tmp, M3, C22); add(C22, M6, tmp);
    C22 = tmp;

    // Juntarlos de vuelta en C
    Matrix C = create(n);
    joinMatrix(C11, C12, C21, C22, C, n);
    return C;
}

#endif