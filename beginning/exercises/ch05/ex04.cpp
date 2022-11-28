#include <iostream>

int main() {
    const size_t max_num_characters{1000};
    char string[max_num_characters];

    std::cout << "Please enter a string: ";
    std::cin.getline(string, max_num_characters);

    // 计算字符个数
    size_t count{};
    for (; count < max_num_characters && string[count] != '\0'; ++count) {}

    // 逆序逐个输出所有字符
    for (size_t i{1}; i <= count; ++i) {
        std::cout << string[count - i];
    }
    std::cout << std::endl;
}
