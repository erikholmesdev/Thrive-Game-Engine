#pragma once
#include <SFML/Graphics.hpp>

namespace Thrive
{
	class Camera
	{

	public:

		Camera(float width, float height)
		{
			m_View.setSize(sf::Vector2f(width, height));
			m_View.setCenter(sf::Vector2f(width / 2.0f, height / 2.0f)); 
		}

		void SetPostion(float x, float y)
		{
			m_View.setCenter(sf::Vector2f(x, y));
		}

		const sf::View& GetView() const { return m_View; }

	protected: 
		sf::View m_View; 
	};
}