#include <iostream>
#include <memory>
#include"EldenTree.hpp"   
// Helper function to create event callbacks for gods
std::function<void()> createGodCallback(const std::string& godName, const std::string& eventName) {
    return [godName, eventName]() {
        std::cout << "God: " << godName << " is executing event: " << eventName << std::endl;
    };
}

int main() {
    // Create the Elden Tree
    EldenTree eldenTree;

    // Create 4 gods
    auto zeusGod = std::make_unique<God>("Zeus");
    auto poseidonGod = std::make_unique<God>("Poseidon");
    auto hadesGod = std::make_unique<God>("Hades");
    auto athenaGod = std::make_unique<God>("Athena");

    // Register gods with the Elden Tree
    eldenTree.registerGod(zeusGod.get());
    eldenTree.registerGod(poseidonGod.get());
    eldenTree.registerGod(hadesGod.get());
    eldenTree.registerGod(athenaGod.get());

    // Create events for Zeus
    Event zeusLightning(zeusGod->getId(), createGodCallback("Zeus", "Lightning Strike"));
    Event zeusThunder(zeusGod->getId(), createGodCallback("Zeus", "Thunder Roar"));
    Event zeusStorm(zeusGod->getId(), createGodCallback("Zeus", "Storm Creation"));
    Event zeusRain(zeusGod->getId(), createGodCallback("Zeus", "Rain Control"));

    // Create events for Poseidon
    Event poseidonWave(poseidonGod->getId(), createGodCallback("Poseidon", "Tidal Wave"));
    Event poseidonWhirlpool(poseidonGod->getId(), createGodCallback("Poseidon", "Whirlpool"));
    Event poseidonEarthquake(poseidonGod->getId(), createGodCallback("Poseidon", "Earthquake"));
    Event poseidonTrident(poseidonGod->getId(), createGodCallback("Poseidon", "Trident Throw"));

    // Create events for Hades
    Event hadesUndead(hadesGod->getId(), createGodCallback("Hades", "Raise Undead"));
    Event hadesShadow(hadesGod->getId(), createGodCallback("Hades", "Shadow Control"));
    Event hadesHellfire(hadesGod->getId(), createGodCallback("Hades", "Hellfire Burst"));
    Event hadesJudgment(hadesGod->getId(), createGodCallback("Hades", "Soul Judgment"));

    // Create events for Athena
    Event athenaWisdom(athenaGod->getId(), createGodCallback("Athena", "Wisdom Blessing"));
    Event athenaStrategy(athenaGod->getId(), createGodCallback("Athena", "Battle Strategy"));
    Event athenaCraft(athenaGod->getId(), createGodCallback("Athena", "Divine Craft"));
    Event athenaShield(athenaGod->getId(), createGodCallback("Athena", "Aegis Shield"));

    // Process all events
    eldenTree.dispatchEvents();

    std::cout << "\nAll events have been processed." << std::endl;

    return 0;
}