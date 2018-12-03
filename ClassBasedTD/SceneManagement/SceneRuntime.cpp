#include "SceneRuntime.h"

#include "SceneManager.h"
#include "../Rendering/GameWindow.h"

using namespace CBTD;
using namespace SceneManagement;

SceneRuntime::SceneRuntime(SceneManager * manager, Rendering::GameWindow* window) : m_CurrentClearColor(0, 0, 0, 255)
{
    m_Manager = manager;
    m_Window = window;
}

SceneRuntime::~SceneRuntime()
{
    if (m_LoadingWorker)
    {
        if (m_LoadingWorker->joinable())
            m_LoadingWorker->join();
        delete m_LoadingWorker;
    }

    m_CurrentScene->Unload();
}

void SceneRuntime::LoadScene(std::string & name)
{
    m_TargetScene = &(m_Manager->GetScene(name));
}

void SceneRuntime::LoadScene(int id)
{
    m_TargetScene = &(m_Manager->GetScene(id));
}

void SceneRuntime::Update(sf::Time& elapsedTime)
{
    if (m_Manager->GetCurrentScene() != m_CurrentScene)
        m_TargetScene = m_Manager->GetCurrentScene();

    if (m_TargetScene)
    {
        if (m_CurrentScene)
            m_CurrentScene->Unload();
        m_LoadingScene = m_Manager->GetCurrentLoadingScene();
        m_LoadingScene->m_Runtime = this;
        m_LoadingScene->Load();
        if (m_LoadingWorker)
        {
            delete m_LoadingWorker;
            m_LoadingWorker = nullptr;
        }

        m_CurrentScene = m_TargetScene;
        m_TargetScene = nullptr;
        m_CurrentScene->m_Runtime = this;
        m_LoadingWorker = new std::thread(&Scene::Load, m_CurrentScene);
    }

    if (m_LoadingScene)
        m_LoadingScene->Update(elapsedTime);
    else
        m_CurrentScene->Update(elapsedTime);

    if (m_CurrentScene->IsLoaded() && m_LoadingScene)
    {
        m_LoadingScene->Unload();
        m_LoadingScene = nullptr;

        m_LoadingWorker->join();
        delete m_LoadingWorker;
        m_LoadingWorker = nullptr;
    }
}

void SceneRuntime::Render(sf::Time& elapsedTime)
{
    m_Window->GetWindow()->clear(m_CurrentClearColor);
    if (m_LoadingScene)
        m_LoadingScene->Render(elapsedTime);
    else
        m_CurrentScene->Render(elapsedTime);
}

void SceneRuntime::SetCurrentClearColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a)
{
    m_CurrentClearColor.r = r;
    m_CurrentClearColor.g = g;
    m_CurrentClearColor.b = b;
    m_CurrentClearColor.a = a;
}

void SceneRuntime::SetCurrentClearColor(sf::Color & color)
{
    m_CurrentClearColor.r = color.r;
    m_CurrentClearColor.g = color.g;
    m_CurrentClearColor.b = color.b;
    m_CurrentClearColor.a = color.a;
}

Rendering::GameWindow * SceneRuntime::GetWindow() const
{
    return m_Window;
}

sf::Color & SceneRuntime::GetCurrentClearColor()
{
    return m_CurrentClearColor;
}
