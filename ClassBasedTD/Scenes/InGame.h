#pragma once
#include "../SceneManagement/Scene.h"

namespace CBTD
{
    class Camera;
    class RendererCollection;
    class Map;
    class Player;

    class InGame : public Scene
    {
    private:
        Camera* m_Camera;
        RendererCollection* m_Renderers;
        Map* m_Map;
        Player* m_Player;

    public:
        using Scene::Scene;
        // Inherited via Scene
        virtual void Load() override;
        virtual void Unload() override;
        virtual void Update(const sf::Time& elapsedTime) override;
        virtual void Render(const sf::Time& elapsedTime) override;
    };
}