#ifndef HYBRID_HPP
#define HYBRID_HPP

#include <iostream>
#include <vector>
#include "clasico.hpp"
#include "strassen.hpp"
using namespace std;

vector<vector<double>> hybrid(const vector<vector<double>>& A, const vector<vector<double>>& B, int n0){
    int n = A.size();

    vector<vector<double>> C;

    if (n >= n0){
        //cout << "Se utilizo Strassen";
        C = strassen(A, B);
    }else{
        //cout << "Se utilizo el algoritmo clasico";
        C = multiply(A, B);
    }

    return C;
}

#endif