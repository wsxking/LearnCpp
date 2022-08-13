// main.cpp
#include <iostream>

class Test {
public:
    int a = 1;
    int b = 2;
    
    virtual void test1() {
        printf("test1\n");
    }
    virtual void test2() {
        printf("test2\n");
    }
};

int main(int argc, const char * argv[]) {
    Test test;
    printf("对象的大小: %ld\n", sizeof(test));
    return 0;
}
