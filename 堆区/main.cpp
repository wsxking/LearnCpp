// main.cpp
#include <iostream>

class Test {
public:
    int a = 1;
    int b = 2;
    
    Test() {
        printf("对象分配到堆\n");
    }
    ~Test() {
        printf("对象手动释放\n");
    }
};

int main(int argc, const char * argv[]) {
    Test *test = new Test();
    printf("释放前\n");
    delete test;
    printf("释放后\n");
    return 0;
}
