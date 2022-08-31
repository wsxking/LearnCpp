// main.cpp
#include <iostream>
#include <vector>
using namespace std;

// 路径点协议：
// 1. 前1-14位是x
// 2. 第15位是x的符号
// 3. 第16-29位是y
// 4. 第30位是y的符号
// 5. 第31,32位是路径类型
// |00|0|00000 00000000 0|0|000000 00000000|
// |tp|+|       y        |+|      x        |

void parse1() {
    uint8_t data[4] = {0x20, 0xB4, 0x02, 0x74};
    
    uint8_t byte0 = data[0];
    uint8_t byte1 = data[1];
    uint8_t byte2 = data[2];
    uint8_t byte3 = data[3];
    
    int signedX = (byte2 & 0b01000000) >> 6;
    int x1 = byte2 & 0b00111111;
    int x2 = byte3 & 0b11111111;
    int x = (x1 << 8) + x2;
    x = (signedX ? -1 : 1) * x;
    
    int signedY = (byte0 & 0b00100000) >> 5;
    int y1 = byte0 & 0b00011111;
    int y2 = byte1 & 0b11111111;
    int y3 = byte2 & 0b10000000;
    int y = (y1 << 9) + (y2 << 1) + (y3 >> 7);
    y = (signedY ? 1 : -1) *y;
    
    int pathType = (byte0 & 0b11000000) >> 6;
    
    printf("x: %d y: %d type; %d\n", x, y, pathType);
}

struct Point {
    int x        : 14;
    int signedX  : 1;
    int y        : 14;
    int signedY  : 1;
    int pathType : 2;
} __attribute__((packed));

void parse2() {
    //uint8_t data[4] = {0x20, 0xB4, 0x02, 0x74};
    uint8_t data[4] = {0x74, 0x02, 0xB4, 0x20};
    
    Point &p = *(Point *)data;
    
    printf("x: %d y: %d type; %d\n", p.x, p.y, p.pathType);
}

int main(int argc, const char * argv[]) {
    printf("%zd\n", sizeof(Point));
    parse1();
    parse2();
    return 0;
}
