#include <iostream>
#include <array>
int main()
{
    std::array<int, 5> data;
    data[1] = 4;
    std::cout << data.size() << std::endl;                        // size_t 的大小是返回的是模板值，实际上不是变量
    std::cout << "size_t的大小为" << sizeof(size_t) << std::endl; // 8位
    std::cout << "unsigned int的大小为" << sizeof(unsigned int) << std::endl;
}