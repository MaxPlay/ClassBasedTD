#include "Player.h"

#include "SFML/Window/Joystick.hpp"
#include "SFML/Window/Keyboard.hpp"
using namespace CBTD;

Player::Player() : m_Position()
{
}

void Player::UpdateInput()
{
    if (sf::Joystick::isButtonPressed(0, 0))
        m_Position.x -= 1;
}

const sf::Vector2f & Player::GetPosition() const
{
    return m_Position;
}
