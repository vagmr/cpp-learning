
#include <iostream>
#include "TimerPro.h"
#include <cmath>

// 构建一个求平方根的函数

void function1()
{

    vTimer t("function1");
    for (int i = 1; i < 10000; i++)
    {
        std::cout << "hello world#" << i << std::endl;
    }
}
void function2()
{
    vTimer t("function2");
    for (int i = 1; i < 10000; i++)
    {
        std::cout << "hello world#" << sqrt(i) << std::endl;
    }
}
int main()
{
    Instrumentor::BeginSession("function1");
    function1();
    function2();
    Instrumentor::EndSession();
    std::cin.get();
}