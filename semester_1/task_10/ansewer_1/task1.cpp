#include <iomanip>
#include <iostream>
#include <cmath>
#include <ctime>

int main() {
    const int Size = 10;
    double matrix[Size][Size] = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
    };

    bool isOrthonormal = true;
    for (int i = 0; i < Size && isOrthonormal; i++) {
        for (int j = i; j < Size && isOrthonormal; j++) {
            const double tolerance = 1e-10;
            double product = 0.0;

            for (int k = 0; k < Size; k++)
                product += matrix[i][k] * matrix[j][k];

            if (i == j) {
                if (fabs(product - 1.0) > tolerance) {
                    isOrthonormal = false;
                    std::cout
                        << "Row " << i + 1
                        << " not normalized: scalar square = " << product
                        << std::endl;
                }
            } else {
                if (fabs(product) > tolerance) {
                    isOrthonormal = false;
                    std::cout
                        << "Rows "<< i << " & " << j
                        << " are not orthogonal: scalar product = " << product
                        << std::endl;
                }
            }
        }
    }

    if (isOrthonormal) {
        std::cout << "The matrix is orthonormal" << std::endl;
    } else {
        std::cout << "The matrix is not orthonormal" << std::endl;
    }

    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            std::cout
                << std::setw(4)
                << matrix[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}