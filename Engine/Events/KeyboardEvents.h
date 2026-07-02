//File		 : KeyboardEvents.h
//Programmer : 
//Date		 : Mar 23, 2026
//Description: This file will contain the KeyboardEvents

#pragma once
#include <pch.h>
#include "Event.h"
#include <SFML/Window/Keyboard.hpp>

namespace Thrive
{
    //Class		 : KeyboardEvent
	//Description: This is the Event class. This will be the base class for all the keyboard events. 

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

    //Class		 : KeyPressed
	//Description: This is the KeyPressed class. It is a derived from the keyboard event class. 
    class KeyPressed : public KeyboardEvent
    {
    public:
        KeyPressed(sf::Keyboard::Key key)
            : KeyboardEvent(key) {
        }

        static EventType GetStaticType() { return EventType::KeyPressed; } // return 2

        EventType GetEventType() const override
        {
            return GetStaticType();
        }
    };

    //Class		 :  KeyReleased
	//Description: This is the KeyReleased class. It is a derived from the keyboard event class. 
    class KeyReleased : public KeyboardEvent
    {
    public:
        KeyReleased(sf::Keyboard::Key key)
            : KeyboardEvent(key) {
        }

        static EventType GetStaticType() { return EventType::KeyReleased; } //return 3 

        EventType GetEventType() const override
        {
            return GetStaticType();
        }
    };
}