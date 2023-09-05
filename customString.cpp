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
    std::cout << str << std::endl;
}