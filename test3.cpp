#define FMT_HEADER_ONLY
#include <fmt/color.h>
#include <fmt/core.h>
#include <cstdio>
int main()
{
    double x, y;
    while (scanf("%lf %lf", &x, &y) != EOF)
    {
        fmt::print(fg(fmt::color::tomato) | fmt::emphasis::bold,
                   "{0} + {1} = {2}  {0} * {1} = {2:.2f}", x, y, x + y);
    }
    return 0;
}