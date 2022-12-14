#include <iostream>
#include <format>
#include <cctype>

int main() {
    unsigned int count{};
    long long total{0};

    while (true) {
        std::cout << "Enter an integer: ";
        int n;
        std::cin >> n;
        // 计算整数和
        total = total + n;
        ++count;

        char yesno{};
        std::cout << "Do you want to enter another (y/n)?";
        std::cin >> yesno;

        if (std::tolower(yesno) == 'n')
            break;
    }

    std::cout
    << std::format("The total is {}. The average is {:.2f}.",
                   total, static_cast<double>(total) / count)
                   << std::endl;
}
