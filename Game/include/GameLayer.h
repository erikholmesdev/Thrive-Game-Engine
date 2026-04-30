//File		 : GameLayer.h 
//Programmer : 
//Date		 : 04/29/2026
//Description: This file contains the GameLayer class.i
#pragma once

#include "Log.h"
#include "Common.h"

#include "Layer.h"
#include "Renderer.h"
#include "Camera.h"
#include "KeyboardEvents.h"


#include <SFML/Graphics.hpp>


//Class		 : GameLayer
//Description: This class is derived from our engines layer class found in the Layer.h 
class GameLayer : public Thrive::Layer
{
public: 

	GameLayer()
		: m_Camera(Thrive::Common::APPLICATION_WIDTH, Thrive::Common::APPLICATION_HEIGHT)
	{
		LOG_CORE_TRACE("Game Layer was created");

		m_Shape.setRadius(50.f);
		m_Shape.setFillColor(sf::Color::Blue); 
		m_Shape.setPosition({ 500.f, 500.f });
	}

	//Method		: OnUpdate (float dt)
	//Parameters	: float dt
	//Returns		: void
	//Description   : This method will be used when the game layer updates
	void OnUpdate(float dt) override
	{
		float speed = 300.f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			m_Camera.Move(0.f, -speed * dt);
	
			
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			m_Camera.Move(0.f, speed * dt);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			m_Camera.Move(-speed * dt, 0.f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			m_Camera.Move(speed * dt, 0.f);

		float cameraPostionX = m_Camera.GetPosition().x; 
		float cameraPostionY = m_Camera.GetPosition().y;

		LOG_CORE_TRACE("Camera location x: {} | y: {}", cameraPostionX, cameraPostionY);
	}

	//Method		: OnRender ()
	//Parameters	: ()
	//Returns		: void
	//Description   : 
	void OnRender() override
	{
		// World pass
		Thrive::Renderer::SetView(m_Camera.GetView());
		Thrive::Renderer::Draw(m_Shape);

		// Reset to UI
		Thrive::Renderer::SetView(Thrive::Renderer::GetDefaultView());
	}

	//Method		: OnEvent (Thrive::Event& e)
	//Parameters	: Thrive::Event& e 
	//Returns		: void
	//Description   : This method will be our OnEvent when event happenes with in the game 
	void OnEvent(Thrive::Event& e) override
	{
		Thrive::EventDispatcher dispatcher(e);

    dispatcher.Dispatch<Thrive::KeyPressed>([this](Thrive::KeyPressed& e)
    {
        return OnKeyPressed(e);
    });

    dispatcher.Dispatch<Thrive::WindowResizeEvent>([this](Thrive::WindowResizeEvent& e)
    {
        m_Camera.SetSize((float)e.GetWidth(), (float)e.GetHeight());
        return false;
    });
	}

	bool OnKeyPressed(Thrive::KeyPressed& e)
	{
		switch (e.GetKeyCode())
		{
		case sf::Keyboard::Key::W:
			m_Camera.Move(0.f, -20.f);
			return true;

		case sf::Keyboard::Key::S:
			m_Camera.Move(0.f, 20.f);
			return true;

		case sf::Keyboard::Key::A:
			m_Camera.Move(-20.f, 0.f);
			return true;

		case sf::Keyboard::Key::D:
			m_Camera.Move(20.f, 0.f);
			return true;
		}
		return false; 
	}


private:
	Thrive::Camera m_Camera; 
	sf::CircleShape m_Shape; 
};