#pragma once

#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include "Event.hpp"
#include "God.hpp"

/**
 * @brief The EldenTree class is responsible for managing the gods and their events.
 * It provides functionality to register gods, receive events, and dispatch events in a round-robin fashion.
 * */
class EldenTree
{
public:
    void registerGod(God *god);
    void dispatchEvents();
    bool eventReceiver(int sourceId, const Event &event);

private:
    std::vector<std::pair<int, std::string>> godNames;
    std::vector<std::pair<int, Event>> eventQueues;
    static int dispatchCounter;
    size_t totalDispatches = 0;
};