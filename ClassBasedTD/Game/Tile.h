#pragma once
#include "Tower.h"

namespace CBTD {
    namespace Game {
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
}