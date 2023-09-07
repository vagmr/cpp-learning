#include <iostream>
#include <cstring>

class String // 自定义实现简易string类型
{
private:
    char *m_buffer;
    unsigned int m_size;

public:
    String(const char *string)
    {
        m_size = strlen(string);
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, string, m_size);
        m_buffer[m_size] = 0;
    }
    ~String()
    {
        delete[] m_buffer;
    }
    // 重载索引运算符
    char &operator[](unsigned int size)
    {
        return m_buffer[size];
    }
    // 默认拷贝构造函数
    String(const String &other) : m_size(other.m_size)
    {
        // 开辟新的内存地址
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, other.m_buffer, m_size);
        m_buffer[m_size] = 0;
    }
    // 声明友元
    friend std::ostream &operator<<(std::ostream &stream, String &string);
};
std::ostream &operator<<(std::ostream &stream, String &string)
{
    stream << string.m_buffer;
    return stream;
}
int main()
{
    String str("vagmr");
    String second = str;
    str[2] = '2';
    std::cout << str << std::endl;
    std::cout << second << std::endl;
    std::cin.get();
}