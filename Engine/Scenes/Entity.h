#pragma once
#include <entt.hpp>
#include "Scene.h"

namespace Thrive
{
	class Entity
	{
	public:
		Entity(entt::entity handle, Scene* scene); 

		template <typename T, typename... Args>
		T& AddComponent(Args&&... args); 
		
		template <typename T>
		T& GetComponent(); 

		template <typename T>
		bool HasComponent(); 

	private: 
		entt::entity m_EntityHandle{ entt::null };
		Scene* m_Scene = nullptr; 
	};
}

