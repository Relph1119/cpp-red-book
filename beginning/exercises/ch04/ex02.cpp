#include <iostream>
#include <cmath>

int main() {
    int value1{};
    int value2{};

    std::cout << "Please input two positive integers, separated by a space: ";
    std::cin >> value1 >> value2;
    std::cout << std::endl;

    if (value1 <= 0 || value2 <= 0) {
        std::cout << "Sorry - positive integers only." << std::endl;
        return 1;
    }

    int value_max {std::max(value1, value2)};
    int value_min {std::min(value1, value2)};

    if (value_max % value_min == 0)
        std::cout << value_max << " divides into " << value_min << " exactly. " << std::endl;
    else
        std::cout << value_max << " is not exactly divisible by " << value_min << std::endl;
}