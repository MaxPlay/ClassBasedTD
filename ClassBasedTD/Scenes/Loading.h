#pragma once
#include "SceneManagement/Scene.h"

namespace CBTD
{
    class Loading : public Scene
    {
        using Scene::Scene;

        // Inherited via Scene
        virtual void Load() override;
        virtual void Unload() override;
        virtual void Update(const sf::Time& elapsedTime) override;
        virtual void Render(const sf::Time& elapsedTime) override;
    };
}