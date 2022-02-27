#include <iostream>
#include "room.h"
#include "creature.h"

Creature::Creature(const char *title, const char *description, Room *room) : Entity(title, description, (Entity *)room)
{
	type = CREATURE;
}

Creature::~Creature()
{
}