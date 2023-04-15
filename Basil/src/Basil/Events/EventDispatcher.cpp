#include "hzpch.h"
#include "EventDispatcher.hpp"

namespace Basil
{
    EventDispatcher::EventMap EventDispatcher::s_EventMap;
    
    void EventDispatcher::Dispatch(const Ref<Event>& event)
    {
        const auto [first, last] = s_EventMap.equal_range(typeid(*event).name());
        for (auto it = first; it != last; ++it)
        {
            it->second.second(event);
            if (event->Handled) return;
        }
    }
}
