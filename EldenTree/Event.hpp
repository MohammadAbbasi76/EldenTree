#include <string>
#include <functional>
#include <chrono>

class Event
{
public:

    Event(int sourceId, std::function<void()> handler = nullptr)
        : SourceId(sourceId), Callback(std::move(handler)),
          TimeStamp(std::chrono::steady_clock::now()) {}

    const void action()
    {
        if (Callback)
            Callback();
    }

    const int sourceId() const { return SourceId; }
    const std::function<void()> &getCallback() const { return Callback; }
    std::chrono::steady_clock::time_point getTimeStamp() const { return TimeStamp; }

private:
    int SourceId;
    std::function<void()> Callback;
    std::chrono::steady_clock::time_point TimeStamp;
};
