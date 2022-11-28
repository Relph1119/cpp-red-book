#include <iostream>
#include <format>
#include <cctype>
#include <string>
#include <vector>

int main() {
    // 输入的文本字符串
    std::string text;
    // 包含字母的字符串
    std::string letters;
    std::cout << "Enter some text terminated by *:\n";
    std::getline(std::cin, text, '*');
    std::cout << "\nEnter the starting letters for the words you want to find: ";
    std::cin >> letters;

    // 单词分隔符
    const std::string separators{" ,;:.\"!?'\n"};
    // 找到的单词
    std::vector<std::string> words;
    // 每5个单词为一行
    const size_t per_line{5};
    size_t count{};
    // 遍历字母
    for (auto ch : letters) {
        // 搜索单词
        size_t start{text.find_first_not_of(separators)};
        size_t max_length{};
        while (start != std::string::npos) {
            auto end{text.find_first_of(separators, start + 1)};
            if (end == std::string::npos)
                end = text.length();
            // 判断单词是否以字母开头
            auto word{text.substr(start, end - start)};
            if (std::toupper(word[0]) == std::toupper(ch)) {
                words.push_back(word);
                if (max_length < word.length()) max_length = word.length();
            }

            // 继续寻找下一个单词
            start = text.find_first_not_of(separators, end + 1);
        }

        // 打印单词列表
        std::cout << "\nWords beginning with '" << ch << "' are:\n";
        for (auto &word : words) {
            std::cout << std::format("{:<{}}", word, max_length + 2);
            if (++count % per_line) continue;
            std::cout << std::endl;
        }
        std::cout << std::endl;
        words.clear();
        count = 0;
    }
}
