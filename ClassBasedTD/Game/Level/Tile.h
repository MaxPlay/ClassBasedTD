#pragma once
#include "Game/Tower.h"

namespace CBTD {
    struct Tile
    {
        int TextureID;
        bool Collision;
        Tower* Tower;

        Tile();
        Tile(int textureID);

        void GenerateCollision();
        bool CollisionSpecification(int textureID) const;
    };
}