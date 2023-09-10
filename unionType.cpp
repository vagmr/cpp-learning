#include <iostream>
struct vector2
{
    float x, y;
};
struct vector4
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        struct
        {
            vector2 a, b;
        };
    };
};
std::ostream &operator<<(std::ostream &stream, const vector2 &v)
{

    stream << v.x << "," << v.y;
    return stream;
};
int main()
{
    vector4 v = {1.0f, 2.0f, 3.0f, 4.0f};
    std::cout << v.x << "," << v.y << "," << v.z << "," << v.w << std::endl;
    v.z = 500.0f;
    std::cout << v.a << "," << v.b << "," << std::endl;
    std::cin.get();
}