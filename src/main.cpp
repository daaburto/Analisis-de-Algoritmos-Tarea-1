#include <iostream>
#include "clasico.hpp"
#include "matriz.hpp"
using namespace std;

int main() {
    // Test 2x2
    //vector<vector<double>> A = {{1, 2}, {3, 4}};
    //vector<vector<double>> B = {{5, 6}, {7, 8}};

    // Multiplicacion clasica
    //auto C = multiply(A, B);

    // Test split.hpp
    vector<vector<double>> A = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    vector<vector<double>> A11, A12, A21, A22;

    splitMatrix(A, A11, A12, A21, A22);

    for (int i = 0; i < A21.size(); i++){
        for (int j = 0; j < A21[i].size(); j++)
        {
            cout << A21[i][j] << " ";
            cout << "\n";
        }
    }

    auto C = joinMatrix(A11, A12, A21, A22);



    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[i].size(); j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }
        
    return 0;
}