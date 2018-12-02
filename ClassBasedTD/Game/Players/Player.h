#pragma once

#include <SFML/System/Vector2.hpp>
#include "Game/Session/PlayerTemplate.h"

namespace CBTD {
    namespace Game {
        namespace Players {
            class Player
            {
                sf::Vector2f m_Position;

            public:
                Player(const Session::PlayerTemplate* playerTemplate);

                void UpdateInput();
                const sf::Vector2f& GetPosition();
                const sf::Vector2f& GetPosition() const;
            };
        }
    }
}