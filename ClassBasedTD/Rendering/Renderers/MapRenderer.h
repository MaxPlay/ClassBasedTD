#pragma once
#include "../Renderer.h"
#include <SFML/Graphics/RectangleShape.hpp>

#include "Game/Level/Map.h"

namespace CBTD {
    namespace Rendering {
        namespace Renderers {
            class MapRenderer : public Renderer
            {
            private:
                unsigned int m_TileSize;
                const Game::Level::Map* m_map;
                sf::RectangleShape m_shape;

            public:
                MapRenderer(Game::Level::Map* map, int priority = 0);
                ~MapRenderer();
                void Draw(sf::RenderTarget& target);
            };
        }
    }
}