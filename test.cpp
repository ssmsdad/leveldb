
#include <iostream>

class FixedInt {
public:
    // 将32位整数编码为4字节
    static void Encode(int32_t value, uint8_t* buf) {
        // 使用大端表示，高位字节存储在低地址
        buf[0] = ((value >> 24) & 0xFF) + '0';
        buf[1] = ((value >> 16) & 0xFF) + '0';
        buf[2] = ((value >> 8) & 0xFF)+ '0';
        buf[3] = value & 0xFF + '0';
    }

    // 从4字节解码出32位整数
    static int32_t Decode(const uint8_t* buf) {
        return (static_cast<int32_t>(buf[0]) << 24) |
               (static_cast<int32_t>(buf[1]) << 16) |
               (static_cast<int32_t>(buf[2]) << 8) |
               static_cast<int32_t>(buf[3]);
    }
};

int main() {
    int32_t originalValue = 123456789;
    uint8_t encodedValue[4];

    // 编码
    FixedInt::Encode(originalValue, encodedValue);

    std::cout << "Original: " << originalValue << std::endl;
    std::cout << "Encoded: " << encodedValue[0] << " " << encodedValue[1] << " " << encodedValue[2] << " " << encodedValue[3] << std::endl;

    // 解码
    int32_t decodedValue = FixedInt::Decode(encodedValue);

    // 输出原始值和解码后的值，以验证它们是否相等
    std::cout << "Original: " << originalValue << ", Decoded: " << decodedValue << std::endl;

    return 0;
}