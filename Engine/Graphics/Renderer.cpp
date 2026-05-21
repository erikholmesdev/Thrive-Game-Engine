//File		 : Renderer.cpp
//Programmer : 
//Date		 : 04/28/2026
//Description: This file contains all the method 

#include <pch.h>
#include "Renderer.h"
#include "ThriveAssert.h"

namespace Thrive
{
	//Static 
	sf::RenderWindow* Renderer::s_Window = nullptr; 
	sf::View Renderer::s_DefaultView;

	//Method		: Renderer::Init
	//Parameters	: (sf::RendererWindow* window)
	//Returns		: void
	//Description   : This methods main purpose is to set the s_Window to our sfml window 
	void Renderer::Init (sf::RenderWindow* window)
	{
		s_Window = window; 

		s_DefaultView = window->getDefaultView();
	}

	//Method		: Renderer::BeginFrame
	//Parameters	: ()
	//Returns		: void
	//Description   : This methods purpose is to clear the screen for our first frame 
	void Renderer::BeginFrame ()
	{
		THRIVE_ASSERT(s_Window != nullptr,"Renderer not initialized!"); 
		s_Window->clear(); 
	}

	//Method		: Renderer::EndFrame()
	//Parameters	: ()
	//Returns		: void
	//Description   : This methods purpose is to display on the screen what has been renderer
	void Renderer::EndFrame ()
	{
		s_Window->display();
	}

	//Method		: Renderer::SetView
	//Parameters	: (const sf::View& view) 
	//Returns		: void
	//Description   : This method will change the view for the current 2D camera
	void Renderer::SetView (const sf::View& view)
	{
		s_Window->setView(view);
	}


	const sf::View& Renderer::GetDefaultView()
	{
		return s_DefaultView;
	}

	//Method		: Renderer::OnWindowResize
	//Parameters	: (uint32_t width, uint32_t height)
	//Returns		:  void
	//Description   : This method will change the view of our window when it is resized
	void Renderer::OnWindowResize (uint32_t width, uint32_t height)
	{
		sf::View view = s_Window->getView();

		view.setSize({ (float)width, (float)height });
		view.setCenter({ width / 2.0f, height / 2.0f });

		s_Window->setView(view);
	}

	//Method		: Renderer::Draw
	//Parameters	: (const sf::Drawable& drawable)
	//Returns		: void
	//Description   : This method will draw a drawable object to the screen 
	void Renderer::Draw (const sf::Drawable& drawable)
	{
		s_Window->draw(drawable); 
	}
}