#include <iostream>
#include <array>

static_assert(sizeof(unsigned long long) >= 8,
              "This program assumes the depth of unsigned long long is (at least) 64 bit.");

int main() {
    const size_t n{93};
    // 包含93个元素的array容器
    std::array<unsigned long long, n> fib{};
    fib[0] = fib[1] = 1UL;
    // 构建Fibonacci数列
    for (size_t i{2}; i < n; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];

    std::cout << "The first " << n << " Fibonacci numbers are:\n";
    // 每行输出一个数
    for (auto number : fib) {
        std::cout << number << std::endl;
    }
}
