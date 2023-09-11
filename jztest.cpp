#include "Timer.h"
int main()
{
    int value = 0;
    {
        Timer t;
        for (int i = 1; i <= 1000000; i++)
        {
            value += 2;
        }
        std::cout << value << std::endl;
    }
    std::cin.get();
}