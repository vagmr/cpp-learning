#include <iostream>
int main()
{
    char a[12] = "hello world";
    a[1] = 'x';
    char *b = "hello world";
    b[1] = 'f';
    std::cout << a << std::endl;
    std::cout << b << std::endl;
}