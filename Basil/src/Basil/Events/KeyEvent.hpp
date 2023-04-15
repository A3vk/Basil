#pragma once

#include "Basil/Events/Event.hpp"
#include "Basil/Core/KeyCodes.hpp"

namespace Basil
{
    class KeyEvent : public Event
    {
    public:
        KeyEvent(const EventType type, const KeyCode keyCode) : Event(type), m_KeyCode(keyCode) {}
    
        KeyCode GetKeyCode() const { return m_KeyCode; }
    protected:
        KeyCode m_KeyCode;
    };
    
    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(const KeyCode keyCode, bool isRepeat = false) : KeyEvent(EventType::KeyPressed, keyCode), m_IsRepeat(isRepeat) {}
    
        bool IsRepeat() const { return m_IsRepeat; }    
    private:
        bool m_IsRepeat;
    };
    
    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(const KeyCode keyCode) : KeyEvent(EventType::KeyReleased, keyCode) {}
    };
    
    class KeyTypedEvent : public KeyEvent
    {
    public:
        KeyTypedEvent(const KeyCode keyCode) : KeyEvent(EventType::KeyTyped, keyCode) {}
    };
}