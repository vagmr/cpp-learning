#include <iostream>
struct Entity
{
    virtual void prt(){};
};
struct Player : public Entity
{
};
struct enemy : public Entity
{
};

int main()
{
    Entity *e = new Entity();
    Entity *p = new Player();
    Entity *e1 = new enemy();
    Player *p1 = dynamic_cast<Player *>(e1); // null
    Player *p2 = dynamic_cast<Player *>(e);  // null
    // 如果转换成功则会输出地址
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    if (p1 == NULL && p2 == NULL)
    {
        std::cout << "null" << std::endl;
    }
    std::cin.get();
}