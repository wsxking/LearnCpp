// main.cpp
#include <iostream>
#include <vector>
using namespace std;

/// 固件端协议，地图头部信息
struct MapInfo {
    int16_t map_id;
    int8_t  map_type;
    int32_t map_width;
    int32_t map_height;
} __attribute__((packed)); // 字节紧凑排列

int main(int argc, const char * argv[]) {
    // 😊假设下面的char数组是固件传来的
    vector<char> bytesFromRobovac = {0x01,0x00, 0x02, 0x03,0x00,0x00,0x00, 0x04,0x00,0x00,0x00};
    // 1. 用对象指针解析
    MapInfo *ptr = (MapInfo *)bytesFromRobovac.data();
    int16_t mapId    = ptr->map_id;
    int8_t  mapType  = ptr->map_type;
    int32_t mapWidth = ptr->map_width;
    printf("id:%d type:%d width:%d height:%d\n", mapId, mapType, mapWidth, ptr->map_height);
    // 2. 用对象"引用"或"值"解析，用"引用"不会发生拷贝，用"值"会发生拷贝
    MapInfo &ref = *(MapInfo *)bytesFromRobovac.data(); // 引用方式
    MapInfo info = *(MapInfo *)bytesFromRobovac.data(); // 值方式
    mapId = ref.map_id;
    // 😊将对象转成char数组传给固件
    vector<char> bytesToRobovac((char *)&info, (char *)&info + sizeof(info));
    for (auto &a : bytesToRobovac) { printf("%02x ", a); } printf("\n");
    return 0;
}
