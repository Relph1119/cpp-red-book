#include <iostream>
#include <format>
#include <cctype>
#include <vector>

int main() {
    // 产品ID
    std::vector<size_t> product_id;
    // 数量
    std::vector<size_t> quantity;
    // 单价
    std::vector<double> unit_cost;

    // Read the records
    while (true) {
        std::cout << "Enter a record - product number, quantity, unit cost separated by spaces: ";
        size_t id{};
        size_t n{};
        double cost{};
        std::cin >> id >> n >> cost;

        // 存入数组中
        product_id.push_back(id);
        quantity.push_back(n);
        unit_cost.push_back(cost);

        // 提示用户是否继续输入
        std::cout << "Do you want to enter another record (Y or N): ";
        char answer{};
        std::cin >> answer;
        if (std::toupper(answer) == 'N') break;
    }

    // 打印表头
    std::cout << std::format("{:10} {:10} {:14} {:10}\n",
                             "Product", "Quantity", "Unit Price", "Cost");

    double total_cost{};
    for (size_t i{}; i < product_id.size(); ++i) {
        // 计算总成本
        const auto cost{quantity[i] * unit_cost[i]};

        std::cout <<
                  std::format("{:<10} {:<10} ${:<13.2f} ${:<9.2f}\n",
                              product_id[i], quantity[i], unit_cost[i], cost);

        total_cost += cost;
    }
    std::cout << std::format("{:37}${:<9.2f}\n", "", total_cost);
}