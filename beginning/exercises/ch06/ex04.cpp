#include <iostream>
#include <format>
#include <cmath>
#include <vector>

int main() {
    size_t n{};
    std::cout << "Enter the number of vector elements: ";
    std::cin >> n;
    // 使用在自由存储区中分配的vector<>容器
    auto *values{new std::vector<double>(n)};

    for (size_t i{}; i < n; ++i)
        (*values)[i] = 1.0 / ((i + 1) * (i + 1));

    double sum{};
    for (auto value : *values)
        sum += value;

    std::cout << std::format("Result is {}", std::sqrt(6.0 * sum)) << std::endl;

    delete values;
}