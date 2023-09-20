#define FMT_HEADER_ONLY
#include <fmt/color.h>
#include <fmt/core.h>
#include <cstdio>
#include <chrono>
#include <thread>
int main()
{
    fmt::print(
        "┌{0:─^{2}}┐\n"
        "│{1: ^{2}}│\n"
        "└{0:─^{2}}┘\n",
        "", "Hello, world!", 20);
    fmt::print(fg(fmt::color::dark_slate_blue) | fmt::emphasis::bold,
               "遇见你是一件很开心的事情,爱你哟！！！");
    float x, y, a;
    for (y = 1.5f; y > -1; y -= 0.1f)
    {
        for (x = -1.5f; x < 1.5f; x += .05f)
        {
            a = x * x + y * y - 1;
            fmt::print(
                fg(fmt::color::aqua) | fmt::emphasis::italic,
                "{}", (a * a * a - x * x * y * y * y < 0.0f ? 'x' : ' '));
            // 控制字符显示速度
            std::this_thread::sleep_for(std::chrono::microseconds(1500));
        }
        fmt::print("\n");
    }
    getchar();
    return 0;
}
