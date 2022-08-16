// main.cpp
#include <iostream>
#include <vector>
#include <thread>
using namespace std;

/// 不捕获外部变量，可以省略掉返回值"-> bool"
void testLambda1() {
    auto compareFunc = [](int a, int b) -> bool {
        return a < b;
    };
    compareFunc(1, 1);
}

/// 以值形式捕获外部变量，会拷贝捕获到的值
void testLambda2() {
    int a = 1;
    int b = 2;
    auto compareFunc = [a, b]() {
        printf("[2] a: %d, b: %d\n", a, b); // 打印 1, 2
        return a < b;
    };
    a = 3;
    b = 4;
    compareFunc();
}

/// 以引用形式捕获外部变量，
/// 与原变量是同一份，要注意原变量的生命周期
/// 原变量释放了，这时表达式内的引用就是野指针了
void testLambda3() {
    int a = 1;
    int b = 2;
    auto compareFunc = [&a, &b]() {
        printf("[3] a: %d, b: %d\n", a, b); // 打印 3, 4
        return a < b;
    };
    a = 3;
    b = 4;
    compareFunc();
}

/// 捕获列表简化，可以用[=]或[&]表示全部以值或引用形式捕获
void testLambda4() {
    int a = 1;
    int b = 2;
    auto compareFunc = [=]() {
        printf("[4] a: %d, b: %d\n", a, b); // 打印 1, 2
        return a < b;
    };
    a = 3;
    b = 4;
    compareFunc();
}

/// Lambda表达式用于容器操作
void testLambda5() {
    vector<int> array = {2, 3, 1, 5, 4};
    // 数组遍历
    for_each(array.begin(), array.end(), [](int a) {
        printf("%d ", a);
    });
    printf("\n");
    
    // 数组排序
    sort(array.begin(), array.end(), [](int a, int b) {
        return a < b;
    });
    for (auto &a : array) { printf("%d ", a); }
    printf("\n");
    
    // 数组转换
    vector<string> array2(array.size(), "");
    transform(array.begin(), array.end(), array2.begin(), [](int a) {
        return "\"" + to_string(a) + "\"";
    });
    for (auto &a : array2) { printf("%s ", a.c_str()); }
    printf("\n");
}

/// Lambda表达式用于回调
void httpRequest(function<void(string)> result) {
    thread t([=]() {
        this_thread::sleep_for(chrono::seconds(2));
        result("请求成功");
    });
    t.join();
}
void testLambda6() {
    httpRequest([](string result) {
        printf("%s\n", result.c_str());
    });
}

int main(int argc, const char * argv[]) {
    testLambda1();
    testLambda2();
    testLambda3();
    testLambda4();
    testLambda5();
    testLambda6();
    return 0;
}
