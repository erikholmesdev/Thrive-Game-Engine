#include "Renderer.h"

namespace Thrive
{
	sf::RenderWindow* Renderer::s_Window = nullptr; 

	void Renderer::Init(sf::RenderWindow* window)
	{
		s_Window = window; 
	}


	void Renderer::BeginFrame()
	{
		s_Window->clear(); 
	}

	void Renderer::EndFrame()
	{
		s_Window->display();
	}

	void Renderer::Draw(const sf::Drawable& drawable)
	{
		s_Window->draw(drawable); 
	}
}