#ifndef STRASSEN_HPP
#define STRASSEN_HPP

#include <vector>
#include "matriz.hpp"
using namespace std;

vector<vector<double>> strassen(const vector<vector<double>>& A, const vector<vector<double>>& B){
    int n = A.size();

    // Caso base
    if (n == 1){
        return {{A[0][0] * B[0][0]}};
    }

    // Particionar A y B en submatrices
    vector<vector<double>> A11, A12, A21, A22;
    vector<vector<double>> B11, B12, B21, B22;
    splitMatrix(A, A11, A12, A21, A22);
    splitMatrix(B, B11, B12, B21, B22);

    auto M1 = strassen(add(A11, A22), add(B11, B22));
    auto M2 = strassen(add(A21, A22), B11);
    auto M3 = strassen(A11, subtract(B12, B22));
    auto M4 = strassen(A22, subtract(B21, B11));
    auto M5 = strassen(add(A11, A12), B22);
    auto M6 = strassen(subtract(A21, A11), add(B11, B12));
    auto M7 = strassen(subtract(A12, A22), add(B21, B22));

    // Calcular subvectores

    auto C11 = add(subtract(add(M1, M4), M5), M7);
    auto C12 = add(M3, M5);
    auto C21 = add(M2, M4);
    auto C22 = add(subtract(M1,M2), add(M3,M6));
    
    // Juntarlos de vuelta en C
    vector<vector<double>> C = joinMatrix(C11, C12, C21, C22);

    return C;
}


#endif