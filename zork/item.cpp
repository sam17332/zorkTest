#include <iostream>
#include "item.h"
#include "entity.h"

Item::Item(const char *name, const char *description, Entity *parent, ItemType itemType) : Entity(name, description, parent), name(name), description(description), parent(parent), itemType(itemType)
{
}

Item::~Item()
{
}

Item* Item::ChangeParent(Entity *newParent)
{
    parent = newParent;

    return this;
}
