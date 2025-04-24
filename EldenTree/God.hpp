#pragma once

#include <string>
#include <unordered_map>
#include "Event.hpp"
class God
{
public:
    God(std::string name);
    bool postEvent(); // Replace std::string with the appropriate type if needed
    std::string godName() { return Name; }

protected:
private:
    std::string Name;
    static int GodId;
};
