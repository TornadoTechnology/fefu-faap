#include<iostream>
#include<cmath>

int main() {
    double a, b, x;

    std::cout << "Enter a, b, x: " << std::endl;
    std::cin >> a >> b >> x;

    double ctg = 1 / tan(b * (x / 2));

    if (ctg != 0) {
        double y = fabs(sin(a * x) + cos(x + M_PI)) / sqrt(ctg);
        std::cout
            << "y = " << y
            << std::endl;
    } else {
        std::cout << "No solution" << std::endl;
    }

    return 0;
}