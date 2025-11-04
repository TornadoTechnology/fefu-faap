#include <iomanip>
#include <iostream>
#include <limits>
#include <cmath>

int main() {
    int pgrRes;
    long double x, eps;
    std::cin >> x >> eps;

    if (eps > 0 && eps < 1) {
        long i = 1;

        long double fact_2i = 2; // (2i)!
        long double fact_i2 = 1; // (i^2)!

        long double a = (fact_2i + fabsl(x)) / fact_i2;
        long double s = 0;

        do {
            s += a;
            i++;

            long i2 = i * i;
            long double product = 1;
            for (long k = i2 - 2 * i + 2; k <= i2; k++) {
                product *= k;
            }

            fact_2i *= (2 * i - 1) * (2 * i);
            fact_i2 *= product;

            a = (fact_2i + fabsl(x)) / fact_i2;
        } while (fabsl(a) > eps);

        std::cout
            << std::fixed
            << std::setprecision(std::numeric_limits<long double>::max_digits10)
            << "s = " << s << std::endl;
        pgrRes = 0;
    } else {
        std::cerr << "eps must be in (0; 1)" << std::endl;
        pgrRes = 1;
    }

    return pgrRes;
}
