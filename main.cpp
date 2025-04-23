#include <iostream>
#include "EventHandler.hpp"

int main() {
    // Initialize EventHandler (Elden Tree)
    EventHandler handler;

    // Register some gods
    handler.registerGod("Zeus");
    handler.registerGod("Thor");
    handler.registerGod("Poseidon");

    // Submit some events
    handler.submitEvent("Zeus", Event("Thunder Strike", "Strike the enemy"));
    handler.submitEvent("Thor", Event("Hammer Swing", "Smash the rock"));
    handler.submitEvent("Poseidon", Event("Tsunami", "Flood the village"));

    // Process events in round-robin fashion
    while (handler.hasPendingEvents()) {
        Event event = handler.getNextEvent();
        // Simulate event handling (printing)
        std::cout << "Handling event: " << event.getName() << std::endl;
    }

    return 0;
}
