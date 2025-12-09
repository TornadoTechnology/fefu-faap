#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

constexpr int SIZE = 5;
constexpr int MATRIX_SIZE = 10;
constexpr int MATRIX_NUMBERS_COUNT = 2;
constexpr int MATRIX_PRINT_STEW = 6;

void print(int matrix[][MATRIX_SIZE]) {
    for (int x = 0; x < MATRIX_SIZE; x++) {
        for (int y = 0; y < MATRIX_SIZE; y++) {
            std::cout << std::setw(MATRIX_PRINT_STEW) << matrix[x][y];
        }

        std::cout << std::endl;
    }
}

void print(int matrix[][MATRIX_SIZE], const std::string &label) {
    std::cout << label << ": " << std::endl;
    print(matrix);
}

void square(int matrix[][MATRIX_SIZE], int result[][MATRIX_SIZE]) {
    for (int x = 0; x < MATRIX_SIZE; x++) {
        for (int y = 0; y < MATRIX_SIZE; y++) {
            result[x][y] = 0;

            for (int k = 0; k < MATRIX_SIZE; k++) {
                result[x][y] += matrix[x][k] * matrix[k][y];
            }
        }
    }
}

int getStep(int matrix[][MATRIX_SIZE]) {
    int step = 0;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        step += matrix[i][i];
    }
    return step;
}

void min(int matrices[SIZE][MATRIX_SIZE][MATRIX_SIZE], int* minIndex, int* minStep) {
    *minIndex = 0;
    *minStep = getStep(matrices[0]);

    for (int i = 1; i < SIZE; i++) {
        const int step = getStep(matrices[i]);

        if (step < *minStep) {
            *minIndex = i;
            *minStep = step;
        }
    }
}

void random(int matrix[][MATRIX_SIZE]) {
    for (int x = 0; x < MATRIX_SIZE; x++) {
        for (int y = 0; y < MATRIX_SIZE; y++) {
            matrix[x][y] = rand() % (10 * MATRIX_NUMBERS_COUNT);
        }
    }
}

void random(int matrices[SIZE][MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        random(matrices[i]);
    }
}

int main() {
    int matrices[SIZE][MATRIX_SIZE][MATRIX_SIZE] = {};
    int squared[MATRIX_SIZE][MATRIX_SIZE] = {};

    std::ostringstream stream;

    srand(time(nullptr));
    random(matrices);

    for (int i = 0; i < SIZE; i++) {
        stream.str("");
        stream << "matrix" << std::to_string(i) << " (step " << getStep(matrices[i]) << ")";
        print(matrices[i], stream.str());
    }

    int minIndex, minStep;
    min(matrices, &minIndex, &minStep);
    square(matrices[minIndex], squared);

    stream.str("");
    stream << "resulted squared matrix (number " << minIndex << ")";

    print(squared, stream.str());

    return 0;
}
