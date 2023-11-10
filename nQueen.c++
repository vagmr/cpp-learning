#include <cstdio>
#include <cmath>
#define N 4 // 定义为4皇后

// 用一维数组存储列号
int r[N + 1];
// 判断所处位置是否合法
bool check(int y)
{
    for (int i = 1; i < y; i++)
    {
        // 判断是否在同一列，同一斜线
        if (r[y] == r[i] || abs(y - i) == abs(r[y] - r[i]))
        {
            return false;
        }
    }
    return true;
}
// 执行逻辑
void queen()
{
    // 保存回答方案
    int answer = 0;
    // 初始化列号
    for (int i = 1; i < N; i++)
    {
        r[i] = 0;
    }
    // 定义n皇后的行号
    int c = 1;
    while (c >= 1)
    {
        r[c] = r[c] + 1; // 列号加1
        // 列号小于等于n，并且不合法
        while (r[c] <= N && !check(c))
        {
            r[c] = r[c] + 1;
        }
        // 列号小于等于n
        if (r[c] <= N)
        {
            // 说明行号已经到4，且所有情况都合法
            if (c == N)
            {
                printf("第%d种方案:\n", ++answer);
                for (int i = 1; i <= N; i++)
                {
                    printf("%d ", r[i]);
                }
                printf("\n");
            }
            else
            {
                c++;
            }
        }
        else
        {
            r[c] = 0;
            c--;
        }
    }
}

// 主函数
int main()
{
    queen();
}