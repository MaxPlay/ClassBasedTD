#pragma once
#include "SceneManagement/Scene.h"

namespace CBTD {
    namespace Scenes {
        class Loading : public SceneManagement::Scene
        {
            using Scene::Scene;
            // Inherited via Scene
            virtual void Load() override;
            virtual void Unload() override;
            virtual void Update(sf::Time & elapsedTime) override;
            virtual void Render(sf::Time & elapsedTime) override;
        };
    }
}