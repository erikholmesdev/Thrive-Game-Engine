//File		 : KeyboardEvents.h
//Programmer : 
//Date		 : Mar 23, 2026
//Description: This file will contain the KeyboardEvents

#pragma once

#include <pch.h>

#pragma once
#include "Event.h"
#include <SFML/Window/Keyboard.hpp>

namespace Thrive
{
    class KeyboardEvent : public Event
    {
    public:
        KeyboardEvent(sf::Keyboard::Key key)
            : m_KeyCode(key) {
        }

        // FIXED: no recursion + const correctness
        sf::Keyboard::Key GetKeyCode() const { return m_KeyCode; }

    protected:
        sf::Keyboard::Key m_KeyCode;
    };


    class KeyPressed : public KeyboardEvent
    {
    public:
        KeyPressed(sf::Keyboard::Key key)
            : KeyboardEvent(key) {
        }

        static EventType GetStaticType() { return EventType::KeyPressed; }

        EventType GetEventType() const override
        {
            return GetStaticType();
        }
    };

    class KeyReleased : public KeyboardEvent
    {
    public:
        KeyReleased(sf::Keyboard::Key key)
            : KeyboardEvent(key) {
        }

        static EventType GetStaticType() { return EventType::KeyReleased; }

        EventType GetEventType() const override
        {
            return GetStaticType();
        }
    };
}