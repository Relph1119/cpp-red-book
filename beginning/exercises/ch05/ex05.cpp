#include <iostream>

int main() {
    const size_t max_num_characters{1000};
    char string[max_num_characters];

    std::cout << "Please enter a string: ";
    std::cin.getline(string, max_num_characters);

    // 使用while统计字符个数
    size_t count{};
    while (count < max_num_characters && string[count] != '\0')
        ++count;

    // 反转数组中的字符
    for (size_t i{0}; i < count / 2; ++i) {
        char temp{string[i]};
        string[i] = string[count - i - 1];
        string[count - i - 1] = temp;
    }

    // 从左至右打印这些字符
    for (size_t i{0}; i < count; ++i) {
        std::cout << string[i];
    }
    std::cout << std::endl;
}