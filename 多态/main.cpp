// main.cpp
#include <iostream>

class BaseObject {
public:
    virtual void test() {
        printf("base\n");
    }
};

class SubObject : public BaseObject {
public:
    void test() override {
        printf("sub\n");
    }
};

int main(int argc, const char * argv[]) {
    SubObject sub;
    // 1. 父类指针
    BaseObject *ptr = &sub;
    ptr->test();
    // 2. 父类引用
    BaseObject &ref = sub;
    ref.test();
    // 3. 父类值
    BaseObject base = sub;
    base.test();
    return 0;
}
