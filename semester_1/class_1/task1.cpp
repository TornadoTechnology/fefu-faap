#include <iomanip>
#include <iostream>
#include <cmath>
#include <ctime>

int main() {
    const int W = 5;
    const int H = 4;
    int matrix [W][H] = {};

    // Init random
    srand(time(nullptr));

    // Fill random
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    // Out random
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}