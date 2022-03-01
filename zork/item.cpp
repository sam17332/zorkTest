#include <iostream>
#include "item.h"
#include "entity.h"

Item::Item(const char *name, const char *description, Entity *parent, ItemType itemType) : Entity(name, description, parent), itemType(itemType), name(name), description(description), parent(parent)
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
