#include "EventHandler.hpp"
#include "God.hpp"
#include "Event.hpp"
#include <iostream>
#include <vector>

// DispatchCounter is a static variable that keeps track of the current god's turn to process events.
int EldenTree::DispatchCounter = 0; 
// GodId is a static variable that keeps track of the number of gods created.
int God::GodId = 0;
/**
* @brief registerGod is responsible for registering a god with the EldenTree.
* @param[in] God *god - A pointer to the God object to be registered.
*/
void EldenTree::registerGod(God *god)
{
    if (god == nullptr)
    {
        std::cout << "Invalid God pointer." << std::endl;
        return;
    }
    GodNames.push_back({god->getId(), god->getName()});
}

/**
* @brief eventReceiver is responsible for receiving events from gods.
* @param[in] int sourceId - The ID of the god that generated the event.
* @param[in] const Event &event - The event to be processed.
* @return bool - Returns true if the event was successfully added to the queue, false otherwise.
* @note The function also prints an error message if the event callback is invalid.
*/
bool EldenTree::eventReceiver(int sourceId, const Event &event)
{
    if (event.getCallback() == nullptr)
    {
        std::cout << "Invalid event callback." << std::endl;
        return false;
    }
    EventQueues.push_back({sourceId, event});
    return true;
}

/**
* @brief dispatchEvents is responsible for processing events in a round-robin fashion.
* It iterates through the event queues, checking if there are any events to process for each god.
* If an event is found, it calls the associated action and removes the event from the queue.
* The function continues until all events have been processed or no new events are found.
* The DispatchCounter is used to keep track of which god's turn it is to process an event.
* The function also ensures that each god gets a chance to process events in a fair manner.
*/
void EldenTree::dispatchEvents() {
    if (GodNames.empty() || EventQueues.empty()) {
        return;  
    }
    size_t numGods = GodNames.size();
    std::vector<bool> godProcessedThisRound(numGods, false);
    bool eventProcessed;
    do {
        eventProcessed = false;
        int currentGodIndex = DispatchCounter % numGods;
        int currentGodId = GodNames[currentGodIndex].first;
        if (!godProcessedThisRound[currentGodIndex]) {
            for (auto it = EventQueues.begin(); it != EventQueues.end(); ++it) {
                if (it->first == currentGodId) {
                    it->second.action();
                    godProcessedThisRound[currentGodIndex] = true;
                    EventQueues.erase(it);
                    eventProcessed = true;
                    TotalDispatches++;
                    break;
                }
            }
        }
        DispatchCounter++;
        if (DispatchCounter % numGods == 0) {
            std::fill(godProcessedThisRound.begin(), godProcessedThisRound.end(), false);
            if (!eventProcessed) {
                break;
            }
        }
    } while (!EventQueues.empty());
}

