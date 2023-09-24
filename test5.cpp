#include <cstdio>
#include <cmath>

double function1()
{
    double pi = log(pow(640320, 3) + 744) / sqrt(163);
    return pi;
}
double function2()
{
    // pi is defined in this scope,can not return the reference
    double pi = 16 * atan(1.0 / 5.0) - 4 * atan(1.0 / 239.0);
    return pi;
}
int main()
{
    printf("%.15lf\n", function1());
    printf("%.15lf\n", function2());
}