//File		 : Input.cpp 
//Programmer : 
//Date		 : May 06, 2026
//Description: This file contains all the Input class method definitions. 

#include <pch.h>
#include "Input.h"


namespace Thrive
{
    std::array<bool, (size_t)Key::COUNT> Input::s_KeyDown{};
    std::array<bool, (size_t)Key::COUNT> Input::s_KeyPressed{};
    std::array<bool, (size_t)Key::COUNT> Input::s_KeyReleased{};


	//Method		: void Input::Init()
	//Parameters	: ()
	//Returns		: void
	//Description   : This method will Init the input class 
    void Input::Init()
    {
        s_KeyDown.fill(false);
        s_KeyPressed.fill(false);
        s_KeyReleased.fill(false);
    }

	//Method		: void Input::EndFrame()
	//Parameters	: ()
	//Returns		: void
	//Description   : This method will update input pressed
    void Input::EndFrame()
    {
        s_KeyPressed.fill(false);
        s_KeyReleased.fill(false);
    }

	//Method		: void Input::SetKeyDown (Key key)
	//Parameters	: (Key key)
	//Returns		: void
	//Description   : This method get called when a key is pressed
    void Input::SetKeyDown(Key key)
    {
        size_t k = (size_t)key;

        if (!s_KeyDown[k])
            s_KeyPressed[k] = true;

        s_KeyDown[k] = true;
    }

	//Method		: void Input::SetKeyUp (Key key)
	//Parameters	: (Key key)
	//Returns		: void
	//Description   : This method gets called when the key is back up. 
    void Input::SetKeyUp(Key key)
    {
        size_t k = (size_t)key;

        s_KeyDown[k] = false;
        s_KeyReleased[k] = true;
    }

	//Method		: bool Input::IsKeyDown (Key key) 
	//Parameters	: (Key key)
	//Returns		: bool (true or false) 
	//Description   : This method is called when the key is down. 
    bool Input::IsKeyDown(Key key)
    {
        return s_KeyDown[(size_t)key];
    }

	//Method		: bool Input::IsKeyPressed (Key key)
	//Parameters	: (Key key)
	//Returns		: bool (true or false)
	//Description   : This method is called when a key pressed
    bool Input::IsKeyPressed(Key key)
    {
        return s_KeyPressed[(size_t)key];
    }

	//Method		: bool Input::IsKeyReleased (Key key)
	//Parameters	: (Key key)
	//Returns		: bool (true or false)
	//Description   : This method is called when the key is released 
    bool Input::IsKeyReleased(Key key)
    {
        return s_KeyReleased[(size_t)key];
    }

    // ============================
    // SFML ISOLATION LAYER
    // ============================
    Key Input::MapSFMLKey(sf::Keyboard::Key key)
    {
        switch (key)
        {
            case sf::Keyboard::Key::W: return Key::W;
            case sf::Keyboard::Key::A: return Key::A;
            case sf::Keyboard::Key::S: return Key::S;
            case sf::Keyboard::Key::D: return Key::D;
            case sf::Keyboard::Key::Space: return Key::Space;
            case sf::Keyboard::Key::Escape: return Key::Escape;
            default: return Key::W;
        }
    }
}