#include <pch.h>

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include "ImGuiLayer.h"


namespace Thrive
{
	
	void ImGuiLayer::OnAttach()
	{
		std::cout << " Game Layer attached\n"; 
		ImGui::CreateContext(); 
		ImGui::StyleColorsDark(); 

		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

		ImGui::SFML::Init(m_Window); 
	}

	void ImGuiLayer::OnDetach()
	{
		ImGui::SFML::Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::Begin(sf::RenderWindow& window, sf::Clock deltaClock)
	{
		ImGui::SFML::Update(window, deltaClock.restart()); 
	}

	void ImGuiLayer::End(sf::RenderWindow& window)
	{
		ImGui::SFML::Render(window);
	}

	void ImGuiLayer::OnUpdate(float dt)
	{
		// Intentionally empty OR debug-only logic
	}

	
	void ImGuiLayer::OnImGuiRender()
	{
		// Example UI
		ImGui::Begin("Debug");
		ImGui::Text("Thrive Engine");
		ImGui::End();
	}

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