#include <iostream>
int a[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
// 由四个长度为3的数组创建一个二维数组
int (*prt)[3] = a;
int main()
{
    int a = 3;
    int c = a++ + a++;
    std::cout << c << std::endl; // 7
    std::cout << a << std::endl; // 5
}
