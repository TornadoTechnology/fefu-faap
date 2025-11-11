#include <iostream>

int main() {
    constexpr int SIZE = 3;
    constexpr int MATRIX[SIZE][SIZE] = {
        {8, 1, 6},
        {3, 5, 7},
        {4, 9, 2},
    };

    bool isMagick = true;

    int sum1 = 0;
    int sum2 = 0;
    int sumRow = 0;
    int sumColum = 0;

    for (int i = 0; i < SIZE && isMagick; i++) {
        sumRow = 0;
        sumColum = 0;

        for (int j = 0; j < SIZE; j++) {
            sumRow += MATRIX[i][j];
            sumColum += MATRIX[j][i];
        }

        sum1 += MATRIX[i][i];
        sum2 += MATRIX[SIZE - i - 1][SIZE - i - 1];

        if (sumRow != sumColum)
            isMagick = false;
    }

    if (isMagick && sum1 != sumRow && sum2 != sumRow)
        isMagick = false;

    if (isMagick) {
        std::cout << "Matrix is magick" << std::endl;
    } else {
        std::cout << "Matrix is not magick" << std::endl;
    }

    return 0;
}