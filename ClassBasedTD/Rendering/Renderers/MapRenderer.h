#pragma once
#include "../Renderer.h"
#include <SFML/Graphics/RectangleShape.hpp>

#include "Game/Level/Map.h"

namespace CBTD
{
    class MapRenderer : public Renderer
    {
    private:
        unsigned int m_TileSize;
        const Map* m_map;
        sf::RectangleShape m_shape;

    public:
        MapRenderer(const Map& map, int priority = 0);
        ~MapRenderer();
        void Draw(sf::RenderTarget& target);
    };
}