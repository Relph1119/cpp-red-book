#include <iostream>
#include <cctype>
#include <string>

int main() {
    std::string word1, word2;

    std::cout << "Enter the first word or phrase: ";
    std::getline(std::cin, word1);
    std::cout << "Enter the second word or phrase: ";
    std::getline(std::cin, word2);

    std::string word2_copy{word2};
    bool anagrams{true};

    for (char c : word1) {
        // 忽略空格
        if (!std::isalnum(c)) continue;

        bool found{false};
        for (size_t i{}; i < word2_copy.length(); ++i) {
            // 如果有一样的字符，就删除掉
            if (std::tolower(word2_copy[i]) == std::tolower(c)) {
                word2_copy.erase(i, 1);
                found = true;
                break;
            }
        }
        if (!found) {
            anagrams = false;
            break;
        }
    }

    // 判断剩下来的是否有空格，如果有，则不是回文
    for (char c : word2_copy) {
        if (std::isalnum(c)) {
            anagrams = false;
            break;
        }
    }

    std::cout << word1 << " and " << word2 << " are "
              << (anagrams ? "" : "not ")
              << "anagrams of one another."
              << std::endl;
}