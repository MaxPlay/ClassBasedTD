#pragma once
#include <SFML/Graphics/Texture.hpp>

namespace CBTD
{
    class Texture
    {
        sf::Texture m_Texture;
        std::string m_File;

    public:
        void Load(std::string file);
        sf::Texture* GetTexture();
    };
}