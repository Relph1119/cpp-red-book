#include <iostream>
#include <cctype>
#include <string>

int main() {
    std::string word1, word2;

    std::cout << "Enter the first word: ";
    std::cin >> word1;
    std::cout << "Enter the second word: ";
    std::cin >> word2;

    // 检查长度是否一致
    if (word1.length() != word2.length()) {
        std::cout << word1 << " and " << word2 << " are different lengths so they can't be anagrams!" << std::endl;
        return 0;
    }

    std::string word2_copy{word2};
    for (char c : word1) {
        for (size_t i{}; i < word2_copy.length(); ++i) {
            // 如果有一样的字符，就删除掉
            if (std::tolower(word2_copy[i]) == std::tolower(c)) {
                word2_copy.erase(i, 1);
                break;
            }
        }
    }

    // 如果全部删完，就打印是回文
    std::cout << word1 << " and " << word2 << " are "
              << (word2_copy.empty() ? "" : "not ")
              << "anagrams of one another."
              << std::endl;
}