#include <iostream>
#include <fstream>
#include <string>
#include <optional>

std::optional<std::string> ReadFileAsString(const std::string &filePath)
{
    std::ifstream stream(filePath);
    if (stream)
    {
        std::string res;
        stream.close();
        return res;
    }
    return {};
}
std::ostream &operator<<(std::ostream &os, const std::optional<std::string> &res)
{
    if (res)
    {
        os << res.value();
    }
    else
    {
        os << "Empty";
    }
    return os;
}
int main()
{
    std::optional<std::string> res = ReadFileAsString("test.txt");
    if (res.has_value())
    {
        std::cout << res << std::endl;
    }
    else
    {
        std::cout << "error" << std::endl;
    }
    std::cin.get();
}