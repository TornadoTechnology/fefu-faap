#include <iostream>

int main() {
    int n, m;
    bool break_flag = false;

    do {
        std::cin >> n >> m;
        if (n % m == 0 || m % n == 0) {
            std::cout
                << "Found pair, where the numbers are multiples of each other: "
                << n << " and " << m << std::endl;
            break_flag = true;
        } else {
            std::cout
                << "Numbers " << n << " and " << m << " "
                << "are not multiples of each other. Continue..." << std::endl;
        }
    } while (!break_flag);

    std::cout << "End" << std::endl;
    return 0;
}