#include <iostream>       // 包含输入输出流库
#include <mingw.thread.h> // 包含MinGW线程库（假设你正在使用MinGW编译器）

static bool is_continue = true; // 定义一个静态的布尔变量is_continue，用于控制线程是否继续运行

void prtHello() // 定义一个名为prtHello的函数，该函数将在新线程中执行
{
    using namespace std::literals::chrono_literals; // 使用chrono_literals命名空间来使用时间字面值

    std::cout << "线程id为" << std::this_thread::get_id() << std::endl; // 输出当前线程的ID
    while (is_continue)                                                 // 进入一个循环，只要is_continue为true，就会一直执行下去
    {
        std::cout << "hello world" << std::endl; // 输出 "hello world"
        std::this_thread::sleep_for(1s);         // 使线程休眠1秒钟
    }
}

int main() // 主函数
{
    std::thread t1(prtHello); // 创建一个名为t1的线程，执行prtHello函数

    std::cin.get(); // 等待用户在控制台输入任意字符后继续执行

    is_continue = false;
    // 设置is_continue为false，以便告诉prtHello函数停止循环
    t1.join();
    // 等待t1线程执行完毕后再继续主线程的执行
    std::cout << "线程id为" << std::this_thread::get_id() << std::endl; // 输出当前线程的ID
    std::cout << "vagmr finished" << std::endl;                         // 输出 "vagmr finished"

    std::cin.get(); // 等待用户在控制台输入任意字符后继续执行
}
