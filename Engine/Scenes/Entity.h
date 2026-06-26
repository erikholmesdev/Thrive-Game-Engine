#pragma once

#include <entt/entt.hpp>

namespace Thrive
{
	class Scene; // Forward delcaration. 

	//Class		 : Entity 
	//Description: This is the Entity class. 
	class Entity
	{
	public:
		Entity() = default; 

		//Constructor : Entity (entt::entity handle, Scene * scene)  
		//Description : This class will take in an Entity handle and the current scene
		Entity(entt::entity handle, Scene* scene)
			: m_EntityHandle(handle),
			m_Scene(scene) 
		{
		}

		explicit operator bool() const;

	private: 
		entt::entity m_EntityHandle{ entt::null };
		Scene* m_Scene = nullptr;
	};
}