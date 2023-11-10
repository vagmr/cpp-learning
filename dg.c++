#include <iostream>
int sum(int n)
{
    if (n == 10)
    {
        return 1;
    }
    else
    {
        return 2 * sum(n + 1) + 2;
    }
}
int main()
{
    std::cout << sum(1) << std::endl;
    std::cin.get();
    return 0;
}