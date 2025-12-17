// ReSharper disable CppUseAuto
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <random>
#include <sstream>

constexpr double MIN_AMOUNT = 0.0;
constexpr double MAX_AMOUNT = 999999.99;

constexpr const char* ONES[]        = {"ноль", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
constexpr const char* ONES_FEMALE[] = {"ноль", "одна", "две", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
constexpr const char* TEENS[]       = {"десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"};
constexpr const char* TENS[]        = {"", "", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};
constexpr const char* HUNDREDS[]    = {"", "сто", "двести", "триста", "четыреста", "пятьсот","шестьсот", "семьсот", "восемьсот", "девятьсот"};

constexpr const char* RUBLE(const int n) {
    return n % 10 == 1 && n % 100 != 11 ? "рубль" : n % 10 >= 2 && n % 10 <= 4 && !(n % 100 >= 12 && n % 100 <= 14) ? "рубля" : "рублей";
}

constexpr const char* KOPECK(const int n) {
    return n % 10 == 1 && n % 100 != 11 ? "копейка" : n % 10 >= 2 && n % 10 <= 4 && !(n % 100 >= 12 && n % 100 <= 14) ? "копейки" : "копеек";
}

std::string convert_hundreds(int n, const bool female = false, const bool showZero = true) {
    if (n == 0) {
        return showZero ? std::string(female ? ONES_FEMALE[n] : ONES[n]) + " " : "";
    }

    std::string result;

    if (n >= 100) {
        result += HUNDREDS[n / 100];
        result += " ";
        n %= 100;
    }

    if (n >= 20) {
        result += TENS[n / 10];
        result += " ";
        n %= 10;
    } else if (n >= 10) {
        result += TEENS[n - 10];
        result += " ";
        n = 0;
    }

    if (n > 0) {
        result += female ? ONES_FEMALE[n] : ONES[n];
        result += " ";
    }

    return result;
}

std::string convert_thousands(const int n) {
    if (n == 0) {
        return "";
    }

    std::string result = convert_hundreds(n, true, true);
    if (n % 10 == 1 && n % 100 != 11) {
        result += "тысяча ";
    } else if (n % 10 >= 2 && n % 10 <= 4 && !(n % 100 >= 12 && n % 100 <= 14)) {
        result += "тысячи ";
    } else {
        result += "тысяч ";
    }

    return result;
}

std::string convert(const double amount) {
    const int rubles = static_cast<int>(amount);
    const int kopecks = static_cast<int>(std::round((amount - rubles) * 100));

    const int thousands = rubles / 1000;
    const int hundreds_part = rubles % 1000;

    std::ostringstream string_stream;

    string_stream << convert_thousands(thousands)
        << convert_hundreds(hundreds_part, false, thousands == 0)
        << RUBLE(rubles)
        << " "
        << convert_hundreds(kopecks, true)
        << KOPECK(kopecks);

    return string_stream.str();
}

void input(const char* label, double& value) {
    std::cout << label;
    std::cin >> value;
}

bool in_range(const double value, const double min, const double max) {
    return value >= min && value <= max;
}

bool valid_precision(const double value) {
    const double scaled = value * 100;
    return std::floor(scaled) == scaled;
}

int main() {
    double sum;
    input("Enter sum: ", sum);

    if (!in_range(sum, MIN_AMOUNT, MAX_AMOUNT)) {
        std::cout << "Out of range. Value must be between "
                  << MIN_AMOUNT << " and " << MAX_AMOUNT << std::endl;
        return EXIT_FAILURE;
    }

    if (!valid_precision(sum)) {
        std::cout << "Invalid input. Maximum 2 decimal places allowed." << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << convert(sum) << std::endl;
    return EXIT_SUCCESS;
}
