#include <iostream>
#include <cmath>

int main() {
    double a = 0;
    for (int i = 99; i > 0; i -= 3) {
        a = sqrt(a + i);
    }

    std::cout
        << "a = " << a << std::endl;

    return 0;
}
