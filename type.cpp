#include <iostream>
struct Entity
{
    int x, y;
};

int main()
{
    int a = 50;
    double b = a;
    std::cout << b << std::endl;
    Entity e = {1, 3};
    int *c = (int *)&e;
    int y = *(int *)((char *)&e + 4);
    std::cout << y << std::endl;
    std::cout << c[1] << "," << c[0] << std::endl;
    std::cin.get();
}