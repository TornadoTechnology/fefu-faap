#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    long int n;
    long double x;

    std::cout << "Enter n, x: " << std::endl;
    std::cin >> n >> x;

    long double sum = 0;
    long double a = -1;
    long double sqrtX = sqrtl(fabsl(x));

    for (long int i = 1; i <= n; i++) {
        sum += a + sqrtX;
        a *= -1.0 / (i + 1);
    }

    std::cout
        << std::fixed
        << std::setprecision(std::numeric_limits<long double>::max_digits10)
        << "Result: " << sum << std::endl;
}
