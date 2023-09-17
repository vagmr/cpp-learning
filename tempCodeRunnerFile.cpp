#include <iostream>
#include <cmath>

class Heart
{
public:
    int x, y, z;

    Heart(const int &X, const int &Y, const int &Z) : x(X), y(Y), z(Z)
    {
        std::cout << "构造函数" << std::endl;
    }

    void draw()
    {
        for (int i = 0; i < z; i++)
        {
            for (int j = 0; j <= 4 * z; j++)
            {
                float dist1 = sqrt(pow(i - z, 2) + pow(j - 2 * z, 2)); // 使用相对坐标
                float dist2 = sqrt(pow(i - z, 2) + pow(j - 4 * z, 2)); // 使用相对坐标

                if ((dist1 < z + 0.5 && j <= 2 * z) || (dist2 < z + 0.5 && j >= 2 * z))
                {
                    std::cout << "*";
                }
                else
                {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    int x; // x坐标
    int y; // y坐标
    int z; // 爱心的大小
    std::cout << "请输入爱心的大小"
              << "\n";
    std::cin >> z;

    // 计算合适的x和y坐标，使得爱心居中
    x = z;
    y = 2 * z;

    Heart heart(x, y, z);
    heart.draw();
    return 0;
}
