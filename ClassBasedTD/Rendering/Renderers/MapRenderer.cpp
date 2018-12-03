#include "MapRenderer.h"
#include "Core/Globals.h"

using namespace CBTD;
using namespace Rendering;
using namespace Renderers;

MapRenderer::MapRenderer(Game::Level::Map * map, int priority) : m_map(map), m_TileSize(Core::Globals::TILE_SIZE), Renderer(priority)
{
    m_shape = sf::RectangleShape(sf::Vector2f((float)m_TileSize, (float)m_TileSize));
}

MapRenderer::~MapRenderer()
{
}

void MapRenderer::Draw(sf::RenderTarget & target)
{
    for (unsigned int y = 0; y < m_TileSize; y++)
    {
        for (unsigned int x = 0; x < m_TileSize; x++)
        {
            m_shape.setFillColor(m_map->GetTile(x, y).TextureID == 0 ? sf::Color::Green : sf::Color::Red);
            m_shape.setPosition((float)(x * m_TileSize), (float)(y *m_TileSize));
            target.draw(m_shape);
        }
    }
}
