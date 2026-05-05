#pragma once

#include "Layer.h"

namespace Thrive
{
	class ImGuiLayer : public Layer
	{
		
	public:
		void OnAttach() override; 
		void OnDetach() override; 
		void OnUpdate(float dt) override; 
	private: 
	};
}