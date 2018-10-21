#pragma once
#include "AssetManager.h"
#include "Texture.h"

namespace CBTD {
    namespace Assets {

        typedef AssetManager<Texture> TextureManager;

        class AssetManagement
        {
            static TextureManager* s_Textures;

        public:
            static TextureManager* GetTextureManager();
        };

    }
}