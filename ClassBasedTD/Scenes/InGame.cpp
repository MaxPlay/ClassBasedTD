#include "InGame.h"
#include "SceneManagement/SceneRuntime.h"
#include "Assets/AssetManagement.h"

using namespace CBTD;
using namespace Scenes;

void InGame::Load()
{
    m_Camera = new Rendering::Camera(m_Runtime->GetWindow()->GetWindow());
    m_Map = new Game::Map(10, 10);
    m_MapRenderer = new Rendering::MapRenderer(m_Map);
    m_Loaded = true;

    texture = Assets::AssetManagement::GetTextureManager()->RequestAsset("D:\\Repos\\ClassBasedTD\\bin\\x86\\Debug\\vanGogh.png", this);
    sprite = sf::Sprite(*(Assets::AssetManagement::GetTextureManager()->GetAsset(texture)->GetTexture()));
    time = sf::Time();
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
    time += elapsedTime;
    if (time.asSeconds() > 4)
    {
        LoadScene(GetId());
    }
}

void InGame::Render(sf::Time & elapsedTime)
{
    m_MapRenderer->Draw(*m_Camera, *(m_Runtime->GetWindow()->GetWindow()));
    m_Runtime->GetWindow()->GetWindow()->draw(sprite);
}
