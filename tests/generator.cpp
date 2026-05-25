#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>
#include <filesystem>
using namespace std;
using namespace std::filesystem;

mt19937 gen(random_device{}());

void save_matrix(const vector<vector<double>>& A, const string& filename) {
    ofstream file(filename);
    int n = A.size();
    file << n << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            file << A[i][j] << " ";
        file << "\n";
    }
}

// Enteros aleatorios
vector<vector<double>> int_random(int n) {
    uniform_int_distribution<int> dist(-500, 500);
    vector<vector<double>> A(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = dist(gen);
    return A;
}

// Reales aleatorios (entre 0 y 1)
vector<vector<double>> real_random(int n) {
    uniform_real_distribution<double> dist(0.0, 1.0);
    vector<vector<double>> A(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = dist(gen);
    return A;
}

// Matriz dispersa (la mayoria de sus elementos son 0)
vector<vector<double>> dispersa(int n) {
    uniform_int_distribution<int> dist(-500, 500);
    uniform_real_distribution<double> prob(0.0, 1.0);
    vector<vector<double>> A(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (prob(gen) > 0.9)
                A[i][j] = dist(gen);
    return A;
}

// Simetrica
vector<vector<double>> simetrica(int n) {
    uniform_int_distribution<int> dist(-100, 100);
    vector<vector<double>> A(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            A[i][j] = dist(gen);
            A[j][i] = A[i][j];
        }
    return A;
}

int main() {
    vector<int> sizes = {4, 8, 16, 32, 64, 128, 256, 512, 1024};

    create_directories("matrices/int_random");
    create_directories("matrices/real_random");
    create_directories("matrices/dispersa");
    create_directories("matrices/simetrica");

    for (int n : sizes) {
        string s = to_string(n);
        save_matrix(int_random(n),  "matrices/int_random/A_"  + s + ".txt");
        save_matrix(int_random(n),  "matrices/int_random/B_"  + s + ".txt");
        save_matrix(real_random(n), "matrices/real_random/A_" + s + ".txt");
        save_matrix(real_random(n), "matrices/real_random/B_" + s + ".txt");
        save_matrix(dispersa(n),    "matrices/dispersa/A_"    + s + ".txt");
        save_matrix(dispersa(n),    "matrices/dispersa/B_"    + s + ".txt");
        save_matrix(simetrica(n), "matrices/simetrica/A_" + s + ".txt");
        save_matrix(simetrica(n), "matrices/simetrica/B_" + s + ".txt");
    }

    cout << "Matrices generadas correctamente\n";
    return 0;
}