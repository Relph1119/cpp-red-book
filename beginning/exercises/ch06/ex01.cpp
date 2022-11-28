#include <iostream>
#include <format>

int main() {
    const size_t n{50};
    // 包含50个奇数的数组
    size_t odds[n];
    for (size_t i{}; i < n; ++i)
        odds[i] = i * 2 + 1;

    // 每一行显示10个数字
    const size_t per_line{10};
    std::cout << "The " << n << " first odd numbers are:\n";
    for (size_t i{}; i < n; ++i) {
        // 使用指针表示法
        std::cout << std::format("{:5}", *(odds + i));
        if ((i + 1) % per_line == 0)
            std::cout << std::endl;
    }

    std::cout << "\nIn reverse order these numbers are:\n";
    for (int i{n - 1}; i >= 0; --i) {
        std::cout << std::format("{:5}", *(odds + i));
        if (i % per_line == 0)
            std::cout << std::endl;
    }
}