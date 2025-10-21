#include <iomanip>
#include <iostream>
#include <limits>

int main() {
    int pgrRes, eps;
    long double x;

    std::cin >> x >> eps;

    long double a = 0;
    if (eps > 0) {
        for (int n = 0; n < eps; n++) {
            long double fact = 1;
            for (int j = 2; j <= 2 * n; j++) {
                fact *= j;
            }

            // Можно не использовать рекурентную формулу
            // проверить делимость на 2 и записать знак
            long double nPwr = 1;
            for (int j = 1; j <= n; j++) {
                nPwr *= -1;
            }

            long double xPwr = 1;
            for (int j = 1; j <= 2 * n; j++) {
                xPwr *= x;
            }

            a += nPwr * (xPwr / fact);
        }

        std::cout
            << std::fixed << std::setprecision(std::numeric_limits<long double>::max_digits10)
            << "sin(x) = " << a << std::endl;
        pgrRes = 0;
    } else {
        std::cerr << "eps must be grater than zero" << std::endl;
        pgrRes = 1;
    }

    return pgrRes;
}
