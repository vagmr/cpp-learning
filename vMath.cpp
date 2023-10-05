#include "vMath.h"

// 函数实现
void vMath::getVersion()
{
    std::cout << "vMath version 1.0" << std::endl;
};
double vMath::vS_sqrt(double x)
{
    std::cout << "sqrt:" << sqrt(x) << std::endl;
    return sqrt(x);
}
double vMath::vS_pow(double x, double y)
{
    return pow(x, y);
}