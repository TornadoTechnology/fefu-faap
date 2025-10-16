#include <iostream>
#include <cmath>

int main() {
    double a;
    std::cin >> a;

    if (a < 0) {
        std::cerr << "Excepted that a grater than zero" << std::endl;
        return 1;
    }

    const double v = pow(a, 3);
    const double s = 6 * pow(a, 2);

    std::cout
        << "v = " << v << std::endl
        << "s = " << s << std::endl;
    return 0;
}
