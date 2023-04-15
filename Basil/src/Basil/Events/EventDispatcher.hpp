#pragma once

#include <map>
#include <string>
#include <functional>

#include "Basil/Core/Base.hpp"
#include "Basil/Core/UUID.hpp"
#include "Basil/Events/Event.hpp"

namespace Basil
{
    class EventDispatcher
    {
    public:
        template<typename T> requires std::is_base_of_v<Event, T>
        static UUID Subscribe(const std::function<void(Ref<T>)>& function)
        {            
            auto uuid = UUID();
            s_EventMap.emplace(typeid(T).name(), std::make_pair(uuid, (const std::function<void(Ref<Event>)>&)function));
            return uuid;
        }

        template<typename T> requires std::is_base_of_v<Event, T>
        static void Unsubscribe(const UUID uuid)
        {
            const auto [first, last] = s_EventMap.equal_range(typeid(T).name());
            for (auto iterator = first; iterator != last; ++iterator)
            {
                if (iterator->second.first == uuid)
                {
                    s_EventMap.erase(iterator);
                    return;
                }
            }
        }

        // template<typename T> requires std::is_base_of_v<Event, T>
        static void Dispatch(const Ref<Event>& event);
        // {
        //     const auto [first, last] = s_EventMap.equal_range(typeid(*event).name());
        //     for (auto it = first; it != last; ++it)
        //     {
        //         it->second.second(std::static_pointer_cast<T>(event));
        //         if (event->Handled) return;
        //     }
        // }
    private:
        using EventMap = std::pmr::multimap<std::string, std::pair<UUID, std::function<void(const Ref<Event>&)>>>;
        static EventMap s_EventMap;
    };
}
