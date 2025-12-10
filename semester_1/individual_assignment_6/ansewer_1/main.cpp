#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

constexpr int SIZE = 5;
constexpr int MATRIX_SIZE = 10;
constexpr int MATRIX_NUMBERS_COUNT = 2;
constexpr int MATRIX_PRINT_STEW = 8;

void print(double matrix[][MATRIX_SIZE]) {
    for (int x = 0; x < MATRIX_SIZE; x++) {
        for (int y = 0; y < MATRIX_SIZE; y++) {
            std::cout << std::setw(MATRIX_PRINT_STEW) << std::fixed << std::setprecision(2) << matrix[x][y];
        }
        std::cout << std::endl;
    }
}

void print(double matrix[][MATRIX_SIZE], const std::string &label) {
    std::cout << label << ": " << std::endl;
    print(matrix);
}

void square(double matrix[][MATRIX_SIZE], double result[][MATRIX_SIZE]) {
    for (int x = 0; x < MATRIX_SIZE; x++) {
        for (int y = 0; y < MATRIX_SIZE; y++) {
            result[x][y] = 0.0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                result[x][y] += matrix[x][k] * matrix[k][y];
            }
        }
    }
}

double getStep(double matrix[][MATRIX_SIZE]) {
    double step = 0.0;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        step += matrix[i][i];
    }
    return step;
}

void min(double matrices[SIZE][MATRIX_SIZE][MATRIX_SIZE], int* minIndex, double* minStep) {
    *minIndex = 0;
    *minStep = getStep(matrices[0]);

    for (int i = 1; i < SIZE; i++) {
        const double step = getStep(matrices[i]);
        if (step < *minStep) {
            *minIndex = i;
            *minStep = step;
        }
    }
}

void random(double matrix[][MATRIX_SIZE]) {
    for (int x = 0; x < MATRIX_SIZE; x++) {
        for (int y = 0; y < MATRIX_SIZE; y++) {
            matrix[x][y] = static_cast<double>(rand()) / RAND_MAX * (2 * MATRIX_NUMBERS_COUNT);
        }
    }
}

void random(double matrices[SIZE][MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        random(matrices[i]);
    }
}

int main() {
    double matrices[SIZE][MATRIX_SIZE][MATRIX_SIZE] = {};
    double squared[MATRIX_SIZE][MATRIX_SIZE] = {};

    std::ostringstream stream;

    srand(static_cast<unsigned int>(time(nullptr)));
    random(matrices);

    for (int i = 0; i < SIZE; i++) {
        stream.str("");
        stream << "matrix" << i << " (step " << getStep(matrices[i]) << ")";
        print(matrices[i], stream.str());
    }

    int minIndex;
    double minStep;
    min(matrices, &minIndex, &minStep);
    square(matrices[minIndex], squared);

    stream.str("");
    stream << "resulted squared matrix (number " << minIndex << ")";
    print(squared, stream.str());

    return 0;
}
