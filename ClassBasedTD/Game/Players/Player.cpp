#include "Player.h"

using namespace CBTD;
using namespace Game;
using namespace Players;

Player::Player(const Session::PlayerTemplate * playerTemplate) : m_Position()
{
    
}

void Player::UpdateInput()
{

}

const sf::Vector2f & Player::GetPosition() const
{
    return m_Position;
}
