#ifndef ELDEN_TREE_HPP // Include guard for implementation
#include "EventHandler.hpp"
#endif

template<typename Payload>
void EldenTree<Payload>::registerGod(const std::string& name, EventHandler<Payload> handler) {
    handlers[name] = handler;
    eventQueues[name]; // Initialize queue for this god
    dispatchCounter[name] = 0; // Initialize dispatch counter
}

template<typename Payload>
void EldenTree<Payload>::postEvent(const std::string& godName, const Event<Payload>& event) {
    if (eventQueues.find(godName) != eventQueues.end()) {
        eventQueues[godName].push(event); // Add event to the god's queue
    }
}

template<typename Payload>
void EldenTree<Payload>::dispatch() {
    // Simple round-robin fairness: process one event per god per cycle if available
    for (auto& [godName, queue] : eventQueues) {
        if (!queue.empty()) {
            auto& handler = handlers[godName];
            if (handler) {
                handler(queue.front()); // Process the event
                queue.pop(); // Remove it from the queue
                dispatchCounter[godName]++;
                totalDispatches++;
            }
        }
    }
}