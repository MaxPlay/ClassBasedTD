#pragma once
#include"Texture.h"

namespace CBTD {
    namespace Assets {
        class TextureAtlas
        {
            Texture* texture;

        protected:
            void Load(std::string file);
        };
    }
}