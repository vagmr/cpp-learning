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
    Xg x;
    std::cout << x.GetName() << std::endl;
}