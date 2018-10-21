#pragma once
#include "SceneManagement/Scene.h"

#include <vector>
#include <map>

namespace CBTD {
    namespace Assets {
        template<class T>
        class AssetManager
        {
            std::map<int, T*> m_Assets;
            std::map<std::string, int> m_AssetFiles;
            std::map<int, std::vector<int>> m_SceneLinks;
            int m_IdPool;

            ~AssetManager();
        public:
            AssetManager();

            T* GetAsset(std::string file);
            T* GetAsset(int id);
            bool HasAsset(int id);
            int RequestAsset(std::string file, SceneManagement::Scene* scene);
            void UnloadAsset(std::string file);
            void UnloadAsset(int id);
            void ClearScene(SceneManagement::Scene* scene);
            friend T;
        };

        template<class T>
        inline AssetManager<T>::~AssetManager()
        {
            std::vector<std::string> allFiles{};
            for (auto i : m_AssetFiles)
                allFiles.insert(allFiles.end(), i.first);

            for (std::string i : allFiles)
                UnloadAsset(i);

            m_SceneLinks.clear();
        }

        template<class T>
        inline AssetManager<T>::AssetManager() : m_IdPool(0), m_AssetFiles(), m_Assets(), m_SceneLinks()
        {

        }

        template<class T>
        inline T * AssetManager<T>::GetAsset(std::string file)
        {
            return m_Assets[m_AssetFiles[file]];
        }

        template<class T>
        inline T * AssetManager<T>::GetAsset(int id)
        {
            return m_Assets[id];
        }

        template<class T>
        inline bool AssetManager<T>::HasAsset(int id)
        {
            return m_Assets.find(id) == m_Assets.end();
        }

        template<class T>
        inline int AssetManager<T>::RequestAsset(std::string file, SceneManagement::Scene* scene)
        {
            if (m_AssetFiles.find(file) == m_AssetFiles.end())
            {
                T* asset = new T();
                asset->Load(file);
                int id = m_IdPool++;

                m_AssetFiles[file] = id;
                m_Assets[id] = asset;
                m_SceneLinks[scene->GetId()].push_back(id);
            }

            return m_AssetFiles[file];
        }

        template<class T>
        inline void AssetManager<T>::UnloadAsset(std::string file)
        {
            if (m_AssetFiles.find(file) == m_AssetFiles.end()) return;

            int id = m_AssetFiles[file];
            m_AssetFiles.erase(file);

            T* asset = m_Assets[id];
            delete asset;
            m_Assets.erase(id);
        }

        template<class T>
        inline void AssetManager<T>::UnloadAsset(int id)
        {
            auto it = std::find_if(m_AssetFiles.begin(), m_AssetFiles.end(), [id](const std::pair<std::string, int> & t)->bool { return t.second == id; });
            if (it == m_AssetFiles.end())
                return;
            
            std::string file = it->first;
            UnloadAsset(file);
        }

        template<class T>
        inline void AssetManager<T>::ClearScene(SceneManagement::Scene* scene)
        {
            int id = scene->GetId();
            if (m_SceneLinks.find(id) == m_SceneLinks.end())
                return;

            std::vector<int> clearableAssets{};

            for (auto i : m_SceneLinks[id])
                clearableAssets.push_back(i);

            for (auto l : m_SceneLinks)
            {
                if (l.first == id)
                    continue;

                for (auto i : l.second)
                {
                    clearableAssets.erase(std::remove(clearableAssets.begin(), clearableAssets.end(), i), clearableAssets.end());
                }
            }

            for (auto i : clearableAssets)
                UnloadAsset(i);

            m_SceneLinks.erase(id);
        }
    }
}