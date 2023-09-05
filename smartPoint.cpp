#include <iostream>
#include <memory>
#define print(x) std::cout << x << std::endl;
class Phone
{
public:
    int price, core;
    Phone() : price(0), core(0) { print("phone created"); }
    Phone(int price, int core) : price(price), core(core) {}
    ~Phone() { print("phone destroyed"); }
    void printh()
    {
        print("hello world");
    }
};
// 作用域指针简单实现
class PhoneScope
{
public:
    const Phone *m_p;
    PhoneScope(Phone *p) : m_p(p) {}
    ~PhoneScope()
    {
        delete m_p;
    }
};
int main()
{
    {
        PhoneScope p = new Phone();
    }
    std::weak_ptr<Phone> e;
    // 使用智能指针
    {
        std::unique_ptr<Phone> p = std::make_unique<Phone>();
        (*p).printh();
        // 使用share_ptr
        std::shared_ptr<Phone> p1 = std::make_shared<Phone>();
        e = p1;
    }
    std::cin.get();
}