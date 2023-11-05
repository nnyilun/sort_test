#include "Timer.h"

Timer::Timer() {
    m_StartTimepoint = std::chrono::high_resolution_clock::now();
    now_time = m_StartTimepoint;
}

Timer::~Timer() {
    Stop();
}

void Timer::Stop() {
    auto endTimepoint = std::chrono::high_resolution_clock::now();

    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch();

    double duration = (end - start).count();
    double ms = duration * 0.001;
    std::cout << "Time usage: " << duration << " us (" << ms << " ms)\n";
}

double Timer::breakpoint() {
    auto before = now_time;
    auto breakTimepoint = std::chrono::high_resolution_clock::now();
    now_time = breakTimepoint;

    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(before).time_since_epoch();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(breakTimepoint).time_since_epoch();

    return (end - start).count();
}