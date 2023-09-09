#include <iostream>
#include <vector>
#define println(x) std::cout << x << std::endl;

struct Va
{
    float x, y, z;
    Va(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
    Va(const Va &v)
        : x(v.x), y(v.y), z(v.z)
    {
        std::cout << "copy constructor" << std::endl;
    }
};
std::ostream &operator<<(std::ostream &stream, Va &va)
{
    stream << va.x << "," << va.y << "," << va.z;
    return stream;
}
int main()
{
    std::vector<Va> v;
    v.reserve(3);
    v.emplace_back(1.2, 2.3, 3.4);
    v.emplace_back(3.3, 1.5, 1.5);
    v.emplace_back(3.5, 1.7, 1.1);
    for (int i = 0; i < v.size(); i++)
    {
        println(v[i]);
    }
    v.erase(v.begin() + 1);
    for (Va &x : v)
    {
        println(x);
    }

    v.clear();
    println(1);
    println("x");
    println(1.4f);
    std::cin.get();
}