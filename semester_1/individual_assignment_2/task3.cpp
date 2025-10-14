#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    const char* inPath = "in3.dat";
    const char* outPath = "out3.dat";

    std::ifstream inStream(inPath);
    if (inStream.fail()) {
        std::cerr << "Failed to open file: " << inPath << std::endl;
        return 1;
    }

    double x, y ,z;
    inStream >> x >> y >> z;
    inStream.close();

    std::cout
        << "Input:" << std::endl
        << "x = " << x << std::endl
        << "y = " << y << std::endl
        << "z = " << z << std::endl
        << std::endl;

    const double x24 = x * x + 4; 
    const double a = (1.0 + y) * ((x + y / x24) / (exp(-x - 2) + 1.0 / x24));
    const double b = (1.0 + cos(y - 2.0)) / (pow(x, 4) / 2.0 + pow(sin(z), 2));

    std::ofstream outStream(outPath);
    if (outStream.fail()) {
        std::cerr << "Failed to open file: " << outPath << std::endl;
        return 1;
    }

    outStream << "a = " << a << std::endl;
    outStream << "b = " << b << std::endl;
    outStream.close();
    return 0;
}
