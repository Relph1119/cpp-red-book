#include <iostream>
#include <format>
#include <cmath>

int main() {
    size_t n{};
    std::cout << "Enter the number of array elements: ";
    std::cin >> n;
    // 动态分配内存
    auto *values{new double[n]};
    for (size_t i{}; i < n; ++i)
        // 设置元素值
        *(values + i) = 1.0 / ((i + 1) * (i + 1));

    double sum{};
    for (size_t i{}; i < n; ++i)
        // 使用指针表示法计算元素的总和
        sum += *(values + i);

    std::cout << std::format("The result is {}", std::sqrt(6.0 * sum)) << std::endl;

    // 清除指针
    delete[] values;
    values = nullptr;
}