#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>

class Timer {
public:
    Timer();
    ~Timer();
    void Stop();
    double breakpoint();
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
    std::chrono::time_point<std::chrono::high_resolution_clock> now_time;
};

#endif // !TIMER_H
