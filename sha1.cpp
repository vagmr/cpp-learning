#include <iostream>
#include <string>
#include <cstdint>

#define pause std::cin.get()
#define open_curly {
// 辅助函数
#define SHA1_ROTL(bits, word) (((word) << (bits)) | ((word) >> (32 - (bits))))

//
#define SHA1_F0(B, C, D) (((B) & (C)) | ((~B) & (D)))
#define SHA1_F1(B, C, D) ((B) ^ (C) ^ (D))
#define SHA1_F2(B, C, D) (((B) & (C)) | ((B) & (D)) | ((C) & (D)))

void sha1(const std::string &input, uint32_t hash[5])
{
    // 初始化
    hash[0] = 0x67452301;
    hash[1] = 0xEFCDAB89;
    hash[2] = 0x98BADCFE;
    hash[3] = 0x10325476;
    hash[4] = 0xC3D2E1F0;

    // 预处理
    uint64_t totalBits = input.length() * 8;
    std::string paddedInput = input + '\x80';
    while ((paddedInput.length() * 8) % 512 != 448)
    {
        paddedInput += '\x00';
    }
    for (int i = 0; i < 8; ++i)
    {
        paddedInput += static_cast<char>((totalBits >> (56 - i * 8)) & 0xFF);
    }

    // 处理每个位块
    for (size_t i = 0; i < paddedInput.length(); i += 64)
    {
        uint32_t w[80];
        for (int j = 0; j < 16; ++j)
        {
            w[j] = (static_cast<uint32_t>(paddedInput[i + j * 4]) << 24) |
                   (static_cast<uint32_t>(paddedInput[i + j * 4 + 1]) << 16) |
                   (static_cast<uint32_t>(paddedInput[i + j * 4 + 2]) << 8) |
                   (static_cast<uint32_t>(paddedInput[i + j * 4 + 3]));
        }
        for (int j = 16; j < 80; ++j)
        {
            w[j] = SHA1_ROTL(1, w[j - 3] ^ w[j - 8] ^ w[j - 14] ^ w[j - 16]);
        }

        uint32_t a = hash[0];
        uint32_t b = hash[1];
        uint32_t c = hash[2];
        uint32_t d = hash[3];
        uint32_t e = hash[4];

        // 主循环
        for (int j = 0; j < 80; ++j)
        {
            uint32_t temp = SHA1_ROTL(5, a) + SHA1_F0(b, c, d) + e + w[j] + 0x5A827999;
            e = d;
            d = c;
            c = SHA1_ROTL(30, b);
            b = a;
            a = temp;
        }

        // 更新所有哈希值
        hash[0] += a;
        hash[1] += b;
        hash[2] += c;
        hash[3] += d;
        hash[4] += e;
    }
}

int main()
    open_curly
    std::string input;
std::cout << "请输入要转换的内容：" << std::endl;
std::cin >> input;
uint32_t hash[5];
sha1(input, hash);

std::cout << "SHA-1 Hash: ";
for (int i = 0; i < 5; ++i)
    open_curly
        printf("%08X ", hash[i]);
}
std::cout << std::endl;
std::cout << "end" << std::endl;
pause;
pause;
return 0;
}
