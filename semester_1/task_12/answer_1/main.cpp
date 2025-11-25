#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
    constexpr int WIDTH = 10;
    constexpr int HEIGHT = 15;

    int MATRIX[WIDTH][HEIGHT] = {};

    /*
    {
        { 3, 8, 4 },
        { 2, 7, 9 },
        { 5, 6, 1 }
    };
        points: (2, 1) = 6
    */

    srand(time(nullptr));

    std::cout << "Matrix: " << std::endl;

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            MATRIX[i][j] = rand() % 100;
            std::cout
                << std::setw(4)
                << MATRIX[i][j];
        }

        std::cout << std::endl;
    }

    std::cout
        << std::endl
        << "Saddle points:"
        << std::endl;

    bool found = false;
    for (int i = 0; i < WIDTH; i++) {
        int minInRow = MATRIX[i][0];
        int maxInRow = MATRIX[i][0];

        int minCol = 0;
        int maxCol = 0;

        for (int j = 1; j < HEIGHT; j++) {
            if (MATRIX[i][j] < minInRow) {
                minInRow = MATRIX[i][j];
                minCol = j;
            }

            if (MATRIX[i][j] > maxInRow) {
                maxInRow = MATRIX[i][j];
                maxCol = j;
            }
        }

        bool isSaddleMin = true;
        bool isSaddleMax = true;

        for (int k = 0; k < WIDTH && (isSaddleMax || isSaddleMin); k++) {
            if (MATRIX[k][minCol] > minInRow)
                isSaddleMin = false;

            if (MATRIX[k][maxCol] < maxInRow)
                isSaddleMax = false;
        }

        if (isSaddleMin) {
            std::cout << "Point (" << i << ", " << minCol << ") = " << minInRow
                      << " (min in row, max in column)" << std::endl;
            found = true;
        }

        if (isSaddleMax) {
            std::cout << "Point (" << i << ", " << maxCol << ") = " << maxInRow
                      << " (max in row, min in column)" << std::endl;
            found = true;
        }
    }

    if (!found)
        std::cout << "No saddle points found." << std::endl;

    return 0;
}
