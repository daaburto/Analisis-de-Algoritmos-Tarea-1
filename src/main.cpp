#include <iostream>
#include "clasico.hpp"
using namespace std;

int main() {
    // Test 2x2
    vector<vector<double>> A = {{1, 2}, {3, 4}};
    vector<vector<double>> B = {{5, 6}, {7, 8}};

    // Multiplicacion clasica
    auto C = multiply(A, B);

    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[i].size(); j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }
    return 0;
}