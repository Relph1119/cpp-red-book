#include <iostream>

int main() {
    // 25美分
    const unsigned quarter{25};
    // 10美分
    const unsigned dime{10};
    // 5美分
    const unsigned nickel{5};

    // 钱款（单位：美元）
    double amountInDollars{0.0};
    std::cout << std::endl << "Please enter a cash amount between 0 and 10 dollars: $";
    std::cin >> amountInDollars;

    if (amountInDollars >= 0.0 && amountInDollars <= 10.0) {
        auto amountInCents{static_cast<unsigned>(amountInDollars * 100.0 + 0.5)};

        // 计算多少个25美分
        const auto quarters{amountInCents / quarter};
        amountInCents %= quarter;

        // 计算多少个10美分
        const auto dimes{amountInCents / dime};
        amountInCents %= dime;

        // 计算多少个5美分
        const auto nickels{amountInCents / nickel};
        amountInCents %= nickel;

        // 剩余多少美分
        const auto pennies{amountInCents};     // The remainder is already in pennies

        std::cout << std::endl
        << "The dollar value $" << amountInDollars << " can be broken down into:" << std::endl
        << quarters << " quarter" << (quarters == 1 ? "" : "s") << ',' << std::endl
        << dimes << " dime" << (dimes == 1 ? "" : "s") << ',' << std::endl
        << nickels << " nickel" << (nickels == 1 ? "" : "s") << ',' << std::endl
        << pennies << " penn" << (pennies == 1 ? "y" : "ies") << '.' << std::endl;
    } else {
        std::cout << std::endl << "You did not enter a dollar amount between 0 and 10." << std::endl;
    }
}
