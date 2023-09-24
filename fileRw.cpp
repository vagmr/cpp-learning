#include <fstream>
#include <iostream>
#include <optional>
#include "Timer.h"
std::optional<std::string> ReadFileAsStringf(const std::string &filePath)
{
    Timer t;
    std::fstream read(filePath, std::ios::in);
    if (read)
    {
        std::string result;
        char buf[3096] = {0};
        while (read.getline(buf, sizeof(buf)))
        {
            result += buf + '\n';
        }
        return result;
    }
    return {};
}
std::optional<std::string> ReadFileAsString(const std::string &filePath)
{
    Timer t;
    std::ifstream read(filePath, std::ios::in | std::ios::binary);

    if (read)
    {
        std::string result; // 用于存储文件内容
        std::string line;
        // 使用循环读取所有行
        while (std::getline(read, line))
        {
            result += line + '\n';
        }
        read.close();
        return result; // 返回最后一行的文本
    }

    return {}; // 文件无法打开或读取失败时返回空的std::optional
}
int main()
{
    /*  std::optional<std::string> res = ReadFileAsStringf("test.txt");
     if (res)
     {
         std::cout << *res << std::endl;
     }
     else
     {
         std::cout << "error" << std::endl;
     } */
    std::optional<std::string> res2 = ReadFileAsString("test.txt");

    if (res2)
    {
        std::cout << *res2 << std::endl;
    }
    std::cin.get();
}