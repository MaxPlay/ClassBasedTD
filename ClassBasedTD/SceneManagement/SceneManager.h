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
            int m_idPool;

        public:
            SceneManager();
            ~SceneManager();

            int AddScene(Scene* scene);
            Scene& GetScene(const std::string name);
            Scene& GetScene(int id);
            Scene* GetCurrentScene();
            int GetCurrentSceneID();
            Scene* GetCurrentLoadingScene();
            int GetCurrentLoadingSceneID();
            void SetCurrentScene(int id);
            void SetCurrentScene(std::string name);
            void SetCurrentScene(Scene& scene);
            void SetCurrentLoadingScene(int id);
            void SetCurrentLoadingScene(std::string name);
            void SetCurrentLoadingScene(Scene& scene);
            int GetSceneCount();
            int GetLoadingSceneCount();
        };
    }
}