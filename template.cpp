#include <iostream>
// 类型模板，适用于传递不同类型
template <typename T>
void print(const T &t)
{
    std::cout << t << std::endl;
}
// 适用于类型已知，类型值未知的情况
// 也可以同时指定
template <typename X, int n>
class array
{
private:
    X m_array[n];

public:
    int getSize() { return n; }
};
int main()
{
    print<int>(1);
    array<int, 8> a;
    std::cout << a.getSize() << std::endl;
    std::cin.get();
}