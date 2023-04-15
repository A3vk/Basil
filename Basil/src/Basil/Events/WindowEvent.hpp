#pragma once

#include "Basil/Events/Event.hpp"

namespace Basil
{
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) : Event(EventType::WindowResize), m_Width(width), m_Height(height) {}
    
        unsigned int GetWidth() const { return m_Width; }
        unsigned int GetHeight() const { return m_Height; }
    private:
        unsigned int m_Width;
        unsigned int m_Height;
    };
    
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() : Event(EventType::WindowClose) {}
    };
    
    class WindowFocusEvent : public Event
    {
    public:
        WindowFocusEvent() : Event(EventType::WindowFocus) {}
    };
    
    class WindowLostFocusEvent : public Event
    {
    public:
        WindowLostFocusEvent() : Event(EventType::WindowLostFocus) {}
    };
}
