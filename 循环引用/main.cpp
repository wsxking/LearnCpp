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
    shared_ptr<A> a;
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
    return 0;
}
