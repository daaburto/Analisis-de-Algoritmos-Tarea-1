#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<vector<double>> add(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int n = A.size();
    vector<vector<double>> C(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

vector<vector<double>> subtract(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int n = A.size();
    vector<vector<double>> C(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Dividir matriz en 4
void splitMatrix(const vector<vector<double>>& A, vector<vector<double>>& A11, vector<vector<double>>& A12, vector<vector<double>>& A21, vector<vector<double>>& A22){
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

// Unir matriz
vector<vector<double>> joinMatrix(const vector<vector<double>>& C11, const vector<vector<double>>& C12, const vector<vector<double>>& C21, const vector<vector<double>>& C22){
    int half = C11.size();
    int n = half*2;

    vector<vector<double>> C(n, vector<double>(n));

    for (int i = 0; i < half; i++){
        for (int j = 0; j < half; j++){
            C[i][j] = C11[i][j];
            C[i][j+half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
    return C;
}

// Cargar matriz de un archivo
vector<vector<double>> load_matrix(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        exit(EXIT_FAILURE);
    }
    int n;
    file >> n;
    vector<vector<double>> A(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            file >> A[i][j];
    return A;
}
#endif