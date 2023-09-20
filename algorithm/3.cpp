#include <cstdio>

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) == 2)
    {
        // 读取两个整数，并计算它们的和
        int sum = a + b;

        // 输出结果
        printf("%d\n", sum);

        // 清空输入缓冲区
        while (getchar() != '\n')
        {
            // 读取并丢弃缓冲区中的字符，直到遇到换行符
        }
    }
    return 0;
}
