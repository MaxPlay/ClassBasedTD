#pragma once

#include <SFML/System/Vector2.hpp>
#include "Game/Session/PlayerTemplate.h"

namespace CBTD {
    struct PlayerTemplate;

    class Player
    {
        sf::Vector2f m_Position;

    public:
        Player();

        void UpdateInput();
        const sf::Vector2f& GetPosition() const;
    };
}