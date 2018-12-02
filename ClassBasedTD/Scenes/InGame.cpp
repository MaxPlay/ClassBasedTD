#include "InGame.h"
#include <SFML/Window.hpp>

#include "SceneManagement/SceneRuntime.h"
#include "Assets/AssetManagement.h"

using namespace CBTD;
using namespace Scenes;

void InGame::Load()
{
    m_Camera = new Rendering::Camera(m_Runtime->GetWindow()->GetWindow());
    m_Map = new Game::Level::Map(10, 10);
    m_MapRenderer = new Rendering::MapRenderer(m_Map);
    m_Player = new Game::Players::Player(nullptr);
    m_Loaded = true;
    m_Runtime->SetCurrentClearColor(120, 150, 15, 255);
}

void InGame::Unload()
{
    Assets::AssetManagement::GetTextureManager()->ClearScene(this);
    delete m_Camera;
    delete m_Map;
    delete m_MapRenderer;
}

void InGame::Update(sf::Time & elapsedTime)
{
    m_Player->UpdateInput();
}

void InGame::Render(sf::Time & elapsedTime)
{
    m_MapRenderer->Draw(*m_Camera, *(m_Runtime->GetWindow()->GetWindow()));
    m_Runtime->GetWindow()->GetWindow()->draw(m_PlayerShape);
}
