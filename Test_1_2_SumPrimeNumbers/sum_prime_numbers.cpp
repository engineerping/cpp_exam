#include <iostream>
#include <vector>
#include <cmath>

// 函数声明
bool isPrime(int n);

int main() {
    /**
    创建一个 vector 来存储素数
    vector 在 C++ 中相类似于数组, 相当于java 中的 Vector类
    list 在 C++ 中相当于链表, 相当于 java 中的 LinkedList类
    */
    std::vector<int> primes;

    // 选出2到100的所有素数, 存入 vector 中
    for (int i = 2; i <= 100; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    
    std::cout << "100以内的素数有: ";
    for (int prime : primes) {
        std::cout << prime << ", ";
    }
    std::cout << std::endl;

    // 计算所有素数的和
    int sum = 0;
    for (int prime : primes) {
        sum += prime;
    }
    std::cout << "100以内的素数的和为: " << sum << std::endl;

    return 0;
}

// 定义上面声明的函数 bool isPrime(int n);
// 判断一个数是否是素数
bool isPrime(int n) {
    // 0和1不是素数
    if (n < 2) {
        return false;
    }

    // 2是素数
    if (n == 2) {
        return true;
    }

    // 排除偶数
    //也可以用 右移来实现 除以 2, 即 if (n >> 1 == 0) {
    if (n % 2 == 0) {
        return false;
    }

    // 检查其他奇数因子
    // 遍历从3到平方根的奇数, 用 std::sqrt(n) 求平方根
    // 因为大于平方根的奇数一定不是素数, 用static_cast<int>() 将浮点数强制转换成整数,达到向下取整的效果
    int squareRoot = static_cast<int>(std::sqrt(n));
    for (int i = 3; i <= squareRoot; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}