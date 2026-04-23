//File		 : Application.h
//Programmer : 
//Date		 : Mar 19, 2026
//Description: This file contains our application class definition. 

#pragma once
#include <pch.h>
#include "Window.h"
#include "LayerStack.h"
#include "Event.h"



namespace Thrive
{

	//Class		 : Application
	//Description: This is our application class
	class Application
	{
	public:
		
		Application();
		virtual ~Application(); 
		void Run(); 
		void Update(); 
		void Renderer(); 
		void PushLayer(std::unique_ptr<Layer> layer); 
		void DispatchEvent(Event& e);
	
	//Class Variables 
	private:
		//delta time
		sf::Clock m_Clock;
		Window m_Window;
		LayerStack m_LayerStack; 
	};
}