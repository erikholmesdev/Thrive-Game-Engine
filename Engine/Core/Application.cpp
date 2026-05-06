//File		 : Application.cpp
//Programmer : 
//Date		 : Mar 20, 2026
//Description: This file contains the main loop for our Thrive game engine application.


#include <pch.h>
#include "Application.h"
#include "Log.h"
#include "Input.h"

namespace Thrive
{
	//Method		: Application::Application
	//Parameters	: ()
	//Description   : This will setup our application by setting up all the window attributes
	Application::Application()
	{
		m_Window.InitWindow(); 
		Renderer::Init(&m_Window.GetWindow()); 

		Input::Init(); 
		
		#ifdef THRIVE_DEBUG
				Log::Init();
		#endif
	
		m_LayerStack.PushOverlay(
			std::make_unique<ImGuiLayer>(m_Window.GetWindow())
		);

	}
	
	//Currently not being used
	Application::~Application()
	{

	}

	//Method		: Application::Run()
	//Parameters	: ()
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
			
			//Update Layers 
			for (auto& layer : m_LayerStack)
			{
				layer->OnUpdate(deltaTime); 
			}

			//Renderer

			Renderer::BeginFrame(); 
			Renderer::SetView(m_Window.GetWindow().getDefaultView());
			for (auto& layer : m_LayerStack)
			{
				layer->OnRender(); 
			}

			//ImGuiLayer 

			ImGuiLayer::Begin(m_Window.GetWindow(), m_Clock); 

			// ImGuiLayer::DrawSpace(); //Currently not needed. 
			
			for (auto& layer : m_LayerStack)
				layer->OnImGuiRender();

			// This is where everything updates. 
			ImGuiLayer::End(m_Window.GetWindow());
			Renderer::EndFrame();
			Input::EndFrame(); 
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

		dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent&)
			{
				m_Window.CloseWindow();
				return true;
			});

		dispatcher.Dispatch<WindowResizeEvent>([this](WindowResizeEvent& ev)
			{
				Renderer::OnWindowResize(ev.GetWidth(), ev.GetHeight());
				return true;
			});

		// Send to layers
		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			(*it)->OnEvent(e);

			if (e.Handled)
				break;
		}
	}

	
}