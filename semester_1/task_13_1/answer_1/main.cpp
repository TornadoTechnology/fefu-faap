// ReSharper disable CppUseAuto
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>

void input(const char* label, double& variable) {
    std::cout << label;
    std::cin >> variable;
}

void input(const char* label, std::string& variable) {
    std::cout << label;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, variable);
}

int main()
{
    const char* database_path = "main.dat1";

    std::ifstream data_stream(database_path);
    if (data_stream.fail()) {
        std::cout << "Failed opening file " << database_path << std::endl;
        return EXIT_FAILURE;
    }

    double min, max;
    input("Min price: ", min);
    input("Max price: ", max);

    std::string filter;
    input("Filter: ", filter);

    int index = 0;
    std::string temp_line;
    while (std::getline(data_stream, temp_line)) {
        std::istringstream temp_stream(temp_line);
        std::string model, price;

        std::getline(temp_stream, model, ';');
        std::getline(temp_stream, price);

        double priceNumber = std::stod(price);
        bool match = true;
        match = min <= priceNumber && priceNumber <= max && match;
        match = model.find(filter) != std::string::npos && match;

        if (match) {
            std::cout
                << ++index
                << ". "
                << model
                << " "
                << "(" << price << "$)"
                << std::endl;
        }
    }

    if (index == 0) {
        std::cout << "No fond" << std::endl;
    }

    data_stream.close();
    return EXIT_SUCCESS;
}