#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string text;
    std::cout << "Enter some text terminated by *:\n";
    std::getline(std::cin, text, '*');

    const auto whitespace{" \t\n\r\f\v"};  // Can be solved using std::isspace() as well...

    // 第一个非空字母索引
    const size_t first_letter_index{text.find_first_not_of(whitespace)};
    if (first_letter_index == std::string::npos) {
        return 0;
    }

    const char start_letter{static_cast<char>(std::toupper(text[first_letter_index]))};
    bool tautogram{true};

    // 第一个字母开始
    for (size_t start_current_word{first_letter_index};;) {
        // 寻找下一个空格的索引
        const size_t next_space_index{text.find_first_of(whitespace, start_current_word)};
        if (next_space_index == std::string::npos) {
            break;
        }
        // 下一个单词的起始索引
        const size_t next_letter_index{text.find_first_not_of(whitespace, next_space_index)};
        if (next_letter_index == std::string::npos) {
            break;
        }

        // 判断是否与当前相同
        if (std::toupper(text[next_letter_index]) != start_letter) {
            tautogram = false;
            break;
        }
        // 如果相同就继续寻找，并索引传递
        start_current_word = next_letter_index;
    }

    std::cout << "The text that you entered is " << (tautogram ? "" : "not ") << "a tautogram.\n";
    if (tautogram) {
        std::cout << "All words start with the letter " << start_letter << '.';
    }
}
