#include <iostream>
int main()
{
    int one[6] = {1, 2, 3, 4, 5, 6};
    for (int i : one)
    {
        std::cout << i << " ";
    }
    for (int i = 0; i < 6; i++)
    {
        printf("第%d的个元素的值为%d\n", i, one[i]);
    }
    getchar();
}