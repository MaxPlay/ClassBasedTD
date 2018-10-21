#include "InGame.h"
#include "SceneManagement/SceneRuntime.h"

using namespace CBTD;
using namespace Scenes;

void InGame::Load()
{
    m_Camera = new Rendering::Camera(m_Runtime->GetWindow()->GetWindow());
    m_Map = new Game::Map(10, 10);
    m_MapRenderer = new Rendering::MapRenderer(m_Map);
    m_Loaded = true;

    texture = sf::Texture();
    texture.loadFromFile("D:\\Repos\\ClassBasedTD\\bin\\x86\\Debug\\vanGogh.png");
    sprite = sf::Sprite(texture);
}

void InGame::Unload()
{
    delete m_Camera;
    delete m_Map;
    delete m_MapRenderer;
}

void InGame::Update(sf::Time & elapsedTime)
{
}

void InGame::Render(sf::Time & elapsedTime)
{
    m_MapRenderer->Draw(*m_Camera, *(m_Runtime->GetWindow()->GetWindow()));
    m_Runtime->GetWindow()->GetWindow()->draw(sprite);
}
