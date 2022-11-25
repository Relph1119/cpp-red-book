#include <iostream>
#include <format>

int main() {
    const int inches_per_foot{12};

    std::cout << "This program will convert inches to feet and inches." << std::endl;

    int inches{};
    std::cout << "Please enter a number of inches: ";
    std::cin >> inches;

    const int feet = inches / inches_per_foot;
    const int remaining_inches = inches % inches_per_foot;

    std::cout
            << std::format("{} inches is {} feet and {} inches.", inches, feet, remaining_inches)
            << std::endl;
}