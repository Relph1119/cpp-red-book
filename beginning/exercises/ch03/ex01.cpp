#include <iostream>
#include <format>

int main() {
    int value{};
    std::cout << "Enter any integer: ";
    std::cin >> value;

    // 取反，并存储
    const auto inverted{static_cast<unsigned>(~value)};

    std::cout << std::format(" {:^34} {:^34} {:^34}\n", "value", "~value", "~value + 1");

    // 以二进制输出
    std::cout << std::format(" {:#034b} {:#034b} {:#034b}\n", value, inverted, inverted + 1);

    // 以十进制输出
    std::cout << std::format(" {:^34} {:^34} {:^34}\n", value, ~value, ~value + 1);
}