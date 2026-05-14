#pragma once
#include "Entity.h"

namespace Thrive
{
	class Registry
	{
	public: 
		Entity CreateEntity(); 

		template <typename T>
		void AddComponent(Entity e, T component);

		template <typename T> 
		T& GetComponent(Entity e); 

	private:
		EntityID m_NextID = 0; 
	};
}