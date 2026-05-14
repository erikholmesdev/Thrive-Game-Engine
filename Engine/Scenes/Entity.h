//File		 : Entity.h
//Programmer : 
//Date		 : May 13, 2026
//Description: This

#pragma once
#include <pch.h>


namespace Thrive
{
	using EntityID = uint32_t; 

	//Class		 : Entity 
	//Description: This will be a basse class for an entity. 
	class Entity
	{
	public:
		Entity(EntityID id) : m_ID(id)
		{
		}

		EntityID GetID() const {
			return m_ID;
		}

	private:
		EntityID m_ID; 
	};
}


