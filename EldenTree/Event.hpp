#pragma once
#include <string>
#include <chrono>

class Event {
public:
    Event(std::string eventName, std::string eventData)
        : name(eventName), data(eventData), timestamp(std::chrono::steady_clock::now()) {}

    std::string getName() const { return name; }
    std::string getData() const { return data; }
    std::chrono::steady_clock::time_point getTimestamp() const { return timestamp; }

private:
    std::string name;  // Name of the event (e.g., "Thunder Strike")
    std::string data;  // Data associated with the event
    std::chrono::steady_clock::time_point timestamp;  // Timestamp for the event
};
