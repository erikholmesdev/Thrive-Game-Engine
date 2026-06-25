#include <pch.h>
#include "Scene.h"
#include "Entity.h"

namespace Thrive
{
	Entity Scene::CreateEntity()
	{
		entt::entity entity = m_Registry.create(); 
		
		return Entity(entity, this);
	}
}