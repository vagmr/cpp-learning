#include <iostream>
void incremence(int *x)
{
    // 函数的作用是直接操作简单数据类型的值，要传入地址，而非值传递
    // 直接值传递实际上是操作另一个变量,类似于int x;x++;
    *x++; // 要先解引用，要不然自增的是地址
}
int main()
{
    int x = 8;
    std::cout << x << std::endl;
    std::cout << "地址是" << &x << std::endl;
    incremence(&x);
    std::cout << x << std::endl;
    std::cout << "地址是" << &x << std::endl;
    std::cin.get();
}