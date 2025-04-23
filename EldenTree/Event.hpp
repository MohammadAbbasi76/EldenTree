#include <string>
#include <functional>
#include <chrono>

template<typename DataType>
class Event {
public:
    using Callback = std::function<void(const DataType&)>;

    Event(std::string name, DataType data, Callback handler = nullptr)
        : name(std::move(name)), data(std::move(data)), callback(handler),
          timestamp(std::chrono::steady_clock::now()) {}

    void trigger() const {
        if (callback) callback(data);
    }

    const std::string& getName() const { return name; }
    const DataType& getData() const { return data; }
    std::chrono::steady_clock::time_point getTimestamp() const { return timestamp; }

private:
    std::string name;
    DataType data;
    Callback callback;
    std::chrono::steady_clock::time_point timestamp;
};
