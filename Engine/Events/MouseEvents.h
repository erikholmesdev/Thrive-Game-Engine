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
    //Class		 : MouseEvent
	//Description: This will be our base Mouse Event class. This class has two methods that will get the x and y location of the mouse. 
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
        sf::Mouse::Button m_Button;
    };

    //Class		 : MouseMoveEvent 
	//Description: This class is a devired from the MouseEvent class. 
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

    //Class		 : MouseButtonEvent 
	//Description: This class will be a base class to all the mouse button actiosn. 
    class MouseButtonEvent : public MouseEvent
    {
    public:
        MouseButtonEvent(sf::Mouse::Button button, float x, float y)
            : MouseEvent(x, y), m_Button(button) {
        }

        sf::Mouse::Button GetMouseButton() const {
            return m_Button;
        }

    protected:
        sf::Mouse::Button m_Button;
    };



    //Class		 : MouseBUttonPressedEvent
	//Description: This class will be a dirived class from the MouseButtonEvent. 
    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(sf::Mouse::Button button, float x, float y)
            : MouseButtonEvent(button, x, y) {
        }

        static EventType GetStaticType() { return EventType::MouseButtonPressed; }

        EventType GetEventType() const override
        {
            return GetStaticType();
        }

    private:
       
       
    };

    //Class		 : MouseButtonReleasedEvent
	//Description: This class is a devired class from MouseButtonEvent. 
    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(sf::Mouse::Button button, float x, float y)
            : MouseButtonEvent(button, x, y) {
        }
       
        static EventType GetStaticType() { return EventType::MouseButtonReleased; }

        EventType GetEventType() const override
        {
            return GetStaticType();
        }

 
    };
}