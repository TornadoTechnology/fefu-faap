#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

int main() {
    long long i = 0;
    long double y = sin(1);

    do {
        i++;
        y = sinl(y);
    } while (fabsl(y) >= 0.0001);

    std::cout
        << "i = " << i << std::endl
        << std::fixed << std::setprecision(std::numeric_limits<long double>::max_digits10)
        << "y = " << y << std::endl;

    return 0;
}
