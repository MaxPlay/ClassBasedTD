#pragma once
#include "../Renderer.h"
#include <SFML/Graphics/CircleShape.hpp>

#include "Game/Players/Player.h"

namespace CBTD
{
    class PlayerRenderer : public Renderer
    {
        const Player* m_Player;
        sf::CircleShape m_Shape;

    public:
        PlayerRenderer(Player* player, int priority = 0);
        ~PlayerRenderer();
        void Draw(sf::RenderTarget& target);
    };
}