#include <iostream>
#include "room.h"
#include "item.h"
#include "entity.h"
#include "door.h"

Door::Door(const char *name, const char *description, Room *room1, Room *room2, Item *opensWith, bool locked) : Entity(name, description, room2), locked(locked)
{
    type = DOOR;
}

Door::~Door()
{
}
