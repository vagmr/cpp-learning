#include <iostream>
#include <mingw.thread.h>
#include <chrono>
// 计时构造器
struct Timer
{
    std::chrono::_V2::system_clock::time_point start, end;
    std::chrono::duration<float> duration;
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        // 转化为ms
        int64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

        std::cout << "duration=" << ms << "ms" << std::endl;
    }
};
void fnc()
{
    Timer t; // 在出栈之前调用析构函数
    for (int i = 1; i <= 100; i++)
    {
        std::cout << i << "\n";
    }
}
int main()
{
    using namespace std::literals::chrono_literals;
    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::cout << "线程id=" << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(1s);
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << "duration=" << duration.count() << "s" << std::endl;
    fnc();
    std::cin.get();
}