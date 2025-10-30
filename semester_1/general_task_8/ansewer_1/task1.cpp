#include <iomanip>
#include <iostream>
#include <cmath>
#include <ctime>

int main() {
    const int W = 7;
    const int H = 7;
    double matrix [W][H] = {};

    // Init random
    srand(time(nullptr));

    // Fill random
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            matrix[i][j] = -1.0 + 2.0 * (rand() / static_cast<double>(RAND_MAX));
        }
    }

    // Out random
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            std::cout
                << std::setprecision(4)
                << std::setw(10)
                << matrix[i][j];
        }
        std::cout << std::endl;
    }

    double maxElement = matrix[0][0];
    int maxRow = 0;
    int maxCol = 0;

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    std::cout << "Max element: "
        << std::fixed << std::setprecision(3)
        << maxElement
        << " {"
        << maxRow + 1
        << ", "
        << maxCol + 1
        << "}"
        << std::endl;


    double minElement = matrix[0][0];
    int minRow = 0;
    int minCol = 0;

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }

    std::cout << "Min element: "
    << std::fixed << std::setprecision(3)
    << minElement
    << " {"
    << minRow + 1
    << ", "
    << minCol + 1
    << "}"
    << std::endl;

    double scalarProduct = 0.0;
    for (int i = 0; i < W; i++) {
        scalarProduct += matrix[maxRow][i] * matrix[i][minCol];
    }

    std::cout << "Scalar product {"
    << maxRow + 1
    << ", "
    << minCol + 1
    << "}: "
    << std::fixed << std::setprecision(6)
    << scalarProduct
    << std::endl;

    return 0;
}