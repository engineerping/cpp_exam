#include <iostream>
#include <vector>
#include <algorithm>

// 冒泡排序用于字符数组
void bubbleSort(std::vector<char>& chars) {
    int n = chars.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (chars[j] > chars[j + 1]) {
                // 交换元素
                std::swap(chars[j], chars[j + 1]);
                swapped = true;
            }
        }
        // 如果在一轮遍历中没有发生交换, 说明已经排序完成
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::string input; // 存储用户输入的字符串
    std::vector<char> chars; // 存储字符数组

    // 读入字符
    std::cout << "请输入一串字符: ";
    std::getline(std::cin, input);

    // 将输入字符串的每个字符存入字符数组
    for (char c : input) {
        chars.push_back(c);
    }

    // 输出排序前的字符数组
    std::cout << "排序前的字符数组: ";
    for (char c : chars) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // 排序
    bubbleSort(chars);

    // 输出排序后的字符数组
    std::cout << "排序后的字符数组: ";
    for (char c : chars) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}
