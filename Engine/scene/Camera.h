//File		 : Camera.h 
//Programmer : 
//Date		 : 04/09/2026
//Description: This file contains the Camera class.

#pragma once
#include <SFML/Graphics.hpp>

namespace Thrive
{
	//Class		 : Camera
	//Description: This is our basic camera class 
	class Camera
	{

	public:

		//Constructor : Camera
		//Parameters  :	(float width, float height) 
		//Descritpion : This constructor will set of our camera and in the middle of the screen
		Camera(float width, float height)
		{
			m_View.setSize(sf::Vector2f(width, height));
			m_View.setCenter(sf::Vector2f(width / 2.0f, height / 2.0f)); 
		}

		//Method		: SetPosition
		//Parameters	: (float x, float y)
		//Returns		: void
		//Description   : This method will set the position of the camera to the middle of the screen 
		void SetPostion (float x, float y)
		{
			m_View.setCenter(sf::Vector2f(x, y));
		}

	    //Method		: GetView()
		//Parameters	: ()
		//Returns		: const sf::View& 
		//Description   : This method will get our view 
		const sf::View& GetView() const { return m_View; }

	protected: 
		sf::View m_View; 
	};
}