#pragma once

#include <entt/entt.hpp>

namespace Thrive
{
	//So Scene knows there is a Entity class that exists
	class Entity;
	

	/*
	* @brief Used to create a Scene for the game being created
	*  
	*  This class will handle our 	
	*/
	class Scene
	{
	public: 
		Scene() = default;
		~Scene() = default;

		Entity CreateEntity();


		//Method		: const entt::registry& GetRegistry() const 
		//Parameters	: 
		//Returns		: return m_Registry
		//Description   : This method will get the current registry 
		const entt::registry& GetRegistry() const
		{
			return m_Registry;
		}
	

	private: 
		entt::registry m_Registry;

		friend class Entity;

		/*
		* 
		*  Scene and Entity are friends with each other and will know about each other. 
		* 
		         ===========================>
			Scene                             Entity
			    <============================
			
		*/
		
	};
}