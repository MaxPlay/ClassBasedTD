#pragma once
#include "SceneManagement/SceneManager.h"
#include "Rendering/GameWindow.h"
#include "Debug.h"

namespace CBTD
{
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
        SceneManager* m_SceneManager;
        GameWindow* m_Window;
        bool m_Running;

    public:
        const SceneManager* GetSceneManager() const;
        const GameWindow& GetWindow() const;
        void Run();
        void Exit();
        bool IsRunning();
    };
}