// main.cpp
#include <iostream>
using namespace std;

// 类模板
template <class T>
class MySwap {
public:
    void operator()(T &a, T&b) {
        T temp = b;
        b = a;
        a= temp;
    }
};

int main(int argc, const char * argv[]) {
    int a = 1;
    int b = 2;
    MySwap<int> mySwap;
    mySwap(a, b); // 重载了()运算符的对象称为"仿函数"
    return 0;
}
