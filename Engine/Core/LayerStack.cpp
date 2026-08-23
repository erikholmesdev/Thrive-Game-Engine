//File		 : LayerStack.cpp
//Programmer : 
//Date		 : Apr 10, 2026
//Description: This file contains all the method definitions for the layer stack object. 

#include <pch.h>
#include "LayerStack.h"

namespace Thrive
{
/**
 * Method		: void LayerStack::PushLayer (LayerPtr layer)
 * Parameters	: (LayerPtr layer)
 * Returns		: void
 * Description   : This method will add a layer to our layer stack. 
 */
	void LayerStack::PushLayer (LayerPtr layer)
	{
		m_Layers.insert(m_Layers.begin() + m_LayerInsertIndex, std::move(layer));
		m_LayerInsertIndex++; 

		m_Layers[m_LayerInsertIndex - 1] -> OnAttach(); 
	}

/**
 * Method		: void LayerStack::PushOverlay(LayerPtr overlay)
 * Parameters	: (LayerPtr overlay)
 * Returns		: void
 * Description   : This method will be used to push an overlay to our layerstack
 */
	void LayerStack::PushOverlay (LayerPtr overlay)
	{
		if (!overlay)
			return; // or assert

		m_Layers.push_back(std::move(overlay));

		if (m_Layers.back())
			m_Layers.back()->OnAttach();
	}


/**
 * Method		: void LayerStack::PopLayer()
 * Parameters	: 
 * Returns		: void
 * Description   : This method will remove the last layer added to the layer stack. 
 */
	void LayerStack::PopLayer()
	{
		if (m_LayerInsertIndex > 0)
		{
			m_Layers[m_LayerInsertIndex - 1]->OnDetach();
			m_Layers.erase(m_Layers.begin() + (m_LayerInsertIndex - 1));
			m_LayerInsertIndex--; 
		}
	}

/**
 * Method		: void LayerStack::PopOverlay()
 * Parameters	: 
 * Returns		: void
 * Description   : This method will remove an overlay 
 */
	void LayerStack::PopOverlay()
	{
		if (m_LayerInsertIndex < m_Layers.size())
		{
			m_Layers.back()->OnDetach();
			m_Layers.pop_back();
		}
	}

}