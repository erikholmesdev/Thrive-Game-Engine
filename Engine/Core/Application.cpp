//File		 : Application.cpp
//Programmer : 
//Date		 : Mar 20, 2026
//Description: This file contains the main loop for our Thrive game engine application.

#include <pch.h>
#include "Application.h"
#include "Log.h"
#include "Input.h"
#include "ThriveTime.h"


namespace Thrive
{
	//Method		: Application::Application
	//Parameters	: ()
	//Description   : This will setup our application by getting the window ready, and the renderer ready. If in debug mode then console logging is turned on. 
	Application::Application ()
	{
		m_Window.InitWindow(); 

		Renderer::Init(&m_Window.GetWindow()); 
		
		Input::Init(); 

		m_LayerStack.PushOverlay(
			std::make_unique<ImGuiLayer>(m_Window.GetWindow())
		);

		// ===============
		// + Debug Mode  +
		// ===============
		// - Turns on logging
		// - Init the DearImGui layer. 
		#ifdef THRIVE_DEBUG
				Log::Init();	
		#endif
	}
	
	//Currently not being used
	Application::~Application ()
	{

	}

	//Method		: Application::Run()
	//Parameters	: ()
	//Returns		: void
	//Description   : This method will run our Application 
	void Application::Run ()
	{
		//Game loop
		while (m_Window.GetWindow().isOpen())
		{
			Time::Update();

			const float deltaTime = Time::GetDeltaTime();

			ProcessEvents();
			Update(deltaTime);
			Render();

			Input::EndFrame();
		}
	}	

	//Method		: Application::ProcessEvents()
	//Parameters	:
	//Returns		: void
	//Description   : This method will call the dispatch events method. 
	void Application::ProcessEvents()
	{
		m_Window.PollEvents([this](Event& e)
			{
				this->DispatchEvent(e);
			});
	}

	//Method		: Application::Update(float deltaTime)
	//Parameters	: float deltaTime
	//Returns		: void
	//Description   : This method will update our layer, 
	void Application::Update(float deltaTime)
	{
		for (auto& layer : m_LayerStack)
		{
			layer->OnUpdate(deltaTime);
		}
	}

	//Method		: Application::Render()
	//Parameters	:
	//Returns		: void
	//Description   : This method will render our engine objects. 
	void Application::Render()
	{
		Renderer::BeginFrame();

		Renderer::SetView(
			m_Window.GetWindow().getDefaultView()
		);

		for (auto& layer : m_LayerStack)
		{
			layer->OnRender();
		}

		m_ImGuiLayer->Begin(
			m_Window.GetWindow(),
			m_Clock
		);

		for (auto& layer : m_LayerStack)
		{
			layer->OnImGuiRender();
		}

		m_ImGuiLayer->End(
			m_Window.GetWindow()
		);

		Renderer::EndFrame();
	}
	
	//Method		: Application::PushLayer
	//Parameters	: (std::unique_ptr<Layer> layer)
	//Returns		: void
	//Description   : This method will push a new layer from our game to our layer stack
	void Application::PushLayer(std::unique_ptr <Layer> layer)
	{
		m_LayerStack.PushLayer(std::move(layer));
	}




	//Method		: Application::DispatchEvent(Event& e)
	//Parameters	: (Event& e)
	//Returns		: void 
	//Description   : This methods job is to take in a current event that needs to be ran and create an 
	//					event dispatcher for that current event. 
	void Application::DispatchEvent (Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch <WindowCloseEvent> ([this](WindowCloseEvent&)
		{
			m_Window.CloseWindow();
			return true;
		});
		

		dispatcher.Dispatch <WindowResizeEvent> ([this](WindowResizeEvent& ev)
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