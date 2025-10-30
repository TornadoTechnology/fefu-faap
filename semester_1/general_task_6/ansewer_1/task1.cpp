#include <iomanip>
#include <iostream>
#include <limits>
#include <cmath>

int main() {
    int pgrRes;
    long double N, D, eps;
    std::cin >> N >> D >> eps;

    if (eps > 0) {
        if (D != 0) {
            long double x = 0.001L;

            do {
                x *= 2.0L - D * x;
            } while (fabsl(x * (2.0L - D * x) - x) > eps);

            long double Q = N * x;
            std::cout
                << std::fixed << std::setprecision(std::numeric_limits<long double>::max_digits10)
                << "N/D = " << Q << std::endl;
            pgrRes = 0;
        } else {
            std::cerr << "D must not be zero" << std::endl;
            pgrRes = 1;
        }
    } else {
        std::cerr << "eps must be grater than zero" << std::endl;
        pgrRes = 1;
    }

    return pgrRes;
}
