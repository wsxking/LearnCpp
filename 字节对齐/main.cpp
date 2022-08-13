// main.cpp
#include <iostream>

class Test {
public:
    char  a = 1;
    int   b = 2;
    short c = 3;
    char  d = 4;
};

int main(int argc, const char * argv[]) {
    printf("对象的大小: %ld\n", sizeof(Test));
    return 0;
}
