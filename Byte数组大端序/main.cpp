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
    vector<char> bytesFromRobovac = {0x00,0x01, 0x02, 0x00,0x00,0x00,0x03, 0x00,0x00,0x00,0x04};
    MapInfo &ref = *(MapInfo *)bytesFromRobovac.data();
    int16_t mapId    = ntohs(ref.map_id);    // ntohs是二字节大端转小端
    int8_t  mapType  = ref.map_type;
    int32_t mapWidth = ntohl(ref.map_width); // ntohl是四字节大端转小端
    printf("id:%d type:%d width:%d height:%d\n", mapId, mapType, mapWidth, ntohl(ref.map_height));
    // 😊将对象转成char数组传给固件
    MapInfo info;
    info.map_id = htons(1);     // htons是二字节小端转大端
    info.map_type = 2;
    info.map_width = htonl(3);  // htonl是四字节小端转大端
    info.map_height = htonl(4);
    vector<char> bytesToRobovac((char *)&info, (char *)&info + sizeof(info));
    for (auto &a : bytesToRobovac) { printf("%02x ", a); } printf("\n");
    return 0;
}
