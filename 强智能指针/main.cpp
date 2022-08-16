// main.cpp
#include <iostream>
using namespace std;

class Person {
public:
    int age;
    Person(int age) : age(age) {
        printf("创建: %d\n", age);
    }
    ~Person() {
        printf("释放: %d\n", age);
    }
    void learnCpp() {
        printf("learnCpp: %d\n", age);
    }
};

int main(int argc, const char * argv[]) {
    shared_ptr<Person> person1(new Person(10));
    printf("引用计数: %ld\n", person1.use_count()); // 1
    person1->learnCpp(); // 智能指针重载了->运算符，使用起来就和普通指针一样
    
    shared_ptr<Person> person2 = person1; // 调用拷贝构造函数
    printf("引用计数: %ld\n", person1.use_count()); // 2
    
    shared_ptr<Person> person3(new Person(30));
    person3 = person1; // 调用=运算符
    printf("引用计数: %ld\n", person1.use_count()); // 3
    
    person3 = shared_ptr<Person>(nullptr);
    printf("引用计数: %ld\n", person1.use_count()); // 2
    person2 = shared_ptr<Person>(nullptr);
    printf("引用计数: %ld\n", person1.use_count()); // 1
    person1 = shared_ptr<Person>(nullptr); // 0, 引用计数为0，自动释放堆中的对象
    printf("引用计数: 0\n");
    return 0;
}
