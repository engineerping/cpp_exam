#include <iostream>

// 定义链表节点结构体
struct ListNode {
    int value; // 节点存储的值
    ListNode* next; // 指向下一个节点的指针

    // 构造函数，初始化节点的值和下一个节点的指针
    ListNode(int val) : value(val), next(nullptr) {}
};

// 单向链表类
class LinkedList {
public:
    ListNode* head; // 链表的头指针

    // 构造函数，初始化头指针为nullptr
    LinkedList() : head(nullptr) {}

    // 添加节点到链表尾部的方法
    void append(int value) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            // 如果链表为空，新节点成为头节点
            head = newNode;
        } else {
            // 否则，找到链表的最后一个节点，并将其next指针指向新节点
            ListNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // 析构函数，释放链表占用的内存
    ~LinkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;
    int value;

    // 从标准输入读取整数，直到输入0
    std::cout << "请输入整数（输入0结束）：" << std::endl;

    while (std::cin >> value && value != 0) {
        list.append(value); // 将读取的整数添加到链表尾部

        if (value == 9) {
            //在尾部插入一个数 9 后， 输出链表节点中的内容。
            break; 
        }
    }
    std::cout << "用户输入：" ;
    // for (std::size_t i = 0; i < list.size(); ++i) {
    //     std::cout << list[i] << " ";
    // }
    std::cout << std::endl;

    // 打印链表中的所有值，以验证链表的构建
    std::cout << "程序输出：" ;
    ListNode* current = list.head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}