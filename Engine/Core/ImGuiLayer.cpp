//File		 : ImGuiLayer.cpp
//Programmer : 
//Date		 : May 5,2026
//Description: This file contains all the method defintions used by the ImGuiLayer class found in the ImGuiLayer.h file. 

#include <pch.h>

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include "ImGuiLayer.h"


namespace Thrive
{
	
	//Method		: void ImGuiLayer::OnAttach()
	//Parameters	: ()
	//Returns		: void
	//Description   : This method will setup the ImGuiLayer
	void ImGuiLayer::OnAttach()
	{
	
		ImGui::CreateContext(); 
		ImGui::StyleColorsDark(); 

		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

		ImGui::SFML::Init(m_Window); 
	}

	//Method		: void ImGuiLayer::OnDetach()
	//Parameters	: ()
	//Returns		: void
	//Description   : This method will destroy the ImGui elements
	void ImGuiLayer::OnDetach()
	{
		ImGui::SFML::Shutdown();
		ImGui::DestroyContext();
	}

	//Method		: void ImGuiLayer::Begin(sf::RenderWindow& window, sf::Clock deltaClock)
	//Parameters	: sf::RenderWindow& window, sf::Clock deltaClock
	//Returns		: void
	//Description   : This method is static. It take the current window and time, so it can update ImGui
	void ImGuiLayer::Begin(sf::RenderWindow& window, sf::Clock deltaClock)
	{
		ImGui::SFML::Update(window, deltaClock.restart()); 
	}

	//Method		: void ImGuiLayer::End (sf::RenderWindow& window)
	//Parameters	: sf::RenderWindow& window
	//Returns		: void
	//Description   : This method is static. It takes in the current window, so it can renderer the ImGUI UI
	void ImGuiLayer::End(sf::RenderWindow& window)
	{
		ImGui::SFML::Render(window);
	}

	//Method		: void ImGuiLayer::OnUpdate(float dt)
	//Parameters	: float dt
	//Returns		: void
	//Description   : This method currently does nothing 
	void ImGuiLayer::OnUpdate(float dt)
	{
		// Intentionally empty OR debug-only logic
	}

	/// <summary>
	/// For Testing at the moment 
	/// </summary>
	void ImGuiLayer::OnImGuiRender()
	{
		// Example UI
		ImGui::Begin("Debug");
		ImGui:
		ImGui::End();
	}


	/// <summary>
	/// For Testing 
	/// </summary>
	void ImGuiLayer::DrawSpace()
	{
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDocking;

		ImGuiViewport* viewport = ImGui::GetMainViewport();

		ImGui::SetNextWindowPos(viewport->Pos);
		ImGui::SetNextWindowSize(viewport->Size);
		ImGui::SetNextWindowViewport(viewport->ID);

		ImGui::Begin("DockSpaceWindow", nullptr, window_flags);

		ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
		ImGui::DockSpace(dockspace_id);
		ImGui::End();
	}


	
}