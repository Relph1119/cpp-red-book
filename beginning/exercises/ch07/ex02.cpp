#include <iostream>
#include <format>
#include <string>
#include <vector>

int main() {
    std::string text;
    std::cout << "Enter some text terminated by *:\n";
    std::getline(std::cin, text, '*');

    // 单词分隔符
    const std::string separators{" ,;:.\"!?'\n"};
    std::vector<std::string> words;
    // 单词个数
    std::vector<size_t> counts;

    size_t start{text.find_first_not_of(separators)};
    while (start != std::string::npos) {
        // 单词尾部的索引
        size_t end{text.find_first_of(separators, start + 1)};
        // 是否为分隔符
        if (end == std::string::npos)
            end = text.length();
        // 找到单词
        std::string word{text.substr(start, end - start)};

        // 该单词是否存在
        bool is_in{false};
        for (int i{}; i < words.size(); ++i) {
            if (words[i] == word) {
                // 记录数加1
                ++counts[i];
                is_in = true;
                break;
            }
        }
        // 如果不存在，是一个新单词
        if (!is_in) {
            words.push_back(word);
            counts.push_back(1);
        }
        // 寻找下一个单词
        start = text.find_first_not_of(separators, end + 1);
    }

    size_t max_length{};
    for (auto &word : words)
        if (max_length < word.length()) max_length = word.length();

    std::cout << "Your string contains the following " << words.size() << " words and counts:\n";
    size_t count{};
    const size_t per_line{3};
    for (size_t i{}; i < words.size(); ++i) {
        std::cout << std::format("{:<{}}{:>4}  ", words[i], max_length, counts[i]);
        if (!(++count % per_line))
            std::cout << std::endl;
    }
    std::cout << std::endl;
}