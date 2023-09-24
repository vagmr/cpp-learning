/*这是一个简单的计时器，用于计算程序运行时间 */

#include <iostream>
#include <chrono>
class Timer
{
public:
    Timer()
    {
        start_timerPoint = std::chrono::high_resolution_clock::now();
    }
    Timer(const char *info)
    {
        start_timerPoint = std::chrono::high_resolution_clock::now();
        m_info = info;
    }
    ~Timer()
    {
        stop();
    }
    void stop()
    {
        end_timePoint = std::chrono::high_resolution_clock::now();
        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(start_timerPoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(end_timePoint).time_since_epoch().count();
        auto duration = end - start;
        double ms = duration * 0.001;
        if (m_info.size() > 0)
        {
            std::cout << m_info << ": ";
        }
        std::cout << "duration=" << ms << "ms(" << duration << " us)" << std::endl;
    }

private:
    std::chrono::_V2::system_clock::time_point start_timerPoint, end_timePoint;
    std::string m_info;
};