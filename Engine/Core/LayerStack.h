//File		 : LayerStack.h
//Programmer : 
//Date		 : Mar 21, 2026
//Description: This file will contain the layer class declaration. 

#pragma once
#include "Layer.h"

namespace Thrive
{
/**
 * Class		 : LayerStack
 * Description: This class will be a vector of layer unique pointers to a 
 */
	class LayerStack {

	public:

		
		using LayerPtr = std::unique_ptr<Layer>;

		LayerStack() = default; 
		~LayerStack() = default; 

/**
 * Add Layer
 */
		void PushLayer (LayerPtr layer); 
		void PushOverlay (LayerPtr overlay);

/**
 * Remove Layer
 */
		void PopLayer(); 
		void PopOverlay();

/**
 * Iterators
 */
		auto begin() { return m_Layers.begin(); }
		auto end() { return m_Layers.end(); }

/**
 * Reverse iteration (Import for Events) 
 */
		auto rbegin() { return m_Layers.rbegin(); }
		auto rend() { return m_Layers.rend(); }


		size_t Size() const { return m_Layers.size(); }

	private: 
		std::vector<LayerPtr> m_Layers; 
		unsigned int m_LayerInsertIndex = 0; 

	};
}