#include <iostream>
#include <list>

// 定义链表节点结构体
struct ListNode {
    int value; // 节点存储的值
    ListNode* next; // 定义一个ListNode类型的指针,用于指向下一个节点

    /** 
    用于初始化链表节点的值和下一个节点的指针。
    构造函数接受一个整数参数 val，将其用于初始化节点存储的值 value，
    并将指针 next 初始化为 nullptr   

    在 C++ 中，nullptr 是空指针常量，用于表示空指针。当将其用在类的成员初始化列表中，它实际上就是在初始化该成员为一个空指针。 
    */
    ListNode(int val) : value(val), next(nullptr) {}
};

// 单向链表类
class LinkedList {
public:
    ListNode* head; // 链表的头指针

    /**
    LinkedList 类的构造函数。
    它使用成员初始值列表语法来初始化链表的头指针 head 为 nullptr。
    这意味着在创建新的 LinkedList 对象时，其头指针将会被设置为 nullptr，表示链表为空。
    */
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


// 打印 本程序中的 自定义LinkedList 中的值
void printMyLinkedList(LinkedList& list) {
    std::cout << "程序输出：" ;
    ListNode* current = list.head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// 打印 标准库中的 std::list 中的值
void pintStdList(std::list<int>& stdList) {
    std::cout << "用户输入：";
    for (auto it = stdList.begin(); it != stdList.end(); it++) {
        if (next(it) == stdList.end()) {
            std::cout << *it;
        } else {
            std::cout << *it << " ";
        }
    }
    std::cout << std::endl;
}

/**
删除链表中指定位置的节点
*/
void removeMyLinkedList(LinkedList& list, int pos) {

    ListNode* current = list.head;
    if (pos == 0) {
        list.head = current->next;
        delete current;
        return;
    }

    // 要删除的节点的位置是 从 1 开始数的
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
    }

    ListNode* toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete; // 释放被删除节点的内存
    //current->next = nextNode;
}   


/**
【 测试数据】
程序输出：请输入若干个整数， 以 0 结束。
用户输入： 5 1 8 4 3 2 0
程序输出： 5 1 8 4 3 2
程序输出：请插入一个整数。
用户输入： 9
程序输出： 5 1 8 4 3 2 9
程序提示： 您要删除哪个位置的数？
用户输入： 3
程序输出： 5 1 4 3 2 9
*/
int main() {
    LinkedList myList;
    //C++ 中的 std::list 是 链表, 相当于 java 中的 LinkedList。
    std::list<int> sysList;
    int num;
    bool removing = false;
    std::cout << "请输入若干个整数，以 0 结束。" << std::endl;
    while (std::cin >> num) {
        if (removing) {
            sysList.clear();
            sysList.push_back(num);
            removeMyLinkedList(myList, num);
            pintStdList(sysList);
            printMyLinkedList(myList);
            removing = false;
        } else {
            if (num == 0) {
                sysList.push_back(num);
                pintStdList(sysList);
                printMyLinkedList(myList);
                std::cout << "程序输出：请插入一个整数。" << std::endl;
                // 清空 sysList
                sysList.clear();
                continue;
            }

            sysList.push_back(num);
            myList.append(num);

            if (num == 9) {
                pintStdList(sysList);
                printMyLinkedList(myList);
                std::cout << "程序提示：您要删除哪个位置的数？" << std::endl;
                removing = true;
                continue;
            }
        }
    }

    return 0;
}
