#include <iostream>
#include <format>
#include <cmath>
#include <vector>
#include <memory>

int main() {
    size_t n{};
    std::cout << "Enter the number of vector elements: ";
    std::cin >> n;
    // 用智能指针替换原始指针
    auto values{std::make_unique<std::vector<double>>(n)};

    for (size_t i{}; i < n; ++i)
        (*values)[i] = 1.0 / ((i + 1) * (i + 1));

    double sum{};
    for (auto value : *values)
        sum += value;

    std::cout << std::format("Result is {}", std::sqrt(6.0 * sum)) << std::endl;
}