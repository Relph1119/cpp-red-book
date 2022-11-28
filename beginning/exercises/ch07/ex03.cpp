#include <iostream>
#include <string>
#include <cctype>

int main() {
    // 输入的单词
    std::string text;
    // 要替换的单词
    std::string word;

    std::cout << "Enter some text terminated by *:\n";
    std::getline(std::cin, text, '*');
    std::cout << "\nEnter the word to be replaced: ";
    std::cin >> word;

    std::string lower_word;
    for (char ch : word)
        lower_word += std::tolower(ch);

    // 单词分割符
    const std::string separators{" ,;:.\"!?'\n"};

    size_t start{text.find_first_not_of(separators)};
    while (start != std::string::npos) {
        // 找到一个单词
        auto end{text.find_first_of(separators, start + 1)};
        if (end == std::string::npos)
            end = text.length();

        // 比较单词
        if (end - start == word.length()) {
            bool is_same_word{true};
            for (size_t i{start}; i < end; ++i) {
                // 单词不同
                if (lower_word[i - start] != std::tolower(text[i])) {
                    is_same_word = false;
                    break;
                }
            }
            // 如果单词相同
            if (is_same_word) {
                // 进行替换
                for (size_t i{start}; i < end; ++i)
                    text[i] = '*';
            }
        }
        // 继续查找下一个单词
        start = text.find_first_not_of(separators, end + 1);
    }

    std::cout << std::endl << text << std::endl;
}
