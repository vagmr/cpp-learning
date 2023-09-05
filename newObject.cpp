#include <iostream>
#include <string>

class Xg
{
private:
    int m_y, m_x;
    std::string m_name;

public:
    Xg() : m_x(10), m_y(12), m_name("null") {}
    Xg(const std::string &name) { m_name = name; };
    const int &GetY() const { return m_y; };
    const std::string &GetName() const { return m_name; }
    void setX(int x)
    {
        m_x = x;
    }
};
int main()
{
    Xg *x3;
    Xg x; // 在栈上创建类实例，出栈时销毁
    // 也可以写成Xg x = Xg("cghss");
    {
        Xg *x1 = new Xg("cghss"); // new返回的是在堆上的内存地址
        // 需要用到delete手动清理 delete x1;
        x3 = x1;
    }
    std::cout << x3->GetName() << std::endl; // 此时已出x1的作用域,x1将不可见，但x1不会被销毁，依旧存在内存中
    // 由于x3是一个地址值，因此不能直接使用.调用方法,可以(*x3).GetName()
    delete x3;
    /*x3和x1指向的是同一个堆上的对象。在代码中，通过x3 = x1;将x1的值赋给了x3，它们指向相同的内存地址。
    因此，如果在删除x3之后再删除x1，实际上是在重复删除同一个对象，这是不必要的。 */
}