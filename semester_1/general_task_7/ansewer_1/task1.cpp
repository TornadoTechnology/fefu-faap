#include <iomanip>
#include <iostream>
#include <cmath>
#include <ctime>

int main() {
    const int W = 9;
    const int H = 9;
    const int cX = W / 2;
    const int cY = H / 2;
    const int r = std::min(W, H) / 2;
    int matrix [W][H] = {};

    // Init random
    srand(time(nullptr));

    // Fill random
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            matrix[i][j] = 1; // rand() % 100;
        }
    }

    // Out random
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    // S1
    int s1 = 0;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if (i == 0 || j == 0 || i == W - 1 || j == H - 1) {
               s1 += matrix[i][j];
            }
        }
    }
    std::cout << "S1: " << s1 << std::endl;

    // S2
    int s2 = 0;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if (i == j || i == H - j) {
                s2 += matrix[i][j];
            }
        }
    }
    std::cout << "S2: " << s2 << std::endl;

    // S3
    int s3 = 0;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if (std::abs(i - cX) + std::abs(j - cY) <= r) {
                s3 += matrix[i][j];
            }
        }
    }
    std::cout << "S3: " << s3 << std::endl;

    // S4
    int s4 = 0;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if ((i <= j && i <= H - 1 - j && i < H / 2) ||
                (i >= j && i >= H - 1 - j && i >= H / 2)) {
                s4 += matrix[i][j];
            }
        }
    }
    std::cout << "S4: " << s4 << std::endl;

    return 0;
}