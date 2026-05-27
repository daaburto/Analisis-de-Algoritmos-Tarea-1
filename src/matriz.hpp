#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Matriz como vector 1D, para evitar problemas de memoria
using Matrix = vector<double>;

Matrix create(int n) {
    return Matrix(n * n, 0.0);
}

void add(const Matrix& A, const Matrix& B, Matrix& C) {
    for (int i = 0; i < A.size(); i++)
        C[i] = A[i] + B[i];
}

void subtract(const Matrix& A, const Matrix& B, Matrix& C) {
    for (int i = 0; i < A.size(); i++)
        C[i] = A[i] - B[i];
}

// Dividir matriz en 4
void splitMatrix(const Matrix& A, Matrix& A11, Matrix& A12, Matrix& A21, Matrix& A22, int n) {
    int half = n / 2;
    A11 = create(half);
    A12 = create(half);
    A21 = create(half);
    A22 = create(half);
    for (int i = 0; i < half; i++)
        for (int j = 0; j < half; j++) {
            A11[i * half + j] = A[i * n + j];
            A12[i * half + j] = A[i * n + j + half];
            A21[i * half + j] = A[(i + half) * n + j];
            A22[i * half + j] = A[(i + half) * n + j + half];
        }
}

// Unir matriz
void joinMatrix(const Matrix& C11, const Matrix& C12, const Matrix& C21, const Matrix& C22, Matrix& C, int n) {
    int half = n / 2;
    for (int i = 0; i < half; i++)
        for (int j = 0; j < half; j++) {
            C[i * n + j] = C11[i * half + j];
            C[i * n + j + half] = C12[i * half + j];
            C[(i + half) * n + j] = C21[i * half + j];
            C[(i + half) * n + j + half] = C22[i * half + j];
        }
}

// Cargar matriz de un archivo
Matrix load_matrix(const string& filename, int& n) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        exit(EXIT_FAILURE);
    }
    file >> n;
    Matrix A = create(n);
    for (int i = 0; i < n * n; i++)
        file >> A[i];
    return A;
}
#endif