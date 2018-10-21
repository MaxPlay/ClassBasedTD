#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "Camera.h"
#include "../Game/Map.h"

namespace CBTD {
    namespace Rendering {
 
        class MapRenderer
        {
        private:
            Game::Map* m_map;
            sf::RectangleShape m_shape;

        public:
            MapRenderer(Game::Map* map);
            ~MapRenderer();
            void Draw(Camera& camera, sf::RenderTarget& target);
        };

    }
}