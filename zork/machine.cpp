#include <iostream>
#include "item.h"
#include "entity.h"
#include "machine.h"

Machine::Machine(const char *name, const char *description, Entity *parent, Item *chargesWith, bool charged) : Entity(name, description, parent), charged(charged)
{
    type = MACHINE;
}

Machine::~Machine()
{
}
