#ifndef OD_EVENT_EVENTMANAGER_HPP
#define OD_EVENT_EVENTMANAGER_HPP

#include <thread>
#include <mutex>

namespace od {
namespace event {

/// Event Manager. Routes events to correct targets.
/// Runs in its own thread.
/// Classes receiving events from this event manager should
/// be implemented thread-safe.
class EventManager
{
public:
    /// Constructor for Event Manager
    EventManager();

    /// Destructor
    virtual ~EventManager();

private:
    EventManager(const EventManager&);
    EventManager& operator= (const EventManager&);

    std::mutex mEventMutex;
    std::thread mEventManagerThread;
};

}
}

#endif /* OD_EVENT_EVENTMANAGER_HPP */
