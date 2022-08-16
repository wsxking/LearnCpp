// main.cpp
#include <iostream>

template <class T>
class HeapPointer {
private:
    /// 指向堆的指针
    T *pointer = nullptr;
    int *refCount = nullptr;
public:
    /// 构造
    HeapPointer(T *pointer) {
        this->pointer = pointer;
        this->refCount = new int(0);
        retain();
    }
    /// 析构
    ~HeapPointer() {
        release();
    }
    /// 拷贝构造
    HeapPointer(const HeapPointer &heapPointer) {
        this->pointer = heapPointer.pointer;
        this->refCount = heapPointer.refCount;
        retain();
    }
    /// 重载=运算符
    HeapPointer& operator=(const HeapPointer &heapPointer) {
        if (this == &heapPointer) {
            return *this; // 处理=两边是同一个对象的情况
        }
        release();
        this->pointer = heapPointer.pointer;
        this->refCount = heapPointer.refCount;
        retain();
        return *this;
    }
    
    /// 引用计数getter
    int retainCount() {
        return *refCount;
    }
    /// 引用计数+1
    HeapPointer& retain() {
        (*refCount)++;
        return *this;
    }
    /// 引用计数-1
    void release() {
        (*refCount)--;
        if (*refCount == 0) {
            delete pointer;
            delete refCount;
        }
    }
};

class Person {
public:
    int age;
    Person(int age) : age(age) {
        printf("创建: %d\n", age);
    }
    ~Person() {
        printf("释放: %d\n", age);
    }
};

int main(int argc, const char * argv[]) {
    HeapPointer<Person> person1(new Person(10));
    printf("引用计数: %d\n", person1.retainCount()); // 1
    
    HeapPointer<Person> person2 = person1; // 调用拷贝构造函数
    printf("引用计数: %d\n", person1.retainCount()); // 2
    
    HeapPointer<Person> person3(new Person(30));
    person3 = person1; // 调用=运算符
    printf("引用计数: %d\n", person1.retainCount()); // 3
    
    person3 = HeapPointer<Person>(nullptr);
    printf("引用计数: %d\n", person1.retainCount()); // 2
    person2 = HeapPointer<Person>(nullptr);
    printf("引用计数: %d\n", person1.retainCount()); // 1
    person1 = HeapPointer<Person>(nullptr); // 0, 引用计数为0，自动释放堆中的对象
    printf("引用计数: 0\n");
    return 0;
}
