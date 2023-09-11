#include <iostream>
#include <string>
#include <tuple>
using String = std::string;
std::tuple<String, int> create()
{
    return {"vagmr", 21};
};

int main()
{
    std::tuple<String, int> t = create();
    String &name = std::get<0>(t);
    int &age = std::get<1>(t);
    std::cout << name << "," << age << std::endl;
    // 另外一种取值方法
    String name1;
    int age1;
    std::tie(name1, age1) = create();
    std::cout << "---------------------------" << std::endl;
    std::cout << name1 << "," << age1 << std::endl;
    std::cin.get();
}