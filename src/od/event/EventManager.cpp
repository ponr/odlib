#include "EventManager.hpp"

namespace od {
namespace event {

EventManager::EventManager() :
    mEventMutex(),
    mEventManagerThread()
{
}

EventManager::~EventManager()
{
}

}
}
