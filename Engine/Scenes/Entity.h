#pragma once

#include <entt/entt.hpp>

namespace Thrive
{
	class Scene; 

	class Entity
	{
	public:
		Entity() = default; 
		Entity(entt::entity handle, Scene* scene)
			: m_EntityHandle(handle),
			m_Scene(scene) 
		{
		}
			  

		operator bool() const;

	private: 
		entt::entity m_EntityHandle{ entt::null };
		Scene* m_Scene = nullptr;
	};
}