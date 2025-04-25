#pragma once
#include <string>
#include <functional>
#include <chrono>

class Event
{
public:
    Event(int sourceId, std::function<void()> handler = nullptr)
        : SourceId(sourceId), Callback(std::move(handler)),
          TimeStamp(std::chrono::steady_clock::now()) {}

     void action() const
    {
        if (Callback)
        {
            Callback();
            auto now = std::chrono::steady_clock::now();
            auto duration =(now - TimeStamp);
            std::cout << "Event action executed after " << duration.count() << " microseconds." << std::endl;   
        }

    }

     int sourceId() const { return SourceId; }
    const std::function<void()> &getCallback() const { return Callback; }
    std::chrono::steady_clock::time_point getTimeStamp() const { return TimeStamp; }

private:
    int SourceId;
    std::function<void()> Callback;
    std::chrono::steady_clock::time_point TimeStamp;
};
