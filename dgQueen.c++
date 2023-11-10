// 用递归求解n皇后
#include <cstdio>
#include <cmath>
#define N 10 // 定义为4皇后

// 用行号变动影响列号
int column[N + 1];
int awnser = 0;
bool check(int row)
{
    for (int i = 1; i < row; i++)
    {
        if (column[row] == column[i] || abs(row - i) == abs(column[row] - column[i]))
        {
            return false;
        }
    }
    return true;
}
void queen(int row)
{
    for (int i = 1; i <= N; i++)
    {
        column[row] = i;
        if (check(row))
        {
            if (row == N)
            {
                printf("第%d种方案:\n", ++awnser);
                for (int i = 1; i <= N; i++)
                {
                    printf("%d ", column[i]);
                }
                printf("\n");
            }
            else
            {
                queen(row + 1);
            }
        }
    }
}
int main()
{
    queen(1);
    getchar();
    return 0;
}