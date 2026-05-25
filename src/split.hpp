#ifndef SPLIT_HPP
#define SPLIT_HPP

#include <vector>
using namespace std;

void splitMatrix(vector<vector<double>>& A, vector<vector<double>>& A11, vector<vector<double>>& A12, vector<vector<double>>& A21, vector<vector<double>>& A22){
    int n = A.size();
    int half = n/2;

    // Crear matrices n/2 x n/2
    A11 = vector<vector<double>>(half, vector<double>(half));
    A12 = vector<vector<double>>(half, vector<double>(half));
    A21 = vector<vector<double>>(half, vector<double>(half));
    A22 = vector<vector<double>>(half, vector<double>(half));

    for (int i = 0; i < half; i++){
        for (int j = 0; j < half; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];
        }
    }
}


#endif