// main.cpp
#include <iostream>

class IntArray {
private:
    int *data = NULL;
    int length = 0;
public:
    IntArray(int len) : length(len) {
        if (length > 0) {
            printf("new\n");
            data = new int[length];
        }
    }
    ~IntArray() {
        if (data != NULL) {
            printf("delete\n");
            delete[] data;
        }
    }
};

int main(int argc, const char * argv[]) {
    {
        IntArray array(10);
        //IntArray array2 = array;
    }
    return 0;
}
