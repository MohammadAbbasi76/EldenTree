#ifndef ELDEN_TREE_HPP
#define ELDEN_TREE_HPP

#include <string>
#include <queue>
#include <unordered_map>
#include <functional>
#include <chrono>

// Templated Event struct for flexible payloads
template<typename Payload>
struct Event {
    std::string name;
    Payload data;
    std::chrono::steady_clock::time_point timestamp;

    Event(const std::string& n, const Payload& d)
        : name(n), data(d), timestamp(std::chrono::steady_clock::now()) {}
};

// Event handler type alias
template<typename Payload>
using EventHandler = std::function<void(const Event<Payload>&)>;

// EldenTree event dispatcher class
template<typename Payload>
class EldenTree {
public:
    // Register a god with its event handler
    void registerGod(const std::string& name, EventHandler<Payload> handler);

    // Post an event for a specific god
    void postEvent(const std::string& godName, const Event<Payload>& event);

    // Dispatch events fairly to all gods
    void dispatch();

private:
    // Store events in queues per god
    std::unordered_map<std::string, std::queue<Event<Payload>>> eventQueues;
    // Store event handlers per god
    std::unordered_map<std::string, EventHandler<Payload>> handlers;
    // Track last dispatch for fairness (round-robin style)
    std::unordered_map<std::string, size_t> dispatchCounter;
    size_t totalDispatches = 0; // To implement a simple round-robin fairness
};

//     std::unordered_map<std::string, std::Event<Payload>> Queues;

#include "EventHandler.cpp" // Include implementation in header for templated class
#endif