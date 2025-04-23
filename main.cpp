#include <iostream>
#include "EventHandler.hpp"

int main() {
    EldenTree<std::string> eldenTree;

    // Register gods with their event handlers
    eldenTree.registerGod("Thor", [](const Event<std::string>& e) {
        std::cout << "Thor received event: " << e.name << " with data: " << e.data << "\n";
    });
    eldenTree.registerGod("Odin", [](const Event<std::string>& e) {
        std::cout << "Odin received event: " << e.name << " with data: " << e.data << "\n";
    });

    // Post some events
    eldenTree.postEvent("Thor", Event<std::string>("Thunder", "Strike!"));
    eldenTree.postEvent("Odin", Event<std::string>("Wisdom", "Seek knowledge"));
    eldenTree.postEvent("Thor", Event<std::string>("Lightning", "Boom!"));

    // Dispatch events
    eldenTree.dispatch();

    return 0;
}