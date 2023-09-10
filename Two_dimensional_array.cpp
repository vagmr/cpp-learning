#include <iostream>
int main()
{
    int **a2d = new int *[50];

    for (int i = 0; i < 50; i++)
    {
        a2d[i] = new int[50];
    }
    // 赋值
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            a2d[i][j] = i * j;
        }
    }
    // 释放内存
    for (int i = 0; i < 5; i++)
    {
        // 删除每一个具体数组
        delete[] a2d[i];
    }
    // 删除保存数组的指针
    delete[] a2d;
    // 创建一个一维数组,起到类似二维数组的作用
    int *a1d = new int[25];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            a1d[i * 5 + j] = i * 5 + j;
        }
    }
}