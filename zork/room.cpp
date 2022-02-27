#include <iostream>
#include "item.h"
#include "room.h"

Room::Room(const char *title, const char *description) : Entity(title, description, NULL)
{
	type = ROOM;
}

Room::~Room()
{
}