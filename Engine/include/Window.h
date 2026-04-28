//File		 : Window.h
//Programmer : 
//Date		 : Mar 21, 2022
//Description: This file contains the Window class delcarations. 

#pragma once
#include <pch.h>
#include <SFML/Graphics.hpp>
#include "Event.h"

namespace Thrive
{
	 
	struct WindowAttribute
	{
		unsigned int width = 0;
		unsigned int height = 0;
		std::string name = " ";
	};

	//Class		 : Window
	//Description: This is our window class and its job is to get all the windows attributes all setup
	class Window
	{
	public: 
		//Found in the src/Window.cpp 
		Window();
		void InitWindow();
		void SetWindowAttributes(const unsigned int width = 800, const unsigned int height = 600, const std::string& name = "Thrive Engine");

		//(Engine - Facing) 
		void PollEvents(const std::function<void(Event&)>& callback); 

		

	public: 

		//Inline 
		 //Method	: GetFrameRate()
		 //Returns  : m_FrameRate = 60
		 inline unsigned int GetFrameRate() const { return m_FrameRate; }

		 //Method   : GetCurrentWindowAttribute()
		 //Returns  : m_WindowAttribute 
		 inline WindowAttribute GetCurrentWindowAttributes() { return m_WindowAttributes; }

		 //Method     : sf::RenderWindow& GetWindow()
		 //Return     : sf::RenderWindow& 
		 //Description: This method GetWindow() will return sf::RenderWindow& 
		 inline sf::RenderWindow& GetWindow() { return m_RenderWindow;  }

		 //Rendering 
		 void Clear() { GetWindow().clear(); }
		 void Display() { GetWindow().display(); }

		 //Close Window 
		 void CloseWindow() { GetWindow().close(); }



	private: 
		std::unique_ptr<Event> TranslateEvent(const sf::Event& e); 
	
	private:

		const unsigned int m_FrameRate = 60;
		sf::RenderWindow m_RenderWindow;
		WindowAttribute m_WindowAttributes;
	};
}