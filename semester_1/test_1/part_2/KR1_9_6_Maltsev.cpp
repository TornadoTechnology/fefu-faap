#include<iostream>
#include<cmath>
#include <iomanip>

int main() {
    long double x, eps;
    std::cin >> x >> eps;

    long i = 1;

    long double ix = x;
    long double xi = x;
    long double ai = 3;
    long double s = 0;

    do {
        s += (xi + cosl(ix)) / ai;

        i++;

        ix += x;
        xi *= x;
        ai *= 3;
    } while (fabsl((xi + cosl(ix)) / ai) > eps);

    std::cout
          << std::fixed
          << std::setprecision(std::numeric_limits<long double>::max_digits10)
          << "s = " << s << std::endl;

    return 0;
}
