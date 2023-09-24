#include <iostream>
#include <cstring>

class String // 自定义实现简易string类型
{
private:
    char *m_buffer = nullptr;
    unsigned int m_size;

public:
    String() = default; // 默认构造函数,无参
    String(const char *string)
    {
        std::cout << "construct " << string << std::endl;
        m_size = strlen(string);
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, string, m_size);
        m_buffer[m_size] = 0;
    }
    ~String()
    {
        std::cout << "destroyed" << std::endl;
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
        std::cout << "copeied" << std::endl;
        // 开辟新的内存地址
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, other.m_buffer, m_size);
        m_buffer[m_size] = 0;
    }
    // 删除默认拷贝构造函数 String(const String &other) = delete;
    // 使用右值引用拷贝函数
    String(String &&other) noexcept : m_size(other.m_size)
    {
        // 浅拷贝other.m_buffer，然后把里面的数据置空
        std::cout << "move" << std::endl;
        m_buffer = other.m_buffer;
        // 置空的原因是为了防止新的对象被析构，他们都指向同一内存地址
        other.m_size = 0;
        other.m_buffer = nullptr;
    }
    // 重写移动赋值运算符
    String &operator=(String &&other) noexcept
    {
        // 避免自赋值操作，否则会产生内存泄漏
        if (this != &other)
        {
            // 一定要释放原来的内存，不然会产生内存泄漏
            delete[] m_buffer;
            std::cout << "move assign" << std::endl;
            // 置空
            m_size = other.m_size;
            m_buffer = other.m_buffer;
            other.m_size = 0;
            other.m_buffer = nullptr;
        }
        return *this;
    }
    //  声明友元
    friend std::ostream &operator<<(std::ostream &stream, String &string);
};
std::ostream &operator<<(std::ostream &stream, String &string)
{
    if (!string.m_buffer)
    {
        stream << "null";
    }
    else
    {
        stream << string.m_buffer;
    }
    return stream;
}
class Entity
{
private:
    // 这里的m_name也会调用一次析构函数
    String m_name;

public:
    Entity(const String &name) : m_name(name) {}
    // 传入的右值引用在函数体内会变成左值
    Entity(String &&name) : m_name((String &&)name) {}
    ~Entity()
    {
    }
};

int main()
{
#if 0
    String str("vagmr");
    String second = str;
    str[2] = '2';
    std::cout << str << std::endl;
    std::cout << second << std::endl;
#endif
    // Entity e("vagmr");

    // 运行到此时，原String构造的对象已被销毁，但是m_name仍然存在，这就是这样做的好处
    {
        String str = "hello";
        String str2;
        std::cout << "str:" << str << std::endl;
        std::cout << "str2:" << str2 << std::endl;
        str2.operator=(std::move(str));
        std::cout << "str:" << str << std::endl;
        std::cout << "str2:" << str2 << std::endl;
    }
    std::cin.get();
}