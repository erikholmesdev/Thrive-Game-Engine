#pragma once
#include "Entity.h"
#include <string.h> 

namespace Thrive
{

	class Entity; 

	class Scene
	{
	public:
		Entity CreateEntity(const std::string& name = ""); 
		void OnUpdate(float deltaTime); 

	private: 
		entt::registry m_Registry; 

		friend class Entity; 
	};
}