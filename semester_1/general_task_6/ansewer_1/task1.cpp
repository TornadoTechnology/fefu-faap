#include <iomanip>
#include <iostream>
#include <limits>
#include <cmath>

int main() {
    const long double x0 = 0.001L;

    int pgrRes;
    long double N, D, eps;
    std::cin >> N >> D >> eps;

    if (eps > 0 && eps < 1) {
        if (D != 0) {
            long double x = x0;

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
        std::cerr << "eps must be in (0; 1)" << std::endl;
        pgrRes = 1;
    }

    return pgrRes;
}
