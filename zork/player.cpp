#include "player.h"

int Player::getActualRoom()
{
    return actualRoom;
}

void Player::changeHasKey(bool value)
{
    hasKey = value;
}

void Player::changeActualRoom(int id)
{
    actualRoom = id;
}