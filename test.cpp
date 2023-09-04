#include <iostream>
#include <string>

std::string name = "cghss";
// std::string name = "cghss" + "hello";

// 底层是char name[6] = {'c','g','h','s','s','\0'};

int main()
{
    // std::string name = "cghss" + "hello";这种操作不被允许，字符串是const char
    // 但可以std::string name = (std::string)"cghss" + "hello";
    name += "hello";
    bool containsGh = name.find('gh') != std::string::npos;
    // 使用find()函数查找在name字符串中有没有子串"gh"。如果找到了该子串，
    // find()函数将返回非std::string::npos的位置索引值，反之则返回npos。
    // containsGh变量等于(找到的位置不是std::string::npos)。
    // 宽字符，2字节，16位
    wchar_t *name2 = L"cghss";
    // char16_t 2字节，16位
    const char16_t *name3 = u"cghss";
    // char32_t 4字节，32位
    const char32_t *name4 = U"cghss";
    std::cout << name << std::endl;
    std::cin.get();
};