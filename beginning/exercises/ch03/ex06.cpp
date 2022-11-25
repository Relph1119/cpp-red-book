#include <iostream>

int main() {
    int first{}, second{};
    std::cout << "Enter two integers separated by a space: ";
    std::cin >> first >> second;

    // 由于亦或能作为备份使用，使用三次亦或即可完成交换目的
    first ^= second;
    second ^= first;
    first ^= second;
    std::cout << "In reverse order they are " << first << " and " << second << std::endl;
}