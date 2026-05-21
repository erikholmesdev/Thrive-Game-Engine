#include <pch.h>
#include "Scene.h"
#include "Entity.h"

namespace Thrive
{
	Entity Scene::CreateEntity(const std::string& name)
	{
		//Creating a new entity
		entt::entity entity = m_Registry.create(); 

		// maybe use later (TagComponent) 
		//  m_Registry.emplace <TagComponent>(entity, name); 

		return Entity(entity, this); 
	}

	void Scene::OnUpdate(float deltaTime)
	{
		//ECS system will go here later
		//Example
		//auto view = m_Registry.view<TransformComponent> (); 
		//for (auto e : view) { ... } 
	}
}