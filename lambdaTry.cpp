#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
void prtHello()
{
    std::cout << "hello world" << std::endl;
}
void prtValue(int value)
{
    std::cout << "value:" << value << std::endl;
}
void forEach(const std::vector<int> &v, std::function<void(int)> prt)
{
    for (const int &val : v)
        prt(val);
}
int main()
{
    typedef void (*xg)(); // 这是一个类型由返回值类型 |自定义名字 |和参数列表构成 ,是fnc的实际类型
    xg x = prtHello;      // 实际上是auto fnc = &prtHello
    x();
    x();
    // typedef int Int; 类型别名，给int类型取别名Int;
    std::vector<int> v;
    v.reserve(6);
    v = {1, 2, 3, 6, 7, 9};
    std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), [](int val)
                                                 { return val > 5; });
    int a = 5;
    auto lambda = [&a](int value)
    { std::cout << "value:" << value << "a " << a << std::endl; };
    forEach(v, lambda);
    std::cin.get();
}