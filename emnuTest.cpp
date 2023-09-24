#include <iostream>
enum class actions
{
    add,
    sub
};
bool operator==(const actions a, int &&b)
{
    return a == static_cast<actions>(b);
}
void test(const actions &a)
{
    if (a == actions::add)
    {
        std::cout << "add" << std::endl;
    }
    if (a == 1)
    {
        std::cout << "sub" << std::endl;
    }
}
int main()
{
    test(actions::add);
    std::cin.get();
}