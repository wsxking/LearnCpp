// main.cpp
#include <iostream>

class IntArray {
private:
    int *data = NULL;
    int length = 0;
public:
    IntArray(int len) : length(len) {
        if (length > 0) {
            printf("new: %d\n", length);
            data = new int[length];
        }
    }
    ~IntArray() {
        if (data != NULL) {
            printf("delete: %d\n", length);
            delete[] data;
        }
    }
    /// 拷贝构造函数
    IntArray(const IntArray &array) {
        if (array.data != NULL) {
            printf("new: 拷贝构造函数\n");
            data = new int[array.length];
            length = array.length;
            memcpy(data, array.data, length * sizeof(int));
        }
    }
    /// 重载=运算符
    IntArray& operator=(const IntArray &array) {
        if (data != NULL) {
            printf("delete: %d 重载=运算符\n", length);
            delete[] data;
            data = NULL;
        }
        if (array.data != NULL) {
            printf("new: 重载=运算符\n");
            data = new int[array.length];
            length = array.length;
            memcpy(data, array.data, length * sizeof(int));
        }
        return *this;
    }
};

/// 入参是"引用"，可以很好的避免不必要的形参拷贝
void printArray(const IntArray &array) {
    /// ...
}

int main(int argc, const char * argv[]) {
    {
        IntArray array(10);
        IntArray array2 = array; // 调用拷贝构造，用array构造array2
        IntArray array3(3);
        array3 = array; // 调用=运算符，将array赋值给array3
    }
    return 0;
}
