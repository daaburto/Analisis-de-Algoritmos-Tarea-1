#ifndef HYBRID_HPP
#define HYBRID_HPP

#include "clasico.hpp"
#include "strassen.hpp"
using namespace std;

Matrix hybrid(const Matrix& A, const Matrix& B, int n, int n0) {
    if (n >= n0)
        return strassen(A, B, n);
    return multiply(A, B, n);
}

#endif