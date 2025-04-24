#include <string>
#include <functional>
#include <chrono>

template<typename DataType>
class Event {
public:
    using CallbackHandler = std::function<void(const DataType&)>;

    Event(int sourceId, CallbackHandler handler = nullptr)
        : SourceId(sourceId), Callback(std::move(handler)),
          TimeStamp(std::chrono::steady_clock::now()) {}

    void action() const {
        if (Callback) Callback();
    }

    const int sourceId() const { return SourceId; }
    const CallbackHandler& getCallback() const { return Callback; }
    std::chrono::steady_clock::time_point getTimeStamp() const { return TimeStamp; }

private:
    int SourceId;
    DataType Data;
    CallbackHandler Callback;
    std::chrono::steady_clock::time_point TimeStamp;
};
