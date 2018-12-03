#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include <thread>

namespace CBTD {
    namespace Rendering {
        class GameWindow;
    }

    namespace SceneManagement {
        class SceneManager;
        class Scene;

        class SceneRuntime
        {
        private:
            SceneManager* m_Manager;
            Scene* m_CurrentScene;
            Scene* m_TargetScene;
            Scene* m_LoadingScene;
            Rendering::GameWindow* m_Window;
            std::thread* m_LoadingWorker;
            sf::Color m_CurrentClearColor;

        public:
            SceneRuntime(SceneManager* manager, Rendering::GameWindow* window);
            ~SceneRuntime();

            void LoadScene(std::string& name);
            void LoadScene(int id);
            void Update(sf::Time& elapsed);
            void Render(sf::Time& elapsed);
            void SetCurrentClearColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a);
            void SetCurrentClearColor(sf::Color& color);

            Rendering::GameWindow* GetWindow() const;
            sf::Color& GetCurrentClearColor();
        };
    }
}