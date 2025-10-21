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
            for (int j = 2; j <= n; j++) {
                fact *= j;
            }

            long double pwr = 1;
            for (int j = 1; j <= n; j++) {
                pwr *= x;
            }

            a += pwr / fact;
        }

        std::cout
            << std::fixed << std::setprecision(std::numeric_limits<long double>::max_digits10)
            << "e^x = " << a << std::endl;
        pgrRes = 0;
    } else {
        std::cerr << "eps must be grater than zero" << std::endl;
        pgrRes = 1;
    }

    return pgrRes;
}
