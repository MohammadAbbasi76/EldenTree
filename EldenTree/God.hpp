#pragma once

#include <string>
#include <unordered_map>
#include "Event.hpp"

class God
{
public:
    God(std::string name):Name(std::move(name))
    {
        GodId++;
    }
    template<typename eventType>
    bool postEvent(const eventType& eventData); // Updated naming for clarity
    
    std::string getName() const { return Name; } // Updated method name for clarity and consistency

protected:
private:
    std::string Name; // Updated member variable naming to follow a consistent convention
    static int GodId; // Updated static member variable naming to follow a consistent convention
};
