#include <iostream>
#include "clasico.hpp"
#include "strassen.hpp"
using namespace std;

int main() {
    int n = 4;

    Matrix A = {1,2,3,4,3,4,5,6,7,8,9,10,11,12,13,14};
    Matrix B = {3,4,5,6,1,2,3,4,11,12,13,14,7,8,9,10};

    // Multiplicacion por Strassen

    auto C = strassen(A,B,n);

    cout << "MULTIPLICACION POR STRASSEN" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i * n + j] << " ";
        cout << "\n";
    }

    // Multiplicación clásica

    auto D = multiply(A,B,n);

    cout << "MULTIPLICACION CLASICA" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << D[i * n + j] << " ";
        cout << "\n";
    }


    return 0;
}