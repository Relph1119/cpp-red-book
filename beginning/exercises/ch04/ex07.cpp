#include <iostream>
#include <cctype>

int main() {
    char entered_letter{};
    std::cout << "Enter a letter: ";
    std::cin >> entered_letter;

    // 判断是否为字母
    if (!std::isalpha(entered_letter)) {
        std::cout << "That's not a letter!" << std::endl;
        return 1;
    }

    const auto lower_case_letter{static_cast<char>(std::tolower(entered_letter))};

    // 是否为小写字母
    std::cout << "'" << entered_letter << "' is " <<
    (std::islower(entered_letter) ? "lowercase" : "uppercase") << '.' << std::endl;

    // 是否为元音字母
    std::cout << "'" << entered_letter << "' is a ";

    switch (lower_case_letter) {
        case 'a':
            case 'e':
                case 'i':
                    case 'o':
                        case 'u':
                            std::cout << "vowel";
                            break;
                            default:
                                std::cout << "consonant";
                                break;
    }
    std::cout << '.' << std::endl;

    // 输出为一个二进制值
    std::cout << "The binary code for '" << lower_case_letter << "' is "
    << ((lower_case_letter & (0b1 << 7)) ? 1 : 0)
    << ((lower_case_letter & (0b1 << 6)) ? 1 : 0)
    << ((lower_case_letter & (0b1 << 5)) ? 1 : 0)
    << ((lower_case_letter & (0b1 << 4)) ? 1 : 0)
    << ((lower_case_letter & (0b1 << 3)) ? 1 : 0)
    << ((lower_case_letter & (0b1 << 2)) ? 1 : 0)
    << ((lower_case_letter & (0b1 << 1)) ? 1 : 0)
    << ((lower_case_letter & 0b1) ? 1 : 0)
    << std::endl;

    return 0;
}
