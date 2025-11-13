#include<iostream>
#include<cmath>
#include <iomanip>

int main() {
    constexpr double lowRadius = 1.0;
    constexpr double highRadius = 2.0;

    double x, y;
    std::cout << "Enter x, y: " << std::endl;
    std::cin >> x >> y;

    double distance = sqrt(x * x + y * y);
    if (y >= 0 && distance >= lowRadius && distance <= highRadius) {
        std::cout << "In circle" << std::endl;
    } else {
        std::cout << "Out of circle" << std::endl;
    }

    return 0;
}
