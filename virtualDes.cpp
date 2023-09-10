#include <iostream>
class Base
{
public:
    Base()
    {
        std::cout << "base created " << std::endl;
    }
    virtual ~Base()
    {
        std::cout << "base destroyed " << std::endl;
    }
};
class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "derived created " << std::endl;
    }
    ~Derived() override
    {
        std::cout << "derived destroyed " << std::endl;
    }
};
int main()
{
    Base *d = new Derived();
    delete d;
    std::cin.get();
}