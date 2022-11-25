#include <iostream>

int main() {
    unsigned a{};
    unsigned b{};

    std::cout << "Enter a positive integer: ";
    std::cin >> a;
    std::cout << "Enter another positive integer: ";
    std::cin >> b;

    // 当a>b，则a/b=1，b/a=0
    // 当a<b，则a/b=0，b/a=1
    const unsigned larger{(a * (a / b) + b * (b / a)) / (a / b + b / a)};
    const unsigned smaller{(b * (a / b) + a * (b / a)) / (a / b + b / a)};
    std::cout << "The larger integer is " << larger << ".\n"
              << "The smaller integer is " << smaller << '.' << std::endl;
}