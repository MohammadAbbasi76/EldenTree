#pragma once

#include <string>
#include <queue>
#include <unordered_map>
#include <functional>
#include <chrono>
#include"Event.hpp"
class God
{
public:
    God();
    ~God();
    bool PostEvent();

protected:
    static int GodId;

private:
    static bool FirstTimeFlag;
    std::unordered_map<std::string, std::Event<Payload>> Queues;
};
