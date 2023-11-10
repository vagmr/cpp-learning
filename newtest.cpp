#include <iostream>
int main()
{
    char a[12] = "hello world";
    a[1] = 'x';
    const char *b = "hello world";
    const char *c = "文档大小";
    std::cout << a << std::endl;
    std::cout << b << std::endl;
}