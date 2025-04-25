#include <iostream>
#include <memory>
#include"EldenTree.hpp"   

std::function<void()> createGodCallback(const std::string& godName, const std::string& eventName) {
    return [godName, eventName]() {
        std::cout << "God: " << godName << "\t,executing event:\t" << eventName ;
    };
}

int main() {

    EldenTree eldenTree;

    God zeus("Zeus");
    God poseidon("Poseidon");
    God hades("Hades");
    God athena("Athena");

    eldenTree.registerGod(&zeus);
    eldenTree.registerGod(&poseidon);
    eldenTree.registerGod(&hades);
    eldenTree.registerGod(&athena);

    Event zeusLightning(zeus.getId(), createGodCallback("Zeus", "Lightning Strike"));
    Event zeusThunder(zeus.getId(), createGodCallback("Zeus", "Thunder Roar"));
    Event zeusStorm(zeus.getId(), createGodCallback("Zeus", "Storm Creation"));
    Event zeusRain(zeus.getId(), createGodCallback("Zeus", "Rain Control"));

    Event poseidonWave(poseidon.getId(), createGodCallback("Poseidon", "Tidal Wave"));
    Event poseidonWhirlpool(poseidon.getId(), createGodCallback("Poseidon", "Whirlpool"));
    Event poseidonEarthquake(poseidon.getId(), createGodCallback("Poseidon", "Earthquake"));
    Event poseidonTrident(poseidon.getId(), createGodCallback("Poseidon", "Trident Throw"));

    Event hadesUndead(hades.getId(), createGodCallback("Hades", "Raise Undead"));
    Event hadesShadow(hades.getId(), createGodCallback("Hades", "Shadow Control"));
    Event hadesHellfire(hades.getId(), createGodCallback("Hades", "Hellfire Burst"));
    Event hadesJudgment(hades.getId(), createGodCallback("Hades", "Soul Judgment"));

    Event athenaWisdom(athena.getId(), createGodCallback("Athena", "Wisdom Blessing"));
    Event athenaStrategy(athena.getId(), createGodCallback("Athena", "Battle Strategy"));
    Event athenaCraft(athena.getId(), createGodCallback("Athena", "Divine Craft"));
    Event athenaShield(athena.getId(), createGodCallback("Athena", "Aegis Shield"));

    zeus.postEvent(zeusLightning);
    zeus.postEvent(zeusThunder);
    zeus.postEvent(zeusStorm);
    zeus.postEvent(zeusRain);

    poseidon.postEvent(poseidonWave);
    poseidon.postEvent(poseidonWhirlpool);
    poseidon.postEvent(poseidonEarthquake);
    poseidon.postEvent(poseidonTrident);

    hades.postEvent(hadesUndead);
    hades.postEvent(hadesShadow);
    hades.postEvent(hadesHellfire);
    hades.postEvent(hadesJudgment);

    athena.postEvent(athenaWisdom);
    athena.postEvent(athenaStrategy);
    athena.postEvent(athenaCraft);
    athena.postEvent(athenaShield);
    
    eldenTree.dispatchEvents();
    return 0;
}