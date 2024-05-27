#include <iostream>
#include <cmath>

int main() {
    int m;
    int numDigits;
    std::cout << "请输入一个正整数: ";
    std::cin >> m;

    // 获取位数
    // log10 函数，计算其以 10 为底的对数，然后将结果转换为整数并加 1 得到位数。
    numDigits = (int)log10(m) + 1;
    int digits[numDigits];

    // 分离每一位数字
    int temp = m;
    for (int i = 0; i < numDigits; i++) {
        digits[numDigits - i - 1] = temp % 10; //对10取模，得到个位数字
        temp /= 10;
    }

    // 打印每一位数字
    std::cout << "每一位数字为: ";
    for (int i = 0; i < numDigits; i++) {
        std::cout << digits[i] << ", ";
    }
    std::cout << std::endl;

    // 逆序打印各位数字
    std::cout << "逆序各位数字: ";
    for (int i = numDigits - 1; i >= 0; i--) {
        std::cout << digits[i];
    }
    std::cout << std::endl;

    return 0;
}