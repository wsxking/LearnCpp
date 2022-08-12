// main.cpp
#include <iostream>

class Test {
public:
    int a = 1;
    int b = 2;
    
    Test() {
        printf("对象分配到栈\n");
    }
    ~Test() {
        printf("对象自动释放\n");
    }
};

int main(int argc, const char * argv[]) {
    {
        const Test test;
        printf("花括号内\n");
    }
    printf("花括号外\n");
    return 0;
}
