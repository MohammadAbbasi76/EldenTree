#include"God.hpp"


int God::GodId = 0;


God::God(std::string name) : Name(name)
{
    GodId++;
}
bool God::postEvent()
{
    return true;
}