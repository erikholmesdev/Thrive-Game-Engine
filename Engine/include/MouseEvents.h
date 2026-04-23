//File		 : MouseEvent.h
//Programmer : 
//Date		 : Mar 23, 2026
//Description: This file contains all the mouse events. 


#pragma once
#include <pch.h>
#include "Event.h"

//TODO: Make the sf::Mouse:button variable from MouseButtonPressed and the MouseButtonReleased and MouseEvent variable ... Maybe ... 

namespace Thrive
{
    class MouseEvent : public Event
    {
    public:
        MouseEvent(float x, float y)
            : m_MouseX(x), m_MouseY(y) {
        }

        float GetX() const { return m_MouseX; }
        float GetY() const { return m_MouseY; }

    protected:
        float m_MouseX;
        float m_MouseY;
    };

    class MouseMoveEvent : public MouseEvent
    {
    public:
        MouseMoveEvent(float x, float y)
            : MouseEvent(x, y) {
        }

        static EventType GetStaticType() { return EventType::MouseMove; }

        EventType GetEventType() const override
        {
            return GetStaticType();
        }
    };

    class MouseButtonPressedEvent : public Event
    {
    public:
        MouseButtonPressedEvent(sf::Mouse::Button button, float x, float y)
            : m_Button(button), m_MouseX(x), m_MouseY(y) {
        }

        sf::Mouse::Button GetMouseButton() const { return m_Button; }

        float GetX() const { return m_MouseX; }
        float GetY() const { return m_MouseY; }

        static EventType GetStaticType() { return EventType::MouseButtonPressed; }

        EventType GetEventType() const override
        {
            return GetStaticType();
        }

    private:
        sf::Mouse::Button m_Button;
        float m_MouseX, m_MouseY;
    };

    class MouseButtonReleasedEvent : public Event
    {
    public:
        MouseButtonReleasedEvent(sf::Mouse::Button button, float x, float y)
            : m_Button(button), m_MouseX(x), m_MouseY(y) {
        }

        sf::Mouse::Button GetMouseButton() const { return m_Button; }

        float GetX() const { return m_MouseX; }
        float GetY() const { return m_MouseY; }

        static EventType GetStaticType() { return EventType::MouseButtonReleased; }

        EventType GetEventType() const override
        {
            return GetStaticType();
        }

    private:
        sf::Mouse::Button m_Button;
        float m_MouseX, m_MouseY;
    };
}