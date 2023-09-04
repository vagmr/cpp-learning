#include <iostream>
int main()
{
    const int Max_Age = 100;
    // int a = 1;
    // 指针指向的内存的值将不能被改变,即指针指向的值是常量const int *ptr = new int;
    // 或者int const *ptr = new int;
    // 指针本身是常量，不能改变指针的指向int* const  ptr = new int;
    // 也可以两者兼备  const int* const  ptr = new int;
    int *ptr;
    ptr = (int *)&Max_Age;
    *ptr = 120;
    std::cout << Max_Age << std::endl;
    std::cin.get();
}