#include <iostream>
#include <string>
#define print(x) std::cout << x << std::endl;
using string = std::string;
class Player
{
private:
    int m_healthy, m_level, m_attack;
    string m_name;

public:
    int m_test;
    Player() : m_name("va"), m_healthy(100), m_level(1), m_attack(10), m_test(1){};
    Player(int health, int level, int attack) : m_test(1)
    {
        m_healthy = health;
        m_level = level;
        m_attack = attack;
        std::cout << "创建有参构造器成功" << std::endl;
    };
    Player(const string &name) { m_name = name; };
    // explicit Player(const string &name) { m_name = name; }; 加上显式关键字后，将不再支持隐式转换
    const int &getHealthy() const { return m_healthy; };
    // 运算符重载
    Player operator+(const Player &p) const
    /*不能返回局部变量或临时对象的引用。在这个情况下，
    Player(m_healthy + p.m_healthy, m_level + p.m_level, m_attack + p.m_attack)
    创建了一个临时对象，所以不能返回它的引用。 */
    {
        return Player(m_healthy + p.m_healthy, m_level + p.m_level, m_attack + p.m_attack);
    }
    Player add(const Player &other) // 利用运算符重载实现效果
    {
        return *this + other; // 或者写成 operator+(other);
        // this是一个指针指向当前的Player对象,对其解引用，实际上就是player1+player2，
        // 利用上面的运算符重载，返回一个Player对象
    }
    //==运算符重载
    bool operator==(const Player &p) const
    {
        return m_healthy == p.m_healthy && m_level == p.m_level && m_attack == p.m_attack;
    }
};
// << 运算符重载
std::ostream &operator<<(std::ostream &stream, const Player &p)
{
    stream << p.m_test << '/';
    return stream;
}
int main()
{
    Player player1 = string("xgo"); // 实际上进行了隐式转换 Player player1 = Player(string("xgao");
    // Player player2 = "va"; //因为要进行两次隐式转换才能成功，所以不行
    Player plus(100, 1, 10);
    Player plus2(200, 2, 12);
    Player res = plus + plus2;
    print(res);
    std::cin.get();
}