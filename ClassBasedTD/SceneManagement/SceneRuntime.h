#pragma once
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

        public:
            SceneRuntime(SceneManager* manager, Rendering::GameWindow* window);
            ~SceneRuntime();

            void LoadScene(std::string& name);
            void LoadScene(int id);
            void Update(sf::Time& elapsed);
            void Render(sf::Time& elapsed);
            Rendering::GameWindow* GetWindow();
        };
    }
}