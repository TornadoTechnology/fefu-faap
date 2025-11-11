#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <cmath>

int main() {
    int pgrRes;
    long double x, eps;

    std::cin >> x >> eps;

    long double a = x;
    long double s = 0;

    if (eps > 0) {
        if (fabsl(x) < 1) {
            int n = 2;
            do {
                s += a;
                a *= -(x * (n - 1)) / n;
                n++;
            } while (fabsl(a) > eps);

            std::cout
                << std::fixed << std::setprecision(std::numeric_limits<long double>::max_digits10)
                << "ln(1 + x) = " << s << std::endl;
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
