#include <iostream>
#include "clasico.hpp"
#include "matriz.hpp"
#include "strassen.hpp"
#include "hybrid.hpp"
using namespace std;

int main() {

    // Multiplicacion por Strassen

    vector<vector<double>> A, B;

    A = {
        {1,2,3,4},
        {3,4,5,6},
        {7,8,9,10},
        {11,12,13,14}
    };
    
    B = {
        {3,4,5,6},
        {1,2,3,4},
        {11,12,13,14},
        {7,8,9,10}
    };

    auto C = strassen(A,B);

    cout << "MULTIPLICACION POR STRASSEN" << endl;
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[i].size(); j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }

    // Multiplicación clásica

    auto D = multiply(A,B);

    cout << "MULTIPLICACION CLASICA" << endl;

    for (int i = 0; i < D.size(); i++) {
        for (int j = 0; j < D[i].size(); j++)
            cout << D[i][j] << " ";
        cout << "\n";
    }
    

    return 0;
}