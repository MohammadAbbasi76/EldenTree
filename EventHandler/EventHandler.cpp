#include "EventHandler.h"
#include <iostream>

void EventHandler::registerGod(const std::string& godName) {
    if (eventQueues.find(godName) == eventQueues.end()) {
        eventQueues[godName] = std::queue<Event>();
        godOrder.push_back(godName);
        std::cout << "Registered god: " << godName << std::endl;
    } else {
        std::cout << "God " << godName << " is already registered." << std::endl;
    }
}

void EventHandler::submitEvent(const std::string& godName, const Event& event) {
    if (eventQueues.find(godName) != eventQueues.end()) {
        eventQueues[godName].push(event);
        std::cout << "Submitted event: " << event.getName() << " for god: " << godName << std::endl;
    } else {
        std::cout << "God " << godName << " is not registered." << std::endl;
    }
}

bool EventHandler::hasPendingEvents() const {
    for (const auto& god : godOrder) {
        if (!eventQueues.at(god).empty()) {
            return true;  // There are pending events in at least one queue
        }
    }
    return false;  // No pending events
}

Event EventHandler::getNextEvent() {
    // Round-robin scheduling
    while (hasPendingEvents()) {
        const std::string& currentGod = godOrder[currentIndex];
        if (!eventQueues[currentGod].empty()) {
            Event event = eventQueues[currentGod].front();
            eventQueues[currentGod].pop();
            std::cout << "Processing event: " << event.getName() << " from god: " << currentGod << std::endl;
            currentIndex = (currentIndex + 1) % godOrder.size();  // Move to the next god in the round-robin queue
            return event;
        }

        currentIndex = (currentIndex + 1) % godOrder.size();  // Move to the next god if current god has no events
    }

    throw std::runtime_error("No events to process");
}
