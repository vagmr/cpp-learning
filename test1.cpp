#include <iostream>
// 递归终止条件
void print()
{
    std::cout << std::endl;
}

// 自定义输出函数
template <typename T, typename... Args>
void print(const T &first, Args... args)
{
    std::cout << first << " ";
    print(args...); // 递归调用，处理剩余参数
}
void testCal(int &x)
{
    int n = 0;
    std::cin >> x;
    std::cin.get();
    n++;
    x /= 10;
    while (x > 0)
    {
        n++;
        x /= 10;
    }
    print(n);
}

int main()
{
    int x;
    testCal(x);
    std::cin.get();
    return 0;
}
