#include <iostream>
#include <cstdint>

static uint32_t s_sizeCount = 0;
// 重载new运算符
void *operator new(size_t size)
{
    s_sizeCount++;
    std::cout << " new函数被调用, 分配的大小为" << size << std::endl;
    return malloc(size);
}
void printSting(const std::string &str)
{
    std::cout << str << std::endl;
}
void printSting(std::string_view str)
{
    std::cout << str << std::endl;
}
int main()
{
#if 0
    std::string str = "vagmr";
    printSting(str);
#else
    const char name[11] = "vagmr king";
    std::string_view firstName(name, 5);
    // 默认接收const char *，会自动隐式转换
    std::string_view lastName(static_cast<const char *>(name) + 6, 4);
    printSting(firstName);
    printSting(lastName);
    std::cout << "次数为" << s_sizeCount << std::endl;
#endif
    std::cin.get();
}