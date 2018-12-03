#pragma once
#include <array>
#include "Core/Globals.h"
#include "GameSessionTemplate.h"

#include "Game/Players/Player.h"

namespace CBTD {
    namespace Game {
        namespace Session {
            class GameSession
            {
                int m_PlayerCount;
                std::array<Players::Player*, Core::Globals::MAX_PLAYER_COUNT> m_Players;

            public:
                GameSession* CreateSession(const GameSessionTemplate& sessionTemplate);
                void RefreshSession(const GameSessionTemplate& sessionTemplate);
            };
        }
    }
}