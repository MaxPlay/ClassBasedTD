#include "Scene.h"

#include "SceneRuntime.h"

using namespace CBTD;
using namespace SceneManagement;

bool Scene::IsLoadingScene()
{
    return m_LoadingScene;
}

void Scene::SetIsLoadingScene(bool isLoadingScene)
{
    m_LoadingScene = isLoadingScene;
}

bool Scene::IsLoaded() const
{
    return m_Loaded;
}

const std::string& Scene::GetName() const
{
    return m_Name;
}

void Scene::LoadScene(std::string name)
{
    m_Runtime->LoadScene(name);
}

void Scene::LoadScene(int id)
{
    m_Runtime->LoadScene(id);
}

int Scene::GetId() const
{
    return m_Id;
}

Scene::Scene()
{
}

Scene::Scene(const char * name, bool isLoadingScene) : m_Name(std::string(name)), m_LoadingScene(isLoadingScene)
{

}

Scene::~Scene()
{
}
