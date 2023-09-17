#include <iostream>
void printName(std::string &name) // 使用左值引用
{
    std::cout << "[lValue]" << name << std::endl;
}
void printName(std::string &&name) // 使用右值引用
{
    std::cout << "[rValue]" << name << std::endl;
}
int main()
{
    std::string name = "hello vagmr";
    // auto name = "hello vagmr"; 使用auto声明类型时算到右值
    printName(name);
    printName("hello world"); // 利用const直接传入右值
    char xg[6] = {'v', 'a', 'g', 'm', 'r', '\0'};
    const char *ss = "hello world";
    printName((ss + 2));
    std::cout << xg << std::endl;
    std::cin.get();
}