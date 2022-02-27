#ifndef __Player__
#define __Player__

#include <iostream>
#include "player.h"
#include "creature.h"

Player::Player(const char *title, const char *description, Room *room) : Creature(title, description, room)
{
	type = PLAYER;
}

Player::~Player()
{
}

#endif //__Player__