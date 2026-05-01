#pragma once

#include "Layer.h"

namespace Thrive
{
	//Class	     : ImGuiLayer
	//Description: The ImGuiLayer class is a derived from the layer class. It overides 
	class ImGuiLayer : public Layer
	{
	public:

		ImGuiLayer() = default; 
		~ImGuiLayer() = default;

		void OnAttach() override;
		void OnDetach() override;
		void OnEvent(Event& e) override;

		void Begin();
		void End();
	};
}

