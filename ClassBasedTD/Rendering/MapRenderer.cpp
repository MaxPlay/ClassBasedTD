#include "MapRenderer.h"

using namespace CBTD;
using namespace Rendering;

MapRenderer::MapRenderer(Game::Level::Map * map) : m_map(map)
{
    m_shape = sf::RectangleShape(sf::Vector2f(10.f, 10.f));
}

MapRenderer::~MapRenderer()
{
}

void MapRenderer::Draw(Camera & camera, sf::RenderTarget & target)
{
    target.setView(camera.GetView());
    for (size_t y = 0; y < 10; y++)
    {
        for (size_t x = 0; x < 10; x++)
        {
            m_shape.setFillColor(m_map->GetTile(x, y).TextureID == 0 ? sf::Color::Green : sf::Color::Red);
            m_shape.setPosition(x * 10.f, y * 10.f);
            target.draw(m_shape);
        }
    }
}
