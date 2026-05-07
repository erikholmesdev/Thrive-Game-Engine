//File		 : ImGuiLayer.h
//Programmer : 
//Date		 : May 05, 2026
//Description: This file contains the ImGuiLayer class declaration.

#pragma once
#include "Layer.h"

namespace Thrive
{
	//Class		 : ImGuiLayer
	//Description: This class is a devired class from Layer. Layer can be found in the Layer.h file. 
	class ImGuiLayer : public Layer
	{
		
	public:
		// This is used to set the m_Window to the current window. 
		ImGuiLayer (sf::RenderWindow& window) : m_Window(window) {}

		void OnAttach () override; 
		void OnDetach () override; 
		void OnUpdate (float dt) override; 
		void OnImGuiRender () override;

		// Static methods
	public:
		static void Begin (sf::RenderWindow& window, sf::Clock deltaClock);
		static void End (sf::RenderWindow& window);

		static void DrawSpace (); 

	private: 
		sf::RenderWindow& m_Window; 
	};

	
}