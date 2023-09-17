#include <iostream>
#include <any>
int main()
{
    std::any data;
    data = 1;
    int a = std::any_cast<int>(data);
    std::cout << a << std::endl;
    data = "hello";
    std::cout << std::any_cast<const char *>(data) << std::endl;
    data = std::string("vagmr");
    data = 1.5f;
    std::cin.get();
}