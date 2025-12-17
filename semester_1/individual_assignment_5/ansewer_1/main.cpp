// ReSharper disable CppUseAuto
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

constexpr double MIN_ELEMENT = -100;
constexpr double MAX_ELEMENT = 100;

double array_max(const double* array, const int length) {
    double max = array[0];
    for (int i = 1; i < length; i++) {
        if (const double element = array[i]; element > max) {
            max = element;
        }
    }
    return max;
}

double array_min(const double* array, const int length) {
    double min = array[0];
    for (int i = 1; i < length; i++) {
        if (const double element = array[i]; element < min) {
            min = element;
        }
    }
    return min;
}

void array_print(const double* array, const int length, const bool new_line = true) {
    for (int i = 0; i < length; i++) {
        std::cout
            << std::setprecision(2)
            << array[i];

        if (i != length - 1) {
            std::cout << ", ";
        }
    }

    if (new_line) {
        std::cout << std::endl;
    }
}

std::mt19937& get_random_device() {
    static std::mt19937 gen { std::random_device{}() };
    return gen;
}

void matrix_randomize(double* matrix, const int length) {
    static std::uniform_real_distribution distribution(MIN_ELEMENT, MAX_ELEMENT);

    std::mt19937& random_device = get_random_device();

    for (int i = 0; i < length; i++) {
        matrix[i] = distribution(random_device);
    }
}

void matrix_randomize(double* matrix, const int width, const int height) {
    matrix_randomize(matrix, width * height);
}

void matrix_print(const double* matrix, const int width, const int height) {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            std::cout
                << std::setw(8)
                << std::fixed
                << std::setprecision(2)
                << matrix[x + y * width];
        }

        std::cout << std::endl;
    }
}

void matrix_get_colum(const double* matrix, double* result, const int colum_index, const int width, const int height)
{
    for (int y = 0; y < height; y++) {
        result[y] = matrix[colum_index + y * width];
    }
}

int main() {
    constexpr int M = 10;
    constexpr int N = 10;

    std::cout << "Matrix:" << std::endl;

    double matrix[M * N];
    matrix_randomize(matrix, M, N);
    matrix_print(matrix, M, N);

    std::cout << std::endl;

    double max_colum_elements[M];
    double temp_colum[N];

    std::cout << "Calculate max colum elements..." << std::endl << std::endl;

    for (int i = 0; i < M; i++) {
        matrix_get_colum(matrix, temp_colum, i, M, N);
        max_colum_elements[i] = array_max(temp_colum, M);

        std::cout << "max { ";
        array_print(temp_colum, N, false);
        std::cout << " } = " << max_colum_elements[i] << std::endl;
    }

    const double result = array_min(max_colum_elements, M);

    std::cout << "min { ";
    array_print(temp_colum, N, false);
    std::cout << " } = " << result << std::endl;

    std::cout << std::endl << "result is " << result << std::endl;

    return EXIT_SUCCESS;
}