#include "InGame.h"
#include <SFML/Window.hpp>

#include "SceneManagement/SceneRuntime.h"
#include "Assets/AssetManagement.h"

using namespace CBTD;
using namespace Scenes;

void InGame::Load()
{
    m_Camera = new Rendering::Camera(m_Runtime->GetWindow()->GetWindow());
    m_Renderers = new Rendering::RendererCollection();
    m_Renderers->SetCamera(m_Camera);
    m_Map = new Game::Level::Map(10, 10);
    m_Renderers->AddRenderer(new Rendering::Renderers::MapRenderer(m_Map));
    m_Player = new Game::Players::Player(nullptr);
    m_Renderers->AddRenderer(new Rendering::Renderers::PlayerRenderer(m_Player));
    m_Loaded = true;
    m_Runtime->SetCurrentClearColor(120, 150, 15, 255);
}

void InGame::Unload()
{
    Assets::AssetManagement::GetTextureManager()->ClearScene(this);
    delete m_Camera;
    delete m_Map;
    m_Renderers->DisposeAndClear();
    delete m_Renderers;
}

void InGame::Update(sf::Time & elapsedTime)
{
    m_Player->UpdateInput();
}

void InGame::Render(sf::Time & elapsedTime)
{
    sf::RenderTarget& currentTarget = *(m_Runtime->GetWindow()->GetWindow());
    m_Renderers->Draw(currentTarget);
}
