#include <iostream>
#include <cstring>
class String
{
private:
    char *m_buffer;
    unsigned int m_size;

public:
    String()
    {
        m_size = 0;
        m_buffer = nullptr;
    }
    String(const char *string)
    {
        m_size = strlen(string);
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, string, m_size);
        m_buffer[m_size] = 0;
    }
    // 拷贝构造函数
    String(const String &other)
    {
        m_size = other.m_size;
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, other.m_buffer, m_size);
        m_buffer[m_size] = 0;
    }
    // 索引运算符重载
    char &operator[](unsigned int size)
    {
        return m_buffer[size];
    }
    ~String()
    {
        delete[] m_buffer;
    }
    friend std::ostream &operator<<(std::ostream &stream, String &string);
    friend std::ostream &operator<<(std::ostream &stream, const String &string)
    {
        stream << string.m_buffer;
        return stream;
    }
};
std::ostream &operator<<(std::ostream &stream, String &string)
{
    stream << string.m_buffer;
    return stream;
}
class Pc
{
private:
    int m_price;
    String m_cpu, m_gpu;

public:
    Pc() : m_price(7999), m_cpu("13900kf"), m_gpu("grx4090") {}
    void println() const
    {
        std::cout << "价格 =" << m_price << "cpu =" << m_cpu << "显卡 =" << m_gpu << std::endl;
    }
};

class ScopePtr
{
private:
    Pc *m_pc;

public:
    ScopePtr(Pc *p)
    {
        m_pc = p;
    }
    ~ScopePtr()
    {
        delete m_pc;
    }
    // 箭头运算符重载
    Pc *operator->()
    {
        return m_pc;
    }
};
struct Vector1
{
    float x, y, z;
};

int main()
{
    ScopePtr sc = new Pc();
    sc->println();
    int offset = (int)&((Vector1 *)0)->x;
    std::cout << offset << std::endl;
    std::cin.get();
}