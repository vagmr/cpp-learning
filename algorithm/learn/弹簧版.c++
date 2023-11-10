#include <cstdio>
/*输入n代码有n个弹簧版即为数组的长度
第二个输入是每个弹簧版弹出的长度，即为数组对应位置的值
 */
int springdg(int n, int (&a)[])
{
    int count = 0;
    int len = n;
    for (int i = 0; i < n; i++)
    {
        if (len < 0)
        {
            return count;
        }
        else
        {
            len -= a[i];
            count++;
        }
    }
    return count;
}
int main()
{
    int n; // 代表弹簧版的长度
    scanf("%d", &n);
    int a[n]; // 创建弹簧板
    for (int i = 0; i < n; i++)
    {
        scanf("%d,", &a[i]); // 依次赋给弹簧版弹出的距离
    }
    printf("%d", springdg(n, a));
    getchar();
}