#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <cmath>

int main() {
    int pgrRes, eps;
    long double x;

    std::cin >> x >> eps;

    long double a = 0;
    if (eps > 0) {
        if (fabsl(x) < 1) {
            for (int n = 1; n < eps + 1; n++) {
                // Можно не использовать рекурентную формулу
                // проверить делимость на 2 и записать знак
                long double nPwr = 1;
                for (int j = 1; j <= n + 1; j++) {
                    nPwr *= -1;
                }

                long double xPwr = 1;
                for (int j = 1; j <= n; j++) {
                    xPwr *= x;
                }

                a += nPwr * (xPwr / n);
            }

            std::cout
                << std::fixed << std::setprecision(std::numeric_limits<long double>::max_digits10)
                << "ln(1 + x) = " << a << std::endl;
            pgrRes = 0;
        } else {
            std::cerr << "x must be less than one" << std::endl;
            pgrRes = 1;
        }
    } else {
        std::cerr << "eps must be grater than zero" << std::endl;
        pgrRes = 1;
    }

    return pgrRes;
}
