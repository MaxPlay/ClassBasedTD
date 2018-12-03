#pragma once
#include <string>
#include <map>

#include "Scene.h"

namespace CBTD {
    namespace SceneManagement {
        class SceneManager
        {
        private:
            std::map<int, Scene*> m_Scenes;
            std::map<int, Scene*> m_LoadingScenes;
            std::map<std::string, int> m_IdLookup;
            int m_CurrentLoadingScene;
            int m_CurrentScene;
            int m_IdPool;

        public:
            SceneManager();
            ~SceneManager();

            int AddScene(Scene* scene);
            Scene& GetScene(const std::string name) const;
            Scene& GetScene(int id) const;
            Scene* GetCurrentScene() const;
            int GetCurrentSceneID() const;
            Scene* GetCurrentLoadingScene() const;
            int GetCurrentLoadingSceneID() const;
            void SetCurrentScene(int id);
            void SetCurrentScene(std::string name);
            void SetCurrentScene(Scene& scene);
            void SetCurrentLoadingScene(int id);
            void SetCurrentLoadingScene(std::string name);
            void SetCurrentLoadingScene(Scene& scene);
            int GetSceneCount() const;
            int GetLoadingSceneCount() const;
        };
    }
}