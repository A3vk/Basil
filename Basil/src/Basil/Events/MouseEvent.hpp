#pragma once

#include "Basil/Events/Event.hpp"
#include "Basil/Core/MouseCodes.hpp"

namespace Basil
{
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(const float x, const float y) : Event(EventType::MouseMoved), m_MouseX(x), m_MouseY(y) {}
    
        float GetX() const { return m_MouseX; }
        float GetY() const { return m_MouseY; }
    private:
        float m_MouseX;
        float m_MouseY;
    };
    
    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(const float offsetX, const float offsetY) : Event(EventType::MouseScrolled), m_OffsetX(offsetX), m_OffsetY(offsetY) {}
    
        float GetOffsetX() const { return m_OffsetX; }
        float GetOffsetY() const { return m_OffsetY; }
    private:
        float m_OffsetX;
        float m_OffsetY;
    };
    
    class MouseButtonEvent : public Event
    {
    public:
        MouseButtonEvent(const EventType type, const MouseCode button) : Event(type), m_Button(button) {}
    
        MouseCode GetButton() const { return m_Button; }
    protected:
        MouseCode m_Button;
    };
    
    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(const MouseCode button) : MouseButtonEvent(EventType::MouseButtonPressed, button) {}
    };
    
    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(const MouseCode button) : MouseButtonEvent(EventType::MouseButtonReleased, button) {}
    };
}
