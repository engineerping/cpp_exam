#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 自定义比较函数，按照题目描述的规则进行比较
bool customCompare(const std::string& a, const std::string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    } else {
        return a < b;
    }
}

int main() {
    std::vector<std::string> data = {"January", "February", "March", "April", "May", "June", "July", "September"};

    // 输出原始数据
    std::cout << "输入: " ;
    for (const auto& month : data) {
        std::cout << month << "  ";
    }
    std::cout << std::endl;

    // 使用自定义的比较函数进行排序
    std::sort(data.begin(), data.end(), customCompare);

    // 输出排序后的结果
    std::cout << "输出: " << std::endl;
    for (const auto& month : data) {
        std::cout << month << std::endl;
    }

    return 0;
}
