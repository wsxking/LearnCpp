// main.cpp
#include <iostream>

class Test {
public:
    /// C++17以前静态成员不能在类内初始化
    /// C++17用inline修饰静态成员并赋初值
    /// 静态成员变量储存在全局区
    inline static int a = 1;
};

int main(int argc, const char * argv[]) {
    int *p = (int *)&Test::a;
    *p = 2;
    return 0;
}
