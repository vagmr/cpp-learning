#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

// 自定义谓词用于判断字符是否是换行符或空格
bool isWhitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\r' || c == '\n');
}

int main()
{
    std::ifstream inFile("styles.css"); // 打开CSS文件
    std::string cssText((std::istreambuf_iterator<char>(inFile)),
                        std::istreambuf_iterator<char>()); // 读取文件内容到字符串

    // 删除换行符和空格
    cssText.erase(std::remove_if(cssText.begin(), cssText.end(), isWhitespace), cssText.end());

    std::cout << cssText << std::endl; // 输出处理后的CSS文本
    std::cin.get();
    return 0;
}
