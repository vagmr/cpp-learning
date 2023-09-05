#include <iostream>
#define print(x) std::cout << x << std::endl;
struct Phone
{
    int x, y;
    Phone(int x, int y)
    {
        Phone *const p = this;
        p->x = x;
        p->y = y;
        // 由于p是一个指针不能直接用.调用方法, p->y = y;可以类比p.y = y;
    }
};