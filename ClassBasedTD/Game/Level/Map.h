#pragma once
#include <string>

#include "Tile.h"
#include "Waves.h"

namespace CBTD {
    namespace Game {
        namespace Level {
            class Map
            {
            private:
                unsigned int m_Height;
                unsigned int m_Width;
                unsigned int m_Count;
                Tile m_DefaultTile;
                Tile* m_Tiles;
                Waves* m_Waves;

            public:
                Map(unsigned int width, unsigned int height);
                ~Map();

                Tile& GetTile(unsigned int x, unsigned int y);
                void GenerateCollision();

                int GetHeight();
                int GetWidth();
                int GetCount();

                static Map* CreateAndLoad(const std::string* file);
            };
        }
    }
}