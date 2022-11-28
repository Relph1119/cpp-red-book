#include <iostream>
#include <format>

int main() {
    // 包含50个奇数的数组
    const size_t n{50};
    size_t odds[n];
    for (size_t i{}; i < n; ++i)
        odds[i] = i * 2 + 1;

    // 每一行显示10个数字
    const size_t per_line{10};
    std::cout << "The " << n << " first odd numbers are:\n";

    size_t *traversal_pointer{odds};
    for (size_t i{}; i < n; ++i) {
        // 使用指针递增
        std::cout << std::format("{:5}", *traversal_pointer++);
        if ((i + 1) % per_line == 0)
            std::cout << std::endl;
    }

    std::cout << "\nIn reverse order these numbers are:\n";
    for (size_t i{}; i < n; ++i) {
        // 使用指针递减
        std::cout << std::format("{:5}", *(--traversal_pointer));
        if ((i + 1) % per_line == 0)
            std::cout << std::endl;
    }
}