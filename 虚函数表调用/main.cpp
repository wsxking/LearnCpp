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

typedef void (*testFunc)(Test *thiz);

int main(int argc, const char * argv[]) {
    Test test;
    // 1. 获取对象前8字节整数
    int64_t vptrValue = *(int64_t *)&test;
    // 2. 将对象前8字节整数转为虚函数表指针
    testFunc *vptr = (testFunc *)vptrValue;
    // 3. 调用第一个虚函数
    vptr[0](&test);
    // 4. 调用第二个虚函数
    vptr[1](&test);
    return 0;
}
