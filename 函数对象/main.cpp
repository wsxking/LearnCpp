// main.cpp
#include <iostream>
#include <vector>
using namespace std;

// 1. 函数指针
bool myCompare(int a, int b) {
    return a < b;
}

// 2. 成员函数+仿函数
class MyCompare {
public:
    bool compare(int a, int b) {
        return a < b;
    }
    bool operator()(int a, int b) {
        return a < b;
    }
};

/// 3. Lumbda表达式
auto myCompareLumbda = [](int a, int b) {
    return a < b;
};

/// 自定义排序函数，入参是函数对象，此时可以传入上面中的任一种
void mySort(vector<int> &array, function<bool(int, int)> compareFunc) {
    sort(array.begin(), array.end(), compareFunc);
}

int main(int argc, const char * argv[]) {
    vector<int> array = {2, 3, 1, 5, 4};
    mySort(array, myCompare);       // 函数指针
    mySort(array, MyCompare());     // 仿函数
    mySort(array, myCompareLumbda); // Lumbda表达式
    /// 成员函数有点特殊，成员函数的第一个参数是this指针
    function<bool(MyCompare*, int, int)> func = &MyCompare::compare; // 成员函数指针
    return 0;
}
