#pragma once

#include <string>
#include <unordered_map>
#include "Event.hpp"
class God
{
public:
    God(std::string name);
    ~God();
    bool postEvent();
    std::string godName(){return Name;}

protected:
private:
    std::string Name;
};
