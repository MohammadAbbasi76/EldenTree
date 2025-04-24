#pragma once

#include <string>
#include <unordered_map>
#include "Event.hpp"

class God
{
public:
    God(std::string name) : Name(std::move(name))
    {
        GodId++;
    };
    template <typename eventType>
    bool postEvent(const eventType &eventData);

    std::string getName() const { return Name; }
    int getId() const { return GodId; }
protected:
private:
    std::string Name;
    static int GodId;
};