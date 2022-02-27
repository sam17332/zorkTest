#include <iostream>
#include "item.h"
#include "entity.h"

Item::Item(const char *name, const char *description, Entity *parent, ItemType item_type) : Entity(name, description, parent)
{
}

Item::~Item()
{
}
