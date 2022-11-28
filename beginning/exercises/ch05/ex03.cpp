#include <iostream>
#include <cctype>

int main() {
    unsigned count{};
    char ch{};

    std::cout << "Please enter a sequence of characters terminated by '#':" << std::endl;

    do {
        std::cin >> ch;
        ++count;
    } while (ch != '#' && !std::isblank(ch));

    --count;
    std::cout << "You entered " << count << " characters (not counting spaces and the terminal #)." << std::endl;
}