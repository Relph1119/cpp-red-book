#include <iostream>
#include <format>

int main() {
    // 每千克2.2磅
    const double lbs_per_kg{2.2};
    // 每英尺12英寸
    const double inches_per_foot{12.0};
    // 每英尺0.3048米
    const double meters_per_foot{0.3048};

    double weight{};
    unsigned int h_feet{};
    unsigned int h_inches{};

    std::cout << "Enter your weight in pounds: ";
    std::cin >> weight;
    std::cout << "Enter you height in feet and inches: ";
    std::cin >> h_feet >> h_inches;

    const double w_kg{weight / lbs_per_kg};
    const double h_meters{meters_per_foot * (h_feet + h_inches / inches_per_foot)};
    const double bmi{w_kg / (h_meters * h_meters)};
    // BMI精度超过小数点后一位
    std::cout << std::format("Your BMI is {:.1f}\n", bmi);
}