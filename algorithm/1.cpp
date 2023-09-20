#include <iostream>

int main()
{
    int n;
    while (std::cin >> n)
    {
        // 使用一个变量sum来保存累加的和
        int sum = 0;

        // 使用for循环来累加从1到n的所有整数
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }

        // 输出结果
        std::cout << sum << std::endl;

        // 输出一个空行
        std::cout << "\n";
    }
}
