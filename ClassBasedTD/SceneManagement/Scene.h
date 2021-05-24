#pragma once
#include <SFML/System/Time.hpp>

#include <string>

namespace CBTD
{
    class SceneRuntime;

    class Scene
    {
    private:
        bool m_LoadingScene;
        std::string m_Name;
        int m_Id;

    protected:
        bool m_Loaded;
        SceneRuntime* m_Runtime;
        void LoadScene(std::string name);
        void LoadScene(int id);
        Scene();

    public:
        explicit Scene(const char* name, bool isLoadingScene = false);
        virtual ~Scene();
        virtual void Load() = 0;
        virtual void Unload() = 0;
        virtual void Update(const sf::Time& elapsedTime) = 0;
        virtual void Render(const sf::Time& elapsedTime) = 0;
        bool IsLoadingScene();
        void SetIsLoadingScene(bool isLoadingScene);
        bool IsLoaded() const;
        const std::string& GetName() const;
        int GetId() const;

        friend class SceneRuntime;
        friend class SceneManager;
    };
}