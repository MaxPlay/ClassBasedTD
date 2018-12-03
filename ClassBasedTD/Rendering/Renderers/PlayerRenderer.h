#pragma once
#include "../Renderer.h"
#include <SFML/Graphics/CircleShape.hpp>

#include "Game/Players/Player.h"

namespace CBTD {
    namespace Rendering {
        namespace Renderers {
            class PlayerRenderer : public Renderer
            {
                const Game::Players::Player* m_Player;
                sf::CircleShape m_Shape;

            public:
                PlayerRenderer(Game::Players::Player* player, int priority = 0);
                ~PlayerRenderer();
                void Draw(sf::RenderTarget& target);
            };
        }
    }
}