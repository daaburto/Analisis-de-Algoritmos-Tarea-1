#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <vector>

using namespace std;

vector<vector<double>> add(vector<vector<double>>& A, vector<vector<double>>& B) {
    int n = A.size();
    vector<vector<double>> C(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

vector<vector<double>> subtract(vector<vector<double>>& A, vector<vector<double>>& B) {
    int n = A.size();
    vector<vector<double>> C(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

#endif