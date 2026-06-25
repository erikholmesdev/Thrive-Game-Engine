#pragma once

#include <entt/entt.hpp>

namespace Thrive
{
	class Entity; // Forward declaration for entity 

	//Class		 : Scene
	//Description: This class will contain the Scene object. 
	class Scene
	{
	public: 
		Scene() = default;
		~Scene() = default;

		Entity CreateEntity();
		void DestoryEntity(Entity entity); 

	private: 
		entt::registry m_Registry;
		friend class Entity; 
	};
}