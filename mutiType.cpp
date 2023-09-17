#include <iostream>
#include <variant>
#include <string>
int main()
{
    std::variant<int, std::string> v;
    std::cout << sizeof(v) << std::endl;
    // 取出对应类型的数据
    v = "hello";
    std::cout << std::get<std::string>(v) << std::endl;
    v = 12;
    if (auto value = std::get_if<int>(&v))
    {
        int &v = *value;
        std::cout << v << std::endl;
        std::cout << "-------------" << std::endl;
    }
    else
    {
        std::cout << "not found this value" << std::endl;
    }
    std::cout << std::get<int>(v) << std::endl;
    // 使用index取值
    std::cout << v.index() << std::endl;
    std::cin.get();
}