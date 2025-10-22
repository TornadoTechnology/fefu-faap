#include <iomanip>
#include <iostream>
#include <limits>
#include <cmath>

int main() {
    int pgrRes;
    long double x, eps;

    std::cin >> x >> eps;

    long double a = 1;
    long double s = 0;

    if (eps > 0) {
        int n = 1;
        do {
            s += a;
            a *= -(x * x) / ((2 * n - 1) * (2 * n));
            n++;
        } while (fabsl(a) > eps);

        std::cout
            << std::fixed << std::setprecision(std::numeric_limits<long double>::max_digits10)
            << "cos(x) = " << s << std::endl;
        pgrRes = 0;
    } else {
        std::cerr << "eps must be grater than zero" << std::endl;
        pgrRes = 1;
    }

    return pgrRes;
}
