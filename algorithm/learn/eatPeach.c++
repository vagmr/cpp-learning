#include <cstdio>
int eatPatch(int x)
{
    if (x == 1)
        return 1;
    else
        return (eatPatch(x - 1) + 1) * 2;
}
int main()
{
    // 路飞吃桃问题的求解
    /* y = x / 2 -1
    *问题分析,每天吃一半+1个桃子，到第n天剩余一个桃子,求一开始有多少桃子
    函数设计：函数表示一开始存在的桃子数量，输入天数，输出桃子数量
    边界值：为n时，只剩一个桃子
     */
    int n;
    scanf("%d", &n);
    getchar();
    int sum = eatPatch(n);
    printf("原本的桃子数量为%d", sum);
    getchar();
}