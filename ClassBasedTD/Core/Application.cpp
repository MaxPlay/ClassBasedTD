#include "Application.h"
#include <SFML/Graphics.hpp>

#include "Settings.h"
#include "SceneManagement/SceneRuntime.h"

using namespace CBTD;

Application* Application::s_Instance = 0;

Application::Application()
{
    Debug::Init(true, true, false, true);
    m_SceneManager = new SceneManager();
    Settings::GetSettings().Load();
    m_Window = new GameWindow();
    m_SceneManager->SetCurrentScene("ingame");
    m_SceneManager->SetCurrentLoadingScene("loading");
}

const SceneManager * Application::GetSceneManager() const
{
    return m_SceneManager;
}

const GameWindow & CBTD::Application::GetWindow() const
{
    return *m_Window;
}

void Application::Run()
{
    sf::RenderWindow* window = m_Window->GetWindow();
    SceneRuntime runtime(m_SceneManager, m_Window);

    sf::Clock clock;
    m_Running = true;
    while (IsRunning())
    {
        sf::Event e;
        while (window->pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                Exit();
        }

        sf::Time elapsed = clock.restart();
        runtime.Update(elapsed);
        window->clear();
        runtime.Render(elapsed);
        window->display();
    }
}

void Application::Exit()
{
    m_Running = false;
}

bool Application::IsRunning()
{
    return m_Running && m_Window->IsOpen();
}
