#pragma once
#include "../SceneManagement/Scene.h"
#include "../Rendering.h"
#include "Game.h"

namespace CBTD {
    namespace Scenes {
        class InGame : public SceneManagement::Scene
        {
        private:
            Rendering::Camera* m_Camera;
            Rendering::RendererCollection* m_Renderers;
            Game::Level::Map* m_Map;
            Game::Players::Player* m_Player;

        public:
            using Scene::Scene;
            // Inherited via Scene
            virtual void Load() override;
            virtual void Unload() override;
            virtual void Update(sf::Time & elapsedTime) override;
            virtual void Render(sf::Time & elapsedTime) override;
        };
    }
}