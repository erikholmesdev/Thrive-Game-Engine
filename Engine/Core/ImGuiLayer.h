#pragma once
#include "Layer.h"



namespace Thrive
{
	class ImGuiLayer : public Layer
	{
		
	public:

		ImGuiLayer(sf::RenderWindow& window) : m_Window(window) {}

		void OnAttach() override; 
		void OnDetach() override; 
		void OnUpdate(float dt) override; 
		void OnImGuiRender() override;

		static void Begin(sf::RenderWindow& window, sf::Clock deltaClock);
		static void End(sf::RenderWindow& window);

		static void DrawSpace(); 

	private: 
		sf::RenderWindow& m_Window; 
		sf::Clock m_DeltaClock; 
	};

	
}