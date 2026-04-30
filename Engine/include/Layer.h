//File		 : Layer.h
//Programmer : 
//Date		 : Mar 21, 2026
//Description: This file will contain the Layer class. This will inherited by every layer add to the layerStack vector

#pragma once
#include <pch.h>
#include "Event.h"

namespace Thrive
{
	//Class		 : Layer 
	//Description: This will be our base layer class. 
	class Layer
	{
	public:
		virtual ~Layer() = default;
		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate(float dt) {};
		virtual void OnEvent(Event& e) {}
		virtual void OnRender(){}

		const std::string& GetName() const {
			return m_DebugName;
		};

	protected:
		std::string m_DebugName;
	};


	
}