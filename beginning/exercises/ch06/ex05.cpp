#include <iostream>
#include <format>
#include <cmath>
#include <memory>

int main() {
    size_t n{};
    std::cout << "Enter the number of array elements: ";
    std::cin >> n;
    // 使用智能指针存储数组
    auto values{std::make_unique<double[]>(n)};
    for (size_t i{}; i < n; ++i)
        values[i] = 1.0 / ((i + 1) * (i + 1));

    double sum{};
    for (size_t i{}; i < n; ++i)
        sum += values[i];

    std::cout << std::format("The result is {}", std::sqrt(6.0 * sum)) << std::endl;
}