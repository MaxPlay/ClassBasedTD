#include "Tile.h"

using namespace CBTD;
using namespace Game;
using namespace Level;

Tile::Tile() : TextureID(0), Collision(false), Tower(0)
{
    GenerateCollision();
}

Tile::Tile(int textureID) : TextureID(textureID), Collision(false), Tower(0)
{
    GenerateCollision();
}

void Tile::GenerateCollision()
{
    Collision = CollisionSpecification(TextureID) || Tower;
}

bool Tile::CollisionSpecification(int textureID) const
{
    switch (textureID)
    {
    case 1:
        return true;
    default:
        return false;
    }
}
