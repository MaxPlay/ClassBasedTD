#include "Map.h"

using namespace CBTD;
using namespace Game;

Map::Map(unsigned int width, unsigned int height) : m_Width(width), m_Height(height), m_Count(width * height)
{
    m_DefaultTile = Tile();
    m_Tiles = new Tile[m_Count];
    for (size_t i = 0; i < m_Count; i++)
        m_Tiles[i] = rand() % 2;
}

Map::~Map()
{
    delete[] m_Tiles;
}

Tile& Map::GetTile(unsigned int x, unsigned int y)
{
    if (x >= m_Width || y >= m_Height)
        return m_DefaultTile;

    return m_Tiles[y * m_Width + x];
}

void Map::GenerateCollision()
{
    for (size_t i = 0; i < m_Count; i++)
        m_Tiles[i].GenerateCollision();
}

int CBTD::Game::Map::GetHeight()
{
    return m_Height;
}

int CBTD::Game::Map::GetWidth()
{
    return m_Width;
}

int CBTD::Game::Map::GetCount()
{
    return m_Count;
}

Map * Map::CreateAndLoad(const std::string * file)
{
    return nullptr;
}
