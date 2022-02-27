#include <iostream>
#include "entity.h"

Entity::Entity(const char* name, const char* description, Entity* parent = NULL) :
name(name), description(description), parent(parent)
{
}

Entity::~Entity()
{}