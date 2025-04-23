#include <iostream>
#include "EventHandler.hpp"

int main() {

    EventHandler handler;


    handler.registerGod("Zeus");
    handler.registerGod("Thor");
    handler.registerGod("Poseidon");

    handler.submitEvent("Zeus", Event("Thunder Strike", "Strike the enemy"));
    handler.submitEvent("Thor", Event("Hammer Swing", "Smash the rock"));
    handler.submitEvent("Poseidon", Event("Tsunami", "Flood the village"));


    while (handler.hasPendingEvents()) {
        Event event = handler.getNextEvent();
        // Simulate event handling (printing)
        std::cout << "Handling event: " << event.getName() << std::endl;
    }

    return 0;
}
