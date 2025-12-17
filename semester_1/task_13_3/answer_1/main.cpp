// ReSharper disable CppUseAuto
// ReSharper disable CppTooWideScopeInitStatement
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

void input(const char* label, std::string& value) {
    std::cout << label;
    std::getline(std::cin, value);
}

std::string remove_nested_parentheses(std::string input) {
    int depth = 0;

    std::size_t write = 0;
    std::size_t read = 0;

    while (read < input.size()) {
        const char ch = input[read];

        if (ch == '(') {
            if (depth == 0) {
                input[write++] = ' ';
            }

            depth++;
        }
        else if (ch == ')') {
            if (depth > 0) {
                depth--;
            }
        }
        else if (depth == 0) {
            input[write++] = ch;
        }

        read++;
    }

    input.resize(write);

    return input;
}

int main() {
    std::string text;
    input("input: ", text);

    std::cout << "output: " << remove_nested_parentheses(text) << std::endl;

    return EXIT_SUCCESS;
}
