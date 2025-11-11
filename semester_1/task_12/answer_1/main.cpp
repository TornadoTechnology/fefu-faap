#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
    constexpr int WIDTH = 10;
    constexpr int HEIGHT = 15;
    int matrix[WIDTH][HEIGHT] = {};

    srand(time(nullptr));

    std::cout << "Matrix: " << std::endl;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            matrix[i][j] = rand() % 100;
            std::cout
                << std::setw(4)
                << matrix[i][j];
        }
        std::cout << std::endl;
    }

    std::cout
        << std::endl
        << "Saddle points:"
        << std::endl;

    bool found = false;
    for (int i = 0; i < WIDTH; i++) {

        int minInRow = matrix[i][0];
        int minCol = 0;

        for (int j = 1; j < HEIGHT; j++) {
            if (matrix[i][j] < minInRow) {
                minInRow = matrix[i][j];
                minCol = j;
            }
        }

        bool isSaddle = true;

        for (int k = 0; k < WIDTH; k++) {
            if (matrix[k][minCol] > minInRow) {
                isSaddle = false;
                break;
            }
        }

        if (isSaddle) {
            std::cout << "Point (" << i << ", " << minCol << ") = " << minInRow
                      << " (min in row, max in column)" << std::endl;
            found = true;
        }
    }

    for (int i = 0; i < WIDTH; i++) {
        int maxInRow = matrix[i][0];
        int maxCol = 0;
        for (int j = 1; j < HEIGHT; j++) {
            if (matrix[i][j] > maxInRow) {
                maxInRow = matrix[i][j];
                maxCol = j;
            }
        }
        bool isSaddle = true;
        for (int k = 0; k < WIDTH; k++) {
            if (matrix[k][maxCol] < maxInRow) {
                isSaddle = false;
                break;
            }
        }

        if (isSaddle) {
            std::cout << "Point (" << i << ", " << maxCol << ") = " << maxInRow
                      << " (max in row, min in column)" << std::endl;
            found = true;
        }
    }

    if (!found)
        std::cout << "No saddle points found." << std::endl;

    return 0;
}
