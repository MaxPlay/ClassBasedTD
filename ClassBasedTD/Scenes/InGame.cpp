#include "InGame.h"
#include <SFML/Window.hpp>

#include "Rendering/GameWindow.h"
#include "Rendering/Camera.h"
#include "Rendering/RendererCollection.h"
#include "Game/Level/Map.h"
#include "Rendering/Renderers/MapRenderer.h"
#include "Game/Players/Player.h"
#include "Rendering/Renderers/PlayerRenderer.h"
#include "SceneManagement/SceneRuntime.h"
#include "Assets/AssetManagement.h"

using namespace CBTD;

void InGame::Load()
{
    m_Camera = new Camera(m_Runtime->GetWindow()->GetWindow());
    m_Renderers = new RendererCollection();
    m_Renderers->SetCamera(m_Camera);
    m_Map = new Map(10, 10);
    m_Renderers->AddRenderer(new MapRenderer(*m_Map));
    m_Player = new Player();
    m_Renderers->AddRenderer(new PlayerRenderer(m_Player));
    m_Loaded = true;
    m_Runtime->SetCurrentClearColor(120, 150, 15, 255);
}

void InGame::Unload()
{
    AssetManagement::GetTextureManager()->ClearScene(this);
    delete m_Camera;
    delete m_Map;
    m_Renderers->DisposeAndClear();
    delete m_Renderers;
}

void InGame::Update(const sf::Time & elapsedTime)
{
    m_Player->UpdateInput();
}

void InGame::Render(const sf::Time & elapsedTime)
{
    sf::RenderTarget& currentTarget = *(m_Runtime->GetWindow()->GetWindow());
    m_Renderers->Draw(currentTarget);
}
