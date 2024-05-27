#include <iostream>  
#include <vector>    
#include <sstream>   
#include <string>   

int main() {
    
    std::cout << "请输入若干个满分为 100 分的成绩(空格间隔,回车结束输入,最多10个): ";
    std::string input; 
    std::getline(std::cin, input); // 从标准输入流中读取整个输入行到input字符串中

    std::vector<int> scores; // 定义一个动态数组容器scores,用于存储分数
    std::stringstream iss(input); // 创建一个字符串流对象 iss,并将input字符串绑定到它上面
    std::string token;
   
    // 循环读取字符串流中的, 用"," 隔开的 每个token
    std::cout << "输入: ";
    while (std::getline(iss, token, ',')) {
        std::istringstream tokenStream(token);
        int num;
        if (tokenStream >> num) { // 将token转换为整数
            std::cout << num << "  ";
            scores.push_back(num);
        }
    }
    std::cout << std::endl;

    // 判断输入的数据如果超过10个则程序退出
    if (scores.size() > 10) {
        std::cout << "输入的分数个数超过10个,程序退出,请输入少于10个数字" << std::endl;
        return 0;
    }

    // 输出提示,准备打印对应的等级成绩
    std::cout << "输出: " ;
    for (const int& score : scores) { 
        if (score >= 90) { 
            std::cout << "  优秀  " ;
        } else if (score >= 80) { 
            std::cout << "  良好  " ;
        } else if (score >= 70) { 
            std::cout << "  中等  " ;
        } else if (score >= 60) { 
            std::cout << "  及格  " ;
        } else { 
            std::cout << "  不及格  " ;
        }
    }
    std::cout << std::endl;

    return 0; 
}