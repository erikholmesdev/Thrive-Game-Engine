#include <pch.h>
#include "Input.h"


namespace Thrive
{
    std::array<bool, (size_t)Key::COUNT> Input::s_KeyDown{};
    std::array<bool, (size_t)Key::COUNT> Input::s_KeyPressed{};
    std::array<bool, (size_t)Key::COUNT> Input::s_KeyReleased{};

    void Input::Init()
    {
        s_KeyDown.fill(false);
        s_KeyPressed.fill(false);
        s_KeyReleased.fill(false);
    }

    void Input::EndFrame()
    {
        s_KeyPressed.fill(false);
        s_KeyReleased.fill(false);
    }

    void Input::SetKeyDown(Key key)
    {
        size_t k = (size_t)key;

        if (!s_KeyDown[k])
            s_KeyPressed[k] = true;

        s_KeyDown[k] = true;
    }

    void Input::SetKeyUp(Key key)
    {
        size_t k = (size_t)key;

        s_KeyDown[k] = false;
        s_KeyReleased[k] = true;
    }

    bool Input::IsKeyDown(Key key)
    {
        return s_KeyDown[(size_t)key];
    }

    bool Input::IsKeyPressed(Key key)
    {
        return s_KeyPressed[(size_t)key];
    }

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