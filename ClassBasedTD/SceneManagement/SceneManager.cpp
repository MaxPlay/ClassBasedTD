#include "Scenes/SceneLoading.h"
#include "SceneManager.h"

using namespace CBTD;

SceneManager::SceneManager() : m_IdPool(0), m_CurrentLoadingScene(-1), m_CurrentScene(-1)
{
    m_Scenes = std::map<int, Scene*>();
    m_LoadingScenes = std::map<int, Scene*>();
    m_IdLookup = std::map<std::string, int>();
    LoadScenes(this);
}

SceneManager::~SceneManager()
{
}

int SceneManager::AddScene(Scene& scene)
{
    int newID = m_IdPool++;
    m_IdLookup[scene.GetName()] = newID;
    if (scene.IsLoadingScene())
        m_LoadingScenes[newID] = &scene;
    m_Scenes[newID] = &scene;
    scene.m_Id = newID;
    return 0;
}

Scene& SceneManager::GetScene(const std::string& name) const
{
    if (m_IdLookup.find(name) == m_IdLookup.end())
        return GetScene(m_CurrentScene);
    int id = m_IdLookup.at(name);
    return GetScene(id);
}

Scene& SceneManager::GetScene(int id) const
{
    if (m_Scenes.find(id) == m_Scenes.end())
        return GetScene(m_CurrentScene);
    return *(m_Scenes.at(id));
}

Scene* SceneManager::GetCurrentScene() const
{
    return m_Scenes.at(m_CurrentScene);
}

int SceneManager::GetCurrentSceneID() const
{
    return m_CurrentScene;
}

Scene* SceneManager::GetCurrentLoadingScene() const
{
    return m_LoadingScenes.at(m_CurrentLoadingScene);
}

int SceneManager::GetCurrentLoadingSceneID() const
{
    return m_CurrentLoadingScene;
}

void SceneManager::SetCurrentScene(int id)
{
    m_CurrentScene = id;
}

void SceneManager::SetCurrentScene(std::string name)
{
    if (m_IdLookup.find(name) == m_IdLookup.end())
        return;

    m_CurrentScene = m_IdLookup[name];
}

void SceneManager::SetCurrentScene(Scene& scene)
{
    if (m_IdLookup.find(scene.GetName()) == m_IdLookup.end())
        return;

    m_CurrentScene = m_IdLookup[scene.GetName()];
}

void SceneManager::SetCurrentLoadingScene(int id)
{
    m_CurrentLoadingScene = id;
}

void SceneManager::SetCurrentLoadingScene(std::string name)
{
    if (m_IdLookup.find(name) == m_IdLookup.end())
        return;

    m_CurrentLoadingScene = m_IdLookup[name];
}

void SceneManager::SetCurrentLoadingScene(Scene& scene)
{
    if (m_IdLookup.find(scene.GetName()) == m_IdLookup.end())
        return;

    m_CurrentLoadingScene = m_IdLookup[scene.GetName()];
}

int SceneManager::GetSceneCount() const
{
    return (int)m_Scenes.size();
}

int SceneManager::GetLoadingSceneCount() const
{
    return (int)m_LoadingScenes.size();
}
