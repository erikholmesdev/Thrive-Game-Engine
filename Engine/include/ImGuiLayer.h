#pragma once

#include "Layer.h"

namespace Thrive
{
	class ImGuiLayer : public Layer
	{
	public:
		void OnAttach() override;
		void OnDetach() override;

		void Begin();
		void End();

		void OnEvent(Event& e) override;

	};
}

