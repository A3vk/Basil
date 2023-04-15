#pragma once

namespace Basil
{
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };
    
    class Event
    {
    public:
        Event(const EventType type) : m_EventType(type) {}
        virtual ~Event() = default;

        EventType GetEventType() const { return m_EventType; }
        
        bool Handled = false;
    protected:
        EventType m_EventType;
    };
}
