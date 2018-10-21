#pragma once
#include "../SceneManagement/Scene.h"
#include "../Rendering.h"
#include "../Game/Map.h"

namespace CBTD {
    namespace Scenes {
        class InGame : public SceneManagement::Scene
        {
        private:
            Rendering::Camera* m_Camera;
            Rendering::MapRenderer* m_MapRenderer;
            Game::Map* m_Map;
            int texture;
            sf::Sprite sprite;
            sf::Time time;

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