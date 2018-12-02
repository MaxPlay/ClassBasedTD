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
            Rendering::MapRenderer* m_MapRenderer;
            Game::Level::Map* m_Map;
            Game::Players::Player* m_Player;
            sf::CircleShape m_PlayerShape;

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