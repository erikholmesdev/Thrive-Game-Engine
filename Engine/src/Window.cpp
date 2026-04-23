//File		 : Window.cpp
//Programmer : 
//Date		 : Mar 25, 2026
//Description: This file contains the method definitions for the public not inline methods in the window class. 
//				Find this class at include/Window.h. 

#include <pch.h>
#include "Window.h"
#include "WindowEvents.h"
#include "KeyboardEvents.h"
#include "MouseEvents.h"
#include "Log.h"

namespace Thrive
{
	//Constructor	: Window::Window()
	//Description	: This constructor will call the Windows SetWindowAttribute() method. 
	Window::Window()
	{
		SetWindowAttributes(); 

		#ifdef THRIVE_DEBUG
			Log::Init();
		#endif
	}

	//Method		: Window::InitWindow()
	//Parameters	: 
	//Returns		: void
	//Description   : This method is used to create our SFML window using our window attributes and creating a window with 
	//					m_RenderWindow variable. 
	void Window::InitWindow()
	{
		m_RenderWindow.create(
			sf::VideoMode({ m_WindowAttributes.width, m_WindowAttributes.height }),
			m_WindowAttributes.name,
			sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize
		);

		m_RenderWindow.setVerticalSyncEnabled(true);
		m_RenderWindow.setFramerateLimit(GetFrameRate()); //60fps 
	}

	//Method		: void Window::SetWindowAttributes(const unsigned int width, const unsigned int height, const std::string& name = "Thrive Engine")
	//Parameters	: const unsigned int width, const unsigned int height, const std::string& name = "Thrive Engine"
	//Returns		: void
	//Description   : This method will be used to set our WindowAttributes. 
	void Window::SetWindowAttributes(const unsigned int width, const unsigned int height, const std::string& name)
	{
		m_WindowAttributes.height = height;
		m_WindowAttributes.width = width;
		m_WindowAttributes.name = name;
	} 

	//Method		: void Window::PollEvents(const std::function<void(Event&)>& callback)
	//Parameters	: const std::function<void(Event&)>& callback
	//Returns		: void
	//Description   : 
	void Window::PollEvents(const std::function<void(Event&)>& callback)
	{
		while (const std::optional event = m_RenderWindow.pollEvent())
		{
			auto e = TranslateEvent(*event);

			// Only dispatch valid events
			if (e)
			{
				callback(*e);
			}
		}
	}

	//Method		: std::unique_ptr<Event> Window::TranslateEvent(const sf::Event& e)
	//Parameters	: (const sf::Event& e)
	//Returns		: nullptr
	//Description   : This method will take an sf::Event and based off what the event is that is the event going to my event system. 
	std::unique_ptr<Event> Window::TranslateEvent (const sf::Event& e)
	{
		//Window Close event
		if (e.is<sf::Event::Closed>())
		{
			GetWindow().close(); 
			return std::make_unique<WindowCloseEvent>(); 
		}

		//Resize Event 
		if (auto resized = e.getIf<sf::Event::Resized>())
		{
			unsigned int width = resized->size.x;
			unsigned int height = resized->size.y;

			// Handle view here (correct layer)
			sf::View view = GetWindow().getView();
			view.setSize({ static_cast<float>(width), static_cast<float>(height) });
			view.setCenter({ width / 2.0f, height / 2.0f });
			GetWindow().setView(view);

			return std::make_unique<WindowResizeEvent>(width, height);
		}

		//Keypressed Event
		if (auto key = e.getIf<sf::Event::KeyPressed>())
		{
			return std::make_unique<KeyPressed>(key->code); 
		}

		//KeyReleased Event
		if (auto key = e.getIf<sf::Event::KeyReleased>())
		{
			return std::make_unique<KeyReleased>(key->code);
		}

		// Mouse Move
		if (auto mouse = e.getIf<sf::Event::MouseMoved>())
		{
			return std::make_unique<MouseMoveEvent>(
				(float) mouse->position.x,
				(float) mouse->position.y
			);
		}

		// Mouse Button Pressed
		if (auto mouse = e.getIf<sf::Event::MouseButtonPressed>())
		{
			return std::make_unique<MouseButtonPressedEvent>(
				mouse->button,
				(float)mouse->position.x,
				(float)mouse->position.y
			);
		}

		// Mouse Button Released
		if (auto mouse = e.getIf<sf::Event::MouseButtonReleased>())
		{
			return std::make_unique<MouseButtonReleasedEvent>(
				mouse->button,
				(float)mouse->position.x,
				(float)mouse->position.y
			);
		}
		
		//Unkown Event 
		return nullptr; 
	}
}