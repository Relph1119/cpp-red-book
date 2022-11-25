#include <iostream>
#include <numbers>

int main() {
    const double inches_per_foot{12.0};
    const double pi_degrees{180.0};
    double feet{};
    double inches{};

    std::cout << "Enter the distance from the tree in feet and inches: ";
    std::cin >> feet >> inches;
    const double distance{feet + inches / inches_per_foot};

    double angle{};
    std::cout << "Enter the angle of the top of the tree in degrees: ";
    std::cin >> angle;

    angle *= std::numbers::pi / pi_degrees;

    double eye_height{};
    std::cout << "Enter your eye height from the ground in inches: ";
    std::cin >> eye_height;
    // 转换为feet
    eye_height /= inches_per_foot;

    // 计算树的高度
    const double height{eye_height + distance * std::tan(angle)};
    const unsigned height_feet{static_cast<unsigned>(height)};
    const unsigned height_inches{static_cast<unsigned>(std::round(inches_per_foot * (height - height_feet)))};

    std::cout << "\nThe height of the tree is "
              << height_feet << " feet "
              << height_inches << " inches.\n" << std::endl;
}