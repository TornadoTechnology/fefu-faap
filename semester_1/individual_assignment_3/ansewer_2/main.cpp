#include <iostream>

int main() {
    int pgrRes;
    int a1, b1, c1, a2, b2, c2;

    std::cout << "Enter: a1, b1, c1, a2, b2, c2" << std::endl;
    std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    if (a1 * b1 * c1 * a2 * b2 * c2 != 0) {
        int result = 0;
        if (a1 * b2 - a2 * b1 != 0 || a1 / a2 == b1 / b2 == c1 / c2) {
            result = 1;
        }

        std::cout << "r = "<< result << std::endl;
        pgrRes = 0;
    } else {
        std::cerr << "Input must be grater than zero" << std::endl;
        pgrRes = 1;
    }

    return pgrRes;
}
