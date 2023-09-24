#include <iostream>
int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;
    std::cout << *p++ << std::endl;
    std::cout << *p << std::endl;
    std::cout << *(p++) << std::endl;
    std::cout << *(++p) << std::endl;
    std::cout << *p << std::endl;
    std::cin.get();
}