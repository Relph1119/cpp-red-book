#include  <iostream>
#include  <format>

int main() {
    int mice{};      // Count of all mice
    int brown{};     // Count of brown mice
    int white{};     // Count of white mice

    std::cout << "How many brown mice do you have? ";
    std::cin >> brown;
    std::cout << "How many white mice do you have? ";
    std::cin >> white;

    if (brown < 0 || white < 0) {
        std::cout << "One cannot have a negative amount of mice..." << std::endl;
        return 1;
    }

    mice = brown + white;

    std::cout <<
              std::format("You have {} {} in total.\n", mice, mice == 1 ? "mouse" : "mice");

    if (mice == 1) {
        std::cout << "It is a " << (brown ? "brown" : "white") << " mouse." << std::endl;
    } else {
        std::cout << std::format("Of these mice, {} {} brown {}.",
                                 brown,
                                 brown == 1 ? "is a" : "are",
                                 brown == 1 ? "mouse" : "mice"
        ) << std::endl;
    }
}
