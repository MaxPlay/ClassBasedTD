#include "PlayerRenderer.h"
#include "Core/Globals.h"

using namespace CBTD;
using namespace Rendering;
using namespace Renderers;

PlayerRenderer::PlayerRenderer(Game::Players::Player * player, int priority) : m_Player(player), Renderer(priority)
{
    m_Shape = sf::CircleShape(Core::Globals::TILE_SIZE / 2);
    m_Shape.setFillColor(sf::Color(0, 255, 255, 255));
}

PlayerRenderer::~PlayerRenderer()
{
}

void PlayerRenderer::Draw(sf::RenderTarget & target)
{
    m_Shape.setPosition(m_Player->GetPosition());
    target.draw(m_Shape);
}
