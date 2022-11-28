#include <iostream>
#include <format>
#include <vector>

int main() {
    std::cout << "Please input the largest number: ";
    unsigned bound{};
    std::cin >> bound;

    std::vector<unsigned> values;
    // 保存从1开始到输入的上界的所有整数
    for (unsigned i{1}; i <= bound; ++i)
        values.push_back(i);

    size_t count{};
    size_t per_line{10};
    for (auto value : values) {
        // 过滤掉7和13的倍数
        if (value % 7 == 0 || value % 13 == 0) continue;
        // 对齐
        std::cout << std::format("{:^5}", value);
        // 每10个输出为一行
        if (++count % per_line == 0) std::cout << "\n";
    }
    std::cout << std::endl;
}
