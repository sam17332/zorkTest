#include <iostream>
#include "player.h"
#include "creature.h"
#include "room.h"

Player::Player(const char *title, const char *description, Room *room) : Creature(title, description, room)
{
	type = PLAYER;
}

Player::~Player()
{
}
