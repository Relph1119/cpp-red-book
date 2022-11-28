#include <iostream>
#include <string>
#include <vector>
#include <format>

int main() {
    std::cout << "Enter a sequence of numbers terminated by #:\n";

    std::string text;
    std::getline(std::cin, text, '#');

    std::vector<int> numbers {};

    size_t index{};
    while (true) {
        // 提取数字
        const size_t start{text.find_first_of("-0123456789", index)};
        if (start == std::string::npos)
            break;

        // 找到数字
        size_t end{text.find_first_not_of("0123456789", start + 1)};
        if (end == std::string::npos)
            end = text.length();

        const size_t length{end - start};
        // 截取数字字符串
        const auto substring{text.substr(start, length)};

        // 转换数字
        if (substring != "-") {
            const int number{std::stoi(substring)};
            numbers.push_back(number);
        }

        index = end;
    }

    std::cout << "The numbers you entered is: \n";

    // 每3个数字为一行
    const size_t per_line{5};
    size_t count{};
    for (auto &n : numbers) {
        std::cout << std::format("{:<4} ", n);
        if (++count % per_line) continue;
        std::cout << std::endl;
    }
}