#include "EldenTree.hpp"
#include "Event.hpp"
#include <iostream>
#include <vector>

int EldenTree::DispatchCounter = 0;
int God::RegisteredGodCount = 0;
std::vector<std::pair<int, Event>> EldenTree::EventQueues;

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
    RegisterGods.push_back({god->getId(), god->getName()});
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
void EldenTree::dispatchEvents()
{
    if (RegisterGods.empty() || EventQueues.empty())
    {
        std::cout << "No gods or events to process." << std::endl;
        return;
    }
    size_t numGods = RegisterGods.size();
    std::vector<bool> godProcessedThisRound(numGods, false);
    bool eventProcessed;
    do
    {
        eventProcessed = false;
        int currentGodIndex = DispatchCounter % numGods;
        int currentGodId = RegisterGods[currentGodIndex].first;
        if (!godProcessedThisRound[currentGodIndex])
        {
            for (auto it = EventQueues.begin(); it != EventQueues.end(); ++it)
            {
                if (it->first == currentGodId)
                {
                    it->second.action();
                    godProcessedThisRound[currentGodIndex] = true;
                    EventQueues.erase(it);
                    eventProcessed = true;
                    break;
                }
            }
        }
        DispatchCounter++;
        if (DispatchCounter % numGods == 0)
        {
            std::fill(godProcessedThisRound.begin(), godProcessedThisRound.end(), false);
            if (!eventProcessed)
            {
                break;
            }
        }
    } while (!EventQueues.empty());
    std::cout << "Dispatch counter: " << DispatchCounter << std::endl;
}

/**
 * @brief postEvent is responsible for posting an event to the EldenTree.
 * @param[in] const Event &eventData - The event to be posted.
 * @return bool - Returns true if the event was successfully posted, false otherwise.
 * @note The function checks if the event callback is valid before posting the event.
 */
bool God::postEvent(const Event &eventData)
{
    if (eventData.getCallback() == nullptr)
    {
        std::cout << "Invalid event callback." << std::endl;
        return false;
    }
    EldenTree::eventReceiver(this->getId(), eventData);
    return true;
}
