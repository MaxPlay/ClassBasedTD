#include "Texture.h"

using namespace CBTD;
using namespace Assets;

void Texture::Load(std::string file)
{
    m_Texture = sf::Texture();
    m_Texture.loadFromFile(file);
}

sf::Texture * Texture::GetTexture()
{
    return &m_Texture;
}
