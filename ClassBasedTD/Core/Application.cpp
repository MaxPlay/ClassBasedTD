#include "Application.h"
#include <SFML/Graphics.hpp>

#include "Settings.h"
#include "SceneManagement/SceneRuntime.h"
#include "Scenes.h"

using namespace CBTD;
using namespace Core;

Application* Application::s_Instance = 0;

Application::Application()
{
    Debug::Init(true, true, false, true);
    m_SceneManager = new SceneManagement::SceneManager();
    Settings::GetSettings().Load();
    m_Window = new Rendering::GameWindow();
    m_SceneManager->SetCurrentScene("ingame");
    m_SceneManager->SetCurrentLoadingScene("loading");
}

const SceneManagement::SceneManager * Application::GetSceneManager()
{
    return m_SceneManager;
}

const Rendering::GameWindow & CBTD::Core::Application::GetWindow()
{
    return *m_Window;
}

void Application::Run()
{
    sf::RenderWindow* window = m_Window->GetWindow();
    SceneManagement::SceneRuntime runtime(m_SceneManager, m_Window);

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
