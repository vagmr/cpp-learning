#include <iostream>
#include <vector>

int f(int start, std::vector<int> &arr, int n)
{
    if (start >= n)
        return 0;
    else
        return f(start + arr[start], arr, n) + 1;
}
int main()
{
    int n; // 定义弹簧版的长度
    std::cin >> n;
    std::vector<int> arr; // 定义弹簧版弹性数组
    for (int i = 0, s; i < n; i++)
    {
        std::cin >> s;
        arr.push_back(s);
    }
    std::cout << f(0, arr, n) << std::endl;
    return 0;
}