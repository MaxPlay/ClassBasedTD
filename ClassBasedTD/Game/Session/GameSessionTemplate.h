#pragma once
#include "Core/Globals.h"
#include "PlayerTemplate.h"

#include <string>

namespace CBTD {
    namespace Game {
        namespace Session {
            class GameSessionTemplate
            {
            private:
                int m_PlayerCount;
                PlayerTemplate* m_Players[Core::Globals::MAX_PLAYER_COUNT];
                int m_StartingResources;
                std::string m_MapFile;
                int m_Lives;
            };
        }
    }
}