#include <iomanip>
#include <iostream>
#include <cmath>
#include <ctime>

int main() {
    const int RND_MAX = 10000;

    const int n = 5;
    const int m = 5;
    const int k = 5;

    const int A_W = n;
    const int A_H = m;
    const int B_W = m;
    const int B_H = k;
    const int C_W = n;
    const int C_H = k;

    int matrixA[A_W][A_H] = {};
    int matrixB[B_W][B_H] = {};
    int matrixC[C_W][C_H] = {};

    // Init random
    srand(time(nullptr));

    // Fill random matrix A
    for (int i = 0; i < A_W; i++) {
        for (int j = 0; j < A_H; j++) {
            matrixA[i][j] = rand() % RND_MAX;
        }
    }

    // Out random matrix A
    std::cout << "MatrixA:" << std::endl;
    for (int i = 0; i < A_W; i++) {
        for (int j = 0; j < A_H; j++) {
            std::cout
                << std::setprecision(4)
                << std::setw(10)
                << matrixA[i][j];
        }
        std::cout << std::endl;
    }

    // Fill random matrix B
    for (int i = 0; i < B_W; i++) {
        for (int j = 0; j < B_H; j++) {
            matrixB[i][j] = rand() % RND_MAX;
        }
    }

    // Out random matrix B
    std::cout << "MatrixB:" << std::endl;
    for (int i = 0; i < B_W; i++) {
        for (int j = 0; j < B_H; j++) {
            std::cout
                << std::setprecision(4)
                << std::setw(10)
                << matrixB[i][j];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < C_W; i++) {
        for (int j = 0; j < C_H; j++) {
            matrixC[i][j] = 0;

            for (int l = 0; l < A_H; l++) {
                matrixC[i][j] += matrixA[i][l] * matrixB[l][j];
            }
        }
    }

    // Out random matrix C
    std::cout << "MatrixC (A x B):" << std::endl;
    for (int i = 0; i < C_W; i++) {
        for (int j = 0; j < C_H; j++) {
            std::cout
                << std::setprecision(4)
                << std::setw(10)
                << matrixC[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}