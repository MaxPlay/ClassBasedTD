#pragma once
#include "SceneManagement/SceneManager.h"
#include "Rendering/GameWindow.h"
#include "Debug.h"

namespace CBTD {
    namespace Core {
        class Application
        {
        private:
            static Application* s_Instance;
        public:
            inline static Application* GetApplication()
            {
                if (!s_Instance)
                    s_Instance = new Application();
                return s_Instance;
            }

        private:
            Application();
            SceneManagement::SceneManager* m_SceneManager;
            Rendering::GameWindow* m_Window;
            bool m_Running;

        public:
            const SceneManagement::SceneManager* GetSceneManager();
            const Rendering::GameWindow& GetWindow();
            void Run();
            void Exit();
            bool IsRunning();
        };
    }
}