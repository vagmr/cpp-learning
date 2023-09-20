/* 输入数据包含多组测试数据，且以 EOF(End of File) 结束。

    每组测试数据占一行，为空格分割的两个整数 A 和 B。

    输出描述

    对于任意一组输入的整数 A 和 B，你应当在一行内输出 A
    + B 的值。两组输出之间需换行分割。 */
#include <cstdio>
int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        printf("%d\n", a + b);
        printf("测试中文输出");
    }

    return 0;
}