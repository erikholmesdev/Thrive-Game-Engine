#pragma once
#include <SFML/Graphics.hpp>

namespace Thrive {

	class Renderer {
		
	public: 
		static void Init(sf::RenderWindow* window);
		
		static void BeginFrame();
		static void EndFrame(); 

		static void Draw(const sf::Drawable& drawable);

	private:
		static sf::RenderWindow* s_Window; 
	};
}