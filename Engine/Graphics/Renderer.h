//File		 : Renderer.h
//Programmer : 
//Date		 : 04/28/2026
//Description: This file contains all the Renderer object. 

#pragma once
#include <SFML/Graphics.hpp>

namespace Thrive 
{
	//Class		 : Renderer 
	//Description: This class will contain our renderer. All method of this class are static, 
	class Renderer {
		
	public: 
		static void Init(sf::RenderWindow* window);
		
		static void BeginFrame();
		static void EndFrame(); 

		static void Draw(const sf::Drawable& drawable);

		static void SetView(const sf::View& view); 

		static void OnWindowResize(uint32_t width, uint32_t height); 

		static const sf::View& GetDefaultView();

	private:
		
		//Set to nullptr at the top of the Renderer.cpp 
		static sf::RenderWindow* s_Window; 
		static sf::View s_DefaultView; 
	};
}