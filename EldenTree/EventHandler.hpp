#pragma once

#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include "Event.hpp"
#include "God.hpp"
class EldenTree
{
public:
    void registerGod(God *god);
    void dispatchEvents();
    bool eventReceiver(int sourceId,const Event &event);

private:
    std::vector<std::pair<int, Event>> eventQueues;
    int dispatchCounter;
    size_t totalDispatches = 0;
};