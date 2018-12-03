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
                const Tile m_DefaultTile;
                Tile* m_Tiles;
                Waves* m_Waves;

            public:
                Map(unsigned int width, unsigned int height);
                ~Map();

                const Tile& GetTile(unsigned int x, unsigned int y) const;
                void GenerateCollision();

                int GetHeight() const;
                int GetWidth() const;
                int GetCount() const;

                static Map* CreateAndLoad(const std::string* file);
            };
        }
    }
}