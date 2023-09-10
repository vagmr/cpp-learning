#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> x = {1, 5, 2, 56, 7, 9, 0, 1, 56, 7, 3};
    // 默认升序排列
    // b是前面的,a是后面的
    std::sort(x.begin(), x.end(), [](int b, int a)
              { 
                if(a == 3) return false;
                if(b == 3) return true;
                return a < b; });
    // 前面的大于后面的为真通过，所以是降序排列
    for (int &val : x)
    {
        std::cout << val << std::endl;
    }
    std::cin.get();
}