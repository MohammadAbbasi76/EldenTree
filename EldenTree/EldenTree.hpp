#pragma once

#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <memory>
#include "Event.hpp"

/**
 * @brief The God class represents a god in the EldenTree system.
 * Each god has a unique ID and a name. The class provides functionality to post events.
 * */
class God
{
public:
    God(std::string name) : Name(std::move(name))
    {
        GodId = RegisteredGodCount;
        RegisteredGodCount++;
    };
    bool postEvent(const Event &eventData);
    std::string getName() const { return Name; }
    int getId() const { return GodId; }

protected:
private:
    std::string Name;
    static int RegisteredGodCount;
    int GodId;
};

/**
 * @brief The EldenTree class is responsible for managing the gods and their events.
 * It provides functionality to register gods, receive events, and dispatch events in a round-robin fashion.
 * */
class EldenTree
{
public:
    void registerGod(God *god);
    void dispatchEvents();
    static bool eventReceiver(int sourceId, const Event &event);

private:
    std::vector<std::pair<int, std::string>> GodNames;
    static std::vector<std::pair<int, Event>> EventQueues;
    static int DispatchCounter;
    size_t TotalDispatches = 0;
};
