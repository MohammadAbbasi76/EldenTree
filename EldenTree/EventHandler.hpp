#pragma once

#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include "Event.hpp"
#include "EventSender.hpp"

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
    std::vector<std::pair<int, std::string>> GodNames;
    std::vector<std::pair<int, Event>> EventQueues;
    static int DispatchCounter;
    size_t TotalDispatches = 0;
};