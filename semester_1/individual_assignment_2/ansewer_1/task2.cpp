#include <iostream>
#include <fstream>

int main() {
    const char* filePath = "in2.dat";

    std::ifstream stream(filePath);
    if (stream.fail()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return 1;
    }

    double a;
    stream >> a;
    stream.close();

    std::cout
        << "Input:" << std::endl
        << "a   = " << a << std::endl;

    const double a2 = a * a;
    const double a5 = a2 * a2 * a;
    const double a17 = a5 * a5 * a5 * a2;

    std::cout
        << "Output:" << std::endl
        << "a2  = " << a2 << std::endl
        << "a5  = " << a5 << std::endl
        << "a17 = " << a17 << std::endl
        << std::endl;
    return 0;
}
