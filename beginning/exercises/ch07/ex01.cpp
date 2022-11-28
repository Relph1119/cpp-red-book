#include <iostream>
#include <format>
#include <cctype>
#include <vector>
#include <string>

int main() {
    // 学生名字
    std::vector<std::string> names;
    // 学生成绩
    std::vector<double> grades;

    size_t max_length{};
    double average_grade{};

    while (true) {
        std::cout << "Enter a student's name: ";
        std::string name;
        std::getline(std::cin, name);

        names.push_back(name);
        // 得到最长的名字长度
        if (max_length < name.length())
            max_length = name.length();

        std::cout << "Enter " << name << "\'s grade: ";
        double grade{};                        // Stores a student grade
        std::cin >> grade;
        grades.push_back(grade);

        // 得到总成绩
        average_grade += grade;

        std::cout << "Do you wish to enter another student's details (y/n): ";
        char answer{};
        std::cin >> answer;

        // 删除后面的空格
        std::cin.ignore();

        if (std::toupper(answer) == 'N') break;
    }

    // 计算平均成绩
    average_grade /= grades.size();

    std::cout << std::format("\nThe class average for {} students is {:.2f}\n", names.size(), average_grade);

    const size_t per_line{3};
    for (size_t i{}; i < names.size(); ++i) {
        std::cout << std::format("{:<{}}({})\t", names[i], max_length, grades[i]);
        if ((i + 1) % per_line) continue;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}