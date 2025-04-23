#pragma once
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include "Event.hpp"

class EventHandler {
public:
    // Registers a new god to handle events
    void registerGod(const std::string& godName);

    // Submit an event for a particular god
    void submitEvent(const std::string& godName, const Event& event);

    // Checks if there are any pending events
    bool hasPendingEvents() const;

    // Get the next event to process (round-robin scheduling)
    Event getNextEvent();

private:
    std::unordered_map<std::string, std::queue<Event>> eventQueues;  // Mapping gods to their event queues
    std::vector<std::string> godOrder;  // Round-robin ordering of gods
    size_t currentIndex = 0;  // To track which god should be dispatched next
};
