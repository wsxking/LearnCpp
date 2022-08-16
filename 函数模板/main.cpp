// main.cpp
#include <iostream>
using namespace std;

// 函数模板
template <typename T> // typename关键字可以换成class
void mySwap(T &a, T &b) {
    T temp = b;
    b = a;
    a= temp;
}

int main(int argc, const char * argv[]) {
    int a = 1;
    int b = 2;
    mySwap<int>(a, b);
    mySwap<>(a, b);
    mySwap(a, b);
    return 0;
}
