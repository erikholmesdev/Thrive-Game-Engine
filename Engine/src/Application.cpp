//File		 : Application.cpp
//Programmer : 
//Date		 : Mar 20, 2026
//Description: This file contains the main loop for our Thrive game engine application.


#include <pch.h>
#include "Application.h"
#include "Window.h"
#include "EventDispatcher.h"
#include "Renderer.h"


namespace Thrive
{
	// *** TODO ** 
	// After we will work on adding stuff to the layer stack. 
	//First Layer -->Render-->ImGuiLayer-->Entiy-->
	

	
	 
	//Method		: Application::Application
	//Parameters	: 
	//Returns		: 
	//Description   : This will setup our application by setting up all the window attributes
	Application::Application()
	{
		m_Window.InitWindow(); 
		
	}

	//Currently not being used
	Application::~Application()
	{

	}

	//Method		: Application::Run()
	//Parameters	: 
	//Returns		: void
	//Description   : This method will run our Application 
	void Application::Run()
	{
		//Game loop
		while (m_Window.GetWindow().isOpen())
		{
			float deltaTime = m_Clock.restart().asSeconds(); 

			//Events 
			//Lamda so we can use the Application::DispatchEvent(Event& e) method. 
			m_Window.PollEvents([this](Event& e)
				{
					this->DispatchEvent(e); 
				});
			
			//update Layers 
			for (auto& layer : m_LayerStack)
			{
				layer->OnUpdate(deltaTime); 
			}

			Renderer::BeginFrame(); 

			for (auto& layer : m_LayerStack)
			{
				layer->OnRender(); 
			}

			Renderer::EndFrame(); 

		}
	}	
	
	//Method		: Application::PushLayer
	//Parameters	: (std::unique_ptr<Layer> layer)
	//Returns		: void
	//Description   : This method will push a new layer to our layer stack
	void Application::PushLayer(std::unique_ptr<Layer> layer)
	{
		m_LayerStack.PushLayer(std::move(layer));
	}

	//Method		: Application::Renderer()
	//Parameters	: 
	//Returns		: void
	//Description   :
	void Application::Renderer()
	{
		
	} 

	//Method		: Application::Update()
	//Parameters	:
	//Returns		: void
	//Description   :
	void Application::Update()
	{

	}

	

	
	//Method		: Application::DispatchEvent(Event& e)
	//Parameters	: (Event& e)
	//Returns		: void 
	//Description   : This methods job is to take in a current event that needs to be ran and create an 
	//					event dispatcher for that current event. 
	void Application::DispatchEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
	}

	
}