#include "AssetManagement.h"

using namespace CBTD;

TextureManager* AssetManagement::s_Textures = 0;

TextureManager* AssetManagement::GetTextureManager()
{
    if (!s_Textures)
        s_Textures = new AssetManager<Texture>();

    return s_Textures;
}
