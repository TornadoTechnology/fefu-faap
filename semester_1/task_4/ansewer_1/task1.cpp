#include <iostream>

int main() {
    int f1 = 1;
    for (int i = 2; i < 11; i++) {
        f1 *= i;
    }

    int f2 = 1;
    {
        int i = 1;
        while (i < 11) {
            f2 *= i;
            i++;
        }
    }

    int f3 = 1;
    {
        int i = 1;
        do {
            f3 *= i;
            i++;
        } while (i < 11);
    }

    std::cout
        << "f1 = " << f1 << std::endl
        << "f2 = " << f2 << std::endl
        << "f3 = " << f3 << std::endl;

    return 0;
}
