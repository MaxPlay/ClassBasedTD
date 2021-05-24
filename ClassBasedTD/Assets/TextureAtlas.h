#pragma once
#include"Texture.h"

namespace CBTD
{
    class TextureAtlas
    {
        Texture* texture;

    protected:
        void Load(std::string file);
    };
}
