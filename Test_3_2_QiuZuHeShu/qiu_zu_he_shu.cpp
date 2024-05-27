#include <iostream>

//----------------------递归的方式--------------------------------------------------------------------------
// 递归函数计算组合数C(n,r)
long long combination(int n, int r) {
    // 基准情况1: 取0个数,只有1种选择
    if (r == 0) {
        return 1;
    }
    // 基准情况2: 全取或全不取,只有1种选择
    if (n == r || r == 0) {
        return 1;
    }
    // 递归情况: C(n,r) = C(n-1,r) + C(n-1,r-1)
    return combination(n - 1, r) + combination(n - 1, r - 1);
}

int main() {
    std::cout << " 递归方式实现" << std::endl;
    int n, r;
    std::cout << "请输入n的值: ";
    std::cin >> n;
    std::cout << "请输入r的值: ";
    std::cin >> r;

    if (n < 0 || r < 0 || r > n) {
        std::cout << "输入不合法, 请重新输入!" << std::endl;
        return 1;
    }


    long long result = combination(n, r);
    std::cout << "从" << n << "个数中取" << r << "个数的所有选择的个数 即 组合数为: " << result << std::endl;

    return 0;
}







//----------------------非递归的方式--------------------------------------------------------------------------

// 计算阶乘
// long long factorial(int n) {
//     long long result = 1;
//     for (int i = 2; i <= n; i++) {
//         result *= i;
//     }
//     return result;
// }

// // 计算组合数C(n,r)
// long long combination(int n, int r) {
//     if (n < r) {
//         return 0; // 无效输入
//     }
//     if (r == 0 || n == r) {
//         return 1; // 基准情况
//     }
//     // 使用公式 C(n,r) = n! / (r! * (n-r)!)
//     long long numerator = factorial(n);
//     long long denominator = factorial(r) * factorial(n - r);
//     return numerator / denominator;
// }

// int main() {
//     std::cout << " 非递归方式实现" << std::endl;
//     int n, r;
//     std::cout << "请输入n的值: ";
//     std::cin >> n;
//     std::cout << "请输入r的值: ";
//     std::cin >> r;

//     long long result = combination(n, r);
//     std::cout << "从" << n << "个数中取" << r << " 个数的所有选择的个数 即 组合数为: " << result << std::endl;

//     return 0;
// }