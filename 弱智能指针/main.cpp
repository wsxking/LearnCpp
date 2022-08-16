// main.cpp
#include <iostream>
using namespace std;

class B;
class A {
public:
    shared_ptr<B> b;
    A() {
        printf("创建A\n");
    }
    ~A() {
        printf("释放A\n");
    }
};

class B {
public:
    weak_ptr<A> a;
    B() {
        printf("创建B\n");
    }
    ~B() {
        printf("释放B\n");
    }
};

int main(int argc, const char * argv[]) {
    shared_ptr<A> a(new A());
    shared_ptr<B> b(new B());
    a->b = b;
    b->a = a;
    // 弱智能指针的使用
    // 1. 必须用强指针复制
    weak_ptr<A> weakA = a;
    // 2. 用弱指针的调用成员，必须先转强指针，并判空
    if (shared_ptr<A> strongA = weakA.lock()) {
        strongA->b = b;
    }
    return 0;
}
