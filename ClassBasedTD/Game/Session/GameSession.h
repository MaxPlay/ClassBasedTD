#pragma once
#include "GameSessionTemplate.h"

#include "Game/Players/Player.h"

namespace CBTD {
    namespace Game {
        namespace Session {
            class GameSession
            {
                int m_PlayerCount;
                Players::Player* m_Players[];


            public:
                GameSession* CreateSession(const GameSessionTemplate& sessionTemplate);
                void RefreshSession(const GameSessionTemplate& sessionTemplate);
            };
        }
    }
}