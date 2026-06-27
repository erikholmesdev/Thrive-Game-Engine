#pragma once

#include <entt/entt.hpp>

namespace Thrive
{
	

	//Class		 : Scene
	//Description: This class will contain the Scene object. 
	class Scene
	{
	public: 
		Scene() = default;
		~Scene() = default;

		void CreateEntity();
	

	private: 
		entt::registry m_Registry;
		
	};
}