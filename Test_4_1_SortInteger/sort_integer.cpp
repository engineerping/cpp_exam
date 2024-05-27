#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

// 冒泡排序
  void bubbleSort(std::vector<int>& numbers) {
    int n = numbers.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                // 交换元素
                std::swap(numbers[j], numbers[j + 1]);
                swapped = true;
            }
        }
        // 如果在一轮遍历中没有发生交换,说明已经排序完成
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::vector<int> numbers; // 存储输入的数字
    std::string input; // 存储用户输入的字符串

    // 读入数字
    std::cout << "请输入一串用逗号隔开的整数: ";
    std::getline(std::cin, input);

    // 解析输入
    std::stringstream ss(input);
    std::string token;
    std::cout << "测试数据: " << std::endl;
    std::cout << "输入整数: ";
    while (std::getline(ss, token, ',')) {
        int num = std::stoi(token); // 将字符串转换为整数
        std::cout << num << "  ";
        numbers.push_back(num);
    }
    std::cout << std::endl;

    // 排序
    bubbleSort(numbers);

    // 输出
    std::cout << "输出: " ;
    for (int n : numbers) {
        std::cout << n << "  ";
    }
    std::cout << std::endl;

    return 0;
}